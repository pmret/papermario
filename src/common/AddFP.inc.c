#include "common.h"

ApiStatus N(AddFP)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    s32 amt = evt_get_variable(script, *script->ptrReadPos);
    s32 newFP = playerData->curFP + amt;

    if (newFP > playerData->curMaxFP) {
        newFP = playerData->curMaxFP;
    }

    playerData->curFP = newFP;

    return ApiStatus_DONE2;
}
