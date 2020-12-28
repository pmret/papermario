#include "common.h"
#include "map.h"

ApiStatus N(GetCurrentFloor)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = gCollisionStatus.currentFloor;
    return ApiStatus_DONE2;
}
