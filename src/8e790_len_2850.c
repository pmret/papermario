#include "common.h"
#include "nu/nusys.h"

typedef struct DefaultWindowStyle {
    /* 0x00 */ u8 bgIndex;
    /* 0x01 */ u8 cornersIndex;
    /* 0x02 */ u8 unk_2;
    /* 0x03 */ Color_RGBA8 color1;
    /* 0x07 */ Color_RGBA8 color2;
} DefaultWindowStyle; // size = 0x0B

typedef struct UnkDrawStruct {
    Vtx vert[16];
} UnkDrawStruct; // size = 0x100

static UnkDrawStruct D_8010D6B0[];

DefaultWindowStyle D_801098E0[] = {
    {
        .bgIndex = 1,
        .cornersIndex = 0,
        .unk_2 = 0,
        .color1 = { .r = 200, .g = 191, .b = 164, .a = 255 },
        .color2 = { .r = 128, .g = 128, .b = 128, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 1,
        .unk_2 = 1,
        .color1 = { .r = 255, .g = 200, .b = 128, .a = 255 },
        .color2 = { .r = 128, .g = 128, .b = 128, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 2,
        .unk_2 = 1,
        .color1 = { .r = 232, .g = 196, .b = 77, .a = 255 },
        .color2 = { .r = 163, .g = 123, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 0,
        .cornersIndex = 3,
        .unk_2 = 1,
        .color1 = { .r = 226, .g = 225, .b = 216, .a = 255 },
        .color2 = { .r = 217, .g = 208, .b = 201, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 61, .g = 74, .b = 188, .a = 255 },
        .color2 = { .r = 0, .g = 25, .b = 28, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 5,
        .unk_2 = 1,
        .color1 = { .r = 235, .g = 230, .b = 119, .a = 255 },
        .color2 = { .r = 142, .g = 90, .b = 37, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 6,
        .unk_2 = 1,
        .color1 = { .r = 235, .g = 230, .b = 119, .a = 255 },
        .color2 = { .r = 142, .g = 99, .b = 37, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 215, .g = 191, .b = 116, .a = 255 },
        .color2 = { .r = 132, .g = 70, .b = 50, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 215, .g = 191, .b = 116, .a = 255 },
        .color2 = { .r = 132, .g = 70, .b = 50, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 141, .g = 143, .b = 255, .a = 255 },
        .color2 = { .r = 43, .g = 69, .b = 102, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 8,
        .unk_2 = 1,
        .color1 = { .r = 141, .g = 143, .b = 255, .a = 255 },
        .color2 = { .r = 43, .g = 69, .b = 102, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 170, .g = 208, .b = 128, .a = 255 },
        .color2 = { .r = 71, .g = 123, .b = 83, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 8,
        .unk_2 = 1,
        .color1 = { .r = 170, .g = 208, .b = 128, .a = 255 },
        .color2 = { .r = 71, .g = 123, .b = 83, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 200, .g = 200, .b = 90, .a = 255 },
        .color2 = { .r = 140, .g = 140, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 8,
        .unk_2 = 1,
        .color1 = { .r = 200, .g = 200, .b = 90, .a = 255 },
        .color2 = { .r = 140, .g = 140, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 235, .g = 230, .b = 119, .a = 255 },
        .color2 = { .r = 142, .g = 90, .b = 37, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 142, .g = 212, .b = 236, .a = 255 },
        .color2 = { .r = 67, .g = 98, .b = 69, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 167, .g = 151, .b = 119, .a = 255 },
        .color2 = { .r = 98, .g = 55, .b = 154, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 7,
        .unk_2 = 1,
        .color1 = { .r = 17, .g = 151, .b = 29, .a = 255 },
        .color2 = { .r = 8, .g = 55, .b = 14, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 7,
        .unk_2 = 1,
        .color1 = { .r = 110, .g = 110, .b = 200, .a = 255 },
        .color2 = { .r = 10, .g = 10, .b = 100, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 181, .g = 60, .b = 60, .a = 255 },
        .color2 = { .r = 76, .g = 10, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 174, .g = 227, .b = 235, .a = 255 },
        .color2 = { .r = 76, .g = 110, .b = 60, .a = 255 }
    },
    {
        .bgIndex = 0,
        .cornersIndex = 3,
        .unk_2 = 1,
        .color1 = { .r = 126, .g = 125, .b = 216, .a = 255 },
        .color2 = { .r = 217, .g = 108, .b = 201, .a = 255 }
    }
};

#include "ui/box/corners9.png.inc.c"
#include "ui/box/corners8.png.inc.c"
#include "ui/box/corners6.png.inc.c"
#include "ui/box/corners7.png.inc.c"
#include "ui/box/corners3.png.inc.c"
#include "ui/box/corners5.png.inc.c"
#include "ui/box/corners4.png.inc.c"
#include "ui/box/bg_tile.png.inc.c"
#include "ui/box/corners1.png.inc.c"
#include "ui/box/corners2.png.inc.c"
#include "ui/box/bg_flat.png.inc.c"

WindowBackground D_8010BAE8[] = {
    {
        .imgData = ui_box_bg_tile_png,
        .packedTileFormatHigh = 0x4,
        .packedTileFormatLow = 0x0,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0},
        .size = 128
    },
    {
        .imgData = ui_box_bg_flat_png,
        .packedTileFormatHigh = 0x4,
        .packedTileFormatLow = 0x0,
        .width = 16,
        .height = 1,
        .unk_07 = { 0, 0, 0, 0},
        .size = 8
    }
};

WindowCorners D_8010BB00[] = {
    {
        .imgData = ui_box_corners1_png,
        .packedTileFormatHigh = 0x3,
        .packedTileFormatLow = 0x1,
        .size1 = { 16, 16},
        .size2 = { 16, 16},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners2_png,
        .packedTileFormatHigh = 0x4,
        .packedTileFormatLow = 0x0,
        .size1 = { 16, 16},
        .size2 = { 16, 16},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners3_png,
        .packedTileFormatHigh = 0x3,
        .packedTileFormatLow = 0x1,
        .size1 = { 16, 32},
        .size2 = { 16, 32},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners4_png,
        .packedTileFormatHigh = 0x3,
        .packedTileFormatLow = 0x1,
        .size1 = { 8, 8},
        .size2 = { 8, 8},
        .size3 = { 8, 8},
        .size4 = { 8, 8},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners5_png,
        .packedTileFormatHigh = 0x3,
        .packedTileFormatLow = 0x1,
        .size1 = { 16, 8},
        .size2 = { 16, 8},
        .size3 = { 16, 8},
        .size4 = { 16, 8},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners6_png,
        .packedTileFormatHigh = 0x3,
        .packedTileFormatLow = 0x1,
        .size1 = { 16, 8},
        .size2 = { 16, 8},
        .size3 = { 16, 8},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners7_png,
        .packedTileFormatHigh = 0x3,
        .packedTileFormatLow = 0x1,
        .size1 = { 16, 8},
        .size2 = { 16, 8},
        .size3 = { 16, 8},
        .size4 = { 16, 8},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners8_png,
        .packedTileFormatHigh = 0x3,
        .packedTileFormatLow = 0x1,
        .size1 = { 24, 24},
        .size2 = { 24, 24},
        .size3 = { 24, 24},
        .size4 = { 24, 24},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners9_png,
        .packedTileFormatHigh = 0x3,
        .packedTileFormatLow = 0x1,
        .size1 = { 16, 16},
        .size2 = { 16, 16},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    }
};

Gfx D_8010BB90[] = {
    gsDPSetCombineLERP(TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL1, TEXEL0, ENVIRONMENT, ENV_ALPHA, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0, 0, 0, 0, TEXEL1, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED),
    gsDPSetCombineLERP(TEXEL0, 0, PRIMITIVE, 0, TEXEL1, 0, PRIMITIVE, 0, TEXEL0, ENVIRONMENT, ENV_ALPHA, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0, TEXEL1, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED)
};
s32 D_8010BBB0 = 0;
s32 D_8010BBB4 = 0;
Vp D_8010BBB8 = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 }
    }
};

#include "vtx/drawbox1.vtx.inc.c"

/*
| 0.0  0.0  0.0  0.0|
| 0.0  0.0  0.0  0.0|
| 0.0  0.0  0.0  0.0|
|-6.0  0.0  0.0  0.0|
*/
Mtx D_8010BC08 = {
    .m = {
        // integer portion
        { 0x00000000, 0x00000000,
          0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000,
          0xFFFA0000, 0x00000000 },
        //fractional portion
        { 0x00000000, 0x00000000,
          0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000,
          0x00000000, 0x00000000 }
    }
};

#define _INTEGER_LOG2(x) ((x) <= 1 ? 0 : (x) <= 2 ? 1 : (x) <= 4 ? 2 : (x) <= 8 ? 3 : (x) <= 16 ? 4 : (x) <= 32 ? 5 : (x) <= 64 ? 6 : (x) <= 128 ? 7 : (x) <= 256 ? 8 : (x) <= 512 ? 9 : 10)

//INCLUDE_ASM(void, "8e790_len_2850", draw_box, s32 flags, WindowStyle windowStyle, s32 posX, s32 posY, s32 posZ, s32 width,
            //s32 height, s32 opacity, s32 darkening, f32 scaleX, f32 scaleY, f32 rotX, f32 rotY, f32 rotZ,
            //void (*fpDrawContents)(s32),s32 drawContentsArg0, Matrix4f rotScaleMtx, s32 translateX, s32 translateY,
            //f32 (*outMtx)[4]);

s32 draw_box(s32 flags, WindowStyleCustom* windowStyle, s32 posX, s32 posY, s32 posZ, s32 width, s32 height, u8 opacity,
              u8 darkening, f32 scaleX, f32 scaleY, f32 rotX, f32 rotY, f32 rotZ, void (*fpDrawContents)(s32, s32, s32, s32, s32, s32, s32),
              void* drawContentsArg0, Matrix4f rotScaleMtx, s32 translateX, s32 translateY, Matrix4f outMtx) {
    Matrix4f sp20;
    Matrix4f sp60;
    Matrix4f spA0;
    u8 spF7, spFF, sp107, sp10F, sp117, sp11F, sp127, sp12F;

    u8* backgroundImageData;
    u8* sp13C;
    s32 sp140;
    s32 sp144;
    Vec2bu* sp148;
    u32 sp14C;
    u32 packedTileFormat;
    Mtx* sp154;

    s32 w0, w1;

    DefaultWindowStyle* defaultStyle = NULL;
    WindowStyleCustom* customStyle = NULL;
    s32 alpha = opacity;
    WindowCorners* corners;
    WindowBackground* background;
    u32 bgWidth, bgHeight;
    u32 cornerWidth, cornerHeight;
    s32 a3;
    s32 t0;
    s32 s6;
    Vtx* fp;
    s32 i, j, k;
    Gfx *combineMode;
    s32 tmem = 0x100;
    u32 bgScrollOffset;

    s32 n1, n2;

    if ((u32)windowStyle < 23) {
        defaultStyle = &D_801098E0[(u32)windowStyle];

        spF7 = defaultStyle->color1.r;
        spFF = defaultStyle->color1.g;
        sp107 = defaultStyle->color1.b;
        sp10F = defaultStyle->color1.a * alpha / 255;
        sp117 = defaultStyle->color2.r;
        sp11F = defaultStyle->color2.g;
        sp127 = defaultStyle->color2.b;
        sp12F = defaultStyle->color2.a;

        background = &D_8010BAE8[defaultStyle->bgIndex];
        corners = &D_8010BB00[defaultStyle->cornersIndex];
    } else {
        spF7 = windowStyle->color1.r;
        spFF = windowStyle->color1.g;
        sp107 = windowStyle->color1.b;
        sp10F = windowStyle->color1.a * alpha / 255;
        sp117 = windowStyle->color2.r;
        sp11F = windowStyle->color2.g;
        sp127 = windowStyle->color2.b;
        sp12F = windowStyle->color2.a;

        customStyle = windowStyle;
        background = &windowStyle->background;
        corners = &windowStyle->corners;
    }

    backgroundImageData = background->imgData;
    sp13C = corners->imgData;
    sp140 = background->packedTileFormatHigh;

    bgWidth = background->width;
    bgHeight = background->height;

    sp144 = _INTEGER_LOG2(bgWidth);
    s6 = _INTEGER_LOG2(bgHeight);

    fp = NULL;
    sp154 = NULL;
    sp148 = (Vec2bu*)&corners->size1;
    sp14C = corners->packedTileFormatHigh;
    packedTileFormat = corners->packedTileFormatLow;

    if (width <= 0 || height <= 0 || opacity == 0 || posX <= -768 || posY <= -768) {
        return TRUE;
    }

    if (posX >= SCREEN_WIDTH || posY >= SCREEN_HEIGHT) {
        return TRUE;
    }

    if (posX + width >= 768 || posY + height >= 768 || posX + width <= 0 || posY + height <= 0) {
        return TRUE;
    }

    if (flags & DRAW_FLAGS_ROTSCALE) {
        fp = D_8010D6B0[D_8010BBB0++].vert;
        if (D_8010BBB0 > 20) {
            D_8010BBB0  = 0;
        }
    }

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_2CYCLE);
    gDPSetBlendColor(gMasterGfxPos++, 0, 0, 0, 0);
    gDPSetFogColor(gMasterGfxPos++, 0, 0, 0, darkening);
    gDPSetRenderMode(gMasterGfxPos++, GBL_c1(G_BL_CLR_BL, G_BL_A_FOG, G_BL_CLR_IN, G_BL_1MA), G_RM_XLU_SURF2);
    if (!(flags & DRAW_FLAGS_CLIP)) {
        gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    }

    if (defaultStyle != NULL) {
        Gfx* gfxPos = gMasterGfxPos;
        *gfxPos = D_8010BB90[defaultStyle->unk_2 + (sp10F != 255 ? 2 : 0)];
    } else {
        Gfx* gfxPos = gMasterGfxPos;
        if (sp10F != 255) {
            *gfxPos = customStyle->transparentCombineMode;
        } else {
            *gfxPos = customStyle->opaqueCombineMode;
        }
    }

    gMasterGfxPos++;
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);

    if (fp) {
        gSPViewport(gMasterGfxPos++, &D_8010BBB8);
        guFrustumF(sp20, -80.0f, 80.0f, 60.0f, -60.0f, 160.0f, 480.0f, 1.0f);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        sp154 = &gDisplayContext->matrixStack[gMatrixListPos];
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        guPositionF(sp20, rotX, rotY, rotZ, 1.0f, posX + width / 2, posY + height / 2, posZ);
        if ((scaleX != 1.0f) || (scaleY != 1.0f)) {
            guScaleF(sp60, scaleX, scaleY, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
        }
        if (rotScaleMtx != 0) {
            guTranslateF(sp60, -translateX / 2, -translateY / 2, 0.0f);
            guMtxCatF(sp20, sp60, sp60);
            guMtxCatF(sp60, rotScaleMtx, sp20);
        }
        if (outMtx) {
            for (k = 0; k < 4; k++) {
                for (j = 0; j < 4; j++) {
                    outMtx[k][j] = sp20[k][j];
                }
            }
        }
        guTranslateF(sp60, -160.0f, -120.0f, -320.0f);
        guMtxCatF(sp20, sp60, sp20);
        gSPClearGeometryMode(gMasterGfxPos++, G_CULL_BOTH | G_LIGHTING);
        if (flags & DRAW_FLAGS_CULL_BACK) {
            gSPSetGeometryMode(gMasterGfxPos++, G_CULL_BACK);
        }
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
        gSPPerspNormalize(gMasterGfxPos++, 20);
    } else {
        gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
    }

    gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
    gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
    gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, spF7, spFF, sp107, sp10F);
    gDPSetEnvColor(gMasterGfxPos++, sp117, sp11F, sp127, sp12F);
    if (backgroundImageData) {
        switch (background->packedTileFormatLow) {
            case G_IM_SIZ_4b:
                gDPLoadTextureTile_4b(gMasterGfxPos++, backgroundImageData, sp140, bgWidth, bgHeight, 0, 0, bgWidth - 1, bgHeight - 1, 0, G_TX_WRAP, G_TX_WRAP, sp144, s6, G_TX_NOLOD, G_TX_NOLOD);
                break;
            case G_IM_SIZ_8b:
                gDPLoadTextureTile(gMasterGfxPos++, backgroundImageData, sp140, G_IM_SIZ_8b, bgWidth, bgHeight, 0, 0, bgWidth - 1, bgHeight - 1, 0, G_TX_WRAP, G_TX_WRAP, sp144, s6, G_TX_NOLOD, G_TX_NOLOD);
                break;
            case G_IM_SIZ_16b:
                gDPLoadTextureTile(gMasterGfxPos++, backgroundImageData, sp140, G_IM_SIZ_16b, bgWidth, bgHeight, 0, 0, bgWidth - 1, bgHeight - 1, 0, G_TX_WRAP, G_TX_WRAP, sp144, s6, G_TX_NOLOD, G_TX_NOLOD);
                break;
            case G_IM_SIZ_32b:
                gDPLoadTextureTile(gMasterGfxPos++, backgroundImageData, sp140, G_IM_SIZ_32b, bgWidth, bgHeight, 0, 0, bgWidth - 1, bgHeight - 1, 0, G_TX_WRAP, G_TX_WRAP, sp144, s6, G_TX_NOLOD, G_TX_NOLOD);
                break;
        }

        if (flags & DRAW_FLAGS_2) {
            bgScrollOffset = 511 - ((gGameStatusPtr->frameCounter * 4) & 0x1FF);
            gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE,
                (width / 2 * 4) + (bgScrollOffset),
                (height / 2 * 4) + (bgScrollOffset),
                (width / 2 + bgWidth - 1) * 4 + (bgScrollOffset),
                (height / 2 + bgHeight - 1) * 4 + (bgScrollOffset));
        } else {
            gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, (width / 2 * 4), (height / 2 * 4), (width / 2 + bgWidth - 1) * 4, (height / 2 + bgHeight - 1)* 4);
        }
    }

    if (sp13C) {
        for (i = 0; i < 4; i++) {
            cornerWidth = sp148[i].x;
            cornerHeight = sp148[i].y;
            a3 = _INTEGER_LOG2(cornerWidth);
            t0 = _INTEGER_LOG2(cornerHeight);


            switch (packedTileFormat) {
                case G_IM_SIZ_4b:
                    gDPLoadMultiTile_4b(gMasterGfxPos++, sp13C, tmem, 1, sp14C, cornerWidth, cornerHeight, 0, 0, cornerWidth - 1, cornerHeight - 1, 0, G_TX_CLAMP, G_TX_CLAMP, a3, t0, G_TX_NOLOD, G_TX_NOLOD);
                    sp13C += cornerWidth * cornerHeight / 2;
                    break;
                case G_IM_SIZ_8b:
                    gDPLoadMultiTile(gMasterGfxPos++, sp13C, tmem, 1, sp14C, G_IM_SIZ_8b, cornerWidth, cornerHeight, 0, 0, cornerWidth - 1, cornerHeight - 1, 0, G_TX_CLAMP, G_TX_CLAMP, a3, t0, G_TX_NOLOD, G_TX_NOLOD);
                    sp13C += cornerWidth * cornerHeight;
                    break;
                case G_IM_SIZ_16b:
                    gDPLoadMultiTile(gMasterGfxPos++, sp13C, tmem, 1, sp14C, G_IM_SIZ_16b, cornerWidth, cornerHeight, 0, 0, cornerWidth - 1, cornerHeight - 1, 0, G_TX_CLAMP, G_TX_CLAMP, a3, t0, G_TX_NOLOD, G_TX_NOLOD);
                    sp13C += cornerWidth * cornerHeight * 2;
                    break;
                case G_IM_SIZ_32b:
                    gDPLoadMultiTile(gMasterGfxPos++, sp13C, tmem, 1, sp14C, G_IM_SIZ_32b, cornerWidth, cornerHeight, 0, 0, cornerWidth - 1, cornerHeight - 1, 0, G_TX_CLAMP, G_TX_CLAMP, a3, t0, G_TX_NOLOD, G_TX_NOLOD);
                    sp13C += cornerWidth * cornerHeight * 4;
                    break;
            }

            switch(i) {
                case 1:
                    gDPSetTileSize(gMasterGfxPos++, 1, (width - cornerWidth) * 4, 0, (width - 1) * 4, (cornerHeight - 1) * 4);
                    break;
                case 2:
                    gDPSetTileSize(gMasterGfxPos++, 1, 0, (height - cornerHeight) * 4, (cornerWidth - 1) * 4, (height - 1) * 4);
                    break;
                case 3:
                    gDPSetTileSize(gMasterGfxPos++, 1, (width - cornerWidth) * 4, (height - cornerHeight) * 4, (width - 1) * 4, (height - 1) * 4);
                    break;
            }

            if (fp) {
                switch(i) {
                    case 0:
                        fp[0].v.ob[0] = -width / 2;
                        fp[0].v.ob[1] = -height / 2;
                        fp[0].v.ob[2] = 0;

                        fp[1].v.ob[0] = 0;
                        fp[1].v.ob[1] = -height / 2;
                        fp[1].v.ob[2] = 0;

                        fp[2].v.ob[0] = -width / 2;
                        fp[2].v.ob[1] = 0;
                        fp[2].v.ob[2] = 0;

                        fp[3].v.ob[0] = 0;
                        fp[3].v.ob[1] = 0;
                        fp[3].v.ob[2] = 0;

                        fp[0].v.tc[0] = 0;
                        fp[0].v.tc[1] = 0;

                        fp[1].v.tc[0] = (width / 2) * 32;
                        fp[1].v.tc[1] = 0;

                        fp[2].v.tc[0] = 0;
                        fp[2].v.tc[1] = (height / 2) * 32;

                        fp[3].v.tc[0] = (width / 2) * 32;
                        fp[3].v.tc[1] = (height / 2) * 32;
                        break;
                    case 1:
                        fp[4].v.ob[0] = 0;
                        fp[4].v.ob[1] = -height / 2;
                        fp[4].v.ob[2] = 0;

                        fp[5].v.ob[0] = (-width / 2) + width;
                        fp[5].v.ob[1] = -height / 2;
                        fp[5].v.ob[2] = 0;

                        fp[6].v.ob[0] = 0;
                        fp[6].v.ob[1] = 0;
                        fp[6].v.ob[2] = 0;

                        fp[7].v.ob[0] = (-width / 2) + width;
                        fp[7].v.ob[1] = 0;
                        fp[7].v.ob[2] = 0;

                        fp[4].v.tc[0] = (width / 2) * 32;
                        fp[4].v.tc[1] = 0;

                        fp[5].v.tc[0] = width * 32;
                        fp[5].v.tc[1] = 0;

                        fp[6].v.tc[0] = (width / 2) * 32;
                        fp[6].v.tc[1] = (height / 2) * 32;

                        fp[7].v.tc[0] = width * 32;
                        fp[7].v.tc[1] = (height / 2) * 32;

                        fp += 4;
                        break;
                    case 2:
                        fp[8].v.ob[0] = -width / 2;
                        fp[8].v.ob[1] = 0;
                        fp[8].v.ob[2] = 0;

                        fp[9].v.ob[0] = 0;
                        fp[9].v.ob[1] = 0;
                        fp[9].v.ob[2] = 0;

                        fp[10].v.ob[0] = -width / 2;
                        fp[10].v.ob[1] = height / 2;
                        fp[10].v.ob[2] = 0;

                        fp[11].v.ob[0] = 0;
                        fp[11].v.ob[1] = height / 2;
                        fp[11].v.ob[2] = 0;

                        fp[8].v.tc[0] = 0;
                        fp[8].v.tc[1] = (height / 2) * 32;

                        fp[9].v.tc[0] = (width / 2) * 32;
                        fp[9].v.tc[1] = (height / 2) * 32;

                        fp[10].v.tc[0] = 0;
                        fp[10].v.tc[1] = height * 32;

                        fp[11].v.tc[0] = (width / 2) * 32;
                        fp[11].v.tc[1] = height * 32;

                        fp += 8;
                        break;
                    case 3:
                        fp[12].v.ob[0] = 0;
                        fp[12].v.ob[1] = 0;
                        fp[12].v.ob[2] = 0;

                        fp[13].v.ob[0] = (-width / 2) + width;
                        fp[13].v.ob[1] = 0;
                        fp[13].v.ob[2] = 0;

                        fp[14].v.ob[0] = 0;
                        fp[14].v.ob[1] = height / 2;
                        fp[14].v.ob[2] = 0;

                        fp[15].v.ob[0] = (-width / 2) + width;
                        fp[15].v.ob[1] = height / 2;
                        fp[15].v.ob[2] = 0;

                        fp[12].v.tc[0] = (width / 2) * 32;
                        fp[12].v.tc[1] = (height / 2) * 32;

                        fp[13].v.tc[0] = width * 32;
                        fp[13].v.tc[1] = (height / 2) * 32;

                        fp[14].v.tc[0] = (width / 2) * 32;
                        fp[14].v.tc[1] = height * 32;

                        fp[15].v.tc[0] = width * 32;
                        fp[15].v.tc[1] = height * 32;

                        fp += 12;
                        break;
                }
                gSPVertex(gMasterGfxPos++, fp, 4, 0);
                gSP2Triangles(gMasterGfxPos++, 0, 3, 1, 0, 0, 2, 3, 0);
            } else {
                switch (i) {
                    case 0:
                        gSPScisTextureRectangle(gMasterGfxPos++, posX * 4, posY * 4, (posX + width / 2) * 4, (posY + height / 2) * 4, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
                        break;
                    case 1:
                        gSPScisTextureRectangle(gMasterGfxPos++, (posX + width / 2) * 4, posY * 4, (posX + width) * 4, (posY + height / 2) * 4, G_TX_RENDERTILE, (width / 2) * 32, 0, 0x400, 0x400);
                        break;
                    case 2:
                        gSPScisTextureRectangle(gMasterGfxPos++, posX * 4, (posY + height / 2) * 4, (posX + width / 2) * 4, (posY + height) * 4, G_TX_RENDERTILE, 0, (height / 2) * 32, 0x400, 0x400);
                        break;
                    case 3:
                        gSPScisTextureRectangle(gMasterGfxPos++, (posX + width / 2) * 4, (posY + height / 2) * 4, (posX + width) * 4, (posY + height) * 4, G_TX_RENDERTILE, (width / 2) * 32, (height / 2) * 32, 0x400, 0x400);
                        break;
                }

            }
            gDPPipeSync(gMasterGfxPos++);
        }
    } else if (backgroundImageData != NULL) {
        if (fp != NULL)
        {
            fp[0].v.ob[0] = -width / 2;
            fp[0].v.ob[1] = -height / 2;
            fp[0].v.ob[2] = 0;

            fp[1].v.ob[0] = (-width / 2) + width;
            fp[1].v.ob[1] = -height / 2;
            fp[1].v.ob[2] = 0;

            fp[2].v.ob[0] = -width / 2;
            fp[2].v.ob[1] = height / 2;
            fp[2].v.ob[2] = 0;

            fp[3].v.ob[0] = (-width / 2) + width;
            fp[3].v.ob[1] = height / 2;
            fp[3].v.ob[2] = 0;


            fp[0].v.tc[0] = 0;
            fp[0].v.tc[1] = 0;

            fp[1].v.tc[1] = 0;
            fp[1].v.tc[0] = width * 32;

            fp[2].v.tc[0] = 0;
            fp[2].v.tc[1] = height * 32;

            fp[3].v.tc[0] = width * 32;
            fp[3].v.tc[1] = height * 32;

            gSPVertex(gMasterGfxPos++, &fp[0], 4, 0);
            gSP2Triangles(gMasterGfxPos++, 0, 3, 1, 0, 0, 2, 3, 0);
        } else {
            gSPScisTextureRectangle(gMasterGfxPos++, posX * 4, posY * 4, (posX + width) * 4, (posY + height) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        }
        gDPPipeSync(gMasterGfxPos++);
    }

    gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    if(fpDrawContents != NULL) {
        if(fp != NULL) {
            s32 mdl_address = mdl_get_next_texture_address(width * height * 2);
            if(mdl_address != 0) {
                gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, OS_K0_TO_PHYSICAL(mdl_address));
                gDPSetScissorFrac(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, width * 4.0f, height * 4.0f);
                gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
                gDPSetFillColor(gMasterGfxPos++, PACK_FILL_COLOR(spF7, spFF, sp107, 0));
                gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
                gDPFillRectangle(gMasterGfxPos++, 0, 0, width - 1, height - 1);
                gDPPipeSync(gMasterGfxPos++);
                gDPSetScissorFrac(gMasterGfxPos++, G_SC_NON_INTERLACE, 4, 4, (width - 1) * 4.0f, (height - 1) * 4.0f);
                gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);

                fpDrawContents(drawContentsArg0, 0, 0, width, height, opacity, darkening);

                gDPPipeSync(gMasterGfxPos++);
                gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(nuGfxCfb_ptr));
                gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
                gSPViewport(gMasterGfxPos++, &D_8010BBB8);
                gSPMatrix(gMasterGfxPos++, sp154, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
                gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
                gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
                gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
                gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_NOOP2);
                gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
                gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
                guTranslateF(spA0, 0.0f, 6.0f, 0.0f);
                guMtxF2L(spA0, &D_8010BC08);
                guTranslateF(spA0, 0.0f, -height / 2, 0.0f);
                guMtxF2L(spA0, &gDisplayContext->matrixStack[gMatrixListPos]);
                gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                for (i = 0; i < height / 6; i++) {
                    s32 v0, a2;
                    if (i == height / 6 - 1) {
                        v0 = 0;
                        if (height % 6 != 0) {
                            v0 = 1;
                        }
                    } else {
                        v0 = 1;
                    }
                    a2 = v0 + 5;
                    gDPLoadTextureTile(gMasterGfxPos++, OS_K0_TO_PHYSICAL(mdl_address), G_IM_FMT_RGBA, G_IM_SIZ_16b, width, 0,
                                       0, i * 6, width - 1, i * 6 + a2, 0,
                                       G_TX_CLAMP, G_TX_CLAMP, 9, 3, G_TX_NOLOD, G_TX_NOLOD);
                    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, (160 - width / 2) * 4, 0, ((160 - width / 2) + width - 1) * 4, a2 * 4);
                    gSPVertex(gMasterGfxPos++, &vtx_drawbox1, 4, 0);
                    gSP2Triangles(gMasterGfxPos++, 0, 3, 1, 0, 0, 2, 3, 0);
                    gDPPipeSync(gMasterGfxPos++);
                    gSPMatrix(gMasterGfxPos++, &D_8010BC08, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                }
            }
        }
        else {
            fpDrawContents(drawContentsArg0, posX, posY, width, height, opacity, darkening);
        }
    }
    if (fp != NULL) {
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
        gDPPipeSync(gMasterGfxPos++);
    }
    return FALSE;
}

