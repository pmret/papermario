#include "common.h"
#include "effects.h"

ApiStatus N(PlayFX3D)(Evt* script, s32 isInitialStatus) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    f32 var2 = evt_get_float_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);
    f32 var5 = evt_get_float_variable(script, *args++);
    f32 var6 = evt_get_float_variable(script, *args++);
    f32 var7 = evt_get_float_variable(script, *args++);
    s32 var8 = evt_get_variable(script, *args++);
    s32 outVal;

    playFX_3D(var1, var2, var3, var4, var5, var6, var7, var8, &outVal);
    script->varTable[0] = outVal;
    return ApiStatus_DONE2;
}
