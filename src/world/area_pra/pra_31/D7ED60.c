#include "pra_31.h"

static char* N(exit_str_0) = "pra_34";
static char* N(exit_str_1) = "pra_40";

ApiStatus func_80240000_D7ED60(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_MARIO_REFLECT_FLOOR;
    return ApiStatus_BLOCK;
}
