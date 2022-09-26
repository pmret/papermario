#include "kzn_09.h"

#include "world/common/enemy/PiranhaPlantAI.inc.c"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802435F0_C7A2D0);

extern s32 D_802452B4_C7BF94;
extern s32 D_802452B8_C7BF98;

/*
ApiStatus func_802435F0_C7A2D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &D_802452B4_C7BF94;
        *ptr = 0;
    }

    ptr = &D_802452B4_C7BF94;
    if (*ptr != NULL) {
        ptr = &D_802452B4_C7BF94;
        *ptr = 0;
        evt_set_variable(script, *args++, D_802452B8_C7BF98);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

ApiStatus func_80243644_C7A324(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_802452B8_C7BF98 = evt_get_variable(script, *args++);
    D_802452B4_C7BF94 = 1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_8024367C_C7A35C);

/*
ApiStatus N(BuildKeyItemChoiceList)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* allowedItemList = (s32*)evt_get_variable(script, *args++);
    s32 i;

    if (allowedItemList != NULL) {
        for (i = 0; allowedItemList[i] != ITEM_NONE; i++) {
            N(KeyItemChoiceList)[i] = allowedItemList[i];
        }
        N(KeyItemChoiceList)[i] = ITEM_NONE;
    } else {
        for (i = 0; i < ITEM_NUM_KEYS; i++) {
            N(KeyItemChoiceList)[i] = ITEM_FIRST_KEY + i;
            N(KeyItemChoiceList)[ITEM_NUM_KEYS] = ITEM_NONE; // vanilla oddity -- should be after the loop!
        }
    }
    return ApiStatus_DONE2;
}
*/

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"
