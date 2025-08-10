//
// Created by me on 2025-08-11.
//

#ifndef AC_FUNDEMENTALS_PG_MIT_H
#define AC_FUNDEMENTALS_PG_MIT_H

#include <ntddk.h>

namespace pg_mit
{
    constexpr size_t ExAllocatePoolWithTag_off = 0xB69010;
    constexpr size_t MaxDataSize_off = 0xFC5A48;
    BOOLEAN check();
};


#endif //AC_FUNDEMENTALS_PG_MIT_H