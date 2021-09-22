#include "dead.h"
#include "common.h"

// Copy from flo_16/UnkFunc44
ApiStatus func_802429A0_EEFAA0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = 0;
    do {} while (0);
    if (gPlayerActionState == ACTION_STATE_GROUND_POUND) {
        script->varTable[0] = 1;
    } else if (gPlayerActionState == ACTION_STATE_ULTRA_POUND) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
