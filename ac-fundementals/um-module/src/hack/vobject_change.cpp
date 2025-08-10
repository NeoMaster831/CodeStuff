#include "vobject_change.hpp"
#include <stdexcept>
#include <iostream>

namespace wsbp::vobj {

    uintptr_t g_circle = [] (size_t g_circleOffset) {
        HMODULE hModule = GetModuleHandleW(L"um_module.dll");
        if (!hModule)
            throw std::runtime_error("Failed to get module handle");
        uintptr_t baseAddress = reinterpret_cast<uintptr_t>(hModule);
        return baseAddress + g_circleOffset;
    }(0x915b8);

    double AreaHook(void* obj) {
        if (!obj)
            throw std::invalid_argument("sanity check failed !!!");
        return 1337.0;
    }

    void HookObject(void* obj, void* hook, size_t vftable_idx) {
        void** vtable = *reinterpret_cast<void***>(obj);

        DWORD oldProtect;
        if (VirtualProtect(vtable, sizeof(void*), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            vtable[vftable_idx] = hook;
            if (!VirtualProtect(vtable, sizeof(void*), oldProtect, &oldProtect)) {
                throw std::runtime_error("Failed to restore memory protection");
            }
        } else {
            throw std::runtime_error("Failed to change memory protection");
        }
    }
}