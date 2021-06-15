#include "common.h"
#include "map.h"

ApiStatus N(UnsetCamera0Flag1000)(ScriptInstance* script, s32 isInitialCall) {
    Camera* camera = CAM(0);

    camera->flags &= ~0x1000;
    return ApiStatus_DONE2;
}
