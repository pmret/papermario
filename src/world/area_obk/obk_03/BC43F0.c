#include "obk_03.h"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_802404B4_BC4734);

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_80240508_BC4788);

extern s32 D_80243BE0[];

ApiStatus func_80240540_BC47C0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80243BE0[i] = ptr[i];
        }
        D_80243BE0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80243BE0[i] = i + 16;
            D_80243BE0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"
