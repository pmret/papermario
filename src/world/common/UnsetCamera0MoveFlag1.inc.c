#include "common.h"
#include "npc.h"

ApiStatus N(UnsetCamera0MoveFlag1)(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    camera->moveFlags &= ~CAMERA_MOVE_FLAGS_1;
    return ApiStatus_DONE2;
}
