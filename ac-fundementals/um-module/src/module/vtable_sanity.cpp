#include "vtable_sanity.hpp"
#include <iostream>
#include <psapi.h>
#include <vector>
#include <algorithm>
#include <cwctype>

static bool ReadPtrSafe(const void* src, void** outp) {
    __try {
        *outp = *(void* const*)src;
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

static bool IsLikelyEndOfVTable(void* slot_ptr) {
    void* pv{};
    if (!ReadPtrSafe(slot_ptr, &pv)) return true;
    return pv == nullptr;
}

static bool IsExecutableProtectAt(const void* addr) {
    MEMORY_BASIC_INFORMATION mbi{};
    if (!VirtualQuery(addr, &mbi, sizeof(mbi))) return false;
    DWORD prot = mbi.Protect & 0xFF;
    if (prot == PAGE_NOACCESS || prot == PAGE_GUARD) return false;
    return (prot & (PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)) != 0;
}

static bool IsMemImageAt(const void* addr)
{
    MEMORY_BASIC_INFORMATION mbi{};
    if (!VirtualQuery(addr, &mbi, sizeof(mbi))) return false;
    return mbi.Type == MEM_IMAGE;
}

static std::wstring ModulePathFromBase(void* base) {
    wchar_t buf[MAX_PATH];
    HMODULE h = (HMODULE)base;
    DWORD n = GetModuleFileNameW(h, buf, MAX_PATH);
    if (!n)
        throw std::runtime_error("Failed to get module path");
    
    return std::wstring(buf, buf+n);
}

static std::wstring ModuleFileNameOnly(const std::wstring& path) {
    size_t p = path.find_last_of(L"\\/");
    if (p == std::wstring::npos) return path;
    return path.substr(p+1);
}

static std::wstring ToLower(const std::wstring& s) {
    std::wstring t = s;
    std::transform(t.begin(), t.end(), t.begin(),
                    [](wchar_t c){ return std::towlower(c); });
    return t;
}

static bool NameMatchesAllowList(const std::wstring& module_name, const std::vector<std::wstring>& allowList) {
    if (allowList.empty()) return true;
    auto low = ToLower(module_name);
    for (auto& k : allowList) {
        auto kk = ToLower(k);
        if (low.find(kk) != std::wstring::npos) return true;
    }
    return false;
}

static bool GetModuleBaseOf(const void* addr, HMODULE& out_mod) {
    MEMORY_BASIC_INFORMATION mbi{};
    if (!VirtualQuery(addr, &mbi, sizeof(mbi))) return false;
    out_mod = (HMODULE)mbi.AllocationBase;
    return true;
}

static bool IsInTrustedRegion(const void* addr)
{
    static auto trusted = [] (const std::vector<std::wstring>& allowed) {
        HMODULE mods[1024];
        DWORD needed = 0;
        if (!EnumProcessModulesEx(GetCurrentProcess(), mods, sizeof(mods), &needed, LIST_MODULES_ALL)) {
            throw std::runtime_error("Failed to enumerate modules");
        }

        size_t count = needed / sizeof(HMODULE);
        std::vector<std::pair<uintptr_t, size_t>> vct(count);

        for (size_t i = 0; i < count; ++i) {
            MODULEINFO mi{};
            if (!GetModuleInformation(GetCurrentProcess(), mods[i], &mi, sizeof(mi))) {
                continue;
            }

            std::wstring path = ModulePathFromBase(mi.lpBaseOfDll);
            std::wstring name = ModuleFileNameOnly(path);
            if (!NameMatchesAllowList(name, allowed))
                continue;
            vct.push_back({(uintptr_t)mi.lpBaseOfDll, (size_t)mi.SizeOfImage});
        }

        return vct;
    }({L"test_app.exe", L"um_module.dll"});

    auto p = (uintptr_t)addr;
    for (auto& r : trusted) {
        auto b = r.first;
        if (p >= b && p < b + r.second) {
            return true;
        }
    }

    return false;
}

static bool ReadSafe(const void* src, void* dst, SIZE_T sz) {
    __try {
        memcpy(dst, src, sz);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

bool IsInExecutableSectionOfModule(const void* addr) {
    HMODULE mod{};
    if (!GetModuleBaseOf(addr, mod)) return false;

    IMAGE_DOS_HEADER dos{};
    if (!ReadSafe(mod, &dos, sizeof(dos))) return false;
    if (dos.e_magic != IMAGE_DOS_SIGNATURE) return false;

    BYTE* base = (BYTE*)mod;
    auto nt = (IMAGE_NT_HEADERS*)(base + dos.e_lfanew);
    IMAGE_FILE_HEADER fh{};
    if (!ReadSafe(&nt->FileHeader, &fh, sizeof(fh))) return false;

    WORD magic{};
    if (!ReadSafe(&nt->OptionalHeader.Magic, &magic, sizeof(magic))) return false;
    DWORD nsects = fh.NumberOfSections;

    IMAGE_SECTION_HEADER* sh = IMAGE_FIRST_SECTION(nt);
    uintptr_t p = (uintptr_t)addr;
    uintptr_t b = (uintptr_t)base;

    for (DWORD i = 0; i < nsects; ++i) {
        IMAGE_SECTION_HEADER sec{};
        if (!ReadSafe(&sh[i], &sec, sizeof(sec))) continue;

        DWORD va = sec.VirtualAddress;
        DWORD vsz = sec.Misc.VirtualSize ? sec.Misc.VirtualSize : sec.SizeOfRawData;

        uintptr_t s_base = b + va;
        uintptr_t s_end = s_base + vsz;

        if ((uintptr_t)addr >= s_base && (uintptr_t)addr < s_end) {
            bool exec = (sec.Characteristics & IMAGE_SCN_MEM_EXECUTE) != 0;
            return exec;
        }
    }

    return false;
}

namespace wsac::module::vsan {

    BOOL CheckObjectVTable(void* object_ptr, size_t max_slots) {
        if (!object_ptr) return FALSE;

        void* vptr{};
        if (!ReadPtrSafe(object_ptr, &vptr) || !vptr) {
            std::cout << "[check vtable] no vptr" << '\n';
            return FALSE;
        }

        BOOL result = FALSE;
        for (size_t i = 0; !result && i < max_slots; ++i) {
            void** slot_addr = (void**)((BYTE*)vptr + i * sizeof(void*));

            if (IsLikelyEndOfVTable(slot_addr))
                break;
            
            void* func{};
            if (!ReadPtrSafe(slot_addr, &func)) {
                std::cout << "[check vtable] invalid slot at index " << i << '\n';
                result |= TRUE;
            }

            if (!IsExecutableProtectAt(func)) {
                std::cout << "[check vtable] non-executable slot at index " << i << '\n';
                result |= TRUE;
            }

            if (!IsMemImageAt(func)) {
                std::cout << "[check vtable] not MEM_IMAGE at index " << i << '\n';
                result |= TRUE;
            }

            if (!IsInTrustedRegion(func)) {
                std::cout << "[check vtable] not in trusted region at index " << i << '\n';
                result |= TRUE;
            }

            if (!IsInExecutableSectionOfModule(func)) {
                std::cout << "[check vtable] not in executable section of module at index " << i << '\n';
                result |= TRUE;
            }

        }

        return result;
    }

}