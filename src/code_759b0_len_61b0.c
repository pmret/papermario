#include "common.h"

PlayerStatus* gPlayerStatusPtr = &gPlayerStatus; // maybe wPlayerStatus

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DC500);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DC778);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DCB7C, s32 arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DCE70);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD04C);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD228);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD44C);

void func_800DD5B4(f32* arg0, f32* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp = (arg2 * arg4) + (arg3 * arg5);

    *arg0 = (arg2 - (temp * arg4)) * 0.5f;
    *arg1 = (arg3 - (temp * arg5)) * 0.5f;
}

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD618);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DD8FC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DDAE4);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DDC44, s32 arg0, f32* arg1, f32* arg2, f32* arg3, f32 arg4, f32 arg5,
            f32 arg6, f32 arg7);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DDCEC);

INCLUDE_ASM(s32, "code_759b0_len_61b0", func_800DDD94);
