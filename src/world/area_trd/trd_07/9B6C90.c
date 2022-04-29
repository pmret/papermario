#include "trd_07.h"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/enemy/ParatroopaAI.inc.c"

#include "world/common/GetDefeatedEnemyCount.inc.c"

ApiStatus func_80242600_9B8F80(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    f32 angle = evt_get_float_variable(script, *args++);
    
    script->varTable[0] = ((posX + (sin_deg(clamp_angle(gCameras->currentYaw + angle + 270.0f)) * 1000.0f)) * 1024.0f) + -2.3e8f;
    script->varTable[1] = ((posZ - (cos_deg(clamp_angle(gCameras->currentYaw + angle + 270.0f)) * 1000.0f)) * 1024.0f) + -2.3e8f;
    script->varTable[2] = ((posX + (sin_deg(clamp_angle(gCameras->currentYaw + angle + 90.0f)) * 1000.0f)) * 1024.0f) + -2.3e8f;
    script->varTable[3] = ((posZ - (cos_deg(clamp_angle(gCameras->currentYaw + angle + 90.0f)) * 1000.0f)) * 1024.0f) + -2.3e8f;
    return ApiStatus_DONE2;
}

ApiStatus func_802427FC_9B917C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);
    f32 yaw = evt_get_variable(script, *args++);

    fx_walking_dust(1, posX, posY + 10, posZ, sin_deg(yaw), -cos_deg(yaw));
    return ApiStatus_DONE2;
}
