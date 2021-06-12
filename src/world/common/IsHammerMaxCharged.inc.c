#include "common.h"
#include "map.h"

ApiStatus N(IsHammerMaxCharged)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0].s = FALSE;

    if (gBattleStatus.hammerCharge >= 99) {
        script->varTable[0].s = TRUE;
    }

    return ApiStatus_DONE2;
}

