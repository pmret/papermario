#include "common.h"

// TODO: rodata
extern s32 D_80078DB0;
extern u16 D_80078DB4;

INCLUDE_ASM(s32, "code_303c0_len_3e10", al_LoadBKHeaders);

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

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055110);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_8005513C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800551E0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055240);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800552D0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055330);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800553C0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800553F4);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055408);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055448, s32 arg0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055464, s32 arg0, s32 arg1);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800554A4, s32 arg0, s32 arg1);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800554E8, s32 arg0, s32 arg1);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_8005553C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055590);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800555E4, s32 arg0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055618);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_8005566C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800556D0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055718);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055760);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800557CC);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055848);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800558D4);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_8005591C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80055970);

s32 func_800559C4(UNK_TYPE arg0) {
    return func_8004DA0C(arg0);
}

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800559E0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800559FC);

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

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800560A8);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800560BC);

INCLUDE_ASM(void, "code_303c0_len_3e10", func_8005610C, void);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056144);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_8005615C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056180);

INCLUDE_ASM(void, "code_303c0_len_3e10", func_800561A4, s16 arg0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800561C4);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800561E4);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056204);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056228);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056250);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800565A4);

INCLUDE_ASM(Acmd*, "code_303c0_len_3e10", alAudioFrame, Acmd* cmdList, s32* cmdLen, s16* outBuf, s32 outLen);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056D34);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056D44);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056D50);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056D5C);

INCLUDE_ASM(void, "code_303c0_len_3e10", func_80056D78, u8 arg0, u16 arg1);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056DA4);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056DCC);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056E34);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056EC0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056EE8);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056F78);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80056FA4);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057224);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057344);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_8005736C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057548);

INCLUDE_ASM(void, "code_303c0_len_3e10", func_800576EC, u8 arg0, s32 arg1, s32 arg2);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057874);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_800579D8);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057B64);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057B8C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057BB4);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057BDC);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057C04);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057C2C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057C54);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057D0C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057DC8);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057E08);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057E5C);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057EB0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057ED0);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057F20);

#undef alHeapAlloc
INCLUDE_ASM(void, "code_303c0_len_3e10", alHeapAlloc, u8* file, s32 line, ALHeap* hp, s32 num, s32 size);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80057FD8);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80058004);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80058050);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80058B20);

INCLUDE_ASM(s32, "code_303c0_len_3e10", func_80058C6C);
