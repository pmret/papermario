#include "common.h"
#include "npc.h"
#include "camera.h"

ApiStatus N(SetCamera0Flag1000)(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    camera->flags |= 0x1000;
    return ApiStatus_DONE2;
}
