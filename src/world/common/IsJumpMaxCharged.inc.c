#include "common.h"
#include "map.h"

ApiStatus N(IsJumpMaxCharged)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;

    if (gBattleStatus.jumpCharge >= 99) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

