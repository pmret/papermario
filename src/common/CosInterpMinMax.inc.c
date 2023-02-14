#include "common.h"
#include "npc.h"

API_CALLABLE(N(CosInterpMinMax)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVarTime = *args++;
    s32 time = evt_get_variable(script, outVarTime);
    s32 outValue = *args++;
    f32 min = evt_get_float_variable(script, *args++);
    f32 max = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    s32 onlyOnce = evt_get_variable(script, *args++);
    f32 phaseOffset = (evt_get_float_variable(script, *args++) / 180.0f) * PI;
    f32 delta = (max - min) / 2;

    if (onlyOnce && duration < time) {
        time = duration;
        evt_set_variable(script, outVarTime, duration);
    }

    evt_set_float_variable(script, outValue,
        (min + delta) // average value
        - (delta * cos_rad(((time * PI) / duration) + phaseOffset))); // perturbation

    return ApiStatus_DONE2;
}
