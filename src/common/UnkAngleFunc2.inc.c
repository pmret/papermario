#include "common.h"

ApiStatus N(UnkAngleFunc2)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 var0 =  get_variable(script, *args++) / 10.0;
    s32 a3 = *args++;
    s32 a4 = *args++;
    s32 a5 = *args++;
    s32 a6 = *args++;
    f32 temp1 = var0 * TAU / 360.0f;
    f32 fout1 = sin_rad(temp1) * 150.0f + 0.0f;
    f32 fout2 = sin_rad(temp1 * 8.0f) * 10.0f + 0.0f;
    f32 fout3 = cos_rad(temp1) * 150.0f / 20.0f + -50.0f;
    s32 outVal;

    set_float_variable(script, a3, fout1);
    set_float_variable(script, a4, fout2);
    set_float_variable(script, a5, fout3);

    outVal = 0;
    if (var0 > 90.0f && var0 < 270.0f) {
        outVal = 180;
    }
    if ((s32)fabsf(90.0f - var0) < 45) {
        outVal = 2.0f * (var0 - 45.0f);
    }
    if ((s32)fabsf(270.0f - var0) < 45) {
        outVal = 2.0f * (var0 - 225.0f) + 180.0f;
    }
    set_variable(script, a6, outVal);

    return ApiStatus_DONE2;
}
