#include "common.h"
#include "npc.h"

ApiStatus N(SetGameStatusUnk84_1)(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_MARIO_REFLECT_FLOOR;
    return ApiStatus_BLOCK;
}
