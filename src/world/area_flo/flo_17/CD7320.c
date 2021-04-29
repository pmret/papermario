#include "flo_17.h"

ApiStatus N(func_80240040_CD7320)(ScriptInstance *script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    set_variable(script, *script->ptrReadPos, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}
