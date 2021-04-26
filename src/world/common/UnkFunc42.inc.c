#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc42)(ScriptInstance *script, s32 isInitialCall) {
    script->varTable[10] = atan2(script->varTable[0], script->varTable[2], script->varTable[3], script->varTable[5]);
    return ApiStatus_DONE2;
}