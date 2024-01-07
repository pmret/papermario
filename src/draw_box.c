#include "common.h"
#include "nu/nusys.h"
#include "include_asset.h"

#define INTEGER_LOG2(x) ((x) <= 1 ? 0 : (x) <= 2 ? 1 : (x) <= 4 ? 2 : (x) <= 8 ? 3 : (x) <= 16 ? 4 : (x) <= 32 ? 5 : (x) <= 64 ? 6 : (x) <= 128 ? 7 : (x) <= 256 ? 8 : (x) <= 512 ? 9 : 10)

typedef struct DefaultWindowStyle {
    /* 0x00 */ u8 bgIndex;
    /* 0x01 */ u8 cornersIndex;
    /* 0x02 */ u8 combineModeIndex;
    /* 0x03 */ Color_RGBA8 color1;
    /* 0x07 */ Color_RGBA8 color2;
} DefaultWindowStyle; // size = 0x0B

#define BOX_QUAD_BUFFER_NUM 21
SHIFT_BSS Vtx gBoxQuadBuffer[BOX_QUAD_BUFFER_NUM][16];

DefaultWindowStyle gBoxDefaultStyles[] = {
    {
        .bgIndex = 1,
        .cornersIndex = 0,
        .combineModeIndex = 0,
        .color1 = { .r = 200, .g = 191, .b = 164, .a = 255 },
        .color2 = { .r = 128, .g = 128, .b = 128, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 1,
        .combineModeIndex = 1,
        .color1 = { .r = 255, .g = 200, .b = 128, .a = 255 },
        .color2 = { .r = 128, .g = 128, .b = 128, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 2,
        .combineModeIndex = 1,
        .color1 = { .r = 232, .g = 196, .b = 77, .a = 255 },
        .color2 = { .r = 163, .g = 123, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 0,
        .cornersIndex = 3,
        .combineModeIndex = 1,
        .color1 = { .r = 226, .g = 225, .b = 216, .a = 255 },
        .color2 = { .r = 217, .g = 208, .b = 201, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 61, .g = 74, .b = 188, .a = 255 },
        .color2 = { .r = 0, .g = 25, .b = 28, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 5,
        .combineModeIndex = 1,
        .color1 = { .r = 235, .g = 230, .b = 119, .a = 255 },
        .color2 = { .r = 142, .g = 90, .b = 37, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 6,
        .combineModeIndex = 1,
        .color1 = { .r = 235, .g = 230, .b = 119, .a = 255 },
        .color2 = { .r = 142, .g = 99, .b = 37, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 215, .g = 191, .b = 116, .a = 255 },
        .color2 = { .r = 132, .g = 70, .b = 50, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 215, .g = 191, .b = 116, .a = 255 },
        .color2 = { .r = 132, .g = 70, .b = 50, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 141, .g = 143, .b = 255, .a = 255 },
        .color2 = { .r = 43, .g = 69, .b = 102, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 8,
        .combineModeIndex = 1,
        .color1 = { .r = 141, .g = 143, .b = 255, .a = 255 },
        .color2 = { .r = 43, .g = 69, .b = 102, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 170, .g = 208, .b = 128, .a = 255 },
        .color2 = { .r = 71, .g = 123, .b = 83, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 8,
        .combineModeIndex = 1,
        .color1 = { .r = 170, .g = 208, .b = 128, .a = 255 },
        .color2 = { .r = 71, .g = 123, .b = 83, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 200, .g = 200, .b = 90, .a = 255 },
        .color2 = { .r = 140, .g = 140, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 8,
        .combineModeIndex = 1,
        .color1 = { .r = 200, .g = 200, .b = 90, .a = 255 },
        .color2 = { .r = 140, .g = 140, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 235, .g = 230, .b = 119, .a = 255 },
        .color2 = { .r = 142, .g = 90, .b = 37, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 142, .g = 212, .b = 236, .a = 255 },
        .color2 = { .r = 67, .g = 98, .b = 69, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 167, .g = 151, .b = 119, .a = 255 },
        .color2 = { .r = 98, .g = 55, .b = 154, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 7,
        .combineModeIndex = 1,
        .color1 = { .r = 17, .g = 151, .b = 29, .a = 255 },
        .color2 = { .r = 8, .g = 55, .b = 14, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 7,
        .combineModeIndex = 1,
        .color1 = { .r = 110, .g = 110, .b = 200, .a = 255 },
        .color2 = { .r = 10, .g = 10, .b = 100, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 181, .g = 60, .b = 60, .a = 255 },
        .color2 = { .r = 76, .g = 10, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .combineModeIndex = 1,
        .color1 = { .r = 174, .g = 227, .b = 235, .a = 255 },
        .color2 = { .r = 76, .g = 110, .b = 60, .a = 255 }
    },
    {
        .bgIndex = 0,
        .cornersIndex = 3,
        .combineModeIndex = 1,
        .color1 = { .r = 126, .g = 125, .b = 216, .a = 255 },
        .color2 = { .r = 217, .g = 108, .b = 201, .a = 255 }
    }
};

INCLUDE_IMG("ui/box/corners9.png", ui_box_corners9_png);
INCLUDE_IMG("ui/box/corners8.png", ui_box_corners8_png);
INCLUDE_IMG("ui/box/corners6.png", ui_box_corners6_png);
INCLUDE_IMG("ui/box/corners7.png", ui_box_corners7_png);
INCLUDE_IMG("ui/box/corners3.png", ui_box_corners3_png);
INCLUDE_IMG("ui/box/corners5.png", ui_box_corners5_png);
INCLUDE_IMG("ui/box/corners4.png", ui_box_corners4_png);
INCLUDE_IMG("ui/box/bg_tile.png", ui_box_bg_tile_png);
INCLUDE_IMG("ui/box/corners1.png", ui_box_corners1_png);
INCLUDE_IMG("ui/box/corners2.png", ui_box_corners2_png);
INCLUDE_IMG("ui/box/bg_flat.png", ui_box_bg_flat_png);

WindowBackground gBoxBackground[] = {
    {
        .imgData = ui_box_bg_tile_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0},
        .size = 128
    },
    {
        .imgData = ui_box_bg_flat_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .width = 16,
        .height = 1,
        .unk_07 = { 0, 0, 0, 0},
        .size = 8
    }
};

WindowCorners gBoxCorners[] = {
    {
        .imgData = ui_box_corners1_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 16, 16},
        .size2 = { 16, 16},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners2_png,
        .fmt = G_IM_FMT_I,
        .bitDepth = G_IM_SIZ_4b,
        .size1 = { 16, 16},
        .size2 = { 16, 16},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners3_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 16, 32},
        .size2 = { 16, 32},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners4_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 8, 8},
        .size2 = { 8, 8},
        .size3 = { 8, 8},
        .size4 = { 8, 8},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners5_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 16, 8},
        .size2 = { 16, 8},
        .size3 = { 16, 8},
        .size4 = { 16, 8},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners6_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 16, 8},
        .size2 = { 16, 8},
        .size3 = { 16, 8},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners7_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 16, 8},
        .size2 = { 16, 8},
        .size3 = { 16, 8},
        .size4 = { 16, 8},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners8_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 24, 24},
        .size2 = { 24, 24},
        .size3 = { 24, 24},
        .size4 = { 24, 24},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_box_corners9_png,
        .fmt = G_IM_FMT_IA,
        .bitDepth = G_IM_SIZ_8b,
        .size1 = { 16, 16},
        .size2 = { 16, 16},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    }
};

Gfx gBoxCombineModes[] = {
    gsDPSetCombineMode(PM_CC_BOX1_OPAQUE, PM_CC_BOX1_CYC2),
    gsDPSetCombineMode(PM_CC_BOX2_OPAQUE, PM_CC_BOX2_CYC2),
    gsDPSetCombineMode(PM_CC_BOX1_TRANSPARENT, PM_CC_BOX1_CYC2),
    gsDPSetCombineMode(PM_CC_BOX2_TRANSPARENT, PM_CC_BOX2_CYC2)
};

s32 gBoxQuadIndex = 0;

Vp gBoxViewport = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 }
    }
};

#include "vtx/drawbox1.vtx.inc.c"

Mtx gBoxMatrix = RDP_MATRIX(
    0.000000, 0.000000, 0.000000, -6.000000,
    0.000000, 0.000000, 0.000000,  0.000000,
    0.000000, 0.000000, 0.000000,  0.000000,
    0.000000, 0.000000, 0.000000,  0.000000
);

// @bug there's an issue with the way the "quads" temp below is used, sometimes going out of bounds.
// In vanilla, this results in some data being written to an unused struct field inside gPartnerStatus, which doesn't
// cause any issues. In shiftable builds, there's no telling where quads might be, so we make some adjustments to
// prevent the overflow
s32 draw_box(s32 flags, WindowStyle windowStyle, s32 posX, s32 posY, s32 posZ, s32 width, s32 height, u8 opacity,
              u8 darkening, f32 scaleX, f32 scaleY, f32 rotX, f32 rotY, f32 rotZ,
              void (*fpDrawContents)(s32, s32, s32, s32, s32, s32, s32), void* drawContentsArg0, Matrix4f rotScaleMtx,
              s32 translateX, s32 translateY, Matrix4f outMtx)
{
    Matrix4f mtx1, mtx2, mtx3;
    u8 primR, primG, primB, primA, envR, envG, envB, envA;
    DefaultWindowStyle* defaultStyle = NULL;
    WindowStyleCustom* customStyle = NULL;
    WindowCorners* corners;
    WindowBackground* background;
    u32 bgWidth, bgHeight;
    u32 cornerWidth, cornerHeight;
    s32 masks, maskt;
    Vtx* quads;
    s32 idx;
    s32 i, j;
    s32 tmem = 0x100;
    u32 bgScrollOffsetX, bgScrollOffsetY;

    s32 foo;
    s32 alpha = foo * opacity / 255;

    if (windowStyle.defaultStyleID <= WINDOW_STYLE_MAX && windowStyle.defaultStyleID >= 0) {
        defaultStyle = &gBoxDefaultStyles[windowStyle.defaultStyleID];

        primR = defaultStyle->color1.r;
        primG = defaultStyle->color1.g;
        primB = defaultStyle->color1.b;
        primA = defaultStyle->color1.a * opacity / 255;
        envR = defaultStyle->color2.r;
        envG = defaultStyle->color2.g;
        envB = defaultStyle->color2.b;
        envA = defaultStyle->color2.a;

        background = &gBoxBackground[defaultStyle->bgIndex];
        corners = &gBoxCorners[defaultStyle->cornersIndex];
    } else {
        primR = windowStyle.customStyle->color1.r;
        primG = windowStyle.customStyle->color1.g;
        primB = windowStyle.customStyle->color1.b;
        primA = windowStyle.customStyle->color1.a * opacity / 255;
        envR = windowStyle.customStyle->color2.r;
        envG = windowStyle.customStyle->color2.g;
        envB = windowStyle.customStyle->color2.b;
        envA = windowStyle.customStyle->color2.a;

        customStyle = windowStyle.customStyle;
        background = &windowStyle.customStyle->background;
        corners = &windowStyle.customStyle->corners;
    }
    {
        u8* bgImage;
        u8* cornersImage;
        s32 bgFmt;
        s32 bgMasks;
        s32 bgMaskt;
        Vec2bu* cornersSizes;
        u32 cornersFmt;
        u32 cornersBitDepth;
        Mtx* sp154;

        bgFmt = background->fmt;
        cornersImage = corners->imgData;

        do {} while (0);

        bgWidth = background->width;
        bgImage = background->imgData;
        bgHeight = background->height;

        bgMasks = INTEGER_LOG2(bgWidth);
        bgMaskt = INTEGER_LOG2(bgHeight);

        quads = NULL;
        sp154 = NULL;
        cornersSizes = (Vec2bu*)&corners->size1;
        cornersFmt = corners->fmt;
        cornersBitDepth = corners->bitDepth;

        if (width <= 0 || height <= 0 || opacity == 0 || posX <= -768 || posY <= -768) {
            return TRUE;
        }

        if (posX >= SCREEN_WIDTH || posY >= SCREEN_HEIGHT) {
            return TRUE;
        }

        if (posX + width >= 768 || posY + height >= 768 || posX + width <= 0 || posY + height <= 0) {
            return TRUE;
        }

        if (flags & DRAW_FLAG_ROTSCALE) {
            quads = gBoxQuadBuffer[gBoxQuadIndex++];
            if (gBoxQuadIndex > BOX_QUAD_BUFFER_NUM - 1) {
                gBoxQuadIndex = 0;
            }
        }

        gDPPipeSync(gMainGfxPos++);
        gDPSetCycleType(gMainGfxPos++, G_CYC_2CYCLE);
        gDPSetBlendColor(gMainGfxPos++, 0, 0, 0, 0);
        gDPSetFogColor(gMainGfxPos++, 0, 0, 0, darkening);
        gDPSetRenderMode(gMainGfxPos++, PM_RM_TILEMODE_B, G_RM_XLU_SURF2);
        if (!(flags & DRAW_FLAG_NO_CLIP)) {
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        }

        if (defaultStyle != NULL) {
            Gfx* gfxPos = gMainGfxPos;
            *gfxPos = gBoxCombineModes[defaultStyle->combineModeIndex + (primA != 255 ? 2 : 0)];
        } else {
            Gfx* gfxPos = gMainGfxPos;
            if (primA != 255) {
                *gfxPos = customStyle->transparentCombineMode;
            } else {
                *gfxPos = customStyle->opaqueCombineMode;
            }
        }

        gMainGfxPos++;
        gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);

        if (quads != NULL) {
            gSPViewport(gMainGfxPos++, &gBoxViewport);
            guFrustumF(mtx1, -80.0f, 80.0f, 60.0f, -60.0f, 160.0f, 480.0f, 1.0f);
            guMtxF2L(mtx1, &gDisplayContext->matrixStack[gMatrixListPos]);
            sp154 = &gDisplayContext->matrixStack[gMatrixListPos];
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            guPositionF(mtx1, rotX, rotY, rotZ, 1.0f, posX + width / 2, posY + height / 2, posZ);
            if (scaleX != 1.0f || scaleY != 1.0f) {
                guScaleF(mtx2, scaleX, scaleY, 1.0f);
                guMtxCatF(mtx2, mtx1, mtx1);
            }
            if (rotScaleMtx != 0) {
                guTranslateF(mtx2, -translateX / 2, -translateY / 2, 0.0f);
                guMtxCatF(mtx1, mtx2, mtx2);
                guMtxCatF(mtx2, rotScaleMtx, mtx1);
            }
            if (outMtx) {
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        outMtx[i][j] = mtx1[i][j];
                    }
                }
            }
            guTranslateF(mtx2, -160.0f, -120.0f, -320.0f);
            guMtxCatF(mtx1, mtx2, mtx1);
            gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH | G_LIGHTING);
            if (flags & DRAW_FLAG_CULL_BACK) {
                gSPSetGeometryMode(gMainGfxPos++, G_CULL_BACK);
            }
            guMtxF2L(mtx1, &gDisplayContext->matrixStack[gMatrixListPos]);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
            gSPPerspNormalize(gMainGfxPos++, 20);
        } else {
            gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
        }

        gSPTexture(gMainGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
        gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
        gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, primR, primG, primB, primA);
        gDPSetEnvColor(gMainGfxPos++, envR, envG, envB, envA);
        if (bgImage != NULL) {
            switch (background->bitDepth) {
                case G_IM_SIZ_4b:
                    gDPLoadTextureTile_4b(gMainGfxPos++, bgImage, bgFmt, bgWidth, bgHeight, 0, 0, bgWidth - 1, bgHeight - 1, 0, G_TX_WRAP, G_TX_WRAP, bgMasks, bgMaskt, G_TX_NOLOD, G_TX_NOLOD);
                    break;
                case G_IM_SIZ_8b:
                    gDPLoadTextureTile(gMainGfxPos++, bgImage, bgFmt, G_IM_SIZ_8b, bgWidth, bgHeight, 0, 0, bgWidth - 1, bgHeight - 1, 0, G_TX_WRAP, G_TX_WRAP, bgMasks, bgMaskt, G_TX_NOLOD, G_TX_NOLOD);
                    break;
                case G_IM_SIZ_16b:
                    gDPLoadTextureTile(gMainGfxPos++, bgImage, bgFmt, G_IM_SIZ_16b, bgWidth, bgHeight, 0, 0, bgWidth - 1, bgHeight - 1, 0, G_TX_WRAP, G_TX_WRAP, bgMasks, bgMaskt, G_TX_NOLOD, G_TX_NOLOD);
                    break;
                case G_IM_SIZ_32b:
                    gDPLoadTextureTile(gMainGfxPos++, bgImage, bgFmt, G_IM_SIZ_32b, bgWidth, bgHeight, 0, 0, bgWidth - 1, bgHeight - 1, 0, G_TX_WRAP, G_TX_WRAP, bgMasks, bgMaskt, G_TX_NOLOD, G_TX_NOLOD);
                    break;
            }

            if (flags & DRAW_FLAG_ANIMATED_BACKGROUND) {
                bgScrollOffsetY = (gGameStatusPtr->frameCounter * 4) & 0x1FF;
                bgScrollOffsetX = 511 - bgScrollOffsetY;
                gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE,
                    width / 2 * 4 + bgScrollOffsetX,
                    height / 2 * 4 + bgScrollOffsetY,
                    (width / 2 + bgWidth - 1) * 4 + bgScrollOffsetX,
                    (height / 2 + bgHeight - 1) * 4 + bgScrollOffsetY);
            } else {
                gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, width / 2 * 4, height / 2 * 4,
                               (width / 2 + bgWidth - 1) * 4, (height / 2 + bgHeight - 1)* 4);
            }
        }

        if (cornersImage != NULL) {
            for (idx = 0; idx < 4; idx++) {
                cornerWidth = cornersSizes[idx].x;
                cornerHeight = cornersSizes[idx].y;
                masks = INTEGER_LOG2(cornerWidth);
                maskt = INTEGER_LOG2(cornerHeight);


                switch (cornersBitDepth) {
                    case G_IM_SIZ_4b:
                        gDPLoadMultiTile_4b(gMainGfxPos++, cornersImage, tmem, 1, cornersFmt, cornerWidth, cornerHeight, 0, 0, cornerWidth - 1, cornerHeight - 1, 0, G_TX_CLAMP, G_TX_CLAMP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                        cornersImage += cornerWidth * cornerHeight / 2;
                        break;
                    case G_IM_SIZ_8b:
                        gDPLoadMultiTile(gMainGfxPos++, cornersImage, tmem, 1, cornersFmt, G_IM_SIZ_8b, cornerWidth, cornerHeight, 0, 0, cornerWidth - 1, cornerHeight - 1, 0, G_TX_CLAMP, G_TX_CLAMP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                        cornersImage += cornerWidth * cornerHeight;
                        break;
                    case G_IM_SIZ_16b:
                        gDPLoadMultiTile(gMainGfxPos++, cornersImage, tmem, 1, cornersFmt, G_IM_SIZ_16b, cornerWidth, cornerHeight, 0, 0, cornerWidth - 1, cornerHeight - 1, 0, G_TX_CLAMP, G_TX_CLAMP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                        cornersImage += cornerWidth * cornerHeight * 2;
                        break;
                    case G_IM_SIZ_32b:
                        gDPLoadMultiTile(gMainGfxPos++, cornersImage, tmem, 1, cornersFmt, G_IM_SIZ_32b, cornerWidth, cornerHeight, 0, 0, cornerWidth - 1, cornerHeight - 1, 0, G_TX_CLAMP, G_TX_CLAMP, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                        cornersImage += cornerWidth * cornerHeight * 4;
                        break;
                }

                switch(idx) {
                    case 1:
                        gDPSetTileSize(gMainGfxPos++, 1, (width - cornerWidth) * 4, 0, (width - 1) * 4, (cornerHeight - 1) * 4);
                        break;
                    case 2:
                        gDPSetTileSize(gMainGfxPos++, 1, 0, (height - cornerHeight) * 4, (cornerWidth - 1) * 4, (height - 1) * 4);
                        break;
                    case 3:
                        gDPSetTileSize(gMainGfxPos++, 1, (width - cornerWidth) * 4, (height - cornerHeight) * 4, (width - 1) * 4, (height - 1) * 4);
                        break;
                }

                if (quads != NULL) {
                    switch(idx) {
                        case 0:
                            quads[0].v.ob[0] = -width / 2;
                            quads[0].v.ob[1] = -height / 2;
                            quads[0].v.ob[2] = 0;

                            quads[1].v.ob[0] = 0;
                            quads[1].v.ob[1] = -height / 2;
                            quads[1].v.ob[2] = 0;

                            quads[2].v.ob[0] = -width / 2;
                            quads[2].v.ob[1] = 0;
                            quads[2].v.ob[2] = 0;

                            quads[3].v.ob[0] = 0;
                            quads[3].v.ob[1] = 0;
                            quads[3].v.ob[2] = 0;

                            quads[0].v.tc[0] = 0;
                            quads[0].v.tc[1] = 0;

                            quads[1].v.tc[0] = (width / 2) * 32;
                            quads[1].v.tc[1] = 0;

                            quads[2].v.tc[0] = 0;
                            quads[2].v.tc[1] = (height / 2) * 32;

                            quads[3].v.tc[0] = (width / 2) * 32;
                            quads[3].v.tc[1] = (height / 2) * 32;
                            break;
                        case 1:
                            quads[4].v.ob[0] = 0;
                            quads[4].v.ob[1] = -height / 2;
                            quads[4].v.ob[2] = 0;

                            quads[5].v.ob[0] = (-width / 2) + width;
                            quads[5].v.ob[1] = -height / 2;
                            quads[5].v.ob[2] = 0;

                            quads[6].v.ob[0] = 0;
                            quads[6].v.ob[1] = 0;
                            quads[6].v.ob[2] = 0;

                            quads[7].v.ob[0] = (-width / 2) + width;
                            quads[7].v.ob[1] = 0;
                            quads[7].v.ob[2] = 0;

                            quads[4].v.tc[0] = (width / 2) * 32;
                            quads[4].v.tc[1] = 0;

                            quads[5].v.tc[0] = width * 32;
                            quads[5].v.tc[1] = 0;

                            quads[6].v.tc[0] = (width / 2) * 32;
                            quads[6].v.tc[1] = (height / 2) * 32;

                            quads[7].v.tc[0] = width * 32;
                            quads[7].v.tc[1] = (height / 2) * 32;

#ifndef SHIFT
                            quads += 4;
#endif
                            break;
                        case 2:
                            quads[8].v.ob[0] = -width / 2;
                            quads[8].v.ob[1] = 0;
                            quads[8].v.ob[2] = 0;

                            quads[9].v.ob[0] = 0;
                            quads[9].v.ob[1] = 0;
                            quads[9].v.ob[2] = 0;

                            quads[10].v.ob[0] = -width / 2;
                            quads[10].v.ob[1] = height / 2;
                            quads[10].v.ob[2] = 0;

                            quads[11].v.ob[0] = 0;
                            quads[11].v.ob[1] = height / 2;
                            quads[11].v.ob[2] = 0;

                            quads[8].v.tc[0] = 0;
                            quads[8].v.tc[1] = (height / 2) * 32;

                            quads[9].v.tc[0] = (width / 2) * 32;
                            quads[9].v.tc[1] = (height / 2) * 32;

                            quads[10].v.tc[0] = 0;
                            quads[10].v.tc[1] = height * 32;

                            quads[11].v.tc[0] = (width / 2) * 32;
                            quads[11].v.tc[1] = height * 32;

#ifndef SHIFT
                            quads += 8;
#endif
                            break;
                        case 3:
                            quads[12].v.ob[0] = 0;
                            quads[12].v.ob[1] = 0;
                            quads[12].v.ob[2] = 0;

                            quads[13].v.ob[0] = (-width / 2) + width;
                            quads[13].v.ob[1] = 0;
                            quads[13].v.ob[2] = 0;

                            quads[14].v.ob[0] = 0;
                            quads[14].v.ob[1] = height / 2;
                            quads[14].v.ob[2] = 0;

                            quads[15].v.ob[0] = (-width / 2) + width;
                            quads[15].v.ob[1] = height / 2;
                            quads[15].v.ob[2] = 0;

                            quads[12].v.tc[0] = (width / 2) * 32;
                            quads[12].v.tc[1] = (height / 2) * 32;

                            quads[13].v.tc[0] = width * 32;
                            quads[13].v.tc[1] = (height / 2) * 32;

                            quads[14].v.tc[0] = (width / 2) * 32;
                            quads[14].v.tc[1] = height * 32;

                            quads[15].v.tc[0] = width * 32;
                            quads[15].v.tc[1] = height * 32;

#ifndef SHIFT
                            quads += 12;
#endif
                            break;
                    }
#ifdef SHIFT
                    gSPVertex(gMainGfxPos++, &quads[idx*4], 4, 0);
#else
                    gSPVertex(gMainGfxPos++, quads, 4, 0);
#endif
                    gSP2Triangles(gMainGfxPos++, 0, 3, 1, 0, 0, 2, 3, 0);
                } else {
                    switch (idx) {
                        case 0:
                            gSPScisTextureRectangle(gMainGfxPos++, posX * 4, posY * 4, (posX + width / 2) * 4, (posY + height / 2) * 4, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
                            break;
                        case 1:
                            gSPScisTextureRectangle(gMainGfxPos++, (posX + width / 2) * 4, posY * 4, (posX + width) * 4, (posY + height / 2) * 4, G_TX_RENDERTILE, (width / 2) * 32, 0, 0x400, 0x400);
                            break;
                        case 2:
                            gSPScisTextureRectangle(gMainGfxPos++, posX * 4, (posY + height / 2) * 4, (posX + width / 2) * 4, (posY + height) * 4, G_TX_RENDERTILE, 0, (height / 2) * 32, 0x400, 0x400);
                            break;
                        case 3:
                            gSPScisTextureRectangle(gMainGfxPos++, (posX + width / 2) * 4, (posY + height / 2) * 4, (posX + width) * 4, (posY + height) * 4, G_TX_RENDERTILE, (width / 2) * 32, (height / 2) * 32, 0x400, 0x400);
                            break;
                    }

                }
                gDPPipeSync(gMainGfxPos++);
            }
        } else if (bgImage != NULL) {
            if (quads != NULL) {
                quads[0].v.ob[0] = -width / 2;
                quads[0].v.ob[1] = -height / 2;
                quads[0].v.ob[2] = 0;

                quads[1].v.ob[0] = (-width / 2) + width;
                quads[1].v.ob[1] = -height / 2;
                quads[1].v.ob[2] = 0;

                quads[2].v.ob[0] = -width / 2;
                quads[2].v.ob[1] = height / 2;
                quads[2].v.ob[2] = 0;

                quads[3].v.ob[0] = (-width / 2) + width;
                quads[3].v.ob[1] = height / 2;
                quads[3].v.ob[2] = 0;


                quads[0].v.tc[0] = 0;
                quads[0].v.tc[1] = 0;

                quads[1].v.tc[1] = 0;
                quads[1].v.tc[0] = width * 32;

                quads[2].v.tc[0] = 0;
                quads[2].v.tc[1] = height * 32;

                quads[3].v.tc[0] = width * 32;
                quads[3].v.tc[1] = height * 32;

                gSPVertex(gMainGfxPos++, &quads[0], 4, 0);
                gSP2Triangles(gMainGfxPos++, 0, 3, 1, 0, 0, 2, 3, 0);
            } else {
                gSPScisTextureRectangle(gMainGfxPos++, posX * 4, posY * 4, (posX + width) * 4, (posY + height) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
            }
            gDPPipeSync(gMainGfxPos++);
        }

        gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
        gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
        if(fpDrawContents != NULL) {
            if (quads != NULL) {
                void* mdl_address = mdl_get_next_texture_address(width * height * 2);
                if(mdl_address != 0) {
                    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, OS_K0_TO_PHYSICAL(mdl_address));
                    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, width, height);
                    gDPSetCycleType(gMainGfxPos++, G_CYC_FILL);
                    gDPSetFillColor(gMainGfxPos++, PACK_FILL_COLOR(primR, primG, primB, 0));
                    gDPSetRenderMode(gMainGfxPos++, G_RM_NOOP, G_RM_NOOP2);
                    gDPFillRectangle(gMainGfxPos++, 0, 0, width - 1, height - 1);
                    gDPPipeSync(gMainGfxPos++);
                    gDPSetScissorFrac(gMainGfxPos++, G_SC_NON_INTERLACE, 4, 4, (width - 1) * 4.0f, (height - 1) * 4.0f);
                    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);

                    fpDrawContents((s32)drawContentsArg0, 0, 0, width, height, opacity, darkening);

                    gDPPipeSync(gMainGfxPos++);
                    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(nuGfxCfb_ptr));
                    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
                    gSPViewport(gMainGfxPos++, &gBoxViewport);
                    gSPMatrix(gMainGfxPos++, sp154, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
                    gSPTexture(gMainGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
                    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
                    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
                    gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                    gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_NOOP2);
                    gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
                    gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
                    guTranslateF(mtx3, 0.0f, 6.0f, 0.0f);
                    guMtxF2L(mtx3, &gBoxMatrix);
                    guTranslateF(mtx3, 0.0f, -height / 2, 0.0f);
                    guMtxF2L(mtx3, &gDisplayContext->matrixStack[gMatrixListPos]);
                    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                    for (idx = 0; idx < height / 6; idx++) {
                        s32 extraHeight, lineHeight;
                        if (idx == height / 6 - 1) {
                            extraHeight = 0;
                            if (height % 6 != 0) {
                                extraHeight = 1;
                            }
                        } else {
                            extraHeight = 1;
                        }
                        lineHeight = extraHeight + 5;
                        gDPLoadTextureTile(gMainGfxPos++, OS_K0_TO_PHYSICAL(mdl_address), G_IM_FMT_RGBA, G_IM_SIZ_16b, width, 0,
                                        0, idx * 6, width - 1, idx * 6 + lineHeight, 0,
                                        G_TX_CLAMP, G_TX_CLAMP, 9, 3, G_TX_NOLOD, G_TX_NOLOD);
                        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, (160 - width / 2) * 4, 0, ((160 - width / 2) + width - 1) * 4, lineHeight * 4);
                        gSPVertex(gMainGfxPos++, &vtx_drawbox1, 4, 0);
                        gSP2Triangles(gMainGfxPos++, 0, 3, 1, 0, 0, 2, 3, 0);
                        gDPPipeSync(gMainGfxPos++);
                        gSPMatrix(gMainGfxPos++, &gBoxMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                    }
                }
            } else {
                fpDrawContents((s32)drawContentsArg0, posX, posY, width, height, opacity, darkening);
            }
        }
        if (quads != NULL) {
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
            gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
            gDPPipeSync(gMainGfxPos++);
        }
        return FALSE;
    }
}
