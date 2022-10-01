#include "trd_10.h"

ApiStatus N(IsPartnerBombette)(Evt* script, s32 isInitialCall) {
    if (gPlayerData.currentPartner == PARTNER_BOMBETTE) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }
    return ApiStatus_DONE2;
}
