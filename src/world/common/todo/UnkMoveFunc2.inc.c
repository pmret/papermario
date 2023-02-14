#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkMoveFunc2)) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);

    fx_energy_in_out(6, var1 + 10, var2 + 18, var3, var4, 45);
    fx_radial_shimmer(12, var1 + 10, var2 + 18, var3, var4, 30);

    return ApiStatus_DONE2;
}
