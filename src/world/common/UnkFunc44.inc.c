#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc44)(ScriptInstance *script, s32 isInitialCall) {
    script->varTable[0].s = 0;
    do {} while(0);
    if (gPlayerActionState == ACTION_STATE_GROUND_POUND) {
        script->varTable[0].s = 1;
    } else if (gPlayerActionState == ACTION_STATE_ULTRA_POUND) {
        script->varTable[0].s = 1;
    }
    return ApiStatus_DONE2;
}
