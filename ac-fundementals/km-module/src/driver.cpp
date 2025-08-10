//
// Created by me on 2025-08-10.
//

#include <ntddk.h>

#include "log.h"
#include "module/ob_reg.h"
#include "module/nmi.h"
#include "module/pg_mit.h"

void DriverUnload(_In_ const PDRIVER_OBJECT DriverObject)
{
    UNREFERENCED_PARAMETER(DriverObject);
    ob_reg::uninit();
    ac_log("driver successfully unloaded");
}

extern "C"
NTSTATUS DriverEntry(_In_ const PDRIVER_OBJECT DriverObject, _In_ const PUNICODE_STRING RegistryPath)
{
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->DriverUnload = DriverUnload;

    if (!NT_SUCCESS(ob_reg::init()))
    {
        ac_log("failed to initialize object callbacks. maybe using '/integritycheck' compile option?");
    }

    if (!NT_SUCCESS(nmi::launch()))
    {
        ac_log("failed to launch nmi");
    }

    if (pg_mit::check())
    {
        ac_err("detected !!!!!!!!!!!!");
    }

    ac_log("driver successfully loaded");
    return STATUS_SUCCESS;
}
