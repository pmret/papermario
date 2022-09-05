#include "kzn_09.h"

#include "world/common/enemy/PiranhaPlantAI.inc.c"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802435F0_C7A2D0);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80243644_C7A324);

extern s32 D_802474A0[];

ApiStatus func_8024367C_C7A35C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802474A0[i] = ptr[i];
        }
        D_802474A0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802474A0[i] = i + 16;
            D_802474A0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"
