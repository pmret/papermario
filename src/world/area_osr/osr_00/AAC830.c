#include "osr_00.h"
#include "effects.h"

static char* N(exit_str_0) = "mac_01";
static char* N(exit_str_1) = "kkj_00";
static char* N(exit_str_2) = "kmr_20";
static char* N(exit_str_3) = "kkj_00\0";

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus func_8024030C_AACB3C(Evt* script, s32 isInitialCall) {
    fx_sun(1, 0.0f, 0.0f, 0.0f, 0.0f, 0);
    return ApiStatus_DONE2;
}

#include "world/common/SpawnSunEffect.inc.c"
