#include "common.h"

extern struct {
    /* 0x000 */ char unk_000[0x9CC];
    /* 0x9CC */ s32 unk_9CC;
    /* 0x9D0 */ s16 unk_9D0;
    /* 0x9D2 */ s16 unk_9D2;
} D_8009BB30; // size unknown

INCLUDE_ASM(s32, "crash", crash_delay_msec);

INCLUDE_ASM(s32, "crash", func_8002BFB0);

INCLUDE_ASM(s32, "crash", func_8002C054);

INCLUDE_ASM(s32, "crash", func_8002C1D4);

INCLUDE_ASM(s32, "crash", crash_printf_string);

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
