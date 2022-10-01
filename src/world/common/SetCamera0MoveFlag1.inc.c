#include "common.h"
#include "npc.h"

ApiStatus N(SetCamera0MoveFlag1)(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    camera->moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
    return ApiStatus_DONE2;
}
