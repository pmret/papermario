#include "kpa_03.h"

ApiStatus func_80241E50_A4A410(Evt* script) {
    PlayerStatus* p = &gPlayerStatus;
    if (p->lastGoodPosition.y >= 0) {
        evt_set_variable(script, GW(0), FALSE);
    }
    if (p->lastGoodPosition.y <= -280) {
        evt_set_variable(script, GW(0), TRUE);
    }
    return ApiStatus_BLOCK;
}
