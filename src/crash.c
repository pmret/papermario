#include "common.h"

extern struct {
    /* 0x000 */ char unk_000[0x9CC];
    /* 0x9CC */ s32 unk_9CC;
    /* 0x9D0 */ s16 unk_9D0;
    /* 0x9D2 */ s16 unk_9D2;
} D_8009BB30; // size unknown

s32 D_80077210[] = {
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF29FFFF,
    0xFF2BFFFF, 0x2526FF2A, 0xFF272CFF, 0x00010203, 0x04050607, 0x080924FF, 0xFFFFFF28, 0xFF0A0B0C, 0x0D0E0F10,
    0x11121314, 0x15161718, 0x191A1B1C, 0x1D1E1F20, 0x212223FF, 0xFFFFFFFF, 0xFF0A0B0C, 0x0D0E0F10, 0x11121314,
    0x15161718, 0x191A1B1C, 0x1D1E1F20, 0x212223FF, 0xFFFFFFFF,
};

s32 D_80077290[] = {
    0x70871C30, 0x8988A250, 0x88808290, 0x88831C90, 0x888402F8, 0x88882210, 0x71CF9C10, 0xF9CF9C70, 0x8228A288,
    0xF200A288, 0x0BC11C78, 0x0A222208, 0x8A222288, 0x71C21C70, 0x23C738F8, 0x5228A480, 0x8A282280, 0x8BC822F0,
    0xFA282280, 0x8A28A480, 0x8BC738F8, 0xF9C89C08, 0x82288808, 0x82088808, 0xF2EF8808, 0x82288888, 0x82288888,
    0x81C89C70, 0x8A08A270, 0x920DA288, 0xA20AB288, 0xC20AAA88, 0xA208A688, 0x9208A288, 0x8BE8A270, 0xF1CF1CF8,
    0x8A28A220, 0x8A28A020, 0xF22F1C20, 0x82AA0220, 0x82492220, 0x81A89C20, 0x8A28A288, 0x8A28A288, 0x8A289488,
    0x8A2A8850, 0x894A9420, 0x894AA220, 0x70852220, 0xF8011000, 0x08020800, 0x10840400, 0x20040470, 0x40840400,
    0x80020800, 0xF8011000, 0x70800000, 0x88822200, 0x08820400, 0x108F8800, 0x20821000, 0x00022200, 0x20800020,
    0x00000000,
};

char* D_80077390[18] = {
    "Interrupt",
    "TLB modification",
    "TLB exception on load",
    "TLB exception on store",
    "Address error on load",
    "Address error on store",
    "Bus error on inst.",
    "Bus error on data",
    "System call exception",
    "Breakpoint exception",
    "Reserved instruction",
    "Coprocessor unusable",
    "Arithmetic overflow",
    "Trap exception",
    "Virtual coherency on inst.",
    "Floating point exception",
    "Watchpoint exception",
    "Virtual coherency on data",
};

char* D_800773D8[6] = {
    "Unimplemented operation",
    "Invalid operation",
    "Division by zero",
    "Overflow",
    "Underflow",
    "Inexact operation",
};

INCLUDE_ASM(s32, "crash", crash_delay_msec);

INCLUDE_ASM(s32, "crash", func_8002BFB0);

INCLUDE_ASM(s32, "crash", func_8002C054);

INCLUDE_ASM(s32, "crash", func_8002C1D4);

INCLUDE_ASM(s32, "crash", crash_printf_msg);

INCLUDE_ASM(s32, "crash", crash_print_fpr);

INCLUDE_ASM(s32, "crash", func_8002C324);

INCLUDE_ASM(s32, "crash", crash_show_handler);

INCLUDE_ASM(s32, "crash", func_8002C7B0);

INCLUDE_ASM(s32, "crash", crash_monitor_thread);

void func_8002C890(s32 arg0, s16 arg1, s16 arg2) {
    D_8009BB30.unk_9CC = arg0 | 0xA0000000;
    D_8009BB30.unk_9D0 = arg1;
    D_8009BB30.unk_9D2 = arg2;
}

INCLUDE_ASM(s32, "crash", crash_create_monitor);

INCLUDE_ASM(s32, "crash", func_8002C94C);
