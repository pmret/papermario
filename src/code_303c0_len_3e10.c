#include "common.h"
#include "audio.h"

// TODO: rodata
extern u16 D_80078DB4;

INCLUDE_ASM(void, "code_303c0_len_3e10", al_LoadBKHeaders, UnkAl19E0* arg0, ALHeap* arg1);

#ifdef NON_MATCHING
// Delay slot (probably needs rodata)
void func_80055050(void) {
    D_80078DB4 = 1;
    D_80078DB0 = 0;
}
#else
INCLUDE_ASM(void, "code_303c0_len_3e10", func_80055050, void);
#endif

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

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800551E0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055240);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800552D0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055330);

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

s32 func_800554A4(s32 arg0, s32 arg1) {
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

void func_80055848(s32);

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

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800557CC);

INCLUDE_ASM(void, "code_303c0_len_3e10", func_80055848, s32 arg1);

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

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055EB4);

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

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056144);

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
