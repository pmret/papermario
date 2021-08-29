#include "common.h"
#include "map.h"

ApiStatus N(SetCamVfov)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    gCameras[cameraID].vfov = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}
