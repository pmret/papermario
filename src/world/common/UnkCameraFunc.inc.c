#include "common.h"
#include "npc.h"

ApiStatus N(UnkCameraFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    Bytecode out1 = *args++;
    Bytecode out2 = *args++;
    s32 cameraYaw = gCameras[gCurrentCameraID].currentYaw;
    s32 outVal1 = evt_get_variable(script, EVT_ARRAY(1)) - (var2 * cos_deg(cameraYaw));
    s32 outVal2 = evt_get_variable(script, EVT_ARRAY(3)) - (var2 * sin_deg(cameraYaw));

    outVal1 -= var0;
    outVal2 -= var1;

    evt_set_variable(script, out1, outVal1);
    evt_set_variable(script, out2, outVal2);

    return ApiStatus_DONE2;
}
