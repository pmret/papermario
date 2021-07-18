#include "common.h"
#include "map.h"

ApiStatus N(SetCamVfov)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = get_variable(script, *args++);

    gCameras[cameraID].vfov = get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}
