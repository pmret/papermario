#include "common.h"

ApiStatus N(AddHP)(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PlayerData* playerData2 = &gPlayerData;
    s32 amt = get_variable(script, *script->ptrReadPos);
    s32 newHP = playerData->curHP + amt;

    if (newHP > playerData->curMaxHP) {
        newHP = playerData->curMaxHP;
    }

    playerData2->curHP = newHP;

    return ApiStatus_DONE2;
}
