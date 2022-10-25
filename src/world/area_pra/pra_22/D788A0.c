#include "pra_22.h"

#include "world/common/todo/UnkFunc11.inc.c"

ApiStatus func_802400DC_D7895C(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z, hitDepth;

    playerStatus->position.x = script->varTable[0];
    x = playerStatus->position.x;
    y = playerStatus->position.y + 10.0f;
    z = playerStatus->position.z;
    hitDepth = 300.0f;
    npc_raycast_down_around(0, &x, &y, &z, &hitDepth, 270.0f, playerStatus->colliderDiameter);
    playerStatus->position.x = x;
    playerStatus->position.z = z;
    script->varTable[10] = 0;
    if (playerStatus->position.y != y) {
        playerStatus->position.y = 0.0f;
        script->varTable[3]++;
        if (script->varTable[3] >= 30) {
            script->varTable[10] = 1;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802401D0_D78A50(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->targetYaw >= 0.0f && playerStatus->targetYaw < 180.0f) {
        script->varTable[0] = 425;
    }
    if (playerStatus->targetYaw >= 180.0f && playerStatus->targetYaw < 360.0f) {
        script->varTable[0] = 325;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_8024025C_D78ADC(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPosition.y == 0) {
        evt_set_variable(script, MapVar(0), 0);
    }
    if (playerStatus->lastGoodPosition.y == -200) {
        evt_set_variable(script, MapVar(0), 1);
    }
    return ApiStatus_BLOCK;
}
