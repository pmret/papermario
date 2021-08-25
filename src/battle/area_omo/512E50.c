#include "common.h"

#define NAMESPACE b_area_omo

INCLUDE_ASM(s32, "battle/area_omo/512E50", func_80218880_512E50);

#include "common/GetItemEntityPosition.inc.c"

INCLUDE_ASM(s32, "battle/area_omo/512E50", func_80218B38_513108);

/// checks if all actions are available.
/// used by Spy Guys.
ApiStatus func_80218CF4_5132C4(Evt* script, s32 isInitialCall) {
    BattleStatus* status = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (status->hammerLossTurns == -1 ||
        status->jumpLossTurns == -1 ||
        status->itemLossTurns == -1
    ) {
        set_variable(script, *args++, 0);
    } else {
        set_variable(script, *args++, -1);
    }

    return ApiStatus_DONE2;
}

#include "common/StartRumbleWithParams.inc.c"
