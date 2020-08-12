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

INCLUDE_ASM(code_8a160_len_700, func_800F0CB0);
// void func_800F0CB0(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
//{
//    sub_struct_func_800F0CB0 *temp_a1 = &D_8010D000[arg0].unk00[0];
//    s32 temp = 0x39;
//    s32 i;
//
//    if (arg0 >= 1) {
//        return;
//    }
//
//    temp_a1->unk0 = 1;
//    temp_a1->unk8 = arg1;
//    temp_a1->unkC = arg2;
//    temp_a1->unk18 = arg3;
//    temp_a1->unk1 = 0x28;
//    temp_a1->unk2 = 0;
//
//    for(i = 1; i < temp; i++)
//        temp_a1[i].unk7 = (s32)(-(f32) i * 0.0f) - 1;
//}

void func_800F0D5C(void) {
    struct_func_800F0CB0* temp = &D_8010D000[0];
    s32 i = 0;

    for (i; i < 1; i++) {
        temp[i].unk00[0].unk0 = 0;
    }
}

INCLUDE_ASM(code_8a160_len_700, func_800F0D80);

/*extern u16 D_800741F0;
extern Gfx *D_8009A66C;
extern Gfx *D_8009A674;
extern void *D_801096B0;
extern Gfx D_80109710[];
extern Gfx D_801097D8[];*/

INCLUDE_ASM(code_8a160_len_700, func_800F102C);
/*void func_800F102C(void) {
    s32 temp_s2;
    s32 temp_s7;
    u16 *temp_v0 = &D_800741F0;
    u16 temp_v0_2;
    u16 temp_v1_4;
    Gfx *temp_a0;
    sub_struct_func_800F0CB0 *temp_v1_3;
    void *phi_s0;
    s32 phi_s2;
    s32 phi_s7;
    Mtx mtx;
    Mtx mtx2;

    temp_a0 = D_8009A66C;

    gDPPipeSync(temp_a0++);
    gSPSegment(temp_a0++, 0x00, 0x00000000);
    gDPSetScissor(temp_a0++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gSPViewport(temp_a0++, &D_801096B0);
    guOrthoF(&mtx, 0.0f, 320.0f, 240.0f, 0.0f, -100.0f, 100.0f, 1.0f);
    guMtxF2L(&mtx, *(void *)0x8009A674 + (*temp_v0 * 64 + 0x11630));
    gSPMatrix(temp_a0++, (*(void *)0x8009A674 + (temp_v0++ * 64 + 0x11630)), G_MTX_NOPUSH | G_MTX_LOAD |
G_MTX_PROJECTION); gSPDisplayList(temp_a0++, &D_80109710); gDPSetEnvColor(temp_a0++, 0x7F, 0x7F, 0x7F, 0x7F); phi_s7 =
0; do
    {
        temp_v1_3 = &D_8010D000[phi_s7].unk00[0];
        if (temp_v1_3->unk0 != 0) {
            phi_s0 = temp_v1_3 + 0x22;
            phi_s2 = 1;
            do {
                if ((s32) phi_s0->unk1 >= 0) {
                    guPositionF(&mtx2, 0.0f, 0.0f, (*gGameStatusPtr)->unk134 * 0xA, phi_s0->unk12 * temp_v1_3->unk18,
phi_s0->unk2, phi_s0->unk6, 0.0f); guMtxF2L(&mtx2, *(void *)0x8009A674 + ((*(void *)0x800741F0 << 6) + 0x11630));
                    gSPMatrix(temp_a0++, (*(void *)0x8009A674 + (temp_v0++ * 64 + 0x11630)), G_MTX_PUSH | G_MTX_MUL |
G_MTX_MODELVIEW); temp_a0_2->unk0 = (s32) (((0x50 - phi_s0->unk1) & 0xFF) | 0xFA000000); temp_a0_2->unk4 = (?32)
((((phi_s0->unk-3 << 0x18) | (phi_s0->unk-2 << 0x10)) | (phi_s0->unk-1 << 8)) | phi_s0->unk0); gSPDisplayList(temp_a0++,
&D_801097D8); gSPPopMatrix(temp_a0++, G_MTX_MODELVIEW);
                }
                phi_s2++;
            } while(phi_s2 < 0x39);
        }
        phi_s7++;
    }
    while(phi_s7 < 1);
}*/
