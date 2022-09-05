#include "kzn_17.h"

#include "world/common/enemy/PiranhaPlantAI.inc.c"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_802428E0_C88390);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242934_C883E4);

extern s32 D_802465F0[];

ApiStatus func_8024296C_C8841C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802465F0[i] = ptr[i];
        }
        D_802465F0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802465F0[i] = i + 16;
            D_802465F0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"
