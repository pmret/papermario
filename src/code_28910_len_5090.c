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

void func_8004E158(UnkAlA9C* arg0, s32 arg1, s32 arg2, UnkAl19E0* arg3) {
    s16 i;

    arg0->unk_00 = arg3;
    func_8004E880(arg0, 0x2625A, 0x30);
    arg0->unk_48 = 0x8000;
    arg0->unk_B0 = 0x3CF0;
    arg0->unk_C0 = 0x7F000000;
    arg0->unk_22B = 1;
    arg0->unk_14 = 0;
    arg0->unk_18 = 0;
    arg0->unk_1C = 0;
    arg0->unk_20 = 0;
    arg0->unk_58 = 0;
    arg0->unk_5A = 0;
    arg0->unk_68 = 0;
    arg0->unk_6C = 0;
    arg0->unk_70 = 0;
    arg0->unk_BC = 0;
    arg0->unk_B8 = 0;
    arg0->unk_B4 = 0;
    arg0->unk_CC = 0;
    arg0->unk_C8 = 0;
    arg0->unk_C4 = 0;
    arg0->unk_20C = 0;
    arg0->unk_20E = 0;
    arg0->unk_220 = 0;
    arg0->unk_204 = 0;
    arg0->unk_232 = 0;
    arg0->unk_221 = 0;
    arg0->unk_234 = arg1;
    arg0->unk_235 = arg2;
    arg0->unk_168 = 0;
    arg0->unk_222 = 0;
    arg0->unk_223 = 0;
    arg0->unk_22A = 0;
    arg0->unk_22C = 0;
    arg0->unk_D0 = 1.0f;
    arg0->unk_22D = 0;
    arg0->unk_22F = 2;
    arg0->unk_230 = 3;
    arg0->unk_22E = 0;
    arg0->unk_231 = 4;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_25C); i++) {
        UnkAl60* temp = &arg0->unk_25C[i];

        temp->unk_18 = 0;
        temp->unk_24[1] = 0;
        temp->unk_46 = 0;
        temp->unk_48 = 0;
        temp->unk_4A = 0;
        temp->unk_4B = 0;
        temp->unk_44 = 0;
        temp->unk_58 = 0;
        temp->unk_49 = 0x7F;
        temp->unk_4C = 0;

        if (i < ARRAY_COUNT(arg0->unk_238)) {
            arg0->unk_238[i] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(arg0->unk_85C); i++) {
        UnkAl24* temp = &arg0->unk_85C[i];

        temp->unk_08 = 0;
        temp->unk_0A = 0;
        temp->unk_0C = 0;
        temp->unk_14 = 0;
        temp->unk_16 = 0;
        temp->unk_17 = 0;
    }

    func_80053AEC(&arg0->unk_2C, 0x7FFF);
    func_80055110(arg0);
}


INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E344);

void func_8004E3A4(UnkAlA9C* arg0) {
    arg0->unk_2C.unk_0A--;

    if (arg0->unk_2C.unk_0A != 0) {
        arg0->unk_2C.unk_00.s32 += arg0->unk_2C.unk_04;
    } else {
        arg0->unk_2C.unk_00.s32 = arg0->unk_2C.unk_08 << 16;

        if (arg0->unk_2C.unk_0C != NULL) {
            arg0->unk_2C.unk_0C();
        }

        if (arg0->unk_20 != 0) {
            func_8004DC80(arg0->unk_20);
        } else if (arg0->unk_2C.unk_00.s32 == 0) {
            func_8004DAA8(arg0);
        }
    }
    func_8004E444(arg0);
}

void func_8004E444(UnkAlA9C *arg0) {
    u16 mult = (arg0->unk_2C.unk_00.u16 * arg0->unk_2C.unk_10.u16) >> 15;
    s32 i;

    for (i = 0; i < 4; i++) {
        s8 temp = arg0->unk_4C[i];

        if (temp < 0) {
            return;
        }
        func_80053A98(temp, mult, arg0->unk_48);
    }
}

INCLUDE_ASM(s16, "code_28910_len_5090", func_8004E4B8, UnkAlA9C* arg0);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E5D8);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E844);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E880);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004E904);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EA34);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EAD4);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EC04);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8004EC68);

void func_8004FBBC(UnkAlA9C* arg0, UnkAl60* arg1) {
    u32 unk_D4 = arg0->unk_D4.u16;
    s32 temp_v0;

    arg0->unk_208 = unk_D4;
    temp_v0 = func_8004FC08(arg0, unk_D4);
    arg0->unk_B0 = temp_v0;
    arg0->unk_08 = temp_v0 * 10;
    arg0->unk_BC = 0;
    arg0->unk_B8 = 0;
    arg0->unk_B4 = 0;
}

s32 func_8004FC08(UnkAlA9C* arg0, u32 arg1) {
    u32 unk_20A = arg0->unk_20A;
    u32 ret = arg1;

    ret *= arg0->unk_D0;

    if (unk_20A < ret) {
        ret = unk_20A;
    } else if (ret == 0) {
        ret = 1;
    }

    return ret * 100;
}

void func_8004FCB4(UnkAlA9C* arg0, UnkAl60* arg1) {
    s32 unk_D4 = arg0->unk_D4.u8[0] & 0x7F;

    if (unk_D4 != 0) {
        unk_D4 = unk_D4 << 0x18;
    }

    arg0->unk_C0 = unk_D4;
    arg0->unk_CC = 0;
    arg0->unk_C8 = 0;
    arg0->unk_C4 = 0;
    arg0->unk_21A = 1;
    arg1->unk_41 = 1;
}

void func_8004FCE4(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg0->unk_20C = (s8)arg0->unk_D4.u8[0] * 100;
}

void func_8004FD04(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg0->unk_00->unk_40[arg0->unk_235].unk_00 = arg0->unk_D4.u8[0];
    arg0->unk_00->unk_40[arg0->unk_235].unk_01 = 1;
}

void func_8004FD38(UnkAlA9C* arg0, UnkAl60* arg1) {
    u8 unk_D4 = arg0->unk_D4.u8[0];
    u32 temp_v1 = arg0->unk_4C[unk_D4];

    if ((unk_D4 < 4) && (temp_v1 < 0x80)) {
        if (arg0->unk_00->unk_40[temp_v1].unk_00 != arg0->unk_D4.u8[1]) {
            arg0->unk_00->unk_40[temp_v1].unk_00 = arg0->unk_D4.u8[1];
            arg0->unk_00->unk_40[temp_v1].unk_01 = 1;
        }
        arg0->unk_224[unk_D4] = arg0->unk_D4.u8[1];
    }
}

void func_8004FD94(UnkAlA9C* arg0, UnkAl60* arg1) {
    s32 unk_D4 = arg0->unk_D4.u16;
    s32 temp_a0 = func_8004FC08(arg0, arg0->unk_D6.u16);
    s32 temp_v0;

    if (unk_D4 <= 0) {
        unk_D4 = 1;
    }
    temp_v0 = (temp_a0 - arg0->unk_B0) / unk_D4;

    arg0->unk_BC = unk_D4;
    arg0->unk_B8 = temp_a0;
    arg0->unk_B4 = temp_v0;
}

void func_8004FE10(UnkAlA9C* arg0, UnkAl60* arg1) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a1 = arg0->unk_D4.u16;
    temp_a2 = arg0->unk_D6.u8[0] & 0x7F;

    if (temp_a2 != 0) {
        temp_a2 = temp_a2 << 0x18;
    }

    if (temp_a1 <= 0) {
        temp_a1 = 1;
    }

    arg0->unk_CC = temp_a1;
    arg0->unk_C8 = temp_a2;
    arg0->unk_C4 = (temp_a2 - arg0->unk_C0) / temp_a1;
}

// Not sure about types
#ifdef NON_MATCHING
void func_8004FE6C(UnkAlA9C* arg0, UnkAl60* arg1) {
    u8 temp_v1 = arg0->unk_D4.u16;

    arg1->unk_44 = temp_v1;
    arg1->unk_0C = func_80053BE8(arg0->unk_00, arg0->unk_D4.u8[0], temp_v1, &arg1->unk_10);
}
#else
INCLUDE_ASM(void, "code_28910_len_5090", func_8004FE6C, UnkAlA9C* arg0, UnkAl60* arg1);
#endif

void func_8004FEB0(UnkAlA9C* arg0, UnkAl60* arg1) {
    u32 unk_D4 = arg0->unk_D4.u8[0] & 0x7F;

    if (unk_D4 != 0) {
        unk_D4 = unk_D4 << 0x18;
    }

    arg1->unk_18 = unk_D4;
    arg1->unk_41 = 1;
}

// Type shenanigans
#ifdef NON_MATCHING
void func_8004FED0(UnkAlA9C* arg0, UnkAl60* arg1) {
    s32 temp_a2 = arg0->unk_D4.u16;
    s32 temp_a0 = arg0->unk_D6.u8[0] & 0x7F;
    s32 phi_a2;

    if (temp_a0 != 0) {
        temp_a0 = temp_a0 << 0x18;
    }

    if (temp_a0 != arg1->unk_18) {


        if (temp_a2 <= 0) {
            phi_a2 = 1;
        } else {
            phi_a2 = temp_a2;
        }
        arg1->unk_24[0] = phi_a2;
        arg1->unk_20 = temp_a0;
        arg1->unk_1C = (temp_a0 - arg1->unk_18) / phi_a2;
    }
}
#else
INCLUDE_ASM(void, "code_28910_len_5090", func_8004FED0, UnkAlA9C* arg0, UnkAl60* arg1);
#endif

void func_8004FF3C(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_4A = arg0->unk_D4.u8[0] & 0x7F;
    arg1->unk_57 = 0;
    arg1->unk_42 = 1;
}

void func_8004FF58(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_4B = arg0->unk_D4.u8[0] & 0x7F;
    arg1->unk_43 = 1;
}

void func_8004FF70(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_49 = arg0->unk_D4.u8[0] & 0x7F;
    arg1->unk_41 = 1;
}

void func_8004FF88(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_46 = (s8)arg0->unk_D4.u8[0] * 100;
}

void func_8004FFA8(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_48 = arg0->unk_D4.u8[0];
}

void func_8004FFB4(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_38 = arg0->unk_D4.u16;
    arg1->unk_40 = 1;
}

void func_8004FFC8(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_3A = arg0->unk_D4.u8[0];
    arg1->unk_55 = arg0->unk_D4.u8[1];
    arg1->unk_56 = arg0->unk_D6.u8[0];
}

void func_8004FFE4(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_55 = arg0->unk_D4.u8[0];
}

void func_8004FFF0(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_56 = arg0->unk_D4.u8[0];
}

void func_8004FFFC(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_56 = 0;
}

void func_80050004(UnkAlA9C* arg0, UnkAl60* arg1) {
    arg1->unk_4A = arg0->unk_D4.u8[0] & 0x7F;
    arg1->unk_57 = arg0->unk_D4.u8[1] & 0x7F;
}

INCLUDE_ASM(void, "code_28910_len_5090", func_80050020, UnkAlA9C* arg0, UnkAl60* arg1);

void func_80050128(UnkAlA9C* arg0, UnkAl60* arg1) {
    u8 temp_v0 = arg0->unk_D4.u8[0];
    u8 temp_v1 = arg0->unk_4C[temp_v0];

    if ((temp_v0 < 4) && ((s8)temp_v1 >= 0)) {
        arg1->unk_5B = temp_v1;
    } else {
        arg1->unk_5B = arg0->unk_235;
    }
}

// unk_D4 type shenanigans
#ifdef NON_MATCHING
void func_8005015C(UnkAlA9C* arg0, UnkAl60* arg1) {
    func_800560BC(arg0->unk_234, arg1->unk_5C, arg0->unk_D4.u16 >> 8);
}
#else
INCLUDE_ASM(void, "code_28910_len_5090", func_8005015C, UnkAlA9C* arg0, UnkAl60* arg1);
#endif

void func_80050184(UnkAlA9C* arg0, UnkAl60* arg1) {
    s32 temp = arg0->unk_D4.u16 + arg0->unk_64;

    arg1->unk_3E = arg0->unk_D6.u8[0];
    arg1->unk_04 = arg1->unk_00;
    arg1->unk_00 = temp;
}

INCLUDE_ASM(void, "code_28910_len_5090", func_800501A8, UnkAlA9C* arg0, UnkAl60* arg1);

INCLUDE_ASM(void, "code_28910_len_5090", func_800502F0, UnkAlA9C* arg0, UnkAl60* arg1);

void func_80050560(UnkAlA9C* arg0, UnkAl60* arg1) {
}

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050568);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800505E4);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050654);

INCLUDE_ASM(s32, "code_28910_len_5090", func_8005068C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_800506C8, s32 arg0, s32 arg1);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050770);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050818);

void func_8005083C(UnkAlA9C* arg0, s32 arg1, s16 arg2, s8 arg3) {
    UnkAl60* temp_a1 = &arg0->unk_25C[arg1];

    if (temp_a1->unk_00 != 0) {
        arg0->unk_D4.u16 = arg2;
        arg0->unk_D6.u8[0] = arg3;
        func_8004FED0(arg0, temp_a1);
    }
}

INCLUDE_ASM(s32, "code_28910_len_5090", func_8005087C);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050888);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050900);

INCLUDE_ASM(s32, "code_28910_len_5090", func_80050970);
