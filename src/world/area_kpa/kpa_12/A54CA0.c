#include "kpa_12.h"

ApiStatus N(func_80240350_A54CA0)(Evt* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    evt_set_variable(script, *script->ptrReadPos, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_12/A54CA0", func_8024037C_A54CCC);

ApiStatus N(IsPartnerLakilester)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actingPartner == PARTNER_LAKILESTER) {
        script->varTable[9] = TRUE;
    } else {
        script->varTable[9] = FALSE;
    }
    return ApiStatus_DONE2;
}
