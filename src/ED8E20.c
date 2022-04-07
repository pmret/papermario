#include "dead.h"
#include "common.h"

// Copy of flo_11 (CBDCD0.c)

#define NAMESPACE ED8E20

ApiStatus N(DeadPipe_SetAnimFlag)(Evt* script, s32 isInitialCall) {
    gPlayerStatusPtr->animFlags |= PLAYER_STATUS_ANIM_FLAGS_100000;
    return ApiStatus_DONE2;
}

// Variation of Pipe_GetCurrentFloor that is non-equivalent
ApiStatus N(DeadPipe_GetCurrentFloor)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = dead_gCollisionStatus.pushingAgainstWall;
    return ApiStatus_DONE2;
}

// Variation of Pipe_AwaitDownInput that is non-equivalent
ApiStatus N(DeadPipe_AwaitDownInput)(Evt* script, s32 isInitialCall) {
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

// Variation of Pipe_GetEntryPos with a debug print at the end
ApiStatus N(DeadPipe_GetEntryPos)(Evt* script, s32 isInitialCall) {
    MapConfig* mapConfig = get_current_map_header();
    s32 index = evt_get_variable(script, EVT_VAR(0));

    evt_set_variable(script, EVT_VAR(1), ((Vec4f*)*mapConfig->entryList)[index].x);
    evt_set_variable(script, EVT_VAR(2), ((Vec4f*)*mapConfig->entryList)[index].y);
    evt_set_variable(script, EVT_VAR(3), ((Vec4f*)*mapConfig->entryList)[index].z);
    evt_set_variable(script, EVT_VAR(4), ((Vec4f*)*mapConfig->entryList)[index].yaw);
    osSyncPrintf("[%d] dokan get pos  (no=%d)  pos=%d, %d, %d,  dir=%d\n\0\0\0flo_23\0\0flo_12\0\0flo_11", dead_gGameStatusPtr->frameCounter, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4]);
    return ApiStatus_DONE2;
}

ApiStatus N(DeadPipe_GetCameraYaw)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = clamp_angle(gCameras[gCurrentCameraID].currentYaw + 180.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(DeadPipe_GetPointAheadOfPlayer)(Evt* script, s32 isInitialStatus) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 r = evt_get_float_variable(script, *script->ptrReadPos);
    f32 x = playerStatus->position.x;
    f32 y = playerStatus->position.y;
    f32 z = playerStatus->position.z;

    add_vec2D_polar(&x, &z, r, playerStatus->targetYaw);
    evt_set_float_variable(script, EVT_VAR(0), x);
    evt_set_float_variable(script, EVT_VAR(1), y);
    evt_set_float_variable(script, EVT_VAR(2), z);

    return ApiStatus_DONE2;
}

ApiStatus func_80240318_ED9138(Evt* script, s32 isInitialCall) {
    dead_fx_sun(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
