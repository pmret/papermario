#include "common.h"
#include "map.h"

ApiStatus N(IsBerserkerEquipped)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0].s = gBattleStatus.unk_83;
    script->varTable[1].s = 15;

    if (is_ability_active(ABILITY_BERSERKER)) {
        script->varTable[0].s = 0;
        script->varTable[1].s = 40;
    }

    return ApiStatus_DONE2;
}

