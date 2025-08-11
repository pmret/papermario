#include "common.h"
#include "npc.h"

API_CALLABLE(N(ShouldMovesAutoSucceed)) {
    script->varTable[0] = false;

    if (is_ability_active(ABILITY_RIGHT_ON)) {
        script->varTable[0] = true;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_AUTO_SUCCEED_ACTION) {
        script->varTable[0] = true;
    }

    return ApiStatus_DONE2;
}
