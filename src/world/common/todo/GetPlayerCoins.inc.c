#include "common.h"
#include "npc.h"

API_CALLABLE(N(GetPlayerCoins)) {
    script->varTable[0] = gPlayerData.coins;
    return ApiStatus_DONE2;
}
