#include "common.h"
#include "effects.h"

ApiStatus N(Set80071270_0_16)(Evt* script, s32 isInitialCall) {
    fx_snowfall(0, 0x10);
    return ApiStatus_DONE2;
}
