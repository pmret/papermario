#include "common.h"

s32 N(map_init)(void) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_MARIO_REFLECT_FLOOR;
    return false;
}
