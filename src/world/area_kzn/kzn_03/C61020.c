#include "kzn_03.h"

// spike top
#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/enemy/PiranhaPlantAI.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802428E0_C635F0);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242934_C63644);

extern s32 D_80247420_kzn_03[];

ApiStatus func_8024296C_C6367C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80247420_kzn_03[i] = ptr[i];
        }
        D_80247420_kzn_03[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80247420_kzn_03[i] = i + 16;
            D_80247420_kzn_03[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"
