#include "common.h"

ApiStatus N(BuildItemChoiceList)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* allowedItemList = (s32*)evt_get_variable(script, *args++);
    s32 i;

    if (allowedItemList != NULL) {
        for (i = 0; allowedItemList[i] != 0; i++) {
            N(ItemChoiceList)[i] = allowedItemList[i];
        }
        N(ItemChoiceList)[i] = 0;
    } else {
        for (i = 0; i <= (ITEM_LAST_VALID_CONSUMABLE - ITEM_FIRST_CONSUMABLE); i++) {
            N(ItemChoiceList)[i] = i + ITEM_FIRST_CONSUMABLE;
            N(ItemChoiceList)[(ITEM_LAST_VALID_CONSUMABLE - ITEM_FIRST_CONSUMABLE) + 1] = 0;
        }
    }
    return ApiStatus_DONE2;
}
