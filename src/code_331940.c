#include "common.h"

typedef struct structE001E000 {
  /* 0x000 */ s32 unk_00;
  /* 0x004 */ Vec3f unk_04;
  /* 0x010 */ Vec3f unk_10;
  /* 0x01C */ s32 unk_1C;
  /* 0x020 */ char unk_20[4];
  /* 0x024 */ f32 unk_24;
  /* 0x028 */ s32 unk_28;
  /* 0x02C */ f32 unk_2C;
  /* 0x030 */ f32 unk_30;
  /* 0x034 */ f32 unk_34;
  /* 0x038 */ char unk_38[4];
  /* 0x03C */ s32 unk_3C;
  /* 0x040 */ char unk_40[0x200];
  /* 0x240 */ f32 unk_240;
  /* 0x244 */ s32 unk_244;
  /* 0x248 */ s32 unk_248;
  /* 0x24C */ s32 unk_24C;
} structE001E000; // size = 0x250

extern Camera D_800B1DEC[2];

INCLUDE_ASM(s32, "code_331940", func_E001E000);
/*
void *func_E001E000(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f2;
    f32 temp_f4;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_s2;
    void *temp_v0;
    void *temp_v0_4;
    f32 phi_f4;
    f32 phi_f0;
    f32 phi_f12;
    f32 phi_f26;
    void *phi_v0;
    void *phi_v1;
    s32 phi_a1;
    f32 phi_f12_2;
    void *phi_a0;

    temp_s2 = func_E0200490(&subroutine_arg4, 0, 0xF, &D_E001E370, &D_E001E378, &D_E001E6E8, 0);
    temp_s2->unk8 = 1;
    temp_v0 = func_E02004B0(0x250); // some kind of allocation function.
    temp_s1 = temp_v0;
    temp_s2->unkC = temp_v0;
    ASSERT(temp_s1 != NULL);
    temp_s1->unk_00 = 1;
    temp_s1->unk_04.x = arg1;
    temp_s1->unk_04.y = arg2;
    temp_s1->unk_04.z = arg3;
    temp_s1->unk_1C = 0;
    temp_s1->unk_24 = 0.0f;
    temp_s1->unk_28 = 0;
    temp_s1->unk_38 = arg0;
    if (arg0 == 3) {
        temp_s1->unk_240 = 0.2f;
        temp_v0_2 = func_E02004E0(0xFF);
        temp_a0 = 0xFF - temp_v0_2;
        temp_s1->unk_244 = temp_v0_2;
        temp_v0_3 = func_E02004E0(temp_a0);
        temp_s0 = 0xFF - temp_v0_3;
        temp_s1->unk_248 = temp_v0_3;
        temp_s1->unk_24C = (s32) (temp_s0 - temp_s1->unk_244);
    } else {
        temp_s1->unk_244 = 0xD2;
        temp_s1->unk_248 = 0xBA;
        temp_s1->unk_24C = 0x5A;
        temp_s1->unk_240 = 0.5f;
    }
    temp_f24 = arg4 - arg1;
    temp_f22 = arg5 - arg2;
    temp_f20 = arg6 - arg3;
    temp_f26 = (temp_f24 * temp_f24) + (temp_f22 * temp_f22) + (temp_f20 * temp_f20);
    phi_f4 = temp_f26;
    phi_f26 = temp_f26;
    if (temp_f26 != 0.0f) {
        temp_f0 = func_E0200550(temp_f26);
        phi_f4 = arg7 / temp_f0;
        phi_f26 = temp_f0;
    }
    temp_s1->unk10.x = (f32) (temp_f24 * phi_f4);
    temp_s1->unk10.y = (f32) (temp_f22 * phi_f4);
    temp_s1->unk10.z = (f32) (temp_f20 * phi_f4);
    temp_f20_2 = *(&D_800B1DEC + (gCurrentCameraID * 0x558));
    temp_f22_2 = -func_E0200510(temp_f20_2);
    temp_f4 = temp_f22_2 * temp_s1->unk10;
    temp_f20_3 = -func_E0200500(temp_f20_2);
    temp_f2 = temp_f20_3 * temp_s1->unk18;
    temp_f12 = (temp_f4 * temp_f4) + (temp_f2 * temp_f2);
    phi_f12_2 = temp_f12;
    if (temp_f12 != 0.0f) {
        phi_f12_2 = func_E0200550(temp_f12);
    }
    if (((temp_f22_2 * temp_s1->unk10) + (temp_f20_3 * temp_s1->unk18)) < 0.0f) {
        phi_f0 = -20.0f;
        phi_f12 = -phi_f12_2;
    } else {
        phi_f0 = 20.0f;
        phi_f12 = phi_f12_2;
    }
    temp_s1->unk2C = phi_f0;
    temp_f20_4 = -phi_f12;
    temp_f0_2 = func_E0200520(0, 0, -temp_s1->unk14, temp_f20_4);
    temp_s1->unk_30 = (bitwise f32) (s32) (phi_f26 / arg7);
    temp_s0_2 = temp_s1 + 0x40;
    temp_s1->unk24 = temp_f0_2;
    temp_s1->unk20 = temp_f0_2;
    temp_s1->unk34 = temp_f20_4;
    func_E0200430(temp_s0_2, (bitwise s32) temp_s1->unk4, (bitwise s32) temp_s1->unk8, (bitwise s32) temp_s1->unkC);
    phi_a1 = 1;
    phi_a0 = temp_s0_2;
loop_13:
    phi_v0 = temp_s0_2;
    phi_v1 = phi_a0 + 0x40;
loop_14:
    phi_v1->unk0 = (s32) phi_v0->unk0;
    phi_v1->unk4 = (s32) phi_v0->unk4;
    phi_v1->unk8 = (s32) phi_v0->unk8;
    phi_v1->unkC = (s32) phi_v0->unkC;
    temp_v0_4 = phi_v0 + 0x10;
    phi_v0 = temp_v0_4;
    phi_v1 = phi_v1 + 0x10;
    if (temp_v0_4 != (temp_s1 + 0x80)) {
        goto loop_14;
    }
    temp_a1 = phi_a1 + 1;
    phi_a1 = temp_a1;
    phi_a0 = phi_a0 + 0x40;
    if (temp_a1 < 8) {
        goto loop_13;
    }
    temp_s1->unk3C = -1;
    return temp_s2;
}*/

INCLUDE_ASM(s32, "code_331940", func_E001E370);

INCLUDE_ASM(s32, "code_331940", func_E001E378);

INCLUDE_ASM(s32, "code_331940", func_E001E6E8);

INCLUDE_ASM(s32, "code_331940", func_E001E730);
