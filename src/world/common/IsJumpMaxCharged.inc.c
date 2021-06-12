#include "common.h"
#include "map.h"

ApiStatus N(IsJumpMaxCharged)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0].s = FALSE;

    if (gBattleStatus.jumpCharge >= 99) {
        script->varTable[0].s = TRUE;
    }

    return ApiStatus_DONE2;
}

