#include "omo_14.h"

INCLUDE_ASM(s32, "world/area_omo/omo_14/DE5810", func_80240160_DE5810);

INCLUDE_ASM(s32, "world/area_omo/omo_14/DE5810", func_802403FC_DE5AAC);

INCLUDE_ASM(s32, "world/area_omo/omo_14/DE5810", func_80240564_DE5C14);

ApiStatus N(IsPartnerWatt)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actingPartner == PARTNER_WATT) {
        script->varTable[1] = TRUE;
    } else {
        script->varTable[1] = FALSE;
    }
    return ApiStatus_DONE2;
}
