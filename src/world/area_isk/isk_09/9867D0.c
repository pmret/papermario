#include "isk_09.h"

ApiStatus func_802402F0_9867D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 colliderID = evt_get_variable(script, *args++);
    if (gCollisionStatus.currentFloor != colliderID) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
