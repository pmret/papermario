#include "common.h"
#include "npc.h"

ApiStatus N(GetCamVfov)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, EVT_FIXED(gCameras[cameraID].vfov));
    return ApiStatus_DONE2;
}
