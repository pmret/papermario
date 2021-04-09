#include "dro_01.h"

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

ApiStatus N(func_80240034_95B234)(ScriptInstance *script, s32 isInitialCall) {
    s32 stickX, stickY;

    if (gCollisionStatus.currentFloor != script->varTable[11]) {
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

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

#include "world/common/UnkFunc27.inc.c"

#include "world/common/UnkFunc26.inc.c"
