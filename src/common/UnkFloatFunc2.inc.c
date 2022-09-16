#include "common.h"
#include "npc.h"

ApiStatus N(UnkFloatFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 a1 = *args++;
    s32 a2 = *args++;
    s32 a3 = *args++;
    f32 temp = sin_rad(DEG_TO_RAD(var0 / 10) * 8.0f) * 10.0f;

    evt_set_variable(script, a1, 0);
    evt_set_variable(script, a2, temp);
    evt_set_variable(script, a3, 0);

    return ApiStatus_DONE2;
}
