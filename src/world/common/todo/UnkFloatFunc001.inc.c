#include "common.h"
#include "npc.h"

// Similar to CosInterpMinMax
API_CALLABLE(N(UnkFloatFunc001)) {
    Bytecode* args = script->ptrReadPos;
    s32 a1 = *args++;
    s32 var0 = evt_get_variable(script, a1);
    s32 a2 = *args++;
    f32 var1 = evt_get_float_variable(script, *args++);
    f32 var2 = evt_get_float_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);
    f32 temp = evt_get_float_variable(script, *args++);
    f32 diff = (var2 - var1) / 2;

    if (var4 != 0 && var3 < var0) {
        var0 = var3;
        evt_set_variable(script, a1, var3);
    }

    evt_set_float_variable(script, a2, (var1 + diff) - (diff * cos_deg(((var0 * 180.0f) / var3) + temp)));
    return ApiStatus_DONE2;
}
