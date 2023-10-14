#include "common.h"
#include "npc.h"
#include "camera.h"

API_CALLABLE(N(DisableCameraLeadingPlayer)) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    camera->flags |= CAMERA_FLAG_SUPRESS_LEADING;
    return ApiStatus_DONE2;
}
