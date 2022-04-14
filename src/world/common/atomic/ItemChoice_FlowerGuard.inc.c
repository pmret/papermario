#include "common.h"

ApiStatus N(FlowerGuard_SetItemEntityPosition)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    ItemEntity* item = get_item_entity(itemIdx);

    item->position.x = x;
    item->position.y = y;
    item->position.z = z;

    return ApiStatus_DONE2;
}

ApiStatus N(FlowerGuard_JudgeItemTastiness)(Evt* script, s32 isInitialCall) {
    s32 itemId = evt_get_variable(script, *script->ptrReadPos);
    ItemData* item = &gItemTable[itemId];

    if (itemId == ITEM_YUMMY_MEAL) {
        script->varTable[9] = 2;
    } else if (item->typeFlags & ITEM_TYPE_FLAG_FOOD_OR_DRINK) {
        script->varTable[9] = 1;
    } else {
        script->varTable[9] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(FlowerGuard_MakeItemList)(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i <= (ITEM_LAST_VALID_CONSUMABLE - ITEM_FIRST_CONSUMABLE); i++) {
        N(FlowerGuard_ItemChoiceList)[i] = ITEM_FIRST_CONSUMABLE + i;
    }

    N(FlowerGuard_ItemChoiceList)[(ITEM_LAST_VALID_CONSUMABLE - ITEM_FIRST_CONSUMABLE) + 1] = ITEM_NONE;
    return ApiStatus_DONE2;
}
