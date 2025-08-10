#include <windows.h>
#include <iostream>
#include "vobject_change.hpp"

BOOL InitializeHack() {
    using namespace wsbp::vobj;
    HookObject(*(void**)g_circle, AreaHook, 0);
    return TRUE;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    BOOL status = TRUE;
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        std::cout << "Hack Injected !!!" << '\n';
        status = InitializeHack();
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return status;
}