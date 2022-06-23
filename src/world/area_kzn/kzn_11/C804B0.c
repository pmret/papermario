#include "kzn_11.h"

INCLUDE_ASM(s32, "world/area_kzn/kzn_11/C804B0", func_80240310_C804B0);

#include "world/common/GetFloorCollider.inc.c"

ApiStatus N(IsPartnerLakilester)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actingPartner == PARTNER_LAKILESTER) {
        script->varTable[9] = TRUE;
    } else {
        script->varTable[9] = FALSE;
    }
    return ApiStatus_DONE2;
}
