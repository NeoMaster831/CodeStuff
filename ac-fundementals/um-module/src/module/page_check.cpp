#include "page_check.hpp"
#include <psapi.h>

static std::unordered_set<void *> GetLoadedModuleBases()
{
    std::unordered_set<void *> bases;
    HMODULE mods[1024]; // who tf loads 1024 modules..
    DWORD needed = 0;
    if (EnumProcessModulesEx(GetCurrentProcess(), mods, sizeof(mods), &needed, LIST_MODULES_ALL))
    {
        size_t count = needed / sizeof(HMODULE);
        for (size_t i = 0; i < count; ++i)
        {
            bases.insert(reinterpret_cast<void *>(mods[i]));
        }
    }
    return bases;
}

static bool IsExecutableProtect(DWORD prot) {
    return (prot & (PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)) != 0;
}

static bool HasImageType(const MEMORY_BASIC_INFORMATION& mbi) {
    // MEM_IMAGE indicates sections created by the loader (normal DLL/EXE).
    return (mbi.Type == MEM_IMAGE);
}

static bool RegionBackedByFile(void* base) {
    wchar_t path[MAX_PATH];
    DWORD len = GetMappedFileNameW(GetCurrentProcess(), base, path, MAX_PATH);
    return (len != 0);
}

static bool LooksSuspicious(const MEMORY_BASIC_INFORMATION& mbi, const std::unordered_set<void*>& loaderBases)
{
    if (mbi.State != MEM_COMMIT) return false;
    if (!IsExecutableProtect(mbi.Protect)) return false;
    
    bool noFile = !RegionBackedByFile(mbi.BaseAddress);
    bool notLoaderImage = !HasImageType(mbi);
    bool notInLoaderList = loaderBases.find(mbi.AllocationBase) == loaderBases.end();

    // It requires heuristics, but this time I will not include heuristics.
    // You can include KofN strategy to implement heuristics
    return noFile && notLoaderImage && notInLoaderList;
}

namespace wsac::module::pgck
{

    BOOL PerformPageCheck()
    {
        SYSTEM_INFO si{};
        GetSystemInfo(&si);

        auto mods = GetLoadedModuleBases();
        BYTE* p = (BYTE*)si.lpMinimumApplicationAddress; // l
        BYTE* end = (BYTE*)si.lpMaximumApplicationAddress;

        BOOL result = FALSE;
        
        while (p < end) {
            MEMORY_BASIC_INFORMATION mbi{};
            SIZE_T q = VirtualQuery(p, &mbi, sizeof(mbi));
            if (q == 0) break;

            if (LooksSuspicious(mbi, mods)) {
                std::cout << "Suspicious memory region found: (" << std::hex << mbi.BaseAddress << ", " << mbi.RegionSize << std::dec << ")\n";
                result |= TRUE;
            }

            BYTE* next = (BYTE*)mbi.BaseAddress + mbi.RegionSize;
            if (next <= p) break; // For extra safety
            p = next;
        }

        return result;
    }

}