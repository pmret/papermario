#include "pra_36.h"

ApiStatus func_80240000_D91700(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = 1;
    sprintf(wMapShapeName, "pra_10_shape");
    sprintf(wMapHitName, "pra_10_hit");
    return ApiStatus_BLOCK;
}

const char* N(exit_str_0) = "pra_21\0\0pra_27";

#include "world/common/atomic/Reflection.inc.c"
