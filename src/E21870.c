#include "common.h"

s32 func_802B7000_2(void) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    s8 actionState = gPlayerActionState;

    if (actionState != ACTION_STATE_USE_TWEESTER) {
        if (partnerActionStatus->actionState.b[0] != 1 || (partnerActionStatus->actionState.b[3] != 9 && partnerActionStatus->actionState.b[3] != 4)) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM(s32, "E21870", func_802B704C);

INCLUDE_ASM(s32, "E21870", func_802B7140);

INCLUDE_ASM(s32, "E21870", func_802B71D4);

INCLUDE_ASM(s32, "E21870", func_802B74F0);
