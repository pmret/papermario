#include "common.h"

ApiStatus N(SetPlayerSpriteSet2)(ScriptInstance* script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = 2;
    return ApiStatus_BLOCK;
}
