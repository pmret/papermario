#include "iwa_01.h"

ApiStatus func_802432B0_912960(Evt* script, s32 isInitialCall) {
    gPlayerStatus.slideParams = script->varTablePtr[0];
    gPlayerStatus.flags |= PA_FLAGS_INTERACT_PROMPT_AVAILABLE;
    return ApiStatus_DONE2;
}
