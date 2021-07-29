#include "common.h"
#include "map.h"

ApiStatus N(GetFloorCollider)(ScriptInstance* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    set_variable(script, *script->ptrReadPos, collisionStatus->currentFloor);
    return ApiStatus_DONE2;
}
