#include "kzn_20.h"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_80240654_C96584);

INCLUDE_ASM(s32, "world/area_kzn/kzn_20/C96240", func_802406A8_C965D8);

extern s32 D_802442D0[];

ApiStatus func_802406E0_C96610(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802442D0[i] = ptr[i];
        }
        D_802442D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802442D0[i] = i + 16;
            D_802442D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

ApiStatus func_80240A68_C96998(Evt* script, s32 isInitialCall) {
    snd_ambient_80055618(0, 1);
    return ApiStatus_DONE2;
}


#include "world/common/GetFloorCollider.inc.c"
