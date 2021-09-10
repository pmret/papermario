#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc18)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 partnerIdx = evt_get_variable(script, *args++);
    s32 evt_var = *args++;

    playerData->partners[partnerIdx].level++;
    evt_set_variable(script, evt_var, playerData->partners[partnerIdx].level);

    return ApiStatus_DONE2;
}

s32 N(UnkFunc37)(s32 idx, s16 arg1) {
    if (!gPlayerData.partners[idx].enabled) {
        return -1;
    }

    if (gPlayerData.partners[idx].level <= arg1) {
        return gPlayerData.partners[idx].level;
    }

    return -1;
}

ApiStatus N(UnkFunc38)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 i;
    s16 var = script->varTable[12] >= 0;

    script->varTable[0] = -1;

    for (i = 1; i < ARRAY_COUNT(playerData->partners); i++) {
        if (playerData->partners[i].enabled && N(UnkFunc37)(i, var) != -1) {
            script->varTable[0] = 1;
            break;
        }
    }

    return ApiStatus_DONE2;
}
