#include "iwa_00.h"

ApiStatus func_802402B0_90CEF0(Evt* script, s32 isInitialCall) {
    gPlayerStatus.slideParams = script->varTablePtr[0];
    gPlayerStatus.flags |= PLAYER_STATUS_FLAGS_10;
    return ApiStatus_DONE2;
}
