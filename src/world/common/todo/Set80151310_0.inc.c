#include "common.h"
#include "npc.h"

ApiStatus N(Set80151310_0)(Evt* script, s32 isInitialCall) {
    gEntityHideMode = ENTITY_HIDE_MODE_0;
    return ApiStatus_DONE2;
}
