#include "common.h"
#include "map.h"

ApiStatus N(Dist3D)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);
    s32 var5 = evt_get_variable(script, *args++);
    s32 var6 = evt_get_variable(script, *args++);
    f32 diff1 = var1 - var4;
    f32 diff2 = var2 - var5;
    f32 diff3 = var3 - var6;

    evt_set_variable(script, *args++, sqrtf(SQ(diff1) + SQ(diff2) + SQ(diff3)));
    return ApiStatus_DONE2;
}
