#include "common.h"

#define NAMESPACE battle_star_smooch

#include "common/StarPower.inc.c"

#include "common/AddHP.inc.c"

ApiStatus func_802A156C_7922FC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);

    playFX_40(0, var1, var2, var3, var4);

    return ApiStatus_DONE2;
}
