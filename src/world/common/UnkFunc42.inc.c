#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc42)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[10].s = atan2(script->varTable[0].s, script->varTable[2].s, script->varTable[3].s, script->varTable[5].s);
    return ApiStatus_DONE2;
}
