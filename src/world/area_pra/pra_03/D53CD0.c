#include "pra_03.h"

ApiStatus func_80240020_D53CD0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->targetYaw >= 0.0f && playerStatus->targetYaw < 180.0f) {
        script->varTable[0] = 150;
    }
    if (playerStatus->targetYaw >= 180.0f && playerStatus->targetYaw < 360.0f) {
        script->varTable[0] = 95;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802400AC_D53D5C(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->targetYaw >= 0.0f && playerStatus->targetYaw < 180.0f) {
        script->varTable[0] = 165;
    }
    if (playerStatus->targetYaw >= 180.0f && playerStatus->targetYaw < 360.0f) {
        script->varTable[0] = 70;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80240138_D53DE8(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPosition.y == 0) {
        evt_set_variable(script, MapVar(0), 0);
    }
    if (playerStatus->lastGoodPosition.y == -200) {
        evt_set_variable(script, MapVar(0), 1);
    }
    return ApiStatus_BLOCK;
}
