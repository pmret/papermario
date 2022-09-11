#include "pra_37.h"

ApiStatus func_80240000_D92F40(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = 1;
    sprintf(wMapShapeName, "pra_10_shape");
    sprintf(wMapHitName, "pra_10_hit");
    return ApiStatus_BLOCK;
}

const char* N(exit_str_0) = "pra_22\0\0pra_28";

#include "world/common/atomic/Reflection.inc.c"

#include "world/common/enemy/MeleeHitbox.inc.c"

#include "world/common/enemy/WanderMeleeAI.inc.c"
