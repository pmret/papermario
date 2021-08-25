#include "trd_05.h"
#include "effects.h"

ApiStatus func_80240720_9AEE20(Evt* script, s32 isInitialCall) {
    fx_walk(2, script->varTable[0], script->varTable[1], script->varTable[2], 0, 0);
    return ApiStatus_DONE2;
}
