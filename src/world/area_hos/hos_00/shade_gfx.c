#include "hos_00.h"

void N(setup_gfx_background_shade)(void) {
    s32 alpha = update_lerp(EASING_LINEAR, 0.0f, 216.0f, gPlayerStatus.pos.x - 200.0f, 500);

    if (alpha < 0) {
        alpha = 0;
    }
    if (alpha > 216) {
        alpha = 216;
    }
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_HOS_BG_SHADE, PM_CC_HOS_BG_SHADE);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha);
}

EvtScript N(EVS_SetupBackgroundShade) = {
    Call(SetModelCustomGfx, MODEL_g107, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(setup_gfx_background_shade)), nullptr)
    Return
    End
};
