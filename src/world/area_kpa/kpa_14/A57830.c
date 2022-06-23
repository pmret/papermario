#include "kpa_14.h"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#include "world/common/SetEntityFlags100000.inc.c"

#include "world/common/GetEntityPosition.inc.c"

ApiStatus N(func_80240710_A57BC0)(Evt* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    evt_set_variable(script, *script->ptrReadPos, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_14/A57830", func_8024073C_A57BEC);

ApiStatus N(IsPartnerLakilester)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actingPartner == PARTNER_LAKILESTER) {
        script->varTable[9] = TRUE;
    } else {
        script->varTable[9] = FALSE;
    }
    return ApiStatus_DONE2;
}
