#include "common.h"
#include "effects.h"

ApiStatus N(DeadUnkFunc1)(Evt* script, s32 isInitialCall) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
