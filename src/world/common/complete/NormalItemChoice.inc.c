#ifndef _COMMON_CONSUMABLE_CHOICE_
#define _COMMON_CONSUMABLE_CHOICE_

#include "common.h"
#include "sprite/player.h"

static s32 N(ItemChoice_List)[ITEM_NUM_CONSUMABLES + 1];

#ifndef _CHOICE_SUPPORT_
#define _CHOICE_SUPPORT_

s32 N(ItemChoice_HasSelectedItem) = 0;
s32 N(ItemChoice_SelectedItemID) = 0;

#include "world/common/todo/GetNpcCollisionHeight.inc.c"
#include "world/common/todo/AddPlayerHandsOffset.inc.c"

API_CALLABLE(N(ItemChoice_WaitForSelection)) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(ItemChoice_HasSelectedItem) = FALSE;
    }

    if (N(ItemChoice_HasSelectedItem)) {
        N(ItemChoice_HasSelectedItem) = FALSE;
        evt_set_variable(script, *args++, N(ItemChoice_SelectedItemID));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(ItemChoice_SaveSelected)) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

#endif

API_CALLABLE(N(BuildItemChoiceList)) {
    Bytecode* args = script->ptrReadPos;
    s32* allowedItemList = (s32*)evt_get_variable(script, *args++);
    s32 i;

    if (allowedItemList != NULL) {
        for (i = 0; allowedItemList[i] != ITEM_NONE; i++) {
            N(ItemChoice_List)[i] = allowedItemList[i];
        }
        N(ItemChoice_List)[i] = ITEM_NONE;
    } else {
        for (i = 0; i < ITEM_NUM_CONSUMABLES; i++) {
            N(ItemChoice_List)[i] = ITEM_FIRST_CONSUMABLE + i;
            N(ItemChoice_List)[ITEM_NUM_CONSUMABLES] = ITEM_NONE; // oddity -- should be after the loop!
        }
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ItemChoicePopup) = {
    EVT_SET(LVar9, LVar1)
    EVT_CALL(ShowConsumableChoicePopup)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveItemAt, LVar1)
            EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
            EVT_CALL(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
            EVT_CALL(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
            EVT_WAIT(30)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_CALL(RemoveItemEntity, LVar0)
    EVT_END_SWITCH
    EVT_CALL(N(ItemChoice_SaveSelected), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ChooseItem) = {
    EVT_CALL(N(BuildItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemChoicePopup)), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(ItemChoice_List)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LVar0)
    EVT_RETURN
    EVT_END
};

#define EVT_CHOOSE_ANY_CONSUMABLE(unkMode) \
    EVT_SET(LVar0, NULL) \
    EVT_SET(LVar1, unkMode) \
    EVT_EXEC_WAIT(N(EVS_ChooseItem))

#define EVT_CHOOSE_CONSUMABLE_FROM(itemList, unkMode) \
    EVT_SET(LVar0, EVT_PTR(itemList)) \
    EVT_SET(LVar1, unkMode) \
    EVT_EXEC_WAIT(N(EVS_ChooseItem))

#endif
