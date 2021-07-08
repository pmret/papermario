#include "common.h"

void title_screen_draw_copyright(f32);

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
                     0xF7F7F700, 0x00000000, 0x00000000,
                   };
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

extern s32 D_80077A2B;
extern s32* D_800A0978;
extern s32* D_800A097C;
extern s32 D_800A0980;

INCLUDE_ASM(void, "state_title_screen", state_init_title_screen, void);

INCLUDE_ASM(void, "state_title_screen", state_step_title_screen, void);

void state_drawUI_title_screen(void) {
    switch (gGameStatusPtr->loadMenuState) {
        case 0:
            D_80077A28 = 0;
            D_80077A2C = 0;
            D_80077A30 = 0;
            draw_title_screen_NOP();
            break;
        case 2:
            draw_title_screen_NOP();
            if (gGameStatusPtr->contBitPattern & 1) {
                title_screen_draw_press_start();
            }
        default:
            break;
        case 1:
        case 4:
        case 5:
            draw_title_screen_NOP();
            break;
    }
}

INCLUDE_ASM(void, "state_title_screen", appendGfx_title_screen);

void draw_title_screen_NOP(void) {
}

void title_screen_draw_images(f32 arg0, f32 arg1) {
    title_screen_draw_logo();
    title_screen_draw_copyright(arg1);
}

INCLUDE_ASM(void, "state_title_screen", title_screen_draw_logo);

void title_screen_draw_press_start(void) {
    switch (D_80077A2C) {
        case 0:
            D_80077A28 -= 128;
            if (D_80077A28 < 0) {
                D_80077A28 = 0;
            }

            D_80077A30++;
            if (D_80077A30 >= 16) {
                D_80077A30 = 0;
                D_80077A2C = 1;
            }
            break;
        case 1:
            D_80077A28 += 128;
            if (D_80077A28 > 255) {
                D_80077A28 = 255;
            }

            D_80077A30++;
            if (D_80077A30 >= 16) {
                D_80077A30 = 0;
                D_80077A2C = 0;
            }
    }

    gSPDisplayList(gMasterGfxPos++, D_80077A50);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0xF8, 0xF0, 0x98, D_80077A28);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, D_800A0980);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadBlock(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 2047, 128);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 0x01FC, 0x007C);
    gSPTextureRectangle(gMasterGfxPos++, 0x0180, 0x0224, 0x0380, 0x02A4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
    gDPPipeSync(gMasterGfxPos++);
}

void title_screen_draw_copyright(f32 arg0) {
    s32 alpha;
    s32 i;

    gSPDisplayList(gMasterGfxPos++, &D_80077A50);
    gDPPipeSync(gMasterGfxPos++);

    alpha = 255.0f - (arg0 * 255.0f);
    if (alpha < 0xFF) {
        if (alpha < 0) {
            alpha = 0;
        }
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0,
                          PRIMITIVE, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, alpha);
    }

    for (i = 0; i < 2; i++) {
        alpha = 0; // TODO figure out why this is needed
        gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_IA, G_IM_SIZ_8b, 144, &D_800A097C[0x240 * i]);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_IA, G_IM_SIZ_8b, 18, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync(gMasterGfxPos++);
        gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 0x023C, 0x003C);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_IA, G_IM_SIZ_8b, 18, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 0x023C, 0x003C);
        gSPTextureRectangle(gMasterGfxPos++, 0x0164, 0x2FC + (0x40 * i), 0x03A4, 0x33C + (0x40 * i), G_TX_RENDERTILE,
                            0, 0, 0x0400, 0x0400);
    }
    gDPPipeSync(gMasterGfxPos++);
}
