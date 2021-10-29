#include "common.h"
#include "npc.h"

ApiStatus N(CamSetFOV)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 camIdx = evt_get_variable(script, *args++);

    gCameras[camIdx].vfov = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}
