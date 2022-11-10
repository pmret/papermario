#include "kpa_03.h"

ApiStatus func_80241E50_A4A410(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPosition.y >= 0) {
        evt_set_variable(script, MapVar(0), FALSE);
    }
    if (playerStatus->lastGoodPosition.y <= -280) {
        evt_set_variable(script, MapVar(0), TRUE);
    }
    return ApiStatus_BLOCK;
}
