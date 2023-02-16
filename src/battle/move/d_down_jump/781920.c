#include "common.h"
#include "effects.h"

#define NAMESPACE battle_move_d_down_jump

#include "world/common/todo/UnkMoveFunc1.inc.c"

API_CALLABLE(func_802A10E4_781A04) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    if (script->varTable[10] == 0) {
        fx_green_impact(TRUE, var0, var1, var2, 0.0f);
    } else {
        fx_green_impact(FALSE, var0, var1, var2, 0.0f);
    }

    return ApiStatus_DONE2;
}
