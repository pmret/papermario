#include "common.h"
#include "npc.h"

ApiStatus N(SetGameStatusUnk84_1)(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = 1;
    return ApiStatus_BLOCK;
}
