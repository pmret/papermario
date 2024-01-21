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
    Set(LVar9, LVar1)
    Call(ShowKeyChoicePopup)
    Set(LVarA, LVar0)
    Switch(LVar0)
        CaseEq(0)
        CaseEq(-1)
        CaseDefault
            Call(RemoveKeyItemAt, LVar1)
            Call(GetPlayerPos, LVar3, LVar4, LVar5)
            Call(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
            BitwiseOrConst(LVar0, ITEM_VIS_GROUP(ITEM_NONE, 5))
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

EvtScript N(EVS_ChooseKeyItem) = {
    Call(N(BuildKeyItemChoiceList), LVar0)
    BindPadlock(Ref(N(EVS_KeyItemChoicePopup)), TRIGGER_FORCE_ACTIVATE, 0, Ref(N(KeyItemChoiceList)), 0, 1)
    Call(N(ItemChoice_WaitForSelection), LVar0)
    Return
    End
};

#define EVT_CHOOSE_ANY_KEY_ITEM() \
    Set(LVar0, NULL) \
    Set(LVar1, 0) \
    ExecWait(N(EVS_ChooseKeyItem))

#define EVT_CHOOSE_KEY_ITEM_FROM(itemList) \
    Set(LVar0, Ref(itemList)) \
    Set(LVar1, 0) \
    ExecWait(N(EVS_ChooseKeyItem))

#endif
