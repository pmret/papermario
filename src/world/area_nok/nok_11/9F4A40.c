#include "nok_11.h"

static char* N(exit_str_0) = "mac_01";
static char* N(exit_str_1) = "nok_12";

#include "world/common/atomic/enemy/UnkAI_5.inc.c"

#include "world/common/atomic/enemy/UnkAI_9.inc.c"

#include "common/foliage.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_11/9F4A40", func_80241F08_9F6948);

ApiStatus func_80241F30_9F6970(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->coins -= 100;

    return ApiStatus_DONE2;
}
