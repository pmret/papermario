#include "common.h"

extern s32 D_800760C0;
extern Mtx D_8009BAA8[];

extern s32 D_80076078;
extern s32 D_80077140;
extern s32 D_800771E8;

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
        gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_8009A64C));
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
