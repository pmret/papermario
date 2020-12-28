#include "common.h"
#include "map.h"

ApiStatus M(GetCurrentCameraYawClamped180)(ScriptInstance* script, s32 isInitialCall) {
    Camera* currentCamera = CURRENT_CAM;

    script->varTable[0] = clamp_angle(currentCamera->currentYaw + 180.0f);
    return ApiStatus_DONE2;
}
