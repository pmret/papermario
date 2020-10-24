#include "common.h"

static ApiStatus GetCurrentFloor(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = gCollisionStatus.currentFloor;
    return ApiStatus_DONE2;
}
