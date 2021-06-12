#include "flo_16.h"

ApiStatus N(func_80242940_CD4770)(ScriptInstance *script, s32 isInitialCall) {
    script->varTable[0].s = 0;
    do {} while(0);
    if ((gPlayerActionState == ACTION_STATE_GROUND_POUND) || (gPlayerActionState == ACTION_STATE_ULTRA_POUND)) {
        script->varTable[0].s = 1;
    }
    return ApiStatus_DONE2;
}
