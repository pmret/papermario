#include "common.h"

#define UNKSTRUCT8013A854_SIZE 90

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A370);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A37C);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A4D0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A610);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A650);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A6E8);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A704);

/* TODO sonicspiral oct 2020
    After reviewing with stuckpixel it looks like there's an array of 90 structs
    here, each struct of size 0x7C. Need to uncover what these other structs are.
*/
typedef struct {
    /* 0x00 */ char unk_0[0x10];
    /* 0x10 */ s16 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk_18[0x64];
} UnkStruct8013A854 ; // size = 0x7C

typedef UnkStruct8013A854 UnkStruct8013A854List[UNKSTRUCT8013A854_SIZE];

extern UnkStruct8013A854List* D_80156954[UNKSTRUCT8013A854_SIZE];

void func_8013A854(u32 i) {
    UnkStruct8013A854* unkStruct80156954ListPtr;
    
    if (i < 90) {
        unkStruct80156954ListPtr = *D_80156954;
        unkStruct80156954ListPtr[i].unk_14 = 0;
        unkStruct80156954ListPtr[i].unk_10 = -1;
    }
}

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A888);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A8E0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A920);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A93C);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A9C8);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A9E8);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013AA9C);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013AF20);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013AF70);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013B0EC);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013B1B0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013BC88);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013C048);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013C220);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013C3F0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013CFA8);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013DAB4);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013E2F0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013E904);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013EE48);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013EE68);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013F1F8);
