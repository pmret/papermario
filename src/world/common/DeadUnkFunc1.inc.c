#include "common.h"

void dead_playFX_82(s32, s32, s32, s32, s32, s32);

ApiStatus N(DeadUnkFunc1)(Evt* script, s32 isInitialCall) {
    dead_playFX_82(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
