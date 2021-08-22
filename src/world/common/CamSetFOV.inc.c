#include "common.h"
#include "map.h"

ApiStatus N(CamSetFOV)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 camIdx = get_variable(script, *args++);

    gCameras[camIdx].vfov = get_variable(script, *args++);

    return ApiStatus_DONE2;
}
