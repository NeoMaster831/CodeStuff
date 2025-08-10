//
// Created by me on 2025-08-10.
//

#ifndef AC_FUNDEMENTALS_LOG_H
#define AC_FUNDEMENTALS_LOG_H

#include <ntddk.h>

#ifdef DBG
#define ac_log(fmt, ...) DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "[>] " fmt "\n", __VA_ARGS__)
#define ac_err(fmt, ...) DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "[!] " fmt "\n", __VA_ARGS__)
#else
#define ac_log(fmt, ...)
#define ac_err(fmt, ...)
#endif

#endif //AC_FUNDEMENTALS_LOG_H