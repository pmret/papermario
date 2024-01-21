#include "mac_02.h"
#include "entity.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(ItemList_OddKey)[] = {
    ITEM_ODD_KEY,
    ITEM_NONE
};

EvtScript N(EVS_ChooseItem_OddKey) = {
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
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, -470, 30, -155)
    Set(LVar0, MV_BlueHouseLockEntityID)
    Call(N(RemovePadlock))
    Wait(5)
    Call(RemoveKeyItemAt, LVar1)
    Set(GF_MAC02_UnlockedHouse, TRUE)
    Call(CloseChoicePopup)
    Unbind
    Return
    End
};

EvtScript N(EVS_ReadSign) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_016B, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_OnInspect_StreetSign) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_0171, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_02_ENTRY_5)
        IfEq(GF_MAC02_UnlockedHouse, FALSE)
            Call(MakeEntity, Ref(Entity_Padlock), -470, 30, -155, 180, MAKE_ENTITY_END)
            Set(MV_BlueHouseLockEntityID, LVar0)
            BindPadlock(Ref(N(EVS_ChooseItem_OddKey)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(ItemList_OddKey)), 0, 1)
        EndIf
    EndIf
    Call(MakeItemEntity, ITEM_ODD_KEY, -412, 20, -320, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC02_Item_OddKey)
    Call(MakeEntity, Ref(Entity_HiddenPanel), 400, 0, 100, 0, MODEL_o236, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_MAC02_HiddenPanel)
    Call(MakeEntity, Ref(Entity_Signpost), -375, 0, 190, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign)))
    BindTrigger(Ref(N(EVS_OnInspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    Return
    End
};
