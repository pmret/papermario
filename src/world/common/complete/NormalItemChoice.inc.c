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
        N(ItemChoice_HasSelectedItem) = false;
    }

    if (N(ItemChoice_HasSelectedItem)) {
        N(ItemChoice_HasSelectedItem) = false;
        evt_set_variable(script, *args++, N(ItemChoice_SelectedItemID));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(ItemChoice_SaveSelected)) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args);
    N(ItemChoice_HasSelectedItem) = true;
    return ApiStatus_DONE2;
}

#endif

API_CALLABLE(N(BuildItemChoiceList)) {
    Bytecode* args = script->ptrReadPos;
    s32* allowedItemList = (s32*)evt_get_variable(script, *args++);
    s32 i;

    if (allowedItemList != nullptr) {
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
    Set(LVar9, LVar1)
    Call(ShowConsumableChoicePopup)
    Set(LVarA, LVar0)
    Switch(LVar0)
        CaseEq(0)
        CaseEq(-1)
        CaseDefault
            Call(RemoveItemAt, LVar1)
            Call(GetPlayerPos, LVar3, LVar4, LVar5)
            Call(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
            Call(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, ITEM_SPAWN_MODE_DECORATION, 0)
            Call(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
            Wait(30)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Call(RemoveItemEntity, LVar0)
    EndSwitch
    Call(N(ItemChoice_SaveSelected), LVarA)
    Call(CloseChoicePopup)
    Unbind
    Return
    End
};

EvtScript N(EVS_ChooseItem) = {
    Call(N(BuildItemChoiceList), LVar0)
    BindPadlock(Ref(N(EVS_ItemChoicePopup)), TRIGGER_FORCE_ACTIVATE, 0, Ref(N(ItemChoice_List)), 0, 1)
    Call(N(ItemChoice_WaitForSelection), LVar0)
    Return
    End
};

#define EVT_CHOOSE_ANY_CONSUMABLE(unkMode) \
    Set(LVar0, nullptr) \
    Set(LVar1, unkMode) \
    ExecWait(N(EVS_ChooseItem))

#define EVT_CHOOSE_CONSUMABLE_FROM(itemList, unkMode) \
    Set(LVar0, Ref(itemList)) \
    Set(LVar1, unkMode) \
    ExecWait(N(EVS_ChooseItem))

#endif
