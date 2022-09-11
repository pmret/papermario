#include "isk_10.h"

static char* N(exit_str_0) = "isk_08";
static char* N(exit_str_1) = "isk_14";
static char* N(exit_str_2) = "isk_18";
static char* N(exit_str_3) = "";

#include "world/common/atomic/SuperBlock.inc.c"

ApiStatus func_80240D38_989898(Evt* script, s32 isInitialCall) {
    s32 status = -1;

    if (gPlayerStatus.lastGoodPosition.y > -600.0) {
        status = 0;
    }
    if (gPlayerStatus.lastGoodPosition.y < -770.0) {
        status = 1;
    }
    if (status >= 0) {
        evt_set_variable(script, MapVar(9), status);
    }
    return ApiStatus_BLOCK;
}
