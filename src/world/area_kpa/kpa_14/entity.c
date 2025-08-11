
#include "kpa_14.h"
#include "entity.h"

// similar to Chest.inc.c, except a script is missing...
#include "world/common/todo/StashVars.inc.c"
#include "world/common/todo/GetItemName.inc.c"
#include "world/common/todo/SomeItemEntityFunc.inc.c"
#include "world/common/todo/IsItemBadge.inc.c"

s32** N(varStash) = nullptr;

EvtScript N(EVS_Chest_ShowGotItem) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_FULL)
    Wait(40)
    Call(ShowGotItem, LVar0, false, 0)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Return
    Return
    End
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

s32 N(KeyList_BowsersCastle)[] = {
    ITEM_BOWSER_CASTLE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_Door) = {
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        Return
    EndIf
    Call(RemoveKeyItemAt, LVar1)
    Set(GF_KPA14_UnlockedDoor, true)
    Call(N(GetEntityPosition), MV_PadlockEntityID, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_PadlockEntityID)
    Call(N(RemovePadlock))
    Set(LVar1, 0)
    Wait(5)
    Call(CloseChoicePopup)
    Unbind
    BindTrigger(Ref(N(EVS_ExitDoor_kpa_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_KPA14_UnlockedDoor, false)
        Call(MakeEntity, Ref(Entity_Padlock), 1995, 40, -162, 270, MAKE_ENTITY_END)
        Set(MV_PadlockEntityID, LVar0)
        BindPadlock(Ref(N(EVS_UnlockPrompt_Door)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(KeyList_BowsersCastle)), 0, 1)
    Else
        BindTrigger(Ref(N(EVS_ExitDoor_kpa_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    EndIf
    Call(MakeItemEntity, ITEM_MYSTERY, 350, 30, -150, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KPA14_Item_Mystery)
    Call(MakeItemEntity, ITEM_THUNDER_RAGE, 800, 30, -150, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KPA14_Item_ThunderRage)
    Return
    End
};
