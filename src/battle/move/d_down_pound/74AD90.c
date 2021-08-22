#include "common.h"
#include "effects.h"

#define NAMESPACE battle_move_d_down_pound

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"

ApiStatus func_802A10A4_74AE34(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    if (script->varTable[10] == 0) {
        playFX_32(TRUE, var0 + 30, var1 + 25, var2, 45.0f);
    } else {
        playFX_32(FALSE, var0 + 30, var1 + 25, var2, 45.0f);
    }

    return ApiStatus_DONE2;
}
