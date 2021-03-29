#include "common.h"
#include "map.h"

ApiStatus N(IsBerserkerEquipped)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = gBattleStatus.unk_83;
    script->varTable[1] = 15;

    if (is_ability_active(ABILITY_BERSERKER)) {
        script->varTable[0] = 0;
        script->varTable[1] = 40;
    }

    return ApiStatus_DONE2;
}

