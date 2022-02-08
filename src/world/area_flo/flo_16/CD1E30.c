#include "flo_16.h"

void fx_sun();

ApiStatus N(func_80240000_CD1E30)(Evt* script, s32 isInitialCall) {
    fx_sun(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
