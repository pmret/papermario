#include "common.h"

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A370);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A37C);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A4D0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A610);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A650);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A6E8);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A704);

typedef struct UnkStructFromfunc8013A854 {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ s16 unk10;
    /* 0x11 */ char unk_11[0x01];
    /* 0x14 */ s32 unk14;
    /* 0x15 */ char unk_15[0x67];
} UnkStructFromfunc8013A854; // size = 0x7C

void func_8013A854(u32 index) {
    u32 temp_v0;
    temp_v0 = index << 5;
    if (index < 0x5AU) {
        UnkStructFromfunc8013A854* unkStruct;
        temp_v0 = temp_v0 - index;
        u32 temp_v1;
        u32 temp_v1 = 0x80156954;
        temp_v0 = temp_v0 << 2;
        temp_v0 = temp_v0 + temp_v1;
        unkStruct = &D_80156954[temp_v0];
        unkStruct->unk14 = 0;
        unkStruct->unk10 = (s16)-1;
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
