//
// Created by me on 2025-08-11.
//

#include "pg_mit.h"

namespace pg_mit
{
    BOOLEAN check()
    {
        uintptr_t nt_kernel = (uintptr_t)ExAllocatePoolWithTag - ExAllocatePoolWithTag_off;
        PVOID* p_max_data_size = (PVOID*)(nt_kernel + MaxDataSize_off);
        if (*p_max_data_size == 0)
            return TRUE;
        return FALSE;
    }
}