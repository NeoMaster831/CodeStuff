#include "veh_detection.hpp"
#include <iostream>
#include <psapi.h>
#include <vector>

// Windows 11, 24H2
// ntdll hash (sha256) A9AA6C80989ABA7A015BAB9781EB4FC17E5592E9D762CF1F140E13ADA2FCD8A9

typedef struct _VECTOR_HANDLER_ENTRY {
    LIST_ENTRY ListEntry;
    PLONG64 pRefCount; // ProcessHeap allocated, initialized with 1
    DWORD unk_0; // always 0
    DWORD pad_0;
    PVOID EncodedHandler;
} VECTOR_HANDLER_ENTRY, * PVECTOR_HANDLER_ENTRY;

BOOL IsUsingVEH() {
    void* ppeb = (void*)__readgsqword(0x60);
    DWORD CrossProcessFlags = *((char*)ppeb + 0x50);
    if (!(CrossProcessFlags & (1 << 2))) {
        return FALSE;
    }
    return TRUE;
}

namespace wsac::module::vehd {

    BOOL PerformCheck() {

        /*
        if (!IsUsingVEH()) {
            std::cout << "[VEHD] process is not using veh" << '\n';
            return FALSE;
        }
        */
       
        char* pLdrpVectorHandlerList = (char*)GetModuleHandleA("ntdll.dll") + 0x1EB568;
        auto vhl = (PVECTOR_HANDLER_ENTRY)(*(uintptr_t*)pLdrpVectorHandlerList);
        //std::cout << std::hex << (uintptr_t)vhl->EncodedHandler << std::dec << '\n';

        // do stuff..
        return FALSE;
    }

}