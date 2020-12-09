#include "common.h"
#include "audio.h"

INCLUDE_ASM(s32, "code_31650", func_80056250);

void func_800565A4(void) {
    s32 *sym = &D_80078E50;

    if (*sym != 0) {
        *sym = 0;
    }
}

INCLUDE_ASM(Acmd*, "code_31650", alAudioFrame, Acmd* cmdList, s32* cmdLen, s16* outBuf, s32 outLen);

#ifdef NON_MATCHING
void func_80056D34(void) {
    D_80078E58 = 1;
}
#else
INCLUDE_ASM(s32, "code_31650", func_80056D34);
#endif

#ifdef NON_MATCHING
void func_80056D44(s16 arg0) {
    D_80078E5A = arg0;
}
#else
INCLUDE_ASM(s16, "code_31650", func_80056D44);
#endif

#ifdef NON_MATCHING
s16 func_80056D50(void) {
    return D_80078E5A;
}
#else
INCLUDE_ASM(s16, "code_31650", func_80056D50);
#endif

#ifdef NON_MATCHING
void func_80056D5C(s8 arg0) {
    D_80078181 = arg0;
    D_80078E5C = 1;
}
#else
INCLUDE_ASM(s32, "code_31650", func_80056D5C);
#endif

#ifdef NON_MATCHING
void func_80056D78(u8 arg0, u16 arg1) {
    D_80078E54->unk_20[arg0].unk_00 = arg1 & 0x7FFF;
}
#else
INCLUDE_ASM(void, "code_31650", func_80056D78, u8 arg0, u16 arg1);
#endif

INCLUDE_ASM(s32, "code_31650", func_80056DA4);

INCLUDE_ASM(void, "code_31650", func_80056DCC, u8 arg0, u8 arg1);

INCLUDE_ASM(s32, "code_31650", func_80056E34);

void func_80056EC0(u8 arg0, s8 arg1) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    al7C->unk_78 = arg1;
}

INCLUDE_ASM(void, "code_31650", func_80056EE8, u8 arg0);

void func_80056F78(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    al7C->unk_70 = 1;
}

INCLUDE_ASM(void, "code_31650", func_80056FA4, u8 arg0, u8 arg1, s32 arg2, f32 arg3, s16 arg4, u8 arg5, u8 arg6, s32 arg7);

INCLUDE_ASM(void, "code_31650", func_80057224, u8 arg0, UnkAl30* arg1);

void func_80057344(u8 arg0, f32 arg1) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    al7C->unk_3C = arg1;
}

INCLUDE_ASM(void, "code_31650", func_8005736C, u8 arg0, s16 arg1, s32 arg2, u8 arg3, u8 arg4);

INCLUDE_ASM(void, "code_31650", func_80057548, u8 arg0, u8 arg1, u8 arg2);

INCLUDE_ASM(void, "code_31650", func_800576EC, u8 arg0, s32 arg1, s32 arg2);

INCLUDE_ASM(s32, "code_31650", func_80057874);

INCLUDE_ASM(s32, "code_31650", func_800579D8);

s32 func_80057B64(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_70;
}

s32 func_80057B8C(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_78;
}

f32 func_80057BB4(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_3C;
}

u8 func_80057BDC(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_4D;
}

s16 func_80057C04(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_54;
}

s16 func_80057C2C(u8 arg0) {
    UnkAl7C* al7C = &D_80078E54->unk_1C[arg0];

    return al7C->unk_56;
}

INCLUDE_ASM(s32, "code_31650", func_80057C54);

INCLUDE_ASM(s32, "code_31650", func_80057D0C);

void func_80057DC8(s32 arg0) {
    s32* sym;
    if (arg0 < 2) {
        D_800A3FF0 = 0;
        D_800A3FEE = 0;
    }

    sym = &D_800A3FF0;
    *sym = arg0;
    if (arg0 >= 5) {
        *sym = 4;
    }
}

INCLUDE_ASM(void, "code_31650", func_80057E08, u8 arg0);

INCLUDE_ASM(void, "code_31650", func_80057E5C, u8 arg0);

void func_80057EB0(void) {
    D_800A3FEC = 0;
    D_800A3FEE = 0;
    D_800A3FE8 = 0;
}

INCLUDE_ASM(s32, "code_31650", func_80057ED0);

INCLUDE_ASM(s32, "code_31650", func_80057F20);

void* alHeapAlloc(ALHeap *heap, s32 arg1, s32 size) {
    void* ret = NULL;
    u8* newCur = &heap->cur[ALIGN16(arg1 * size)];

    if (&heap->base[heap->len] >= newCur) {
        ret = heap->cur;
        heap->cur = newCur;
    }

    return ret;
}

INCLUDE_ASM(s32, "code_31650", func_80057FD8);

INCLUDE_ASM(s32, "code_31650", func_80058004);

INCLUDE_ASM(s32, "code_31650", func_80058050);

INCLUDE_ASM(s32, "code_31650", func_80058B20);

INCLUDE_ASM(s32, "code_31650", func_80058C6C);
