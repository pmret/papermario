#include "iwa_03.h"

#include "world/common/enemy/CleftAI.inc.c"

ApiStatus func_80241320_919ED0(Evt* script, s32 isInitialCall) {
    gPlayerStatus.slideParams = script->varTablePtr[0];
    gPlayerStatus.flags |= PS_FLAGS_10;
    return ApiStatus_DONE2;
}
