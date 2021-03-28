#include "common.h"
#include "map.h"

ApiStatus N(DeadUnkFloatFunc)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a1 = *args++;
    s32 var0 = dead_get_variable(script, a1);
    s32 a2 = *args++;
    f32 var1 = dead_get_float_variable(script, *args++);
    f32 var2 = dead_get_float_variable(script, *args++);
    s32 var3 = dead_get_variable(script, *args++);
    s32 var4 = dead_get_variable(script, *args++);
    f32 temp = (dead_get_float_variable(script, *args++) / 180.0f) * PI;
    f32 diff = (var2 - var1) / 2;

    if (var4 != 0 && var3 < var0) {
        var0 = var3;
        dead_set_variable(script, a1, var3);
    }

    dead_set_float_variable(script, a2, (var1 + diff) - (diff * dead_cos_rad(((var0 * PI) / var3) + temp)));

    return ApiStatus_DONE2;
}
