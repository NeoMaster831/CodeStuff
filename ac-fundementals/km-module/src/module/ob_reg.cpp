//
// Created by me on 2025-08-10.
//

#include "ob_reg.h"
#include "log.h"

extern "C" POBJECT_TYPE* PsProcessType;
extern "C" CHAR* PsGetProcessImageFileName(PEPROCESS);

static PVOID g_ob_reg_handle = nullptr;

static bool equal_ascii_ignore_case(const char* a, const char* b)
{
    if (!a || !b)
        return false;
    while (*a && *b)
    {
        unsigned char ca = static_cast<unsigned char>(*a);
        unsigned char cb = static_cast<unsigned char>(*b);
        if (ca >= 'A' && ca <= 'Z')
            ca = static_cast<unsigned char>(ca + ('a' - 'A'));
        if (cb >= 'A' && cb <= 'Z')
            cb = static_cast<unsigned char>(cb + ('a' - 'A'));
        if (ca != cb)
            return false;
        ++a;
        ++b;
    }
    return *a == 0 && *b == 0;
}

static OB_PREOP_CALLBACK_STATUS NTAPI pre_operation_callback(
    PVOID /*registration_context*/,
    const POB_PRE_OPERATION_INFORMATION info)
{

    if (info->ObjectType != *PsProcessType)
        return OB_PREOP_SUCCESS;

    const auto target_process = static_cast<PEPROCESS>(info->Object);

    if (const char* image_name = PsGetProcessImageFileName(target_process); image_name && equal_ascii_ignore_case(
        image_name, "test_app.exe"))
    {
        const ULONG opener = HandleToULong(PsGetCurrentProcessId());
        const ULONG target = HandleToULong(PsGetProcessId(target_process));

        ac_log("process handle op=%lu, opener=%lu, target=%lu",
               static_cast<ULONG>(info->Operation),
               opener,
               target);
    }

    return OB_PREOP_SUCCESS;
}

namespace ob_reg
{
    NTSTATUS init()
    {
        if (g_ob_reg_handle)
            return STATUS_SUCCESS;

        OB_OPERATION_REGISTRATION reg{};
        reg.ObjectType = PsProcessType;
        reg.Operations = OB_OPERATION_HANDLE_CREATE | OB_OPERATION_HANDLE_DUPLICATE;
        reg.PreOperation = pre_operation_callback;
        reg.PostOperation = nullptr;

        OB_CALLBACK_REGISTRATION cb_reg{};
        cb_reg.Version = OB_FLT_REGISTRATION_VERSION;
        cb_reg.RegistrationContext = nullptr;
        cb_reg.OperationRegistrationCount = 1;
        cb_reg.OperationRegistration = &reg;
        RtlInitUnicodeString(&cb_reg.Altitude, L"13370");

        if (const NTSTATUS status = ObRegisterCallbacks(&cb_reg, &g_ob_reg_handle); !NT_SUCCESS(status))
        {
            ac_log("failed to register callbacks: %x", status);
            return status;
        }

        ac_log("registered callbacks");
        return STATUS_SUCCESS;
    }

    void uninit()
    {
        if (g_ob_reg_handle)
        {
            ObUnRegisterCallbacks(g_ob_reg_handle);
            g_ob_reg_handle = nullptr;
            ac_log("unregistered callbacks");
        }
    }
}
