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

void func_800F0CB0(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 temp_v1;
    struct_func_800F0CB0* temp_a1;
    s32 phi_v1;
    sub_struct_func_800F0CB0* phi_a1;

    temp_a1 = &D_8010D000[arg0];
    phi_a1 = &temp_a1->unk00[0];
    temp_v1 = 0x39;

    if (arg0 <= 0) {
        phi_a1->unk0 = 1;
        phi_a1->unk8 = arg1;
        phi_a1->unkC = arg2;
        phi_a1->unk18 = arg3;
        phi_a1->unk1 = 0x28;
        phi_a1->unk2 = 0;
        phi_a1 = &temp_a1->unk00[1];
        phi_v1 = 1;
    while (phi_v1 < temp_v1) {
        phi_a1->unk7 = (s32) (-(f32) phi_v1 * 0.0f) - 1;
        phi_v1 = phi_v1 + 1;
        phi_a1++;
    }
    }
}

void func_800F0D5C(void) {
    struct_func_800F0CB0* temp = &D_8010D000[0];
    s32 i = 0;

    for (i; i < 1; i++) {
        temp[i].unk00[0].unk0 = 0;
    }
}

INCLUDE_ASM(s32, "8a160_len_700", func_800F0D80);

INCLUDE_ASM(s32, "8a160_len_700", func_800F102C);
