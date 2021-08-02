#include "common.h"
#include "ui/no_controller.png.h"
#include "ld_addrs.h"
#include "nu/nusys.h"

extern s32 D_80076078;
extern s32 D_800760C0;

Gfx D_80077140[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, ui_no_controller_png_width, ui_no_controller_png),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 16, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_CLAMP, 7, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x01FC, 0x007C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 16, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_CLAMP, 7, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x01FC, 0x007C),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

Gfx D_800771E8[] = {
    gsSPTextureRectangle(0x0180, 0x0260, 0x0380, 0x02E0, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

// BSS
extern Mtx D_8009BAA8[];

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
        Mtx m;
        f32 scale;
        s8 rgb;

        gDPPipeSync(gMasterGfxPos++);
        gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
        gSPDisplayList(gMasterGfxPos++, &D_800760C0);

        guFrustumF(m.m[0], -80.0f, 80.0f, -60.0f, 60.0f, 160.0f, 640.0f, 1.0f);
        guMtxF2L(m.m[0], &D_8009BAA8[0]);

        gSPMatrix(gMasterGfxPos++, &D_8009BAA8[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

        scale = gCurtainScale - 0.01;
        if (scale < 1.0f) {
            scale = 1.0f;
        }

        guPositionF(m.m[0], 0.0f, 0.0f, 0.0f, scale * 0.1, 0.0f, 0.0f, -320.0f);

        guMtxF2L(m.m[0], &D_8009BAA8[1]);

        gSPMatrix(gMasterGfxPos++, &D_8009BAA8[1], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        rgb = 255.0f - (gCurtainFade * 255.0f);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, rgb, rgb, rgb, 255);
        gSPDisplayList(gMasterGfxPos++, &D_80076078);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        gDPPipeSync(gMasterGfxPos++);
    }

    if (gCurtainDrawCallback != NULL) {
        gCurtainDrawCallback();
    }

    if (!(gGameStatusPtr->contBitPattern & 1)) {
        if ((get_game_mode() == 0x10) || (get_game_mode() == 2) || (gGameStatusPtr->demoState != 0)) {
            s32 alpha = ((gGameStatusPtr->frameCounter) % 0x18) << 5;

            if (alpha > 255) {
                alpha = 255;
            }

            gSPDisplayList(gMasterGfxPos++, &D_800760C0);
            gSPDisplayList(gMasterGfxPos++, &D_80077140);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0xFF, 0x20, 0x10, alpha);
            gSPDisplayList(gMasterGfxPos++, &D_800771E8);
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
