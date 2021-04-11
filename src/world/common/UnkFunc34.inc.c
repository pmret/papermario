#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc34)(ScriptInstance *script, s32 isInitialCall) {
    PlayerData* playerData = ({ PlayerData* p = &gPlayerData; p; });

    script->varTable[1] = 0;
    if (playerData->curMaxHP != playerData->curHP) {
        return ApiStatus_DONE2;
    }
    if (playerData->curMaxFP != playerData->curFP) {
        return ApiStatus_DONE2;
    }
    if (playerData->specialBarsFilled != playerData->maxStarPower * 256) {
        return ApiStatus_DONE2;
    }
    script->varTable[1] = 1;

    return ApiStatus_DONE2;
}