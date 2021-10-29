#include "common.h"
#include "npc.h"

ApiStatus N(Set80151310_1)(Evt* script, s32 isInitialCall) {
    D_80151310 = 1;
    return ApiStatus_DONE2;
}

#include "world/common/Set80151310_0.inc.c"
