#include "common.h"
#include "battle/battle.h"

ApiStatus N(UnkFloatFunc4)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 prevX = evt_get_variable(script, *args++);
    s32 prevZ = evt_get_variable(script, *args++);
    s32 length = evt_get_variable(script, *args++);
    s32 angle = evt_get_variable(script, *args++);

    f32 outX = prevX + (length * cos_deg(angle));
    f32 outZ = prevZ - (length * sin_deg(angle));

    evt_set_float_variable(script, *args++, outX);
    evt_set_float_variable(script, *args++, outZ);
    return ApiStatus_DONE2;
}
