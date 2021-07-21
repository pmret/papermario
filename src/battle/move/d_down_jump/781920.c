#include "common.h"
#include "effects.h"

#define NAMESPACE battle_move_d_down_jump

#include "world/common/UnkMoveFunc1.inc.c"

ApiStatus func_802A10E4_781A04(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    if (script->varTable[10] == 0) {
        playFX_32(TRUE, var0, var1, var2, 0.0f);
    } else {
        playFX_32(FALSE, var0, var1, var2, 0.0f);
    }

    return ApiStatus_DONE2;
}
