#include "kzn_02.h"

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/FlyingNoAttackAI.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_02/C5AC20", func_80242310_C5CA50);

INCLUDE_ASM(s32, "world/area_kzn/kzn_02/C5AC20", func_80242364_C5CAA4);

extern s32 D_802465D0_kzn_02[];

ApiStatus func_8024239C_C5CADC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802465D0_kzn_02[i] = ptr[i];
        }
        D_802465D0_kzn_02[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802465D0_kzn_02[i] = i + 16;
            D_802465D0_kzn_02[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"
