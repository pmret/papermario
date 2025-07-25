#include "common.h"
#include "npc.h"

API_CALLABLE(N(IsHammerMaxCharged)) {
    script->varTable[0] = false;

    if (gBattleStatus.hammerCharge >= 99) {
        script->varTable[0] = true;
    }

    return ApiStatus_DONE2;
}

