#include "kgr_02.h"

ApiStatus func_80240730_8AAB80(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actionState.b[3] == PARTNER_WATT) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_80240748_8AAB98(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actionState.b[3] != PARTNER_WATT) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
 
 ApiStatus N(HasBombetteExploded)(Evt* script, s32 isInitialCall) {
    if (gCollisionStatus.bombetteExploded >= 0) {
        script->varTable[1] = TRUE;
    }
    return ApiStatus_DONE2;
}
