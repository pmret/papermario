#include "jan_13.h"

static char* N(exit_str_0) = "jan_14";
static char* N(exit_str_1) = "jan_12";

extern u16 D_80240850_B77000;

void func_80240000_B767B0(void) {
    f64 temp_f20 = ((sin_rad((f32) D_80240850_B77000 * 0.02) + 1.0f) * 0.3) + 0.6;
    f64 temp_f21 = (sin_rad((f32) D_80240850_B77000 * 0.1) + 1.0f) * 0.1;
    f32 scale = temp_f20 + temp_f21;

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], (scale * 0.3) + 0.5, scale, (scale * 0.3) + 0.5);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80240850_B77000++;
}

ApiStatus func_802401AC_B7695C(Evt* script, s32 isInitialCall) {
    script->varTable[2] = EVT_FLOAT_TO_FIXED(script->varTable[1] / 100.0f);
    script->varTable[3] = EVT_FLOAT_TO_FIXED(script->varTable[1] / 100.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80240214_B769C4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_4E, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802402B8_B76A68(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 vt0 = script->varTable[0];
    s32 vt2 = script->varTable[2];

    if (script->varTable[1] >= -99) {
        f32 theta = (playerStatus->targetYaw / 180.0f) * 3.141592f;

        vt0 -= (s32) (sin_rad(theta) * 25.0f);
        vt2 -= (s32) (-cos_rad(theta) * 25.0f);
    } else {
        vt2 += 25;
    }
    script->varTable[0] = vt0;
    script->varTable[2] = vt2;
    return ApiStatus_DONE2;
}

#include "common/foliage.inc.c"

