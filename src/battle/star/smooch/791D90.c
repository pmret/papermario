#include "common.h"

#define NAMESPACE battle_star_smooch

#include "common/StarPower.inc.c"

#include "common/AddHP.inc.c"

ApiStatus func_802A156C_7922FC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    playFX_40(0, var1, var2, var3, var4);

    return ApiStatus_DONE2;
}
