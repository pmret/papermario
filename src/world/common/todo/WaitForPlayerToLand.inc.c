#include "common.h"
#include "npc.h"

API_CALLABLE(N(WaitForPlayerToLand)) {
    script->varTable[0] = 0;
    if ((gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE) && (gPartnerActionStatus.actingPartner == PARTNER_BOMBETTE)) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
