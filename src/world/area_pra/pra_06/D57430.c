#include "pra_06.h"

ApiStatus func_80240000_D57430(void) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_MARIO_REFLECT_FLOOR;
    sprintf(wMapShapeName, "pra_05_shape");
    sprintf(wMapHitName, "pra_05_hit");
    return ApiStatus_BLOCK;
}

const char N(exit_str_0)[] = "pra_39";

#include "world/common/atomic/Reflection.inc.c"
