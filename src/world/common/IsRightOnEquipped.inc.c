#include "common.h"
#include "map.h"

ApiStatus N(IsRightOnEquipped)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;

    if (is_ability_active(ABILITY_RIGHT_ON)) {
        script->varTable[0] = TRUE;
    }

    if (gBattleStatus.flags1 & 0x1000) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}
