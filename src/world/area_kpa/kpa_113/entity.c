#include "kpa_113.h"
#include "entity.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(KeyList_BowsersCastle)[] = {
    ITEM_BOWSER_CASTLE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_ExitDoors_kpa_82_0) = EVT_EXIT_DOUBLE_DOOR(kpa_113_ENTRY_1, "kpa_82", kpa_82_ENTRY_0, COLLIDER_deiliett, MODEL_o136, MODEL_o137);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_UnlockPrompt_LockedDoor) = {
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
    Call(PlaySound, SOUND_USE_KEY)
    Call(RemoveKeyItemAt, LVar1)
    Set(GF_KPA113_UnlockedDoor, TRUE)
    Set(LVar0, MV_PadlockEntityID)
    Call(N(RemovePadlock))
    Set(LVar1, 0)
    Wait(5)
    Call(CloseChoicePopup)
    Unbind
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_82_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliett, 1, 0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_KPA113_UnlockedDoor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), 418, 10, 100, 280, MAKE_ENTITY_END)
        Set(MV_PadlockEntityID, LVar0)
        BindPadlock(Ref(N(EVS_UnlockPrompt_LockedDoor)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(KeyList_BowsersCastle)), 0, 1)
    Else
        BindTrigger(Ref(N(EVS_ExitDoors_kpa_82_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliett, 1, 0)
    EndIf
    Call(MakeEntity, Ref(Entity_SavePoint), 375, 60, 50, 0, MAKE_ENTITY_END)
    Return
    End
};
