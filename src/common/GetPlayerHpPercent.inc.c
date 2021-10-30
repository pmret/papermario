#include "common.h"

ApiStatus N(GetPlayerHpPercent)(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, (gPlayerData.curHP * 100) / gPlayerData.curMaxHP);
    return ApiStatus_DONE2;
}

