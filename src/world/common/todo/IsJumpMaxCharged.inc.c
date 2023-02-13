#include "common.h"
#include "npc.h"

API_CALLABLE(N(IsJumpMaxCharged)) {
    script->varTable[0] = FALSE;

    if (gBattleStatus.jumpCharge >= 99) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

