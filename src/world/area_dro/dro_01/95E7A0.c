#include "dro_01.h"

#define NAMESPACE dro_01_dup
#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"
#define NAMESPACE dro_01

#define NAMESPACE dro_01_dup
#include "world/common/GetCurrentFloor.inc.c"
#define NAMESPACE dro_01

ApiStatus N(func_802435D4_95E7D4)(ScriptInstance* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 stickX, stickY;

    if (collisionStatus->currentFloor != script->varTable[11]) {
        script->varTable[0] = 0;
        return ApiStatus_DONE2;
    }

    stickX = abs(gGameStatusPtr->stickX);
    stickY = gGameStatusPtr->stickY;

    if ((stickX != 0) || (stickY != 0)) {
        if (atan2(0.0f, 0.0f, stickX, stickY) < 60.0f) {
            script->varTable[0] = 1;
            return ApiStatus_DONE2;
        }
    }

    return ApiStatus_BLOCK;
}

#define NAMESPACE dro_01_dup
#include "world/common/GetEntryPos.inc.c"
#define NAMESPACE dro_01

#define NAMESPACE dro_01_dup
#include "world/common/GetCurrentCameraYawClamped180.inc.c"
#define NAMESPACE dro_01

#define NAMESPACE dro_01_dup
#include "world/common/SomeXYZFunc2.inc.c"
#define NAMESPACE dro_01

#include "world/common/SomeMatrixOperations.inc.c"
