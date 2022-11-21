#include "pra_37.h"

ApiStatus func_80240000_D92F40(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_MARIO_REFLECT_FLOOR;
    sprintf(wMapShapeName, "pra_10_shape");
    sprintf(wMapHitName, "pra_10_hit");
    return ApiStatus_BLOCK;
}

const char* N(exit_str_0) = "pra_22\0\0pra_28";

#include "world/common/atomic/Reflection.inc.c"

#include "world/common/enemy/ai/MeleeHitbox.inc.c"

#include "world/common/enemy/ai/WanderMeleeAI.inc.c"
