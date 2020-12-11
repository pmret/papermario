#include "common.h"
#include "audio.h"

INCLUDE_ASM(void, "code_26840_len_20d0", func_8004B440, UnkAl6CC* arg0, u8 arg1, u8 arg2, UnkAl19E0* arg3, s32 arg4);

INCLUDE_ASM(void, "code_26840_len_20d0", func_8004B62C, UnkAl6CC* arg0);

void func_8004B698(UnkAl6CC *arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_C2); i++) {
        arg0->unk_C2[i].unk_00 = 0;
        arg0->unk_C2[i].unk_02 = 0;
        arg0->unk_C2[i].unk_04 = 0;
        arg0->unk_C2[i].unk_06 = 0;
        arg0->unk_C2[i].unk_08 = 0;
    }

    arg0->unk_165 = 0;
    arg0->unk_164 = 0;
    arg0->unk_163 = 0;
    arg0->unk_162 = 0;
}

void func_8004B6D8(UnkAl6CC *arg0, s32 arg1, s16 arg2, s16 arg3, u8 arg4) {
    u8 temp_v1 = arg0->unk_164;
    s32 temp_v0 = temp_v1 - (u8) arg0->unk_163;
    u32 temp_t0;

    if (temp_v0 < 0) {
        temp_v0 += 0x10;
    }

    if (temp_v0 < 0x10) {
        temp_t0 = temp_v1;

        arg0->unk_C2[temp_v1].unk_00 = arg1 & 0xBFFF;
        arg0->unk_C2[temp_v1].unk_02 = (((u32) arg1 >> 0x10) & 0x3FF);
        arg0->unk_C2[temp_v1].unk_04 = arg2;
        arg0->unk_C2[temp_v1].unk_06 = arg3;
        arg0->unk_C2[temp_v1].unk_08 = arg4;

        temp_t0++;
        if (temp_t0 >= 0x10) {
            temp_t0 = 0;
        }

        arg0->unk_164 = temp_t0;
    }
}

INCLUDE_ASM(void, "code_26840_len_20d0", func_8004B748, UnkAl6CC* arg0);

s32 func_8004B9E4(UnkAl6CC *arg0, s32 arg1) {
    s32 a1 = (u8) arg1;

    if (a1 != 0xF0) {
        if (a1 < 8) {
            if (arg0->unk_8C != a1) {
                arg0->unk_8C = a1;
                arg0->unk_00->unk_40[1].unk_00 = 6;
                arg0->unk_00->unk_40[1].unk_01 = 1;
                D_8007F1F8 = arg0->unk_64[a1];
            }
            arg0->unk_8D = arg0->unk_84[a1];
        } else {
            arg0->unk_8C = 0xFF;
            arg0->unk_8D = 0;
        }
    }
    return arg0->unk_8C;
}

void func_8004BA54(UnkAl6CC* arg0, s32 arg1) {
    if (arg1 == 0) {
        arg0->unk_C0 = 0;
    } else if (arg1 == 1) {
        arg0->unk_C0 = 1;
    }
}

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004BA74);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004C0E4);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004C268);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004C2A4);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004C300);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004C358);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004C3D4);

INCLUDE_ASM(s16, "code_26840_len_20d0", func_8004C444, UnkAl6CC* arg0);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004C578);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004C844);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004C884);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004CD94);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004CDF8);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004CE70);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004CEA4);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004CEC4);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004CF0C);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004CF3C);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D00C);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D038);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D050);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D07C);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D114);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D130);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D15C);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D180);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D1B4);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D23C);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D2B0);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D2E4);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D310);

void func_8004D31C(void) {
}

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D324);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D33C);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D354);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D36C);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D3A0);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D3F8);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D428);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D484);

INCLUDE_ASM(s32, "code_26840_len_20d0", func_8004D4BC);
