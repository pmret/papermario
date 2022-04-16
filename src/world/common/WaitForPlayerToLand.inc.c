#include "common.h"
#include "npc.h"

ApiStatus N(WaitForPlayerToLand)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = 0;
    if ((gPartnerActionStatus.partnerActionState != 0) && (gPartnerActionStatus.actingPartner == PARTNER_BOMBETTE)) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
