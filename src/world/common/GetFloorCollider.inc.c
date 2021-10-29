#include "common.h"
#include "npc.h"

ApiStatus N(GetFloorCollider)(Evt* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    evt_set_variable(script, *script->ptrReadPos, collisionStatus->currentFloor);
    return ApiStatus_DONE2;
}
