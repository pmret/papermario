#include "common.h"

#define NAMESPACE battle_star_focus

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_78A378(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 deepFocusSP;
    s32 superFocusSP;

    script->varTable[0] = 0;

    if (playerData->specialBarsFilled >= playerData->maxStarPower * 256) {
        script->varTable[0] = 1;
        return ApiStatus_DONE2;
    }

    deepFocusSP = is_ability_active(ABILITY_DEEP_FOCUS) * 64;
    superFocusSP = is_ability_active(ABILITY_SUPER_FOCUS) * 128;

    add_SP(deepFocusSP + superFocusSP + 128);

    if (playerData->specialBarsFilled == playerData->maxStarPower * 256) {
        script->varTable[0] = 2;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A15B0_78A410(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[0] = 0;

    if (playerData->specialBarsFilled >= playerData->maxStarPower * 256) {
        script->varTable[0] = 1;
        return ApiStatus_DONE2;
    }

    add_SP(128);

    if (playerData->specialBarsFilled == playerData->maxStarPower * 256) {
        script->varTable[0] = 2;
    }

    return ApiStatus_DONE2;
}
