#include "common.h"
#include "npc.h"

API_CALLABLE(N(IsJumpMaxCharged)) {
    script->varTable[0] = false;

    if (gBattleStatus.jumpCharge >= 99) {
        script->varTable[0] = true;
    }

    return ApiStatus_DONE2;
}

