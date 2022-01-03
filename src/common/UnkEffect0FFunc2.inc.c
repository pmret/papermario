#include "battle/battle.h"
#include "effects.h"

ApiStatus N(UnkEffect0FFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 var0 = evt_get_float_variable(script, *args++);
    f32 var1 = evt_get_float_variable(script, *args++);
    f32 var2 = evt_get_float_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);
    f32 var5 = evt_get_float_variable(script, *args++);
    f32 var6 = evt_get_float_variable(script, *args++);
    f32 var7 = evt_get_float_variable(script, *args++);

    playFX_0F(var0, var1, var2, var3, var4, var5, var6, var7);
    return ApiStatus_DONE2;
}
