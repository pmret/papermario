#include "common.h"
#include "map.h"

ApiStatus N(UnkMoveFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);

    playFX_6B(6, var1 + 10, var2 + 18, var3, var4, 45);
    playFX_33(12, var1 + 10, var2 + 18, var3, var4, 30);

    return ApiStatus_DONE2;
}
