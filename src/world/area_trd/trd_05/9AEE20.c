#include "trd_05.h"

ApiStatus func_80240720_9AEE20(ScriptInstance* script, s32 isInitialCall) {
    fx_walk_normal(2, script->varTable[0].s, script->varTable[1].s, script->varTable[2].s, 0, 0);
    return ApiStatus_DONE2;
}
