#include "common.h"
#include "npc.h"

ApiStatus N(Pipe_SetAnimFlag)(Evt* script, s32 isInitialCall) {
    gPlayerStatusPtr->animFlags |= PLAYER_STATUS_ANIM_FLAGS_100000;
    return ApiStatus_DONE2;
}

ApiStatus N(Pipe_GetCurrentFloor)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = gCollisionStatus.currentFloor;
    return ApiStatus_DONE2;
}

ApiStatus N(Pipe_AwaitDownInput)(Evt* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 stickX, stickY;

    if (collisionStatus->currentFloor != script->varTable[11]) {
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

ApiStatus N(Pipe_GetEntryPos)(Evt* script, s32 isInitialCall) {
    MapConfig* mapConfig = get_current_map_header();
    s32 index = evt_get_variable(script, EVT_VAR(0));

    evt_set_variable(script, EVT_VAR(1), ((Vec4f*)*mapConfig->entryList)[index].x);
    evt_set_variable(script, EVT_VAR(2), ((Vec4f*)*mapConfig->entryList)[index].y);
    evt_set_variable(script, EVT_VAR(3), ((Vec4f*)*mapConfig->entryList)[index].z);
    evt_set_variable(script, EVT_VAR(4), ((Vec4f*)*mapConfig->entryList)[index].yaw);
    return ApiStatus_DONE2;
}

ApiStatus N(Pipe_GetCameraYaw)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = clamp_angle(gCameras[gCurrentCameraID].currentYaw + 180.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(Pipe_GetPointAheadOfPlayer)(Evt* script, s32 isInitialStatus) {
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
