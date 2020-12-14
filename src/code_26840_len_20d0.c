#include "common.h"
#include "audio.h"

void func_8004B440(UnkAl6CC *arg0, u8 arg1, u8 arg2, UnkAl19E0 *arg3, u8 arg4) {
    u32 i;
    s32 c = 0x6A25E;

    arg0->unk_00 = arg3;
    arg0->unk_34 = 0x4C4B4;
    arg0->unk_38 = arg0->unk_3C = c;
    arg0->unk_BC = arg1;
    arg0->unk_BE = arg2;

    if (arg4 > 0x10) {
        arg0->unk_BD = 0x10;
    } else {
        arg0->unk_BD = arg4;
    }

    arg0->unk_5C = 0x8000;
    arg0->unk_B8 = 0x8000;
    arg0->unk_30 = 0;
    arg0->unk_60 = 0;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_16C); i++) {
        UnkAlAC* sub = &arg0->unk_16C[i];

        sub->unk_00 = 0;
        sub->unk_5C = 0;
        sub->unk_8E = 0;
        sub->unk_90 = 0;
        sub->unk_92 = 0;
        sub->unk_94 = 0;
        sub->unk_9B = 0;
        sub->unk_9C = 0;
        sub->unk_9D = 0;
        sub->unk_9E = 0;
        sub->unk_9F = 0;
        sub->unk_99 = 0;
        sub->unk_78 = 0;
        sub->unk_79 = 0;
        sub->unk_7A = 0;
        sub->unk_7B = 0x40;
        sub->unk_7C = 0;
        sub->unk_7D = 0xB0;
        sub->unk_7E = 0;
        sub->unk_7F = 0;
    }

    for (i = 0; i < 4; i++) {
        arg0->unk_90[i] = 0;
    }

    for (i = 0; i < 4; i++) {
        arg0->unk_A0[i].x = 0;
    }

    arg0->unk_168 = 0;
    func_8004BA54(arg0, 0);
    func_8004B698(arg0);
    func_80053974(&arg0->unk_40, 0, 0x7FFF, 0x7FFF);
    func_80053A98(arg0->unk_BE, arg0->unk_40.unk_00.u16, arg0->unk_5C);
    arg0->unk_8C = 0xFF;

    arg0->unk_64[0] = &D_80078290;
    arg0->unk_64[1] = &D_800782F8;
    arg0->unk_64[2] = &D_80078320;
    arg0->unk_64[3] = &D_80078348;
    arg0->unk_64[4] = &D_80078348;
    arg0->unk_64[5] = &D_80078348;
    arg0->unk_64[6] = &D_80078348;
    arg0->unk_64[7] = &D_80078348;

    arg0->unk_84[0] = 0x10;
    arg0->unk_84[1] = 0x20;
    arg0->unk_84[2] = 0x20;
    arg0->unk_84[3] = 0x20;
    arg0->unk_84[4] = 0x20;
    arg0->unk_84[5] = 0x30;
    arg0->unk_84[6] = 0x40;
    arg0->unk_84[7] = 0x50;

    func_8004B9E4(arg0, 0);
}

INCLUDE_ASM(void, "code_26840_len_20d0", func_8004B62C, UnkAl6CC* arg0);

void func_8004B698(UnkAl6CC* arg0) {
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

void func_8004B6D8(UnkAl6CC* arg0, s32 arg1, s16 arg2, s16 arg3, u8 arg4) {
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

s32 func_8004B9E4(UnkAl6CC* arg0, s32 arg1) {
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
