#include "hos_04.h"

u16 N(FountainPumpPhase) = 0;

void N(setup_gfx_fountain_water)(void) {
    f32 temp_f0 = ((sin_rad(N(FountainPumpPhase) * (1 / 32.0f)) + 1.0f) * 0.25f) + 0.75;

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], (temp_f0 * 0.3) + 0.5, temp_f0, (temp_f0 * 0.3) + 0.5);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    N(FountainPumpPhase)++;
}

void N(setup_gfx_fountain_stars)(void) {
    f64 t1 = (sin_rad(N(FountainPumpPhase) * (1 / 32.0f)) * 10.0f) + 1.5;
    f64 t2 = sin_rad(N(FountainPumpPhase) * 0.25f) * 2.5;

    guTranslate(&gDisplayContext->matrixStack[gMatrixListPos], 0.0f, t1 + t2, 0.0f);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_SetupFountains) = {
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  100,  -80,  -50,  120)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0,-2000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_o438, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o462, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o469, TRUE)
    EVT_CALL(SetModelCustomGfx, MODEL_o469, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o462, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o465, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o461, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_fountain_water)), NULL)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(setup_gfx_fountain_stars)), NULL)
    EVT_RETURN
    EVT_END
};
