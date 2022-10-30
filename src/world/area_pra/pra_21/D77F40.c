#include "pra_21.h"

ApiStatus func_80240020_D77F40(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->targetYaw >= 0.0f && playerStatus->targetYaw < 180.0f) {
        script->varTable[0] = 425;
    }
    if (playerStatus->targetYaw >= 180.0f && playerStatus->targetYaw < 360.0f) {
        script->varTable[0] = 325;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802400AC_D77FCC(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPosition.y == 0) {
        evt_set_variable(script, MapVar(0), 0);
    }
    if (playerStatus->lastGoodPosition.y == -200) {
        evt_set_variable(script, MapVar(0), 1);
    }
    return ApiStatus_BLOCK;
}
