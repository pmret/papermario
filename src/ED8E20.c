#include "dead.h"
#include "common.h"

// Copy of flo_11 (CBDCD0.c)

#define NAMESPACE ED8E20

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

// Variation of GetCurrentFloor that is non-equivalent
ApiStatus N(DeadGetCurrentFloor)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = dead_gCollisionStatus.pushingAgainstWall;
    return ApiStatus_DONE2;
}

// Variation of UnkFunc25 that is non-equivalent
ApiStatus N(DeadUnkFunc25)(Evt* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 stickX, stickY;

    if (collisionStatus->pushingAgainstWall != script->varTable[11]) {
        script->varTable[0] = FALSE;
        return ApiStatus_DONE2;
    }

    stickX = abs(gGameStatusPtr->stickX);
    stickY = gGameStatusPtr->stickY;

    if (stickX != 0 || stickY != 0) {
        if (atan2(0.0f, 0.0f, stickX, stickY) < 60.0f) {
            script->varTable[0] = TRUE;
            return ApiStatus_DONE2;
        }
    }

    return ApiStatus_BLOCK;
}

// Variation of GetEntryPos with a debug print at the end
ApiStatus N(DeadGetEntryPos)(Evt* script, s32 isInitialCall) {
    MapConfig* mapConfig = get_current_map_header();
    s32 index = evt_get_variable(script, EVT_VAR(0));

    evt_set_variable(script, EVT_VAR(1), ((Vec4f*)*mapConfig->entryList)[index].x);
    evt_set_variable(script, EVT_VAR(2), ((Vec4f*)*mapConfig->entryList)[index].y);
    evt_set_variable(script, EVT_VAR(3), ((Vec4f*)*mapConfig->entryList)[index].z);
    evt_set_variable(script, EVT_VAR(4), ((Vec4f*)*mapConfig->entryList)[index].yaw);
    osSyncPrintf("[%d] dokan get pos  (no=%d)  pos=%d, %d, %d,  dir=%d\n\0\0\0flo_23\0\0flo_12\0\0flo_11", dead_gGameStatusPtr->frameCounter, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4]);
    return ApiStatus_DONE2;
}
}

// Variation of GetEntryPos with a debug print at the end
ApiStatus func_802400F0_ED8F10(Evt* script, s32 isInitialCall) {
    MapConfig* mapConfig = get_current_map_header();
    s32 index = evt_get_variable(script, EVT_VAR(0));

    evt_set_variable(script, EVT_VAR(1), ((Vec4f*)*mapConfig->entryList)[index].x);
    evt_set_variable(script, EVT_VAR(2), ((Vec4f*)*mapConfig->entryList)[index].y);
    evt_set_variable(script, EVT_VAR(3), ((Vec4f*)*mapConfig->entryList)[index].z);
    evt_set_variable(script, EVT_VAR(4), ((Vec4f*)*mapConfig->entryList)[index].yaw);
    osSyncPrintf("[%d] dokan get pos  (no=%d)  pos=%d, %d, %d,  dir=%d\n\0\0\0flo_23\0\0flo_12\0\0flo_11", dead_gGameStatusPtr->frameCounter, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4]);
    return ApiStatus_DONE2;
}
