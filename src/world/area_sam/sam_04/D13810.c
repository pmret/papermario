#include "sam_04.h"

ApiStatus func_80240240_D13810 (Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var = *args++;
    f32 x1 = evt_get_float_variable(script, *args++);
    f32 z1 = evt_get_float_variable(script, *args++);
    f32 x2 = evt_get_float_variable(script, *args++);
    f32 z2 = evt_get_float_variable(script, *args++);    
    f32 angle = clamp_angle(atan2(x1, z1, x2, z2));

    evt_set_float_variable(script, var, angle);
    return ApiStatus_DONE2;
}
