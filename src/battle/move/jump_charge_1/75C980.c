#include "common.h"
#include "effects.h"

extern s32 D_802A2C50;

#define NAMESPACE battle_move_jump_charge_1

#include "world/common/UnkMoveFunc1.inc.c"

#include "world/common/IsJumpMaxCharged.inc.c"

ApiStatus func_802A1108_75CA88(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32* var4;

    fx_stat_change(1, var1, var2, var3, 1.0f, 60);
    var4 = &D_802A2C50;
    *var4 = 0;
    if (battleStatus->jumpCharge > 0) {
        *var4 = 1;
    }

    battleStatus->jumpCharge += 2;

    if (battleStatus->jumpCharge > 99) {
        battleStatus->jumpCharge = 99;
    }

    battleStatus->hammerCharge = 0;
    battleStatus->flags1 |= BS_FLAGS1_20000000;
    battleStatus->flags1 &= ~BS_FLAGS1_10000000;

    return ApiStatus_DONE2;
}

#include "world/common/UnkMoveFunc2.inc.c"

ApiStatus func_802A133C_75CCBC(Evt* script, s32 isInitialCall) {
    if (D_802A2C50 == 0) {
        script->varTable[0] = 6;
    } else {
        script->varTable[0] = 7;
    }

    return ApiStatus_DONE2;
}
