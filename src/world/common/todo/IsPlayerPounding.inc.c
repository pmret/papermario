#include "common.h"
#include "npc.h"

API_CALLABLE(N(IsPlayerPounding)) {
    script->varTable[0] = false;
    if (gPlayerStatus.actionState == ACTION_STATE_SPIN_POUND || gPlayerStatus.actionState == ACTION_STATE_TORNADO_POUND) {
        script->varTable[0] = true;
    }
    return ApiStatus_DONE2;
}
