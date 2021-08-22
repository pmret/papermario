#include "common.h"
#include "map.h"

ApiStatus N(GetCurrentCameraYawClamped180)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = clamp_angle(gCameras[gCurrentCameraID].currentYaw + 180.0f);
    return ApiStatus_DONE2;
}
