#include "common.h"

ApiStatus N(SetPlayerSpriteSet2)(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = 2;
    return ApiStatus_BLOCK;
}
