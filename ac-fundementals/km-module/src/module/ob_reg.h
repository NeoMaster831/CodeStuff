//
// Created by me on 2025-08-10.
//

#ifndef AC_FUNDEMENTALS_OB_REG_H
#define AC_FUNDEMENTALS_OB_REG_H

#include <ntddk.h>

namespace ob_reg
{
    NTSTATUS init();
    void uninit();
};


#endif //AC_FUNDEMENTALS_OB_REG_H