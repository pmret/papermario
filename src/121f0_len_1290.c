#include "common.h"

void title_draw_copyright(f32);

s16 D_800779C0[] = {0, 0};
s32 D_800779C4 = 0;
s8 D_800779C8[] = {0, 0};
s8 D_800779CA = 0;
s8 D_800779CB = 0x45;
s32 D_800779CC = 0x52524F52;
s32 D_800779D0 = 0xF7F7F700;
s32 D_800779D4 = 0;
s32 D_800779D8[] = { 0x00000000, 0x00000000, 0x00000045, 0x52524F52, 0xF7F7F700, 0x00000000, 0x00000000, 0x00000000,
                     0x00000045, 0x52524F52, 0xF7F7F700, 0x00000000, 0x00000000, 0x00000000, 0x00000045, 0x52524F52,
                     0xF7F7F700, 0x00000000, 0x00000000, };
s32 D_80077A24 = 0x01010101;

s32 D_80077A28 = 0;
s32 D_80077A2C = 0;
s32 D_80077A30 = 0;
s32 D_80077A34[] = {0x00000000, 0xFFFFFF00, 0xFFFFFF00};
s32 D_80077A40[] = {0, 0, 0, 0};
Gfx D_80077A50[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_CLD_SURF, G_RM_CLD_SURF2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPNoOp(),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 320, 240),
    gsSPEndDisplayList(),
};

INCLUDE_ASM(s32, "121f0_len_1290", begin_state_title_screen);

INCLUDE_ASM(s32, "121f0_len_1290", step_title_screen);

INCLUDE_ASM(s32, "121f0_len_1290", func_800375A4);
// void func_800375A4(void) {
//     switch (gGameStatusPtr->loadMenuState) {
//         case 0:
//             D_80077A28 = 0;
//             D_80077A2C = 0;
//             D_80077A30 = 0;
//             func_80037960();
//             break;
//         case 2:
//             func_80037960();
//             if (gGameStatusPtr->contBitPattern & 1) {
//                 title_draw_press_start();
//             }
//         default:
//             break;
//         case 1:
//         case 4:
//         case 5:
//             func_80037960();
//             break;
//     }
// }

INCLUDE_ASM(s32, "121f0_len_1290", title_append_gfx);

void func_80037960(void) {
}

void title_draw_images(f32 arg0, f32 arg1) {
    title_draw_logo();
    title_draw_copyright(arg1);
}

INCLUDE_ASM(void, "121f0_len_1290", title_draw_logo);

extern s32 D_80077A2B;
extern s32 D_800A0980;

INCLUDE_ASM(s32, "121f0_len_1290", title_draw_press_start);
// void title_draw_press_start(void) {
//     s32* temp80077A28;
//     s32* temp80077A2C = &D_80077A2C;
//     s32* temp80077A30;

//     switch (*temp80077A2C) {
//         case 0:
//             temp80077A28 = &D_80077A28;
//             *temp80077A28 -= 128;
//             if (*temp80077A28 < 0) {
//                 *temp80077A28 = 0;
//             }

//             temp80077A30 = &D_80077A30;
//             (*temp80077A30)++;
//             if (*temp80077A30 >= 16) {
//                 *temp80077A30 = 0;
//                 *temp80077A2C = 1;
//             }
//             break;
//         case 1:
//             temp80077A28 = &D_80077A28;
//             *temp80077A28 += 128;
//             if (*temp80077A28 > 255) {
//                 *temp80077A28 = 255;
//             }

//             temp80077A30 = &D_80077A30;
//             (*temp80077A30)++;
//             if (*temp80077A30 >= 16) {
//                 *temp80077A30 = 0;
//                 *temp80077A2C = 0;
//             }
//     }

//     gSPDisplayList(gMasterGfxPos++, D_80077A50);
//     gDPSetCombineMode(gMasterGfxPos++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
//     gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0xF8, 0xF0, 0x98, D_80077A28);
//     gDPPipeSync(gMasterGfxPos++);
//     gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, D_800A0980);
//     gDPSetTile(gMasterGfxPos++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
//                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPLoadSync(gMasterGfxPos++);
//     gDPLoadBlock(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 2047, 128);
//     gDPPipeSync(gMasterGfxPos++);
//     gDPSetTile(gMasterGfxPos++, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
//                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 0x01FC, 0x007C);
//     gSPTextureRectangle(gMasterGfxPos++, 0x0180, 0x0224, 0x0380, 0x02A4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
//     gDPPipeSync(gMasterGfxPos++);
// }

INCLUDE_ASM(void, "121f0_len_1290", title_draw_copyright, f32 arg0);
