#include "flo_16.h"

// Copy from flo_16/UnkFunc44
ApiStatus func_802429A0_EEFAA0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = 0;
    do {} while (0);
    if (gPlayerStatus.actionState == ACTION_STATE_SPIN_POUND) {
        script->varTable[0] = 1;
    } else if (gPlayerStatus.actionState == ACTION_STATE_TORNADO_POUND) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
