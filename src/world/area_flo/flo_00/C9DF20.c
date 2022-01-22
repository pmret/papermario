#include "flo_00.h"

// Same as SpawnSunEffect, but doesn't touch float regs like SpawnSunEffect does
void fx_sun();

ApiStatus N(func_80240000_C9DF20)(Evt* script, s32 isInitialCall) {
    fx_sun(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
