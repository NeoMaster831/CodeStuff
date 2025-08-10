//
// Created by me on 2025-08-10.
//

#include "nmi.h"
#include <intrin.h>

#include "log.h"

extern "C" PVOID ExAllocatePool2(POOL_FLAGS, SIZE_T, ULONG);
extern "C" VOID KeInitializeAffinityEx(PKAFFINITY_EX);
extern "C" VOID KeAddProcessorAffinityEx(PKAFFINITY_EX, INT);
extern "C" VOID HalSendNMI(PKAFFINITY_EX);

BOOLEAN nmi_callback(PVOID context, BOOLEAN handled)
{
    UNREFERENCED_PARAMETER(handled);

    auto* ctx = static_cast<nmi_context*>(context);
    ULONG proc_num = KeGetCurrentProcessorNumber();
    UINT64 kpcr = 0;
    TASK_STATE_SEGMENT_64* tss = nullptr;
    machine_frame* pmf = nullptr;

    kpcr = __readmsr(IA32_GS_BASE);
    tss = *reinterpret_cast<TASK_STATE_SEGMENT_64**>(kpcr + KPCR_TSS_BASE_OFFSET);
    pmf = reinterpret_cast<machine_frame*>(tss->Ist3 - sizeof(machine_frame));

    if (pmf->rip <= WINDOWS_USERMODE_MAX_ADDRESS)
        ctx[proc_num].user_thread = TRUE;

    ctx[proc_num].interrupted_rip = pmf->rip;
    ctx[proc_num].interrupted_rsp = pmf->rsp;
    ctx[proc_num].callback_count += 1;

    ac_log("core number: %lx, interrupted rip: %llx, interrupted rsp: %llx", proc_num, pmf->rip, pmf->rsp);

    return TRUE;
}

namespace nmi
{
    nmi_context g_nmi_context[24];

    NTSTATUS launch()
    {
        auto proc_affinity_pool = static_cast<PKAFFINITY_EX>(ExAllocatePool2(
            POOL_FLAG_NON_PAGED, sizeof(kaffinity_ex), 0x50505050));

        if (!proc_affinity_pool)
            return STATUS_INSUFFICIENT_RESOURCES;

        PVOID registration_handle = KeRegisterNmiCallback(nmi_callback, g_nmi_context);

        if (!registration_handle)
        {
            ExFreePoolWithTag(proc_affinity_pool, 0x50505050);
            return STATUS_INSUFFICIENT_RESOURCES;
        }

        LARGE_INTEGER delay = { 0 };
        delay.QuadPart = -100 * 10000;

        for (ULONG core = 0; core < KeQueryActiveProcessorCountEx(0); core++)
        {
            KeInitializeAffinityEx(proc_affinity_pool);
            KeAddProcessorAffinityEx(proc_affinity_pool, core);

            ac_log("sending nmi");
            HalSendNMI(proc_affinity_pool);

            KeDelayExecutionThread(KernelMode, FALSE, &delay);
        }

        KeDeregisterNmiCallback(registration_handle);
        ExFreePoolWithTag(proc_affinity_pool, 0x50505050);

        return STATUS_SUCCESS;

    }
}
