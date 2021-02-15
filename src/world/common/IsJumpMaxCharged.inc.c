#include "common.h"
#include "map.h"

ApiStatus N(IsJumpMaxCharged)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    script->varTable[0] = FALSE;

    if (battleStatus->jumpCharge >= 99) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

