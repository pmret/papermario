#include "common.h"
#include "audio.h"

INCLUDE_ASM(s32, "code_31650", func_80056250);

INCLUDE_ASM(s32, "code_31650", func_800565A4);

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

INCLUDE_ASM(s32, "code_31650", func_80056D5C);

#ifdef NON_MATCHING
void func_80056D78(u8 arg0, u16 arg1) {
    D_80078E54->unk_20[arg0].unk_00 = arg1 & 0x7FFF;
}
#else
INCLUDE_ASM(void, "code_31650", func_80056D78, u8 arg0, u16 arg1);
#endif

INCLUDE_ASM(s32, "code_31650", func_80056DA4);

INCLUDE_ASM(s32, "code_31650", func_80056DCC);

INCLUDE_ASM(s32, "code_31650", func_80056E34);

INCLUDE_ASM(s32, "code_31650", func_80056EC0);

INCLUDE_ASM(s32, "code_31650", func_80056EE8);

INCLUDE_ASM(s32, "code_31650", func_80056F78);

INCLUDE_ASM(s32, "code_31650", func_80056FA4);

INCLUDE_ASM(s32, "code_31650", func_80057224);

INCLUDE_ASM(s32, "code_31650", func_80057344);

INCLUDE_ASM(s32, "code_31650", func_8005736C);

INCLUDE_ASM(s32, "code_31650", func_80057548);

INCLUDE_ASM(void, "code_31650", func_800576EC, u8 arg0, s32 arg1, s32 arg2);

INCLUDE_ASM(s32, "code_31650", func_80057874);

INCLUDE_ASM(s32, "code_31650", func_800579D8);

INCLUDE_ASM(s32, "code_31650", func_80057B64);

INCLUDE_ASM(s32, "code_31650", func_80057B8C);

INCLUDE_ASM(s32, "code_31650", func_80057BB4);

INCLUDE_ASM(s32, "code_31650", func_80057BDC);

INCLUDE_ASM(s32, "code_31650", func_80057C04);

INCLUDE_ASM(s32, "code_31650", func_80057C2C);

INCLUDE_ASM(s32, "code_31650", func_80057C54);

INCLUDE_ASM(s32, "code_31650", func_80057D0C);

INCLUDE_ASM(s32, "code_31650", func_80057DC8);

INCLUDE_ASM(s32, "code_31650", func_80057E08);

INCLUDE_ASM(s32, "code_31650", func_80057E5C);

INCLUDE_ASM(void, "code_31650", func_80057EB0, void);

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
