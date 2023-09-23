#include "common.h"
#include "theater/walls.png.h"
#include "theater/curtains.png.h"
#include "theater/floor.png.h"
#include "ui/no_controller.png.h"
#include "ld_addrs.h"
#include "nu/nusys.h"
#include "game_modes.h"

#include "theater/walls.png.inc.c"

Gfx D_800746E0[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock_4b(theater_walls_png, G_IM_FMT_I, 16, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

#include "theater/curtains.png.inc.c"

Gfx D_80075730[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(theater_curtains_png, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

#include "theater/floor.png.inc.c"
#include "theater/floor.pal.inc.c"

Gfx D_800758A0[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, theater_floor_pal),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock_4b(theater_floor_png, G_IM_FMT_CI, 32, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR |
                            G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

#include "theater/left_wall_vtx.vtx.inc.c"
#include "theater/right_wall_vtx.vtx.inc.c"
#include "theater/floor_vtx.vtx.inc.c"
#include "theater/left_inset_shadow_vtx.vtx.inc.c"
#include "theater/right_inset_shadow_vtx.vtx.inc.c"
#include "theater/curtain_vtx.vtx.inc.c"
#include "theater/wall_shadows_vtx.vtx.inc.c"

Gfx TheaterWallShadowsGfx[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_PASS, G_RM_CLD_SURF2),
    gsDPSetCombineMode(G_CC_MODULATEIA, PM_CC_16),
    gsSPDisplayList(D_80075730),
    gsSPVertex(theater_wall_shadows_vtx, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx TheaterCurtainGfx[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
    gsSPDisplayList(D_80075730),
    gsSPVertex(theater_curtain_vtx, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(15, 16, 17, 0, 15, 17, 18, 0),
    gsSP2Triangles(19, 20, 21, 0, 19, 21, 22, 0),
    gsSP2Triangles(13, 23, 24, 0, 13, 24, 14, 0),
    gsSP2Triangles(23, 25, 26, 0, 23, 26, 24, 0),
    gsSP2Triangles(25, 27, 28, 0, 25, 28, 26, 0),
    gsSP2Triangles(27, 29, 30, 0, 27, 30, 28, 0),
    gsSPEndDisplayList(),
};

Gfx TheaterInsetShadowsGfx[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPVertex(theater_left_inset_shadow_vtx, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPVertex(theater_right_inset_shadow_vtx, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx TheaterFloorGfx[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(CVG_DST_FULL | ZMODE_OPA | FORCE_BL | G_RM_PASS, CVG_DST_FULL | ZMODE_OPA | FORCE_BL |
                      GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)),
    gsDPSetCombineMode(G_CC_MODULATEIA, PM_CC_16),
    gsSPDisplayList(D_800746E0),
    gsSPVertex(theater_floor_vtx, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 0, 0, 4, 0, 3, 0),
    gsSP2Triangles(1, 6, 7, 0, 1, 7, 2, 0),
    gsSP2Triangles(3, 8, 9, 0, 3, 9, 10, 0),
    gsSP2Triangles(11, 4, 3, 0, 11, 3, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(8, 12, 15, 0, 8, 15, 9, 0),
    gsSP2Triangles(6, 16, 13, 0, 6, 13, 7, 0),
    gsSP2Triangles(14, 17, 18, 0, 19, 14, 18, 0),
    gsSP2Triangles(20, 11, 21, 0, 11, 22, 21, 0),
    gsSP2Triangles(23, 19, 18, 0, 23, 18, 24, 0),
    gsSP2Triangles(22, 23, 24, 0, 22, 24, 21, 0),
    gsSPEndDisplayList(),
};

Gfx TheaterRightWallGfx[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(CVG_DST_FULL | ZMODE_OPA | FORCE_BL | G_RM_PASS, CVG_DST_FULL | ZMODE_OPA | FORCE_BL |
                      GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)),
    gsDPSetCombineMode(G_CC_MODULATEIA, PM_CC_16),
    gsSPDisplayList(D_800758A0),
    gsSPVertex(theater_right_wall_vtx, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSPEndDisplayList(),
};

Gfx TheaterLeftWallGfx[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(CVG_DST_FULL | ZMODE_OPA | FORCE_BL | G_RM_PASS, CVG_DST_FULL | ZMODE_OPA | FORCE_BL |
                      GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)),
    gsDPSetCombineMode(G_CC_MODULATEIA, PM_CC_16),
    gsSPDisplayList(D_800758A0),
    gsSPVertex(theater_left_wall_vtx, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSPEndDisplayList(),
};

Gfx TheaterGfx[] ={
    gsSPDisplayList(TheaterFloorGfx),
    gsSPDisplayList(TheaterLeftWallGfx),
    gsSPDisplayList(TheaterRightWallGfx),
    gsSPDisplayList(TheaterInsetShadowsGfx),
    gsSPDisplayList(TheaterWallShadowsGfx),
    gsSPDisplayList(TheaterCurtainGfx),
    gsSPEndDisplayList(),
};

Vp TheaterViewport = {
    {
        {(SCREEN_WIDTH/2)*4, (SCREEN_HEIGHT/2)*4, 0x200 - 1, 0},
        {(SCREEN_WIDTH/2)*4, (SCREEN_HEIGHT/2)*4, 0x200 - 1, 0},
    }
};

Gfx TheaterInitGfx[] = {
    gsSPViewport(&TheaterViewport),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 320, 240),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetAlphaDither(G_AD_PATTERN),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPPerspNormalize(0x0014),
    gsSPEndDisplayList(),
};

#include "ui/no_controller.png.inc.c"

Gfx NoControllerSetupTexGfx[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile(ui_no_controller_png, G_IM_FMT_IA, G_IM_SIZ_8b, ui_no_controller_png_width,
                        ui_no_controller_png_height, 0, 0, ui_no_controller_png_width - 1,
                        ui_no_controller_png_height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 7,
                        5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx NoControllerGfx[] = {
    gsSPTextureRectangle(0x0180, 0x0260, 0x0380, 0x02E0, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

SHIFT_BSS Mtx D_8009BAA8[2];
SHIFT_BSS f32 gCurtainScale;
SHIFT_BSS f32 gCurtainScaleGoal;
SHIFT_BSS f32 gCurtainFade;
SHIFT_BSS f32 gCurtainFadeGoal;
SHIFT_BSS UNK_FUN_PTR(gCurtainDrawCallback);

void initialize_curtains(void) {
    gCurtainDrawCallback = NULL;
    gCurtainScale = 2.0f;
    gCurtainScaleGoal = 2.0f;
    gCurtainFade = 0.0f;
    gCurtainFadeGoal = 0.0f;
}

void update_curtains(void) {
}

void render_curtains(void) {
    if (gCurtainScaleGoal != gCurtainScale) {
        gCurtainScale += (gCurtainScaleGoal - gCurtainScale) * 0.1;
    }

    if (gCurtainFadeGoal != gCurtainFade) {
        gCurtainFade += (gCurtainFadeGoal - gCurtainFade) * 0.03;
    }

    if (gCurtainScale < 1.9) {
        Matrix4f m;
        f32 scale;
        s8 rgb;

        gDPPipeSync(gMainGfxPos++);
        gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
        gSPDisplayList(gMainGfxPos++, &TheaterInitGfx);

        guFrustumF(m, -80.0f, 80.0f, -60.0f, 60.0f, 160.0f, 640.0f, 1.0f);
        guMtxF2L(m, &D_8009BAA8[0]);

        gSPMatrix(gMainGfxPos++, &D_8009BAA8[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

        scale = gCurtainScale - 0.01;
        if (scale < 1.0f) {
            scale = 1.0f;
        }

        guPositionF(m, 0.0f, 0.0f, 0.0f, scale * 0.1, 0.0f, 0.0f, -320.0f);

        guMtxF2L(m, &D_8009BAA8[1]);

        gSPMatrix(gMainGfxPos++, &D_8009BAA8[1], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        rgb = 255.0f - (gCurtainFade * 255.0f);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, rgb, rgb, rgb, 255);
        gSPDisplayList(gMainGfxPos++, &TheaterGfx);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        gDPPipeSync(gMainGfxPos++);
    }

    if (gCurtainDrawCallback != NULL) {
        gCurtainDrawCallback();
    }

    if (!(gGameStatusPtr->contBitPattern & 1)) {
        if ((get_game_mode() == GAME_MODE_INTRO)
                || (get_game_mode() == GAME_MODE_TITLE_SCREEN)
                || (gGameStatusPtr->demoState != DEMO_STATE_NONE)) {
            s32 alpha = ((gGameStatusPtr->frameCounter) % 0x18) << 5;

            if (alpha > 255) {
                alpha = 255;
            }

            gSPDisplayList(gMainGfxPos++, &TheaterInitGfx);
            gSPDisplayList(gMainGfxPos++, &NoControllerSetupTexGfx);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0xFF, 0x20, 0x10, alpha);
            gSPDisplayList(gMainGfxPos++, &NoControllerGfx);
        }
    }
}

void set_curtain_scale_goal(f32 scale) {
    gCurtainScaleGoal = scale;
}

void set_curtain_scale(f32 scale) {
    gCurtainScaleGoal = scale;
    gCurtainScale = scale;
}

void set_curtain_draw_callback(UNK_FUN_PTR(callback)) {
    gCurtainDrawCallback = callback;
}

void set_curtain_fade_goal(f32 fade) {
    gCurtainFadeGoal = fade;
}

void set_curtain_fade(f32 fade) {
    gCurtainFadeGoal = fade;
    gCurtainFade = fade;
}
