#include "flo_16.h"

ApiStatus N(func_80242940_CD4770)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = 0;
    do {} while (0);
    if (gPlayerStatus.actionState == ACTION_STATE_SPIN_POUND || gPlayerStatus.actionState == ACTION_STATE_TORNADO_POUND) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
