#include "common.h"
#include "npc.h"
#include "camera.h"

ApiStatus N(UnsetCamera0Flag1000)(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    camera->flags &= ~CAMERA_FLAG_1000;
    return ApiStatus_DONE2;
}
