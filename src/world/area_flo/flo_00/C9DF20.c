#include "flo_00.h"

// Same as SpawnSunEffect, but doesn't touch float regs like SpawnSunEffect does
void playFX_82();

ApiStatus N(func_80240000_C9DF20)(ScriptInstance* script, s32 isInitialCall) {
    playFX_82(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
