#include "common.h"
#include "map.h"

ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 xVar = *args++;
    f32 x = (f32)evt_get_variable(script, xVar);
    s32 yVar = *args++;
    f32 y = (f32)evt_get_variable(script, yVar);
    s32 zVar = *args++;
    f32 z = (f32)evt_get_variable(script, zVar);
    f32 cameraYaw;

    cameraYaw = gCameras[gCurrentCameraID].currentYaw;

    if (playerStatus->spriteFacingAngle == 0.0f) {
        cameraYaw -= 100.0f;
    } else {
        cameraYaw += 100.0f;
    }
    cameraYaw = clamp_angle(cameraYaw);

    x += sin_deg(cameraYaw) * 15.0f;
    y += playerStatus->colliderHeight * 0.5f;
    z -= cos_deg(cameraYaw) * 15.0f;

    evt_set_variable(script, xVar, x);
    evt_set_variable(script, yVar, y);
    evt_set_variable(script, zVar, z);

    return ApiStatus_DONE2;
}
