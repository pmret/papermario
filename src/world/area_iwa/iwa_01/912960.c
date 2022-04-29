#include "iwa_01.h"

ApiStatus func_802432B0_912960(Evt* script, s32 isInitialCall) {
    gPlayerStatus.unk_D0 = script->varTablePtr[0];
    gPlayerStatus.flags |= PLAYER_STATUS_ANIM_FLAGS_INTERACT_PROMPT_AVAILABLE;
    return ApiStatus_DONE2;
}
