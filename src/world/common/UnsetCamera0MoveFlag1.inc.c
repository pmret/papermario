#include "common.h"

static ApiStatus UnsetCamera0MoveFlag1(ScriptInstance* script, s32 isInitialCall) {
    Camera* camera = &gCameras[0];

    camera->moveFlags &= ~1;
    return ApiStatus_DONE2;
}
