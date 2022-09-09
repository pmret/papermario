#include "kpa_14.h"

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus func_8024034C_A577FC(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.partnerActionState != 0) {
        script->varTable[9] = gPartnerActionStatus.actingPartner;
    } else {
        script->varTable[9] = -1;
    }
    return ApiStatus_DONE2;
}
