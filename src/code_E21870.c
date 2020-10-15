#include "common.h"

s32 func_802B7000_2(void) {
    s8* something = &D_8010EBB0;
    ActionState* actionState = gPlayerActionState;

    if (actionState != ActionState_USE_TWEESTER) {
        if (something[0] != 1 || (something[3] != 9 && something[3] != 4)) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM(s32, "code_E21870", func_802B704C);

INCLUDE_ASM(s32, "code_E21870", func_802B7140);

INCLUDE_ASM(s32, "code_E21870", func_802B71D4);

INCLUDE_ASM(s32, "code_E21870", func_802B74F0);
