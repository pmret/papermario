#include "common.h"

static ApiStatus GetPlayerCoins(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = gPlayerData.coins;
    return ApiStatus_DONE2;
}
