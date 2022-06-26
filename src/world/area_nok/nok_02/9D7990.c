#include "nok_02.h"
#include "effects.h"

ApiStatus func_80240970_9D7990(Evt* script, s32 isInitialCall) {
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    return ApiStatus_DONE2;
}
