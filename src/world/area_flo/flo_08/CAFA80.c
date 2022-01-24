#include "flo_08.h"

// It seems like fx_sun was not properly defined for this file. Having a proper
// declaration makes it not match.
#ifdef AVOID_UB
void fx_sun(s32, f32, f32, f32, f32, s32);
#else
void fx_sun(s32, s32, s32, s32, s32, s32);
#endif

ApiStatus N(func_80240D40_CAFA80)(Evt* script, s32 isInitialCall) {
    fx_sun(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
