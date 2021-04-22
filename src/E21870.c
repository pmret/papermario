#include "common.h"

s32 func_802B7000_2(void) {
    Temp8010EBB0* something = &D_8010EBB0;
    ActionState actionState = gPlayerActionState;

    if (actionState != ACTION_STATE_USE_TWEESTER) {
        if (something->unk_00 != 1 || (something->unk_03 != 9 && something->unk_03 != 4)) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM(s32, "E21870", func_802B704C);

INCLUDE_ASM(s32, "E21870", func_802B7140);

INCLUDE_ASM(s32, "E21870", func_802B71D4);

INCLUDE_ASM(s32, "E21870", func_802B74F0);
