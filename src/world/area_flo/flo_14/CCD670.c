#include "flo_14.h"

ApiStatus N(D_80242360_CCD670)(ScriptInstance *script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    set_variable(script, *script->ptrReadPos, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}
