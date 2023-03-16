#include "common.h"
#include "npc.h"

API_CALLABLE(N(WaitForPlayerToLand)) {
    script->varTable[0] = 0;
    if ((gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) && (gPartnerStatus.actingPartner == PARTNER_BOMBETTE)) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
