#include "common.h"
#include "map.h"

ApiStatus N(DoesPlayerNeedSleep)(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[1].s = FALSE;
    if (playerData->curMaxHP != playerData->curHP) {
        return ApiStatus_DONE2;
    }
    if (playerData->curMaxFP != playerData->curFP) {
        return ApiStatus_DONE2;
    }
    if (playerData->specialBarsFilled != playerData->maxStarPower * 256) {
        return ApiStatus_DONE2;
    }
    script->varTable[1].s = TRUE;

    return ApiStatus_DONE2;
}
