#include "common.h"

static s32 N(KeyItemChoiceList)[112];
static s32** N(varStash) = NULL;

// GiveKeyItem?
EvtScript N(80241C6C) = {
    EVT_CALL(ShowGotItem, LVar0, ITEM_TYPE_KEY, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

// GiveCoin?
EvtScript N(80241C9C) = {
    EVT_CALL(ShowGotItem, LVar0, ITEM_TYPE_KEY, ITEM_PICKUP_FLAG_1_COIN)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

s32 N(ItemChoice_HasSelectedItem) = 0;

s32 N(ItemChoice_SelectedItemID) = 0;

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/atomic/ItemChoice_PartA.inc.c"

#include "world/common/atomic/MakeKeyChoice.inc.c"

EvtScript N(80241CD4) = {
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
            EVT_BITWISE_OR_CONST(LVar0, 0x00050000)
            EVT_CALL(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_60005)
            EVT_WAIT(30)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_CALL(RemoveItemEntity, LVar0)
    EVT_END_SWITCH
    EVT_CALL(N(ItemChoice_SaveSelected), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80241E18) = {
    EVT_CALL(N(BuildKeyItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(EVT_PTR(N(80241CD4)), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(KeyItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LVar0)
    EVT_RETURN
    EVT_END
};
