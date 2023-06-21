#ifndef _COMMON_KEY_CHOICE_
#define _COMMON_KEY_CHOICE_

#include "common.h"
#include "sprite/player.h"

static s32 N(KeyItemChoiceList)[ITEM_NUM_KEYS + 1];

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

#include "world/common/atomic/MakeKeyChoice.inc.c"

EvtScript N(EVS_KeyItemChoicePopup) = {
    EVT_SET(LVar9, LVar1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, LVar1)
            EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
            EVT_CALL(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
            EVT_BITWISE_OR_CONST(LVar0, ITEM_VIS_GROUP(ITEM_NONE, 5))
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

EvtScript N(EVS_ChooseKeyItem) = {
    EVT_CALL(N(BuildKeyItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_KeyItemChoicePopup)), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LVar0)
    EVT_RETURN
    EVT_END
};

#define EVT_CHOOSE_ANY_KEY_ITEM() \
    EVT_SET(LVar0, NULL) \
    EVT_SET(LVar1, 0) \
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))

#define EVT_CHOOSE_KEY_ITEM_FROM(itemList) \
    EVT_SET(LVar0, EVT_PTR(itemList)) \
    EVT_SET(LVar1, 0) \
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))

#endif
