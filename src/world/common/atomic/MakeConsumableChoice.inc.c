#include "common.h"

API_CALLABLE(N(BuildItemChoiceList)) {
    Bytecode* args = script->ptrReadPos;
    s32* allowedItemList = (s32*)evt_get_variable(script, *args++);
    s32 i;

    if (allowedItemList != NULL) {
        for (i = 0; allowedItemList[i] != ITEM_NONE; i++) {
            N(ItemChoiceList)[i] = allowedItemList[i];
        }
        N(ItemChoiceList)[i] = ITEM_NONE;
    } else {
        for (i = 0; i < ITEM_NUM_CONSUMABLES; i++) {
            N(ItemChoiceList)[i] = ITEM_FIRST_CONSUMABLE + i;
            N(ItemChoiceList)[ITEM_NUM_CONSUMABLES] = ITEM_NONE;
        }
    }
    return ApiStatus_DONE2;
}
