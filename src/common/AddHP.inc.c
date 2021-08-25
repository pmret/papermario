#include "common.h"

ApiStatus N(AddHP)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    s32 amt = get_variable(script, *script->ptrReadPos);
    s32 newHP = playerData->curHP + amt;

    if (newHP > playerData->curMaxHP) {
        newHP = playerData->curMaxHP;
    }

    playerData->curHP = newHP;

    return ApiStatus_DONE2;
}
