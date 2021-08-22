#include "flo_16.h"

void playFX_82();

ApiStatus N(func_80240000_CD1E30)(Evt* script, s32 isInitialCall) {
    playFX_82(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
