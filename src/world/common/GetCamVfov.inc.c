#include "common.h"
#include "map.h"

ApiStatus N(GetCamVfov)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = get_variable(script, *args++);

    set_variable(script, *args++, SI_FIXED(gCameras[cameraID].vfov));
    return ApiStatus_DONE2;
}
