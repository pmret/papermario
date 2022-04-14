#include "common.h"

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
        for (i = 0; i <= (ITEM_LAST_KEY - ITEM_FIRST_VALID_KEY); i++) {
            N(KeyItemChoiceList)[i] = ITEM_FIRST_VALID_KEY + i;
            N(KeyItemChoiceList)[(ITEM_LAST_KEY - ITEM_FIRST_VALID_KEY) + 1] = ITEM_NONE; // vanilla oddity -- should be after the loop!
        }
    }
    return ApiStatus_DONE2;
}
