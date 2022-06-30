#include "common.h"
#include "npc.h"

ApiStatus N(UnkTrigFunc001)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s2 = evt_get_variable(script, *args++);
    s32 temp_s3 = evt_get_variable(script, *args++);
    f32 temp_f24 = evt_get_variable(script, *args++);

    script->varTable[0] = temp_s2 + (sin_deg(gCameras[CAM_DEFAULT].currentYaw + 270.0f + temp_f24) * 100.0f);
    script->varTable[1] = temp_s3 - (cos_deg(gCameras[CAM_DEFAULT].currentYaw + 270.0f + temp_f24) * 100.0f);
    script->varTable[2] = temp_s2 + (sin_deg(gCameras[CAM_DEFAULT].currentYaw + 90.0f + temp_f24) * 100.0f);
    script->varTable[3] = temp_s3 - (cos_deg(gCameras[CAM_DEFAULT].currentYaw + 90.0f + temp_f24) * 100.0f);
    return ApiStatus_DONE2;
}
