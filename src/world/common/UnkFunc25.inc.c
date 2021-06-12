#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc25)(ScriptInstance* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 stickX, stickY;

    if (collisionStatus->currentFloor != script->varTable[11].s) {
        script->varTable[0].s = FALSE;
        return ApiStatus_DONE2;
    }

    stickX = abs(gGameStatusPtr->stickX);
    stickY = gGameStatusPtr->stickY;

    if (stickX != 0 || stickY != 0) {
        if (atan2(0.0f, 0.0f, stickX, stickY) < 60.0f) {
            script->varTable[0].s = TRUE;
            return ApiStatus_DONE2;
        }
    }

    return ApiStatus_BLOCK;
}
