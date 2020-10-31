#include "common.h"

static ApiStatus Set80151310_1(ScriptInstance* script, s32 isInitialCall) {
    D_80151310 = 1;
    return ApiStatus_DONE2;
}

#include "world/common/Set80151310_0.inc.c"
