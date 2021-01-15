#include "common.h"

ApiStatus func_802A1000_7345A0(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = BATTLE_STATUS->unk_83;
    script->varTable[1] = 15;

    if (is_ability_active(Ability_BERSERKER)) {
        script->varTable[0] = 0;
        script->varTable[1] = 40;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A1050_7345F0(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = 0;

    if (is_ability_active(Ability_RIGHT_ON)) {
        script->varTable[0] = 1;
    }

    if (gBattleStatus.flags1 & 0x1000) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}
