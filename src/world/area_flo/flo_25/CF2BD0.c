#include "flo_25.h"

void fx_sun();

ApiStatus N(func_80240000_CF2BD0)(Evt* script, s32 isInitialCall) {
    fx_sun(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
