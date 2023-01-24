#include "common.h"
#include "npc.h"

//TODO this is a map_init function
s32 N(map_init)(void) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_MARIO_REFLECT_FLOOR;
    return FALSE;
}
