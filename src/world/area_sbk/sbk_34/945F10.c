#include "sbk_34.h"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_34/945F10", func_80240384_946254);

INCLUDE_ASM(s32, "world/area_sbk/sbk_34/945F10", func_802403D8_9462A8);

extern s32 sbk_34_802427E0[];

ApiStatus func_80240410_9462E0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            sbk_34_802427E0[i] = ptr[i];
        }
        sbk_34_802427E0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            sbk_34_802427E0[i] = i + 16;
            sbk_34_802427E0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"
