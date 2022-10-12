#include "nok_11.h"

static char* N(exit_str_0) = "mac_01";
static char* N(exit_str_1) = "nok_12";

#include "world/common/enemy/ai/TackleAI.inc.c"

#include "world/common/enemy/ai/FlyingAI.inc.c"

#include "common/foliage.inc.c"

ApiStatus func_80241F08_9F6948(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    if (playerData->coins >= 100) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80241F30_9F6970(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->coins -= 100;

    return ApiStatus_DONE2;
}
