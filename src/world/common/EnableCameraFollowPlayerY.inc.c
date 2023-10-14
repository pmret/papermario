#include "common.h"
#include "npc.h"

API_CALLABLE(N(EnableCameraFollowPlayerY)) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    camera->moveFlags &= ~CAMERA_MOVE_IGNORE_PLAYER_Y;
    return ApiStatus_DONE2;
}
