#include "kpa_83.h"

ApiStatus func_80240050_A834E0(Evt* script, s32 isInitialCall) {
    gPlayerStatus.spriteFacingAngle = script->varTable[0];
    return ApiStatus_DONE2;
}
