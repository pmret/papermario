#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc44)) {
    script->varTable[0] = FALSE;
    if (gPlayerStatus.actionState == ACTION_STATE_SPIN_POUND || gPlayerStatus.actionState == ACTION_STATE_TORNADO_POUND) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}
