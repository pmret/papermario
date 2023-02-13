#include "common.h"

API_CALLABLE(N(GetPlayerHpPercent)) {
    evt_set_variable(script, *script->ptrReadPos, (gPlayerData.curHP * 100) / gPlayerData.curMaxHP);
    return ApiStatus_DONE2;
}

