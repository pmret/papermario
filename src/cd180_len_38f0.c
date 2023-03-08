#include "common.h"
#include "overlay.h"

// BSS
extern s32 screen_overlay_frontType;
extern f32 screen_overlay_frontZoom;
extern s32 screen_overlay_backType;
extern f32 screen_overlay_backZoom;
extern s32 D_80156910;
extern ScreenOverlay D_8015C790[2];

ScreenTransition D_8014C6F0 = TRANSITION_2;

// padding?
s32 D_8014C6F4[] = { 0x00000000, 0x00000000, 0x00000000, };

#include "ui/stencil/star.png.inc.c"

#include "ui/stencil/mario.png.inc.c"

#include "ui/stencil/sharp_circle.png.inc.c"

#include "ui/stencil/blurry_circle.png.inc.c"

#include "vtx/stencil1.vtx.inc.c"

Gfx Gfx_LoadStencilTex_CommonParams[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetAlphaDither(G_AD_PATTERN),
    gsDPSetCombineLERP(0, 0, 0, PRIMITIVE, 1, TEXEL0, PRIMITIVE, TEXEL0, 0, 0, 0, PRIMITIVE, 1, TEXEL0, PRIMITIVE, TEXEL0),
    gsDPSetRenderMode(G_RM_CLD_SURF, G_RM_CLD_SURF2),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList()
};

Gfx Gfx_LoadStencilTex_SharpCircle[] = {
    gsSPDisplayList(Gfx_LoadStencilTex_CommonParams),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(ui_stencil_sharp_circle_png, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x00FC, 0x00FC),
    gsSPEndDisplayList()
};

Gfx Gfx_LoadStencilTex_Mario[] = {
    gsSPDisplayList(Gfx_LoadStencilTex_CommonParams),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(ui_stencil_mario_png, G_IM_FMT_I, 64, 0, 0, 0, 63, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList()
};

Gfx Gfx_LoadStencilTex_Star[] = {
    gsSPDisplayList(Gfx_LoadStencilTex_CommonParams),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(ui_stencil_star_png, G_IM_FMT_I, 32, 0, 0, 0, 31, 63, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x00FC, 0x00FC),
    gsSPEndDisplayList(),
};

Gfx Gfx_LoadStencilTex_BlurryCircle[] = {
    gsSPDisplayList(Gfx_LoadStencilTex_CommonParams),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b, 64, ui_stencil_blurry_circle_png),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_MIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_MIRROR | G_TX_CLAMP, 6, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x00FC, 0x00FC),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_MIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_MIRROR | G_TX_CLAMP, 6, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x00FC, 0x00FC),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x01FC, 0x01FC),
    gsSPEndDisplayList()
};

#include "vtx/stencil2.vtx.inc.c"

Gfx D_8014E8F0[] = {
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsDPSetPrimDepth(0, 0),
    gsDPSetRenderMode(Z_UPD | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_MEM, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), Z_UPD | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_MEM, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 1, 0, PRIMITIVE, 0, 0, 0, 0, SHADE, 1, 0, PRIMITIVE, 0),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK),
    gsSPVertex(&vtx_stencil1, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(0, 4, 1, 0, 3, 5, 0, 0),
    gsSP2Triangles(1, 6, 2, 0, 7, 3, 2, 0),
    gsSP2Triangles(8, 7, 2, 0, 7, 9, 3, 0),
    gsDPPipeSync(),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsSPEndDisplayList()
};

Gfx D_8014E9A8[] = {
    gsDPPipeSync(),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsDPSetPrimDepth(20, 0),
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 1, 0, PRIMITIVE, 0, 0, 0, 0, SHADE, 1, 0, PRIMITIVE, 0),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPFillRectangle(0, 0, 320, 240),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsSPEndDisplayList()
};

Gfx D_8014EA48[] = {
    gsDPSetDepthSource(G_ZS_PRIM),
    gsDPSetPrimDepth(20, 0),
    gsDPSetRenderMode(Z_CMP | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), Z_CMP | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPVertex(&vtx_stencil2, 24, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 0, 159, 11, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 11, 159, 22, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(2, 4, 3, 0, 5, 3, 4, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 22, 159, 33, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 6, 5, 0, 7, 5, 6, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 33, 159, 44, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(6, 8, 7, 0, 9, 7, 8, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 44, 159, 55, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 10, 9, 0, 11, 9, 10, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 55, 159, 66, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(10, 12, 11, 0, 13, 11, 12, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 66, 159, 77, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 14, 13, 0, 15, 13, 14, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 77, 159, 88, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(14, 16, 15, 0, 17, 15, 16, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 88, 159, 99, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(16, 18, 17, 0, 19, 17, 18, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 99, 159, 110, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(18, 20, 19, 0, 21, 19, 20, 0),
    gsDPLoadTextureTile(&D_80156910, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, 0, 110, 159, 119, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 8, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(20, 22, 21, 0, 23, 21, 22, 0),
    gsDPPipeSync(),
    gsDPSetDepthSource(G_ZS_PIXEL)
};

void _render_transition_stencil(u8 arg0, f32 arg1, ScreenOverlay* overlay) {
    Camera* camera = &gCameras[gCurrentCameraID];
    u8 s3, s4, s5;
    s32 s1, s2, s6, s7;
    f32 f28;
    s16 v0;
    s16 s0;
    Mtx* matrixStack = gDisplayContext->matrixStack;

    if (arg1 == 0.0f) {
        return;
    }

    if (overlay != NULL) {
        s3 = overlay->color.r;
        s4 = overlay->color.g;
        s5 = overlay->color.b;
        s1 = overlay->screenPos[0][0];
        s2 = overlay->screenPos[0][1];
        s6 = overlay->screenPos[1][0];
        s7 = overlay->screenPos[1][1];
        f28 = overlay->alpha;
    } else {
        s3 = s4 = s5 = 0;
        s1 = s2 = s6 = s7 = 0;
        f28 = 0.0f;
    }

    switch (arg0) {
        case 0:
            gDPPipeSync(gMainGfxPos++);
            gDPSetColorDither(gMainGfxPos++, G_CD_MAGICSQ);
            gDPSetAlphaDither(gMainGfxPos++, G_AD_PATTERN);
            gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
            if (arg1 == 255.0f) {
                gDPSetRenderMode(gMainGfxPos++, CVG_DST_SAVE | G_RM_OPA_SURF, CVG_DST_SAVE | G_RM_OPA_SURF2);
            } else {
                gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
            }
            gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, s3, s4, s5, arg1);
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            gDPFillRectangle(gMainGfxPos++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
            gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
            return;
        case 1:
            gDPPipeSync(gMainGfxPos++);
            gDPSetColorDither(gMainGfxPos++, G_CD_MAGICSQ);
            gDPSetAlphaDither(gMainGfxPos++, G_AD_PATTERN);
            gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
            if (arg1 == 255.0f) {
                gDPSetRenderMode(gMainGfxPos++, CVG_DST_SAVE | G_RM_OPA_SURF, CVG_DST_SAVE | G_RM_OPA_SURF2);
            } else {
                gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
            }
            gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, s3, s4, s5, arg1);
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            gDPFillRectangle(gMainGfxPos++, camera->viewportStartX, camera->viewportStartY,
                             camera->viewportStartX + camera->viewportW, camera->viewportStartY + camera->viewportH);
            gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
            return;
    }

    guOrtho(&matrixStack[gMatrixListPos], 0.0f, 320.0f, 0.0f, 240.0f, -1000.0f, 1000.0f, 1.0f);
    gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    switch (arg0) {
        case 4:
            gSPDisplayList(gMainGfxPos++, Gfx_LoadStencilTex_Mario);
            func_80139F10(160, 120, arg1, s3, s4, s5, arg1 * f28 / 255.0f, gCurrentCameraID);
            break;
        case 7:
            gSPDisplayList(gMainGfxPos++, Gfx_LoadStencilTex_Mario);
            func_80139F10(160, 120, arg1, s3, s4, s5, arg1 * f28 / 255.0f, -1);
            break;
        case 5:
            gSPDisplayList(gMainGfxPos++, Gfx_LoadStencilTex_Star);
            func_80139F10(160, 120, arg1, s3, s4, s5, arg1 * f28 / 255.0f, gCurrentCameraID);
            break;
        case 8:
            gSPDisplayList(gMainGfxPos++, Gfx_LoadStencilTex_Star);
            func_80139F10(160, 120, arg1, s3, s4, s5, arg1 * f28 / 255.0f, -1);
            break;
        case 3:
            gSPDisplayList(gMainGfxPos++, Gfx_LoadStencilTex_SharpCircle);
            func_80139F10(s1, s2, arg1, 0, 0, 0, 0, gCurrentCameraID);
            break;
        case 6:
            gSPDisplayList(gMainGfxPos++, Gfx_LoadStencilTex_SharpCircle);
            func_80139F10(s1, s2, arg1, 0, 0, 0, 0, -1);
            break;
        case 2:
            s0 = arg1;
            guTranslate(&matrixStack[gMatrixListPos], 80.0f, 120.0f, 0.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            guScale(&matrixStack[gMatrixListPos], (1.0f - s0 / 255.0f) * 0.8, (1.0f - s0 / 255.0f) * 0.8, 1.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            guRotate(&matrixStack[gMatrixListPos], s0 * 0.5f, 0.0f, 0.0f, 1.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_8014E8F0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

            guTranslate(&matrixStack[gMatrixListPos], 240.0f, 120.0f, 0.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            guScale(&matrixStack[gMatrixListPos], (1.0f - s0 / 255.0f) * 0.8, (1.0f - s0 / 255.0f) * 0.8, 1.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            guRotate(&matrixStack[gMatrixListPos], s0 * 0.5f, 0.0f, 0.0f, 1.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_8014E8F0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

            guTranslate(&matrixStack[gMatrixListPos], 0.0f, 0.0f, 0.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_8014EA48);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
            break;
        case 9:
            s0 = arg1;
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, 0);
            guTranslate(&matrixStack[gMatrixListPos], s1, SCREEN_HEIGHT - s2, 0.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            guScale(&matrixStack[gMatrixListPos], (1.0f - s0 / 255.0f) * 0.8, (1.0f - s0 / 255.0f) * 0.8, 1.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            guRotate(&matrixStack[gMatrixListPos], -s0, 0.0f, 0.0f, 1.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_8014E8F0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

            guTranslate(&matrixStack[gMatrixListPos], s6, SCREEN_HEIGHT - s7, 0.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            guScale(&matrixStack[gMatrixListPos], (1.0f - s0 / 255.0f) * 0.8, (1.0f - s0 / 255.0f) * 0.8, 1.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            guRotate(&matrixStack[gMatrixListPos], -s0, 0.0f, 0.0f, 1.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_8014E8F0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

            guTranslate(&matrixStack[gMatrixListPos], 0.0f, 0.0f, 0.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, f28);
            gSPDisplayList(gMainGfxPos++, D_8014E9A8);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
            break;
        case 10:
            s0 = arg1;
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, 0);
            guTranslate(&matrixStack[gMatrixListPos], s1, SCREEN_HEIGHT - s2, 0.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            guScale(&matrixStack[gMatrixListPos], (1.0f - s0 / 255.0f) * 0.8, (1.0f - s0 / 255.0f) * 0.8, 1.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            guRotate(&matrixStack[gMatrixListPos], (f32)(-s0) * 0.5, 0.0f, 0.0f, 1.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_8014E8F0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

            guTranslate(&matrixStack[gMatrixListPos], 0.0f, 0.0f, 0.0f);
            gSPMatrix(gMainGfxPos++, &matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, f28);
            gSPDisplayList(gMainGfxPos++, D_8014E9A8);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
            v0 = arg1 + 40;
            if (arg1 > 170) {
                v0 = 170;
            }
            func_80138D88(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, v0);
            break;
        case 11:
            gSPDisplayList(gMainGfxPos++, Gfx_LoadStencilTex_BlurryCircle);
            func_80138E54(1, s6, s7, f28, arg1);
            break;
        case 12:
            func_80138D88(s1, s2, s6, s7, arg1);
            break;
        case 13:
            gSPDisplayList(gMainGfxPos++, Gfx_LoadStencilTex_BlurryCircle);
            func_80138E54(0, s1, s2, f28, arg1);
            break;
        case 14:
        case 15:
            break;
    }

    gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
}

void set_screen_overlay_params_front(u8 type, f32 zoom) {
    screen_overlay_frontType = type;
    screen_overlay_frontZoom = zoom;
}

void set_screen_overlay_params_back(u8 type, f32 zoom) {
    screen_overlay_backType = type;
    screen_overlay_backZoom = zoom;
}

void get_screen_overlay_params(s32 idx, u8* type, f32* zoom) {
    switch (idx) {
        case 0:
            *type = screen_overlay_frontType;
            *zoom = screen_overlay_frontZoom;
            break;
        case 1:
            *type = screen_overlay_backType;
            *zoom = screen_overlay_backZoom;
            break;
    }
}

void set_screen_overlay_color(s32 idx, u8 r, u8 g, u8 b) {
    switch (idx) {
        case 0:
        case 1:
            D_8015C790[idx].color.r = r;
            D_8015C790[idx].color.g = g;
            D_8015C790[idx].color.b = b;
            break;
    }
}

void set_screen_overlay_center(s32 idx, s32 arg1, s32 arg2, s32 arg3) {
    switch (idx) {
        case 0:
        case 1:
            switch (arg1) {
                case 0:
                    D_8015C790[idx].screenPos[0][0] = arg2;
                    D_8015C790[idx].screenPos[0][1] = arg3;
                    break;
                case 1:
                    D_8015C790[idx].screenPos[1][0] = arg2;
                    D_8015C790[idx].screenPos[1][1] = arg3;
                    break;
            }
            break;
    }
}

void set_screen_overlay_center_worldpos(s32 idx, s32 posIdx, s32 x, s32 y, s32 z) {
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 tx, ty, tz, tw;

    switch (idx) {
        case 0:
        case 1:
            transform_point(camera->perspectiveMatrix, x, y, z, 1.0f, &tx, &ty, &tz, &tw);
            tw = 1.0f / tw;
            tx *= tw;
            ty *= -tw;
            tz *= tw;
            tx = (((tx * camera->viewportW) + camera->viewportW) * 0.5) + camera->viewportStartX;
            ty = (((ty * camera->viewportH) + camera->viewportH) * 0.5) + camera->viewportStartY;

            switch (posIdx) {
                case 0:
                    D_8015C790[idx].screenPos[0][0] = tx;
                    D_8015C790[idx].screenPos[0][1] = ty;
                    break;
                case 1:
                    D_8015C790[idx].screenPos[1][0] = tx;
                    D_8015C790[idx].screenPos[1][1] = ty;
                    break;
            }
            break;
    }
}

void set_screen_overlay_alpha(s32 idx, f32 alpha) {
    switch (idx) {
        case 0:
        case 1:
            D_8015C790[idx].alpha = alpha;
            break;
    }
}

void clear_screen_overlays(void) {
    ScreenOverlay* it;
    s32 i;

    screen_overlay_frontType = -1;
    screen_overlay_backType = -1;
    screen_overlay_frontZoom = -1.0f;
    screen_overlay_backZoom = -1.0f;

    for (it = &D_8015C790[0], i = 0; i < ARRAY_COUNT(D_8015C790); i++, it++) {
        it->color.b = 0;
        it->color.g = 0;
        it->color.r = 0;
        it->screenPos[1][1] = 0;
        it->screenPos[1][0] = 0;
        it->screenPos[0][1] = 0;
        it->screenPos[0][0] = 0;
        it->alpha = 255.0f;
    }
}

void func_80138188(void) {
    screen_overlay_backZoom = 0;
}

void func_80138198(void) {
}

void render_screen_overlay_frontUI(void) {
    if (screen_overlay_frontType != -1 && screen_overlay_frontZoom != -1.0f && gGameStatusPtr->isBattle != 2) {
        _render_transition_stencil(screen_overlay_frontType, screen_overlay_frontZoom, &D_8015C790[0]);
    }
}

void render_screen_overlay_backUI(void) {
    if (screen_overlay_backType != -1 && screen_overlay_backZoom != -1.0f && gGameStatusPtr->isBattle != 2) {
        _render_transition_stencil(screen_overlay_backType, screen_overlay_backZoom, &D_8015C790[1]);
    }
}

void set_map_transition_effect(ScreenTransition transition) {
    D_8014C6F0 = transition;
}

s16 update_exit_map_screen_overlay(s16* progress) {
    u8 overlayColor;
    u8 type = 0;
    u8 r = 0;
    u8 g = 0;
    u8 b = 0;
    s16 t = 0;
    s32 amt = 20;

    switch (D_8014C6F0) {
        case TRANSITION_1:
            type = 0;
            break;
        case TRANSITION_3:
            r = g = b = 208;
            type = 1;
            amt = 10;
            if (gGameStatusPtr->demoState == 2) {
                gGameStatusPtr->nextDemoScene = 18;
            }
            break;
        case TRANSITION_6:
            r = g = b = 208;
            type = 1;
            break;
        case TRANSITION_0:
            type = 1;
            break;
        case TRANSITION_7:
            if (gGameStatusPtr->demoState == 2) {
                gGameStatusPtr->nextDemoScene = 18;
            }
            r = g = b = 208;
            type = 1;
            amt = 7;
            break;
        case TRANSITION_11:
        case TRANSITION_15:
            r = g = b = 208;
            type = 1;
            amt = 7;
            break;
        case TRANSITION_4:
        case TRANSITION_5:
            type = 1;
            amt = 7;
            break;
        case TRANSITION_14:
            r = g = b = 208;
            type = 1;
            amt = 50;
            break;
        case TRANSITION_2:
            type = 1;
            amt = 50;
            break;
        case TRANSITION_8:
            set_screen_overlay_alpha(0, 0.0f);
            type = 4;
            break;
        case TRANSITION_9:
            r = g = b = 208;
            set_screen_overlay_alpha(0, 0.0f);
            type = 4;
            amt = 7;
            break;
        case TRANSITION_10:
            set_screen_overlay_alpha(0, 0.0f);
            type = 4;
            amt = 7;
            break;
        case TRANSITION_12:
            set_screen_overlay_alpha(0, 160.0f);
            r = g = b = 208;
            type = 5;
            amt = 7;
            break;
        case TRANSITION_13:
            set_screen_overlay_alpha(0, 0.0f);
            type = 5;
            amt = 7;
            break;
        case TRANSITION_16:
            set_screen_overlay_center(0, 0, 15, 28);
            set_screen_overlay_center(0, 1, 305, 156);
            set_screen_overlay_params_front(12, 255.0f);
            *progress = 0xFF;
            return 1;
    }

    if (D_8014C6F0 == TRANSITION_5) {
        overlayColor = ((255 - *progress) * 208) / 255;
        set_screen_overlay_color(0, overlayColor, overlayColor, overlayColor);
        set_screen_overlay_params_front(type, 255.0f);
        if (*progress == 0xFF) {
            return 1;
        }

        *progress += amt;
        if (*progress > 0xFF) {
            *progress = 0xFF;
        }
    } else {
        set_screen_overlay_color(t, r, g, b);

        if (t == 0) {
            set_screen_overlay_params_front(type, *progress);
        } else {
            set_screen_overlay_params_back(type, *progress);
        }

        if (*progress == 0xFF) {
            return 1;
        }

        *progress += amt;
        if (*progress > 0xFF) {
            *progress = 0xFF;
        }
    }
    return 0;
}

s16 update_enter_map_screen_overlay(s16* progress) {
    u8 frontType = 0;
    s32 amt = 20;
    u8 ret = FALSE;

    switch (D_8014C6F0) {
        case TRANSITION_3:
            set_screen_overlay_color(0, 208, 208, 208);
            amt = 50;
            break;
        case TRANSITION_2:
            frontType = 1;
            amt = 50;
            break;
        case TRANSITION_4:
        case TRANSITION_5:
        case TRANSITION_7:
        case TRANSITION_9:
        case TRANSITION_10:
            frontType = 1;
            amt = 7;
            break;
        case TRANSITION_0:
        case TRANSITION_1:
        case TRANSITION_6:
        case TRANSITION_13:
        case TRANSITION_14:
            frontType = 1;
            break;
        case TRANSITION_8:
        case TRANSITION_15:
            frontType = 4;
            break;
        case TRANSITION_11:
            frontType = 5;
            amt = 7;
            break;
        case TRANSITION_12:
            frontType = 4;
            amt = 7;
            break;
        case TRANSITION_16:
            set_screen_overlay_center(0, 0, 15, 28);
            set_screen_overlay_center(0, 1, 305, 156);
            set_screen_overlay_params_front(12, *progress);
            amt = 2;
            break;
    }

    if (D_8014C6F0 != TRANSITION_16) {
        set_screen_overlay_params_front(frontType, *progress);
    }

    if (*progress == 0) {
        ret = TRUE;
    }

    *progress -= amt;

    if (*progress < 0) {
        *progress = 0;
    }

    return ret;
}
