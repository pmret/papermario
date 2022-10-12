#include "mac_03.h"

static char* N(exit_str_0) = "mac_02";
static char* N(exit_str_1) = "mgm_00";
static char* N(exit_str_2) = "iwa_11";
static char* N(exit_str_3) = "mac_03";

#include "world/common/entity/Pipe.inc.c"

ApiStatus func_802402E0_831AE0(Evt* script, s32 isInitialCall) {
    if (script->varTable[15] > 720) {
        script->varTable[15] = 0;
    }

    script->varTable[0] = script->varTable[15] * 6;
    script->varTable[1] = script->varTable[15] / 2;
    return ApiStatus_DONE2;
}
