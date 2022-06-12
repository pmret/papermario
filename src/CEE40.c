#include "common.h"
#include "nu/nusys.h"

Gfx D_8014ED90[] = {
    gsSPEndDisplayList(),
};

Vp D_8014ED98 = {
    .vp = {
        .vscale = { 128, 128, 511, 0 },
        .vtrans = { 128, 128, 511, 0 }
    }
};

Vtx D_8014EDA8[4] = {
    {{{ -16,-16, 0 }, 0, { 0x0000, 0x0000 }, { 0, 0, 0, 255 }}},
    {{{  16,-16, 0 }, 0, { 0x1000, 0x0000 }, { 0, 0, 0, 255 }}},
    {{{  16, 16, 0 }, 0, { 0x1000, 0x1000 }, { 0, 0, 0, 255 }}},
    {{{ -16, 16, 0 }, 0, { 0x0000, 0x1000 }, { 0, 0, 0, 255 }}},
};

Gfx D_8014EDE8[] = {
    gsSPVertex(D_8014EDA8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

void func_80138740(s32 x1, s32 y1, s32 x2, s32 y2, f32 arg4) {
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
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 255, arg4);

    for (i = 0; i < t9; i++) {
        gDPLoadTextureTile(gMasterGfxPos++, osVirtualToPhysical(prevGfxCfb), G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 6,
                           x1, y1 + i * 6, x2 - 1, y1 + i * 6 + 5, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gMasterGfxPos++, x1 * 4, (y1 + i * 6) * 4, x2 * 4, (y1 + i * 6 + 6) * 4,
                            G_TX_RENDERTILE, x1 * 32, (y1 + i * 6) * 32, 1024, 1024);
    }

    if (sp10 != 0) {
        gDPLoadTextureTile(gMasterGfxPos++, osVirtualToPhysical(prevGfxCfb), G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, sp10,
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

void func_80138E54(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4) {
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 f22, f24;
    s32 i;

    if (arg3 == 0.0f) {
        return;
    }

    if (arg0 == 0) {
        f22 = (255.0f - arg3) * 10.0f / 255.0f + 0.14;
    } else {
        f22 = 0.5f;
        f22 = (255.0f - arg3) * 9.5f / 255.0f + f22;
        arg1 += (camera->viewportW / 2 - arg1) * (255.0f - arg3) / 255.0f;
        arg2 += (camera->viewportH / 2 - arg2) * (255.0f - arg3) / 255.0f;
    }

    guOrtho(&gDisplayContext->matrixStack[gMatrixListPos], -16.0f, 0.0f, 0.0f, 16.0f, -1000.0f, 1000.0f, 1.0f);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPSetAlphaDither(gMasterGfxPos++, G_AD_PATTERN);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 64, osVirtualToPhysical(nuGfxZBuffer));
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, 64, 64);
    gSPViewport(gMasterGfxPos++, &D_8014ED98);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1);
    guRotate(&gDisplayContext->matrixStack[gMatrixListPos], 0.0f, 0.0f, 0.0f, 1.0f);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_8014EDE8);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 0, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, 0, 0, PRIMITIVE, TEXEL0, PRIMITIVE, 0);

    for (i = 0; i < 2; i++) {
        f32 f20;
        f32 f2;
        s32 s0 = 255;

        if (i == 0) {
            f20 = 0.9 - sin_deg(gGameStatusPtr->frameCounter) * 0.05;
        } else {
            f20 = 0.9 - sin_deg(gGameStatusPtr->frameCounter * 2 + i * 40) * 0.07;
        }
        f2 = 0;
        if (s0 > 255) {
            s0 = 255;
        }

        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 255, 255, s0);
        guRotate(&gDisplayContext->matrixStack[gMatrixListPos], i * 70 + f2, 0.0f, 0.0f, 1.0f);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        guScale(&gDisplayContext->matrixStack[gMatrixListPos], f20, f20, 1.0f);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_8014EDE8);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gDPPipeSync(gMasterGfxPos++);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 64, osVirtualToPhysical(nuGfxZBuffer));
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, 64, 64);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, 0, 0, 0, 1, 0, 0, 0, TEXEL0, 0, 0, 0, 1);

    for (i = 0; i < 4; i++) {
        gDPLoadTextureTile(gMasterGfxPos++, osVirtualToPhysical(&nuGfxZBuffer[i * 2048]), G_IM_FMT_RGBA, G_IM_SIZ_32b, 64, 16, 0, 0, 63, 15, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPPipeSync(gMasterGfxPos++);
        gSPTextureRectangle(gMasterGfxPos++, 0, (i * 16) * 4, 64 * 4, (i * 16 + 16) * 4, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
        gDPPipeSync(gMasterGfxPos++);
    }

    gDPLoadTextureTile(gMasterGfxPos++, osVirtualToPhysical(nuGfxZBuffer), G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, 0, 63, 63,
                       0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 6, 6, 15, 15);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 0x01FC, 0x01FC);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 64, osVirtualToPhysical(nuGfxZBuffer));
    gDPSetFillColor(gMasterGfxPos++, GPACK_ZDZ(G_MAXFBZ, 0)<<16 | GPACK_ZDZ(G_MAXFBZ, 0));
    gDPFillRectangle(gMasterGfxPos++, 0, 0, 63, 63);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetColorDither(gMasterGfxPos++, G_CD_MAGICSQ);
    gDPSetAlphaDither(gMasterGfxPos++, G_AD_PATTERN);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_AVERAGE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);

    if (arg3 != 255.0f || arg0 == 1) {
        gDPSetCombineLERP(gMasterGfxPos++, 1, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, ENVIRONMENT, PRIMITIVE, 1, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, ENVIRONMENT, PRIMITIVE);
    } else {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 0, 1, 0, ENVIRONMENT, PRIMITIVE, 0, 0, 0, 0, 1, 0, ENVIRONMENT, PRIMITIVE);
    }
    arg3 *= 0.5f;
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, arg3 * 0.5f * arg4 / 255.0f);
    gDPSetEnvColor(gMasterGfxPos++, 255, 255, 255, (255.0f - arg3 * 0.5f) * arg4 / 255.0f);

    if (arg0 == 0) {
        gSPTextureRectangle(gMasterGfxPos++,
                            camera->viewportStartX * 4, camera->viewportStartY * 4,
                            (camera->viewportStartX + camera->viewportW) * 4, (camera->viewportStartY + camera->viewportH) * 4,
                            G_TX_RENDERTILE,
                            (12 - arg1) * 32.0f / f22 + 16.0f + 1024.0f, (19 - arg2) * 32.0f / f22 + 16.0f + 1024.0f,
                            1024.0f / f22, 1024.0f / f22);
    } else {
        gSPTextureRectangle(gMasterGfxPos++,
                            camera->viewportStartX * 4, camera->viewportStartY * 4,
                            (camera->viewportStartX + camera->viewportW) * 4, (camera->viewportStartY + camera->viewportH) * 4,
                            G_TX_RENDERTILE,
                            (9 - arg1) * 32.0f / f22 + 1024.0f, (32 - arg2) * 32.0f / f22 + 1024.0f,
                            1024.0f / f22, 1024.0f / f22);
    }
}

void func_80139F10(s32 arg0, s32 arg1, f32 alpha, s32 primR, s32 primG, s32 primB, s32 primA, s32 camID) {
    s32 x1, y1, x2, y2, t5, t6;
    f32 scale;

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
    scale = (255.0f - alpha) * 10.5f / 255.0f + 0.09;
    gSPTextureRectangle(gMasterGfxPos++, x1 * 4, y1 * 4, x2 * 4, y2 * 4, G_TX_RENDERTILE,
                        (t5 - arg0) * 32.0f / scale + 16.0f + 1024.0f, (t6 - arg1) * 32.0f / scale + 16.0f + 1024.0f,
                        1024.0f / scale, 1024.0f / scale);
    gDPPipeSync(gMasterGfxPos++);
}
