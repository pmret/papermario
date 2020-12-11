#include "audio.h"

INCLUDE_ASM(void, "code_28910_len_5090", func_8004D510, UnkAlA9C* arg0);

// Return values are being pushed into v0 in the wrong place
// May depend on data decomp
#ifdef NON_MATCHING
UnkAlA9C* func_8004D794(s32 arg0) {
    UnkAl19E0* temp_v1 = D_8009A664->unk_00;

    if (arg0 == temp_v1->unk_5C[2]) {
        return D_8009A664;
    }
    if (arg0 == temp_v1->unk_60[2]) {
        return D_8009A5FC;
    }
    return NULL;
}
#else
INCLUDE_ASM(UnkAlA9C*, "code_28910_len_5090", func_8004D794, s32 arg0);
#endif

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004D7E0);

s32 func_8004DA0C(UNK_TYPE arg0) {
    s32 ret = 0;

    if (arg0 != 0) {
        UnkAlA9C* unknown;

        do {
            unknown = func_8004D794(arg0);
        } while (0);

        do {
            if (unknown == NULL) {
                ret = 2;
            } else if (arg0 == unknown->unk_1C) {
                func_8004DAA8(unknown);
                ret = 0;
            }
        } while (0);
    } else {
        ret = 3;
    }

    return ret;
}

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DA74);

void func_8004DAA8(UnkAlA9C* arg0) {
    if (arg0->unk_221 != 0) {
        arg0->unk_221 = 4;
        arg0->unk_10 = 1;
        arg0->unk_08 = 1;
        func_80053A18(&arg0->unk_2C);
    }
}

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DAE0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DB28);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DB4C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DC80);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DCB8);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004DE2C);

INCLUDE_ASM(void, "code_28910_len_5090", func_8004DFD4, UnkAl19E0* arg0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E0F4);

INCLUDE_ASM(void, "code_28910_len_5090", func_8004E158, UnkAlA9C* arg0, s32 arg1, s32 arg2, UnkAl19E0* arg3);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E344);

void func_8004E3A4(UnkAlA9C *arg0) {
    arg0->unk_2C.unk_0A--;

    if (arg0->unk_2C.unk_0A != 0) {
        arg0->unk_2C.unk_00 += arg0->unk_2C.unk_04;
    } else {
        arg0->unk_2C.unk_00 = arg0->unk_2C.unk_08 << 0x10;

        if (arg0->unk_2C.unk_0C != NULL) {
            arg0->unk_2C.unk_0C();
        }

        if (arg0->unk_20 != 0) {
            func_8004DC80(arg0->unk_20);
        } else if (arg0->unk_2C.unk_00 == 0) {
            func_8004DAA8(arg0);
        }
    }
    func_8004E444(arg0);
}

INCLUDE_ASM(void, "code_28910_len_5090", func_8004E444, UnkAlA9C* arg0);

INCLUDE_ASM(s16, "code_28910_len_5090", func_8004E4B8, UnkAlA9C* arg0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E5D8);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E844);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E880);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E904);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EA34);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EAD4);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EC04);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EC68);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FBBC);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FC08);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FCB4);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FCE4);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FD04);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FD38);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FD94);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FE10);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FE6C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FEB0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FED0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FF3C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FF58);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FF70);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FF88);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FFA8);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FFB4);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FFC8);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FFE4);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FFF0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004FFFC);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050004);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050020);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050128);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8005015C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050184);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800501A8);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800502F0);

void func_80050560(void) {
}

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050568);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800505E4);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050654);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8005068C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800506C8);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050770);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050818);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8005083C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8005087C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050888);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050900);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050970);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050B90);

s32 func_80050C30(u32 arg0) {
    if (D_8009A628->unk_20 <= arg0) {
        return 3;
    } else {
        return 0;
    }
}

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050C54);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050C64);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050CA0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050D50);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050E18);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050E84);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050EF0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050F64);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050FD0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80051050);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800510A4);

INCLUDE_ASM(void, "code_28910_len_5090", func_800511BC, UnkAl834* arg0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80051334);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80051434);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800521D0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800521E8);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800522A8);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8005232C);
