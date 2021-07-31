#include "common.h"
#include "effects.h"

#define NAMESPACE battle_move_jump_charge_0

#include "world/common/UnkMoveFunc1.inc.c"

#include "world/common/IsJumpMaxCharged.inc.c"

ApiStatus func_802A1108_74D678(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    playFX_56(0, var1, var2, var3, 1.0f, 60);

    battleStatus->jumpCharge++;
    if (battleStatus->jumpCharge > 99) {
        battleStatus->jumpCharge = 99;
    }

    battleStatus->hammerCharge = 0;
    battleStatus->flags1 |= 0x20000000;
    battleStatus->flags1 &= ~0x10000000;

    return ApiStatus_DONE2;
}

ApiStatus func_802A120C_74D77C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    f32 var3 = get_float_variable(script, *args++);

    playFX_6B(6, var0 + 10, var1 + 18, var2, var3, 45);

    return ApiStatus_DONE2;
}
