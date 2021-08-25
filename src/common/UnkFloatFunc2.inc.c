#include "common.h"
#include "map.h"

ApiStatus N(UnkFloatFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 a1 = *args++;
    s32 a2 = *args++;
    s32 a3 = *args++;
    f32 temp = sin_rad(var0 / 10 * 6.28318f / 360.0f * 8.0f) * 10.0f;

    set_variable(script, a1, 0);
    set_variable(script, a2, temp);
    set_variable(script, a3, 0);

    return ApiStatus_DONE2;
}
