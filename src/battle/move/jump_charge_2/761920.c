#include "common.h"
#include "effects.h"

BSS s32 D_802A2C20;

#define NAMESPACE battle_move_jump_charge_2

#include "world/common/todo/UnkMoveFunc1.inc.c"

#include "world/common/todo/IsJumpMaxCharged.inc.c"

API_CALLABLE(func_802A1108_761A28) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32* var4;

    fx_stat_change(2, var1, var2, var3, 1.0f, 60);
    var4 = &D_802A2C20;
    *var4 = 0;
    if (battleStatus->jumpCharge > 0) {
        *var4 = 1;
    }

    battleStatus->jumpCharge += 3;

    if (battleStatus->jumpCharge > 99) {
        battleStatus->jumpCharge = 99;
    }

    battleStatus->hammerCharge = 0;
    battleStatus->flags1 |= BS_FLAGS1_JUMP_CHARGED;
    battleStatus->flags1 &= ~BS_FLAGS1_HAMMER_CHARGED;

    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkMoveFunc3.inc.c"

API_CALLABLE(func_802A133C_761C5C) {
    if (D_802A2C20 == 0) {
        script->varTable[0] = 6;
    } else {
        script->varTable[0] = 7;
    }

    return ApiStatus_DONE2;
}
