#include "common.h"

s32 func_802B7000_2(void) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    s8 actionState = gPlayerActionState;

    if (actionState != ACTION_STATE_USE_TWEESTER) {
        if (partnerActionStatus->partnerActionState != 1 || 
                (partnerActionStatus->actingPartner != PARTNER_BOW
                && partnerActionStatus->actingPartner != PARTNER_PARAKARRY)) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM(s32, "E21870", func_802B704C);

INCLUDE_ASM(s32, "E21870", func_802B7140);

INCLUDE_ASM(s32, "E21870", func_802B71D4);

INCLUDE_ASM(s32, "E21870", func_802B74F0);
