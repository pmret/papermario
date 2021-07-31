#include "common.h"
#include "effects.h"

#define NAMESPACE battle_move_hammer_charge_0

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"

#include "world/common/IsHammerMaxCharged.inc.c"

ApiStatus func_802A10C8_74F1F8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    playFX_56(0, var1, var2, var3, 1.0f, 60);

    battleStatus->hammerCharge++;
    if (battleStatus->hammerCharge > 99) {
        battleStatus->hammerCharge = 99;
    }

    battleStatus->jumpCharge = 0;
    battleStatus->flags1 |= 0x10000000;
    battleStatus->flags1 &= ~0x20000000;

    return ApiStatus_DONE2;
}

ApiStatus func_802A11CC_74F2FC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    f32 var3 = get_float_variable(script, *args++);

    playFX_6B(6, var0 + 10, var1 + 18, var2, var3, 45);

    return ApiStatus_DONE2;
}
