#pragma once

#include <windows.h>

namespace wsbp::vobj {
    extern uintptr_t g_circle;
    double AreaHook(void* obj);
    void HookObject(void* obj, void* hook, size_t vftable_idx);
}