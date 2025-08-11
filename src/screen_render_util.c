#include "common.h"
#include "nu/nusys.h"

Gfx D_8014ED90[] = {
    gsSPEndDisplayList(),
};

Vp DarknessStencilViewport = {
    .vp = {
        .vscale = { 128, 128, 511, 0 },
        .vtrans = { 128, 128, 511, 0 }
    }
};

Vtx Vtx_DarknessStencil[] = {
    {{{ -16,-16, 0 }, 0, { 0x0000, 0x0000 }, { 0, 0, 0, 255 }}},
    {{{  16,-16, 0 }, 0, { 0x1000, 0x0000 }, { 0, 0, 0, 255 }}},
    {{{  16, 16, 0 }, 0, { 0x1000, 0x1000 }, { 0, 0, 0, 255 }}},
    {{{ -16, 16, 0 }, 0, { 0x0000, 0x1000 }, { 0, 0, 0, 255 }}},
};

Gfx Gfx_DarknessStencilQuad[] = {
    gsSPVertex(Vtx_DarknessStencil, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

void appendGfx_draw_prev_frame_buffer(s32 x1, s32 y1, s32 x2, s32 y2, f32 alpha) {
    s32 stripY, extraY;
    s32 i;
    u16* prevGfxCfb = nullptr;

    // round the x positions
    x1 = x1 - (x1 % 4);
    x2 = x2 - (x2 % 4) + 4;
    // can only load 6 rows of the color buffer at a time: 320*6*2 = 3840 bytes of the 4096 capacity
    stripY = (y2 - y1) / 6;
    extraY = (y2 - y1) % 6;

    // get previous color buffer
    for (i = 0; i < nuGfxCfbNum; i++) {
        if (nuGfxCfb[i] == nuGfxCfb_ptr) {
            prevGfxCfb = nuGfxCfb[(i + nuGfxCfbNum - 1) % nuGfxCfbNum];
        }
    }

    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_10, PM_CC_10);
    gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_NOISE);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
    gSPTexture(gMainGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
    gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, alpha);

    for (i = 0; i < stripY; i++) {
        gDPLoadTextureTile(gMainGfxPos++, osVirtualToPhysical(prevGfxCfb), G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 6,
                           x1, y1 + i * 6, x2 - 1, y1 + i * 6 + 5, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gMainGfxPos++, x1 * 4, (y1 + i * 6) * 4, x2 * 4, (y1 + i * 6 + 6) * 4,
                            G_TX_RENDERTILE, x1 * 32, (y1 + i * 6) * 32, 1024, 1024);
    }

    if (extraY != 0) {
        gDPLoadTextureTile(gMainGfxPos++, osVirtualToPhysical(prevGfxCfb), G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, extraY,
                           x1, y1 + i * 6, x2 - 1, y1 + i * 6 + extraY - 1, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gMainGfxPos++, x1 * 4, (y1 + i * 6) * 4, x2 * 4, (y1 + i * 6 + extraY) * 4,
                            G_TX_RENDERTILE, x1 * 32, (y1 + i * 6) * 32, 1024, 1024);
    }
}

void draw_prev_frame_buffer_at_screen_pos(s32 x1, s32 y1, s32 x2, s32 y2, f32 alpha) {
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
    if (maxY < y1) {
        minY = maxY;
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
            appendGfx_draw_prev_frame_buffer(minX, minY, maxX, maxY, alpha);
        }
    }
}

void appendGfx_darkness_stencil(bool isWorld, s32 posX, s32 posY, f32 alpha, f32 progress) {
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 texScale, f24;
    s32 i;

    if (alpha == 0.0f) {
        return;
    }

    if (!isWorld) {
        texScale = (255.0f - alpha) * 10.0f / 255.0f + 0.14;
    } else {
        texScale = 0.5f;
        texScale = (255.0f - alpha) * 9.5f / 255.0f + texScale;
        posX += (camera->viewportW / 2 - posX) * (255.0f - alpha) / 255.0f;
        posY += (camera->viewportH / 2 - posY) * (255.0f - alpha) / 255.0f;
    }

    guOrtho(&gDisplayContext->matrixStack[gMatrixListPos], -16.0f, 0.0f, 0.0f, 16.0f, -1000.0f, 1000.0f, 1.0f);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_PATTERN);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 64, osVirtualToPhysical(nuGfxZBuffer));
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, 64, 64);
    gSPViewport(gMainGfxPos++, &DarknessStencilViewport);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_CONST_1, PM_CC_CONST_1);
    guRotate(&gDisplayContext->matrixStack[gMatrixListPos], 0.0f, 0.0f, 0.0f, 1.0f);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, Gfx_DarknessStencilQuad);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_56, PM_CC_56);

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

        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, s0);
        guRotate(&gDisplayContext->matrixStack[gMatrixListPos], i * 70 + f2, 0.0f, 0.0f, 1.0f);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        guScale(&gDisplayContext->matrixStack[gMatrixListPos], f20, f20, 1.0f);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, Gfx_DarknessStencilQuad);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gDPPipeSync(gMainGfxPos++);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 64, osVirtualToPhysical(nuGfxZBuffer));
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, 64, 64);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_0F, PM_CC_0F);

    for (i = 0; i < 4; i++) {
        gDPLoadTextureTile(gMainGfxPos++, osVirtualToPhysical(&nuGfxZBuffer[i * 2048]), G_IM_FMT_RGBA, G_IM_SIZ_32b, 64, 16, 0, 0, 63, 15, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPPipeSync(gMainGfxPos++);
        gSPTextureRectangle(gMainGfxPos++, 0, (i * 16) * 4, 64 * 4, (i * 16 + 16) * 4, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
        gDPPipeSync(gMainGfxPos++);
    }

    gDPLoadTextureTile(gMainGfxPos++, osVirtualToPhysical(nuGfxZBuffer), G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, 0, 63, 63,
                       0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 6, 6, 15, 15);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, 0, 0x01FC, 0x01FC);
    gDPPipeSync(gMainGfxPos++);

    gDPSetCycleType(gMainGfxPos++, G_CYC_FILL);
    gDPSetRenderMode(gMainGfxPos++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 64, osVirtualToPhysical(nuGfxZBuffer));
    gDPSetFillColor(gMainGfxPos++, GPACK_ZDZ(G_MAXFBZ, 0)<<16 | GPACK_ZDZ(G_MAXFBZ, 0));
    gDPFillRectangle(gMainGfxPos++, 0, 0, 63, 63);
    gDPPipeSync(gMainGfxPos++);

    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetColorDither(gMainGfxPos++, G_CD_MAGICSQ);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_PATTERN);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_AVERAGE);
    gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);

    if (alpha != 255.0f || isWorld == 1) {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_57, PM_CC_57);
    } else {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_58, PM_CC_58);
    }
    alpha *= 0.5f;
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha * 0.5f * progress / 255.0f);
    gDPSetEnvColor(gMainGfxPos++, 255, 255, 255, (255.0f - alpha * 0.5f) * progress / 255.0f);

    if (!isWorld) {
        gSPTextureRectangle(gMainGfxPos++,
                            camera->viewportStartX * 4, camera->viewportStartY * 4,
                            (camera->viewportStartX + camera->viewportW) * 4, (camera->viewportStartY + camera->viewportH) * 4,
                            G_TX_RENDERTILE,
                            (12 - posX) * 32.0f / texScale + 16.0f + 1024.0f, (19 - posY) * 32.0f / texScale + 16.0f + 1024.0f,
                            1024.0f / texScale, 1024.0f / texScale);
    } else {
        gSPTextureRectangle(gMainGfxPos++,
                            camera->viewportStartX * 4, camera->viewportStartY * 4,
                            (camera->viewportStartX + camera->viewportW) * 4, (camera->viewportStartY + camera->viewportH) * 4,
                            G_TX_RENDERTILE,
                            (9 - posX) * 32.0f / texScale + 1024.0f, (32 - posY) * 32.0f / texScale + 1024.0f,
                            1024.0f / texScale, 1024.0f / texScale);
    }
}

void appendGfx_screen_transition_stencil(s32 arg0, s32 arg1, f32 progress, s32 primR, s32 primG, s32 primB, s32 primA, s32 camID) {
    s32 x1, y1, x2, y2, t5, t6;
    f32 texScale;

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

    if (progress == 0.0f) {
        return;
    }

    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);
    if (progress == 255.0f) {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_PRIM_FULL_ALPHA, PM_CC_PRIM_FULL_ALPHA);
    }
    gDPSetPrimColor(gMainGfxPos++, 0, 0, primR, primG, primB, primA);
    texScale = (255.0f - progress) * 10.5f / 255.0f + 0.09; // range from
    gSPTextureRectangle(gMainGfxPos++, x1 * 4, y1 * 4, x2 * 4, y2 * 4, G_TX_RENDERTILE,
                        (t5 - arg0) * 32.0f / texScale + 16.0f + 1024.0f, (t6 - arg1) * 32.0f / texScale + 16.0f + 1024.0f,
                        1024.0f / texScale, 1024.0f / texScale);
    gDPPipeSync(gMainGfxPos++);
}
