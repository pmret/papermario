#include "common.h"

#define NAMESPACE b_area_omo

INCLUDE_ASM(s32, "battle/area_omo/512E50", func_80218880_512E50);

#include "common/GetItemEntityPosition.inc.c"

INCLUDE_ASM(s32, "battle/area_omo/512E50", func_80218B38_513108);

// checks if all actions are available
// used by Spy Guys
ApiStatus func_80218CF4_5132C4(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* status = &gBattleStatus;
    s32* readPos = script->ptrReadPos;

    if ((status->hammerLossTurns == -1) || 
        (status->jumpLossTurns == -1) || 
        (status->itemLossTurns == -1)) {
        set_variable(script, *readPos, 0);
    } else {
        set_variable(script, *readPos, -1);
    }

    return ApiStatus_DONE2;
}

#include "common/StartRumbleWithParams.inc.c"
