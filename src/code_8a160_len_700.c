#include "common.h"

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ char unk3[4];
    /* 0x07 */ s8 unk7;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ char unk10[8];
    /* 0x18 */ f32 unk18;
} sub_struct_func_800F0CB0;

typedef struct {
    /* 0x00 */ sub_struct_func_800F0CB0 unk00[0x39];
} struct_func_800F0CB0;

extern struct_func_800F0CB0 D_8010D000[];

INCLUDE_ASM(s32, "code_8a160_len_700", func_800F0CB0);

void func_800F0D5C(void) {
    struct_func_800F0CB0* temp = &D_8010D000[0];
    s32 i = 0;

    for (i; i < 1; i++) {
        temp[i].unk00[0].unk0 = 0;
    }
}

INCLUDE_ASM(s32, "code_8a160_len_700", func_800F0D80);

INCLUDE_ASM(s32, "code_8a160_len_700", func_800F102C);
