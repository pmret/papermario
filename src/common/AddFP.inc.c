#include "common.h"

ApiStatus N(AddFP)(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PlayerData* playerData2 = &gPlayerData;
    s32 amt = get_variable(script, *script->ptrReadPos);
    s32 newFP = playerData->curFP + amt;

    if (newFP > playerData->curMaxFP) {
        newFP = playerData->curMaxFP;
    }

    playerData2->curFP = newFP;

    return ApiStatus_DONE2;
}
