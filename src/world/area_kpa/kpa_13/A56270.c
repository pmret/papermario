#include "kpa_13.h"

ApiStatus N(func_80240350_A56270)(Evt* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    evt_set_variable(script, *script->ptrReadPos, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_13/A56270", func_8024037C_A5629C);

ApiStatus N(IsPartnerLakilester)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actingPartner == PARTNER_LAKILESTER) {
        script->varTable[9] = TRUE;
    } else {
        script->varTable[9] = FALSE;
    }
    return ApiStatus_DONE2;
}
