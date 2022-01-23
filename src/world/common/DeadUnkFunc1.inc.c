#include "common.h"

void dead_fx_sun(s32, s32, s32, s32, s32, s32);

ApiStatus N(DeadUnkFunc1)(Evt* script, s32 isInitialCall) {
    dead_fx_sun(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
