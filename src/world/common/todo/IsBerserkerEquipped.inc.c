#include "common.h"
#include "npc.h"
#include "battle/action_cmd.h"

ApiStatus N(IsBerserkerEquipped)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = gBattleStatus.actionCommandMode;
    script->varTable[1] = 15;

    if (is_ability_active(ABILITY_BERSERKER)) {
        script->varTable[0] = ACTION_COMMAND_MODE_NOT_LEARNED;
        script->varTable[1] = 40;
    }

    return ApiStatus_DONE2;
}

