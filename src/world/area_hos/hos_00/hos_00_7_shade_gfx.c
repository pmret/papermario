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
    gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, SHADE, SHADE, 0, PRIMITIVE, 0, 0, 0, 0, SHADE, SHADE, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha);
}

EvtScript N(EVS_SetupBackgroundShade) = {
    EVT_CALL(SetModelCustomGfx, MODEL_g107, CUSTOM_GFX_1, FOG_MODE_UNCHANGED)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(setup_gfx_background_shade)), NULL)
    EVT_RETURN
    EVT_END
};
