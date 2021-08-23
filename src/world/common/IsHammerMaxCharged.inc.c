#include "common.h"
#include "map.h"

ApiStatus N(IsHammerMaxCharged)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;

    if (gBattleStatus.hammerCharge >= 99) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

