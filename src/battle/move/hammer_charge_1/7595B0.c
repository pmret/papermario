#include "common.h"
#include "effects.h"

BSS s32 D_802A43D0;

#define NAMESPACE battle_move_hammer_charge_1

#include "world/common/todo/IsBerserkerEquipped.inc.c"

#include "world/common/todo/IsRightOnEquipped.inc.c"

#include "world/common/todo/IsHammerMaxCharged.inc.c"

ApiStatus func_802A10C8_759678(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32* var4;

    fx_stat_change(1, var1, var2, var3, 1.0f, 60);
    var4 = &D_802A43D0;
    *var4 = 0;
    if (battleStatus->hammerCharge > 0) {
        *var4 = 1;
    }

    battleStatus->hammerCharge += 2;

    if (battleStatus->hammerCharge > 99) {
        battleStatus->hammerCharge = 99;
    }

    battleStatus->jumpCharge = 0;
    battleStatus->flags1 |= BS_FLAGS1_HAMMER_CHARGED;
    battleStatus->flags1 &= ~BS_FLAGS1_JUMP_CHARGED;

    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkMoveFunc2.inc.c"

ApiStatus func_802A12FC_7598AC(Evt* script, s32 isInitialCall) {
    if (D_802A43D0 == 0) {
        script->varTable[0] = 4;
    } else {
        script->varTable[0] = 5;
    }

    return ApiStatus_DONE2;
}

