#include "common.h"
#include "npc.h"

ApiStatus N(SetCamera0MoveFlag1)(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    camera->moveFlags |= 1;
    return ApiStatus_DONE2;
}
