#include "common.h"
#include "npc.h"

ApiStatus N(ShouldMovesAutoSucceed)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;

    if (is_ability_active(ABILITY_RIGHT_ON)) {
        script->varTable[0] = TRUE;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_AUTO_SUCCEED_ACTION) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}
