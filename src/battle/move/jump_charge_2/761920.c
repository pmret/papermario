#include "common.h"

extern s32 D_802A2C20;

#define NAMESPACE battle_move_jump_charge_2

#include "world/common/UnkMoveFunc1.inc.c"

#include "world/common/IsJumpMaxCharged.inc.c"

ApiStatus func_802A1108_761A28(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* battleStatus2 = battleStatus; // TODO: macro?
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32* var4;

    playFX_56(2, var1, var2, var3, 1.0f, 60);
    var4 = &D_802A2C20;
    *var4 = 0;
    if (battleStatus2->jumpCharge > 0) {
        *var4 = 1;
    }

    battleStatus2->jumpCharge += 3;

    if (battleStatus2->jumpCharge > 99) {
        (* &battleStatus)->jumpCharge = 99; // TODO: macro?
    }

    battleStatus->hammerCharge = 0;
    battleStatus->flags1 |= 0x20000000;
    battleStatus->flags1 &= ~0x10000000;

    return ApiStatus_DONE2;
}

#include "world/common/UnkMoveFunc3.inc.c"

ApiStatus func_802A133C_761C5C(ScriptInstance* script, s32 isInitialCall) {
    if (D_802A2C20 == 0) {
        script->varTable[0] = 6;
    } else {
        script->varTable[0] = 7;
    }

    return ApiStatus_DONE2;
}
