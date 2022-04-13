#include "common.h"

ApiStatus N(BuildKeyItemChoiceList)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* allowedItemList = (s32*)evt_get_variable(script, *args++);
    s32 i;

    if (allowedItemList != NULL) {
        for (i = 0; allowedItemList[i] != 0; i++) {
            N(KeyItemChoiceList)[i] = allowedItemList[i];
        }
        N(KeyItemChoiceList)[i] = 0;
    } else {
        for (i = 0; i <= (ITEM_LAST_KEY - ITEM_FIRST_VALID_KEY); i++) {
            N(KeyItemChoiceList)[i] = i + ITEM_FIRST_VALID_KEY;
            N(KeyItemChoiceList)[(ITEM_LAST_KEY - ITEM_FIRST_VALID_KEY) + 1] = 0;
        }
    }
    return ApiStatus_DONE2;
}
