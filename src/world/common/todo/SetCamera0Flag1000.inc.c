#include "common.h"
#include "npc.h"
#include "camera.h"

API_CALLABLE(N(SetCamera0Flag1000)) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    camera->flags |= CAMERA_FLAG_1000;
    return ApiStatus_DONE2;
}
