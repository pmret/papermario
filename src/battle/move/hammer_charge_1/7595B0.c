#include "common.h"
#include "effects.h"

extern s32 D_802A43D0;

#define NAMESPACE battle_move_hammer_charge_1

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"

#include "world/common/IsHammerMaxCharged.inc.c"

ApiStatus func_802A10C8_759678(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* battleStatus2 = battleStatus; // TODO: macro?
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32* var4;

    playFX_56(1, var1, var2, var3, 1.0f, 60);
    var4 = &D_802A43D0;
    *var4 = 0;
    if (battleStatus->hammerCharge > 0) {
        *var4 = 1;
    }

    battleStatus2->hammerCharge += 2;

    if (battleStatus2->hammerCharge > 99) {
        (* &battleStatus)->hammerCharge = 99; // TODO: macro?
    }

    battleStatus->jumpCharge = 0;
    battleStatus->flags1 |= 0x10000000;
    battleStatus->flags1 &= ~0x20000000;

    return ApiStatus_DONE2;
}

#include "world/common/UnkMoveFunc2.inc.c"

ApiStatus func_802A12FC_7598AC(Evt* script, s32 isInitialCall) {
    if (D_802A43D0 == 0) {
        script->varTable[0] = 4;
    } else {
        script->varTable[0] = 5;
    }

    return ApiStatus_DONE2;
}

