#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc44)(ScriptInstance *script, s32 isInitialCall) {
    script->varTable[0] = 0;
    do {} while(0);
    if (gPlayerActionState == 14) {
        script->varTable[0] = 1;
    } else if (gPlayerActionState == 16) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}