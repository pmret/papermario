#include "flo_08.h"

// It seems like playFX_82 was not properly defined for this file. Having a proper
// declaration makes it not match.
#ifdef AVOID_UB
void playFX_82(s32, f32, f32, f32, f32, s32);
#else
void playFX_82(s32, s32, s32, s32, s32, s32);
#endif

ApiStatus N(func_80240D40_CAFA80)(Evt* script, s32 isInitialCall) {
    playFX_82(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
