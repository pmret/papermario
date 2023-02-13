#include "common.h"
#include "npc.h"

API_CALLABLE(N(IsHammerMaxCharged)) {
    script->varTable[0] = FALSE;

    if (gBattleStatus.hammerCharge >= 99) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

