#include "common.h"
#include "map.h"

ApiStatus N(UnkFloatFunc)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a1 = *args++;
    s32 var0 = get_variable(script, a1);
    s32 a2 = *args++;
    f32 var1 = get_float_variable(script, *args++);
    f32 var2 = get_float_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);
    f32 temp = (get_float_variable(script, *args++) / 180.0f) * PI;
    f32 diff = (var2 - var1) / 2;

    if (var4 != 0 && var3 < var0) {
        var0 = var3;
        set_variable(script, a1, var3);
    }

    set_float_variable(script, a2, (var1 + diff) - (diff * cos_rad(((var0 * PI) / var3) + temp)));

    return ApiStatus_DONE2;
}
