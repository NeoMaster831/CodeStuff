//
// Created by me on 2025-08-10.
//

#ifndef AC_FUNDEMENTALS_NMI_H
#define AC_FUNDEMENTALS_NMI_H

#include <ntddk.h>

#define IA32_GS_BASE 0xC0000101
#define KPCR_TSS_BASE_OFFSET 0x8
#define TSS_IST_OFFSET 0x1c
#define WINDOWS_USERMODE_MAX_ADDRESS 0x00007FFFFFFFFFFF

struct machine_frame
{
    UINT64 rip;
    UINT64 cs;
    UINT64 eflags;
    UINT64 rsp;
    UINT64 ss;
};

struct kaffinity_ex
{
    USHORT Count;
    USHORT Size;
    ULONG Reserved;
    ULONGLONG Bitmap[20];

};

struct nmi_context
{
    UINT64 interrupted_rip;
    UINT64 interrupted_rsp;
    UINT32 callback_count;
    BOOLEAN user_thread;
};

#pragma pack(push, 1)
typedef struct
{
    /**
     * Reserved bits. Set to 0.
     */
    UINT32 Reserved0;

    /**
     * Stack pointer for privilege level 0.
     */
    UINT64 Rsp0;

    /**
     * Stack pointer for privilege level 1.
     */
    UINT64 Rsp1;

    /**
     * Stack pointer for privilege level 2.
     */
    UINT64 Rsp2;

    /**
     * Reserved bits. Set to 0.
     */
    UINT64 Reserved1;

    /**
     * Interrupt stack table pointer (1).
     */
    UINT64 Ist1;

    /**
     * Interrupt stack table pointer (2).
     */
    UINT64 Ist2;

    /**
     * Interrupt stack table pointer (3).
     */
    UINT64 Ist3;

    /**
     * Interrupt stack table pointer (4).
     */
    UINT64 Ist4;

    /**
     * Interrupt stack table pointer (5).
     */
    UINT64 Ist5;

    /**
     * Interrupt stack table pointer (6).
     */
    UINT64 Ist6;

    /**
     * Interrupt stack table pointer (7).
     */
    UINT64 Ist7;

    /**
     * Reserved bits. Set to 0.
     */
    UINT64 Reserved2;

    /**
     * Reserved bits. Set to 0.
     */
    UINT16 Reserved3;

    /**
     * The 16-bit offset to the I/O permission bit map from the 64-bit TSS base.
     */
    UINT16 IoMapBase;
} TASK_STATE_SEGMENT_64;
#pragma pack(pop)

namespace nmi
{
    extern nmi_context g_nmi_context[24];
    NTSTATUS launch();
};



#endif //AC_FUNDEMENTALS_NMI_H