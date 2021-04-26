#include "flo_16.h"

ApiStatus N(func_80242940_CD4770)(ScriptInstance *script, s32 isInitialCall) {
    script->varTable[0] = 0;
    do {} while(0);
    if ((gPlayerActionState == 14) || (gPlayerActionState == 16)) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
