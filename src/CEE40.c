#include "common.h"
#include "nu/nusys.h"

void func_80138740(s32 x1, s32 y1, s32 x2, s32 y2, f32 alpha) {
    s32 t9, sp10;
    s32 i;
    u16* prevGfxCfb = NULL;

    x1 -= x1 % 4;
    x2 = x2 - x2 % 4 + 4;
    t9 = (y2 - y1) / 6;
    sp10 = (y2 - y1) % 6;

    for (i = 0; i < nuGfxCfbNum; i++) {
        if (nuGfxCfb[i] == nuGfxCfb_ptr) {
            prevGfxCfb = nuGfxCfb[(i + nuGfxCfbNum - 1) % nuGfxCfbNum];
        }
    }

    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
    gDPSetAlphaDither(gMasterGfxPos++, G_AD_NOISE);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
    gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
    gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
    gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 255, alpha);

    for (i = 0; i < t9; i++) {
        gDPLoadTextureTile(gMasterGfxPos++, osVirtualToPhysical(prevGfxCfb), G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0,
                           x1, y1 + i * 6, x2 - 1, y1 + i * 6 + 5, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gMasterGfxPos++, x1 * 4, (y1 + i * 6) * 4, x2 * 4, (y1 + i * 6 + 6) * 4,
                            G_TX_RENDERTILE, x1 * 32, (y1 + i * 6) * 32, 1024, 1024);
    }

    if (sp10 != 0) {
        gDPLoadTextureTile(gMasterGfxPos++, osVirtualToPhysical(prevGfxCfb), G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0,
                           x1, y1 + i * 6, x2 - 1, y1 + i * 6 + sp10 - 1, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gMasterGfxPos++, x1 * 4, (y1 + i * 6) * 4, x2 * 4, (y1 + i * 6 + sp10) * 4,
                            G_TX_RENDERTILE, x1 * 32, (y1 + i * 6) * 32, 1024, 1024);
    }
}

void func_80138D88(s32 x1, s32 y1, s32 x2, s32 y2, f32 alpha) {
    s32 minX;
    s32 minY;
    s32 maxX;
    s32 maxY;

    maxX = x2;
    maxY = y2;
    if (maxX < x1) {
        minX = maxX;
        maxX = x1;
    } else {
        minX = x1;
    }
    minY = maxY;
    if (maxY < y1) {
        maxY = y1;
    } else {
        minY = y1;
    }
    if (minX < maxX && minY < maxY) {
        if (minX < 0) {
            minX = 0;
        }
        if (minY < 0) {
            minY = 0;
        }
        if (maxX < 0) {
            maxX = 0;
        }
        if (maxY < 0) {
            maxY = 0;
        }
        if (minX >= SCREEN_WIDTH) {
            minX = SCREEN_WIDTH - 1;
        }
        if (minY >= SCREEN_HEIGHT) {
            minY = SCREEN_HEIGHT - 1;
        }
        if (maxX >= SCREEN_WIDTH) {
            maxX = SCREEN_WIDTH - 1;
        }
        if (maxY >= SCREEN_HEIGHT) {
            maxY = SCREEN_HEIGHT - 1;
        }
        if (minX != maxX && minY != maxY) {
            func_80138740(minX, minY, maxX, maxY, alpha);
        }
    }
}

INCLUDE_ASM(s32, "CEE40", func_80138E54);

void func_80139F10(s32 arg0, s32 arg1, f32 alpha, s32 primR, s32 primG, s32 primB, s32 primA, s32 camID) {
    s32 x1, y1, x2, y2, t5, t6;
    f32 f4;

    if (camID >= 0) {
        x1 = gCameras[camID].viewportStartX;
        y1 = gCameras[camID].viewportStartY;
        x2 = gCameras[camID].viewportStartX + gCameras[camID].viewportW;
        y2 = gCameras[camID].viewportStartY + gCameras[camID].viewportH;
        t5 = x1;
        t6 = y1;
    } else {
        x1 = 0;
        y1 = 0;
        x2 = SCREEN_WIDTH;
        y2 = SCREEN_HEIGHT;
        t5 = 0;
        t6 = 0;
    }

    if (alpha == 0.0f) {
        return;
    }

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);
    if (alpha == 255.0f) {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1);
    }
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, primR, primG, primB, primA);
    f4 = (255.0f - alpha) * 10.5f / 255.0f + 0.09;
    gSPTextureRectangle(gMasterGfxPos++, x1 * 4, y1 * 4, x2 * 4, y2 * 4, G_TX_RENDERTILE,
                        (t5 - arg0) * 32.0f / f4 + 16.0f + 1024.0f, (t6 - arg1) * 32.0f / f4 + 16.0f + 1024.0f,
                        1024.0f / f4, 1024.0f / f4);
    gDPPipeSync(gMasterGfxPos++);
}
