#include "flo_03.h"

void fx_sun();

ApiStatus N(func_80240000_CA72A0)(Evt* script, s32 isInitialCall) {
    fx_sun(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
