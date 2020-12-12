#include "common.h"
#include "audio.h"

s32* D_80078DB0 = 0;
u16 D_80078DB4 = 0;
u16 D_80078DB6 = 0;
s32 D_80078DB8[] = { 0x025E0350, 0x04640554, 0x00000000, };
s32 D_80078DC4[] = { 0x0264036E, 0x045A0000, };
s32 D_80078DCC[] = { 0x025F0000, };
s32 D_80078DD0[] = { 0x0546065A, 0x075A0864, 0x00000000, };
s32 D_80078DDC[] = { 0x05000600, 0x07000800, 0x09000A00, 0x0B000C00, 0x0D000E00, 0x0F001000, 0x00000000, };
s32 D_80078DF8[] = { 0x05640666, 0x0758086E, 0x09000A00, 0x0B000C00, 0x0D000E00, 0x0F001000, 0x00000000, };
s32 D_80078E14[] = { 0x05640666, 0x0758086E, 0x097E0A58, 0x0B640C00, 0x0D000E00, 0x0F001000, 0x00000000, };
s32 D_80078E30[] = { 0x05640666, 0x0758086E, 0x097E0A58, 0x0B640C64, 0x0D6A0E64, 0x0F64106E, 0x00000000, 0x00000000, };

INCLUDE_ASM(void, "code_303c0_len_3e10", al_LoadBKHeaders, UnkAl19E0* arg0, ALHeap* arg1);

void func_80055050(void) {
    D_80078DB4 = 1;
    D_80078DB0 = 0;
}

INCLUDE_ASM(void, "code_303c0_len_3e10", func_80055068, u32 arg0);

void func_80055110(UnkAlA9C *arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        arg0->unk_238[i] = 0;
    }

    arg0->unk_25B = 0;
    arg0->unk_25A = 0;
    arg0->unk_259 = 0;
    arg0->unk_258 = 0;
}

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_8005513C);

void func_800551E0(s32 arg0, u8 arg1, s8 arg2) {
    UnkAl6CC* sym = D_8009A640;
    s16 a1temp = arg1 * 256;

    if (a1temp != 0) {
        a1temp |= 0xFF;
    }

    if (arg2 < 0) {
        arg2 = 0x7F;
    }

    func_8004B6D8(sym, arg0, a1temp, 0, arg2);
}

void func_80055240(s32 arg0, u8 arg1, s8 arg2, s16 arg3) {
    UnkAl6CC* sym = D_8009A640;
    s16 a1temp = arg1 * 256;

    if (a1temp != 0) {
        a1temp |= 0xFF;
    }

    if (arg2 < 0) {
        arg2 = 0x7F;
    }

    if (arg3 > 0x960) {
        arg3 = 0x960;
    } else if (arg3 < -0x960) {
        arg3 = -0x960;
    }

    func_8004B6D8(sym, arg0, a1temp, arg3, arg2);
}

void func_800552D0(s32 arg0, u8 arg1, s8 arg2) {
    UnkAl6CC* sym = D_8009A640;
    s16 a1temp = arg1 * 256;

    if (a1temp != 0) {
        a1temp |= 0xFF;
    }

    if (arg2 < 0) {
        arg2 = 0x7F;
    }

    func_8004B6D8(sym, arg0 | 0x1000, a1temp, 0, arg2);
}

void func_80055330(s32 arg0, u8 arg1, s8 arg2, s16 arg3) {
    UnkAl6CC* sym = D_8009A640;
    s16 a1temp = arg1 * 256;

    if (a1temp != 0) {
        a1temp |= 0xFF;
    }

    if (arg2 < 0) {
        arg2 = 0x7F;
    }

    if (arg3 > 0x960) {
        arg3 = 0x960;
    } else if (arg3 < -0x960) {
        arg3 = -0x960;
    }

    func_8004B6D8(sym, arg0 | 0x1000, a1temp, arg3, arg2);
}

void func_800553C0(s32 arg0) {
    func_8004B6D8(D_8009A640, arg0 | 0x8000, 0, 0, 0);
}

void func_800553F4(void) {
    D_8009A640->unk_168 = 1;
}

void func_80055408(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_8004B6D8(D_8009A640, arg0, arg1, arg2, arg3);
}

s32 func_80055448(s32 arg0) {
    return func_80053F80(arg0);
}

s32 func_80055464(s32 arg0, s32 arg1) {
    if (func_80050C30(arg0) == 0) {
        func_80050CA0(arg0, arg1);
    }
}

s32 func_800554A4(s32 arg0) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050EF0(arg0);
    }

    return ret;
}

s32 func_800554E8(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050F64(arg0, arg1);
    }

    return ret;
}

s32 func_8005553C(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050E18(arg0, arg1);
    }

    return ret;
}

s32 func_80055590(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050E84(arg0, arg1);
    }

    return ret;
}

void func_800555E4(s32 arg0) {
    if (func_80050C30(arg0) == 0) {
        func_80051050(arg0);
    }
}

s32 func_80055618(s32 arg0, s32 arg1) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050C54(arg0, arg1);
    }

    return ret;
}

s32 func_8005566C(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050FD0(arg0, arg1, arg2);
    }

    return ret;
}

s32 func_800556D0(s32 arg0) {
    s32 ret = func_80050C30(arg0);

    if (ret == 0) {
        func_80050C64(arg0, 1);
    }

    return ret;
}

s32 func_80055718(s32 arg0) {
    s32 ret  = func_80050C30(arg0);

    if (ret == 0) {
        func_80050C64(arg0, 0);
    }

    return ret;
}

void func_80055760(s32 arg0) {
    u32 i;
    s32 lim = 4;

    D_80078DB6 = 0xFF;

    for (i = 0; i < lim; i++) {
        if (func_80055464(i, 0) != 0) {
            return;
        }
    }

    func_80055848(arg0);
}

s32 func_800557CC(s32 arg0) {
    u32 i;
    s32 lim = 4;
    s32 phi_v1;

    for (i = 0; i < lim; i++) {
        if (i == D_80078DB6) {
            phi_v1 = func_800554E8(i, arg0);
        } else {
            phi_v1 = func_800554A4(i);
        }

        if (phi_v1 != 0) {
            break;
        }
    }
    return phi_v1;
}

s32 func_80055848(s32 arg0) {
    s32 lim = 4;
    s32 phi_v1 = 0;

    if (arg0 != D_80078DB6) {
        u32 i;

        for (i = 0; i < lim; i++) {
            if (i == arg0) {
                phi_v1 = func_80055718(arg0);
            } else {
                phi_v1 = func_800556D0(i);
            }

            if (phi_v1 != 0) {
                break;
            }
        }

        if (phi_v1 == 0) {
            D_80078DB6 = arg0;
        }
    }

    return phi_v1;
}

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800558D4);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_8005591C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055970);

s32 func_800559C4(UNK_TYPE arg0) {
    return func_8004DA0C(arg0);
}

void func_800559E0(void) {
    func_8004DA74();
}

void func_800559FC(void) {
    func_8004DAE0();
}

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055A18);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055A6C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055ABC);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055AF0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055B28);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055B80);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055BB8);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055BF0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055C2C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055C64);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055C94);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055CC4);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055CE8);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055D38);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055D8C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055DDC);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055E48);

// needs rodata
#ifdef NON_MATCHING
s32* func_80055EB4(s32 arg0) {
    s32* ret = NULL;

    switch(arg0) {
        case 0:
            ret = &D_80078DB8;
            break;
        case 1:
            ret = &D_80078DC4;
            break;
        case 2:
            ret = &D_80078DCC;
            break;
        case 3:
            ret = &D_80078DD0;
            break;
        case 4:
            ret = &D_80078DDC;
            break;
        case 5:
            ret = &D_80078DF8;
            break;
        case 6:
            ret = &D_80078E14;
            break;
        case 7:
            ret = &D_80078E30;
            break;
    }

    return ret;
}
#else
INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055EB4);
#endif

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055F58);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055FD4);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055FF0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_8005600C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056028);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056044);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056068);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_8005608C);

void func_800560A8(void) {
    D_8009A5C0->unk_9C = 1;
}

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800560BC);

INCLUDE_ASM(void, "code_303c0_len_3e10", func_8005610C, void);

void func_80056144(UnkFuncAl arg0, s32 arg1) {
    D_8009A5C0->unk_A4[arg1] = arg0;
}

void func_8005615C(void) {
    func_80056D5C(1);
    func_80054DA8(0);
}

void func_80056180(void) {
    func_80056D5C(0);
    func_80054DA8(1);
}

void func_800561A4(s32 arg0) {
    func_80054CE0(1, arg0);
}

void func_800561C4(s32 arg0) {
    func_80054CE0(16, arg0);
}

void func_800561E4(s32 arg0) {
    func_80054D74(16, arg0);
}

void func_80056204(void) {
    func_8004BA54(D_8009A640, 0);
}

void func_80056228(void) {
    func_8004BA54(D_8009A640, 1);
}
