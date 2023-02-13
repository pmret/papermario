#include "common.h"

API_CALLABLE(N(AddHP)) {
    PlayerData* playerData = &gPlayerData;

    s32 amt = evt_get_variable(script, *script->ptrReadPos);
    s32 newHP = playerData->curHP + amt;

    if (newHP > playerData->curMaxHP) {
        newHP = playerData->curMaxHP;
    }

    playerData->curHP = newHP;

    return ApiStatus_DONE2;
}
