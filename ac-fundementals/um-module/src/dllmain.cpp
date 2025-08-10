#include <windows.h>
#include <iostream>
#include "module/veh_detection.hpp"
#include "idle.hpp"

BOOL InitializeUmModules() {
    
    if (!wsac::idle::StartIdleMonitor())
        return FALSE;
    
    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    BOOL status = TRUE;
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        status = InitializeUmModules();
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
