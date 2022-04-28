#include "iwa_10.h"

static char* N(exit_str_0) = "iwa_00";
static char* N(exit_str_1) = "iwa_11";

ApiStatus func_80240000_91E570(Evt* script, s32 isInitialCall) {
    if (script->varTable[15] > 720) {
        script->varTable[15] = 0;
    }
    script->varTable[0] = script->varTable[15] * 6;
    script->varTable[1] = script->varTable[15] / 2;
    return ApiStatus_DONE2;
}
