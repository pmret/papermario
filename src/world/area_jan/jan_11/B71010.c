#include "jan_11.h"

#include "world/common/GetFloorCollider.inc.c"

ApiStatus N(IsPartnerWatt)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actingPartner == PARTNER_WATT) {
        script->varTable[9] = TRUE;
    } else {
        script->varTable[9] = FALSE;
    }
    return ApiStatus_DONE2;
}
