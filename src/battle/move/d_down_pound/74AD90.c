#include "common.h"
#include "effects.h"

#define NAMESPACE battle_move_d_down_pound

#include "world/common/todo/IsBerserkerEquipped.inc.c"

#include "world/common/todo/ShouldMovesAutoSucceed.inc.c"

ApiStatus func_802A10A4_74AE34(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    if (script->varTable[10] == 0) {
        fx_green_impact(TRUE, var0 + 30, var1 + 25, var2, 45.0f);
    } else {
        fx_green_impact(FALSE, var0 + 30, var1 + 25, var2, 45.0f);
    }

    return ApiStatus_DONE2;
}
