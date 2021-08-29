#include "common.h"

#define NAMESPACE battle_star_star_storm

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_78ECE8(Evt* script, s32 isInitialCall) {
    s32 var1 = -50 - rand_int(200);
    s32 var2 = 200;
    s32 var3 = rand_int(40);
    f32 var4;

    if (script->varTable[0] % 4) {
        var4 = var1 + (rand_int(50) + var2);
        playFX_0F(2, var1, var2, var3, var4, 0, var3, rand_int(10) + 7);
    } else {
        var4 = var1 + (rand_int(50) + var2);
        playFX_0F(3, var1, var2, var3, var4, 0, var3, rand_int(10) + 7);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A1628_78EDF8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    playFX_18(2, var1, var2, var3, 0, -1.0f, 0, 5);

    return ApiStatus_DONE2;
}
