#include "iwa_11.h"

#include "common/UnkFloatFunc.inc.c"

ApiStatus func_802401B0_926BA0(Evt* script) {
    f32 angle = clamp_angle(script->varTable[2] * -2.4f);
    
    evt_set_float_variable(script, LW(0), angle);
    return ApiStatus_DONE2;
}

ApiStatus func_80240208_926BF8(Evt* script,  s32 isInitialCall) {
    f32 angle = clamp_angle(script->varTable[2] * -2.4f * 0.6f);
    
    evt_set_float_variable(script, LW(0), angle);
    return ApiStatus_DONE2;
}
