#include "isk_11.h"

extern EvtScript N(EVS_ItemPrompt_Socket1);
extern EvtScript N(EVS_ItemPrompt_Socket2);
extern EvtScript N(EVS_ItemPrompt_Socket3);
extern EvtScript N(EVS_ItemPrompt_Socket4);
extern EvtScript N(EVS_ItemPrompt_Socket5);

API_CALLABLE(N(GetItemNameInSocket)) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, gItemTable[itemID & 0xFFF0FFFF].nameMsg);
    return ApiStatus_DONE2;
}

s32 N(ItemList_Artifacts)[] = {
    ITEM_LUNAR_STONE,
    ITEM_PYRAMID_STONE,
    ITEM_DIAMOND_STONE,
    ITEM_NONE
};

EvtScript N(EVS_SetupPuzzle) = {
    IfLt(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        BindPadlock(Ref(N(EVS_ItemPrompt_Socket1)), TRIGGER_WALL_PRESS_A, COLLIDER_o2087, Ref(N(ItemList_Artifacts)), 0, 1)
        BindPadlock(Ref(N(EVS_ItemPrompt_Socket2)), TRIGGER_WALL_PRESS_A, COLLIDER_o2091, Ref(N(ItemList_Artifacts)), 0, 1)
        BindPadlock(Ref(N(EVS_ItemPrompt_Socket3)), TRIGGER_WALL_PRESS_A, COLLIDER_o2090, Ref(N(ItemList_Artifacts)), 0, 1)
        BindPadlock(Ref(N(EVS_ItemPrompt_Socket4)), TRIGGER_WALL_PRESS_A, COLLIDER_o2089, Ref(N(ItemList_Artifacts)), 0, 1)
        BindPadlock(Ref(N(EVS_ItemPrompt_Socket5)), TRIGGER_WALL_PRESS_A, COLLIDER_o2088, Ref(N(ItemList_Artifacts)), 0, 1)
    EndIf
    Set(MV_Socket1_ItemEntity, -1)
    Set(MV_Socket2_ItemEntity, -1)
    Set(MV_Socket3_ItemEntity, -1)
    Set(MV_Socket4_ItemEntity, -1)
    Set(MV_Socket5_ItemEntity, -1)
    IfNe(GB_ISK11_ItemSocket1, 0)
        Call(MakeItemEntity, GB_ISK11_ItemSocket1, -88, -508, 502, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket1_ItemEntity, LVar0)
    EndIf
    IfNe(GB_ISK11_ItemSocket2, 0)
        Call(MakeItemEntity, GB_ISK11_ItemSocket2, -44, -508, 508, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket2_ItemEntity, LVar0)
    EndIf
    IfNe(GB_ISK11_ItemSocket3, 0)
        Call(MakeItemEntity, GB_ISK11_ItemSocket3, 0, -508, 510, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket3_ItemEntity, LVar0)
    EndIf
    IfNe(GB_ISK11_ItemSocket4, 0)
        Call(MakeItemEntity, GB_ISK11_ItemSocket4, 44, -508, 508, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket4_ItemEntity, LVar0)
    EndIf
    IfNe(GB_ISK11_ItemSocket5, 0)
        Call(MakeItemEntity, GB_ISK11_ItemSocket5, 88, -508, 502, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket5_ItemEntity, LVar0)
    EndIf
    Return
    End
};

EvtScript N(EVS_ItemPrompt_Socket1) = {
    IfGe(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        Unbind
        Return
    EndIf
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    IfNe(GB_ISK11_ItemSocket1, 0)
        Call(DisablePlayerInput, TRUE)
        Call(N(GetItemNameInSocket), GB_ISK11_ItemSocket1, LVar0)
        Call(SetMessageText, LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_ISK11_TakeItemPrompt, 160, 40)
        Call(ShowChoice, MSG_Choice_000D)
        Call(CloseMessage)
        IfEq(LVar0, 0)
            Call(PlaySoundAtCollider, COLLIDER_o2087, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
            Call(AddKeyItem, GB_ISK11_ItemSocket1)
            Set(LVar0, GB_ISK11_ItemSocket1)
            Set(GB_ISK11_ItemSocket1, 0)
            Call(RemoveItemEntity, MV_Socket1_ItemEntity)
            Set(MV_Socket1_ItemEntity, -1)
            Call(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_SOUND)
        EndIf
        Call(DisablePlayerInput, FALSE)
        Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        Return
    EndIf
    Call(ShowKeyChoicePopup)
    Set(LVar2, LVar0)
    Switch(LVar2)
        CaseEq(0)
            Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_ChompStatue, 160, 40)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
        CaseEq(-1)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
    EndSwitch
    Set(GB_ISK11_ItemSocket1, LVar2)
    Call(RemoveKeyItemAt, LVar1)
    Call(MakeItemEntity, GB_ISK11_ItemSocket1, -88, -508, 502, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(MV_Socket1_ItemEntity, LVar0)
    Call(CloseChoicePopup)
    Call(PlaySoundAtCollider, COLLIDER_o2087, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    End
};

EvtScript N(EVS_ItemPrompt_Socket2) = {
    IfGe(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        Unbind
        Return
    EndIf
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    IfNe(GB_ISK11_ItemSocket2, 0)
        Call(DisablePlayerInput, TRUE)
        Call(N(GetItemNameInSocket), GB_ISK11_ItemSocket2, LVar0)
        Call(SetMessageText, LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_ISK11_TakeItemPrompt, 160, 40)
        Call(ShowChoice, MSG_Choice_000D)
        Call(CloseMessage)
        IfEq(LVar0, 0)
            Call(PlaySoundAtCollider, COLLIDER_o2091, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
            Call(AddKeyItem, GB_ISK11_ItemSocket2)
            Set(LVar0, GB_ISK11_ItemSocket2)
            Set(GB_ISK11_ItemSocket2, 0)
            Call(RemoveItemEntity, MV_Socket2_ItemEntity)
            Set(MV_Socket2_ItemEntity, -1)
            Call(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_SOUND)
        EndIf
        Call(DisablePlayerInput, FALSE)
        Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        Return
    EndIf
    Call(ShowKeyChoicePopup)
    Set(LVar2, LVar0)
    Switch(LVar2)
        CaseEq(0)
            Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_ChompStatue, 160, 40)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
        CaseEq(-1)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
    EndSwitch
    Set(GB_ISK11_ItemSocket2, LVar2)
    Call(RemoveKeyItemAt, LVar1)
    Call(MakeItemEntity, GB_ISK11_ItemSocket2, -44, -508, 508, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(MV_Socket2_ItemEntity, LVar0)
    Call(CloseChoicePopup)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Call(PlaySoundAtCollider, COLLIDER_o2091, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_ItemPrompt_Socket3) = {
    IfGe(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        Unbind
        Return
    EndIf
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    IfNe(GB_ISK11_ItemSocket3, 0)
        Call(DisablePlayerInput, TRUE)
        Call(N(GetItemNameInSocket), GB_ISK11_ItemSocket3, LVar0)
        Call(SetMessageText, LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_ISK11_TakeItemPrompt, 160, 40)
        Call(ShowChoice, MSG_Choice_000D)
        Call(CloseMessage)
        IfEq(LVar0, 0)
            Call(PlaySoundAtCollider, COLLIDER_o2090, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
            Call(AddKeyItem, GB_ISK11_ItemSocket3)
            Set(LVar0, GB_ISK11_ItemSocket3)
            Set(GB_ISK11_ItemSocket3, 0)
            Call(RemoveItemEntity, MV_Socket3_ItemEntity)
            Set(MV_Socket3_ItemEntity, -1)
            Call(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_SOUND)
        EndIf
        Call(DisablePlayerInput, FALSE)
        Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        Return
    EndIf
    Call(ShowKeyChoicePopup)
    Set(LVar2, LVar0)
    Switch(LVar2)
        CaseEq(0)
            Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_ChompStatue, 160, 40)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
        CaseEq(-1)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
    EndSwitch
    Set(GB_ISK11_ItemSocket3, LVar2)
    Call(RemoveKeyItemAt, LVar1)
    Call(MakeItemEntity, GB_ISK11_ItemSocket3, 0, -508, 510, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(MV_Socket3_ItemEntity, LVar0)
    Call(CloseChoicePopup)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Call(PlaySoundAtCollider, COLLIDER_o2090, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_ItemPrompt_Socket4) = {
    IfGe(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        Unbind
        Return
    EndIf
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    IfNe(GB_ISK11_ItemSocket4, 0)
        Call(DisablePlayerInput, TRUE)
        Call(N(GetItemNameInSocket), GB_ISK11_ItemSocket4, LVar0)
        Call(SetMessageText, LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_ISK11_TakeItemPrompt, 160, 40)
        Call(ShowChoice, MSG_Choice_000D)
        Call(CloseMessage)
        IfEq(LVar0, 0)
            Call(PlaySoundAtCollider, COLLIDER_o2089, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
            Call(AddKeyItem, GB_ISK11_ItemSocket4)
            Set(LVar0, GB_ISK11_ItemSocket4)
            Set(GB_ISK11_ItemSocket4, 0)
            Call(RemoveItemEntity, MV_Socket4_ItemEntity)
            Set(MV_Socket4_ItemEntity, -1)
            Call(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_SOUND)
        EndIf
        Call(DisablePlayerInput, FALSE)
        Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        Return
    EndIf
    Call(ShowKeyChoicePopup)
    Set(LVar2, LVar0)
    Switch(LVar2)
        CaseEq(0)
            Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_ChompStatue, 160, 40)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
        CaseEq(-1)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
    EndSwitch
    Set(GB_ISK11_ItemSocket4, LVar2)
    Call(RemoveKeyItemAt, LVar1)
    Call(MakeItemEntity, GB_ISK11_ItemSocket4, 44, -508, 508, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(MV_Socket4_ItemEntity, LVar0)
    Call(CloseChoicePopup)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Call(PlaySoundAtCollider, COLLIDER_o2089, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_ItemPrompt_Socket5) = {
    IfGe(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        Unbind
        Return
    EndIf
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    IfNe(GB_ISK11_ItemSocket5, 0)
        Call(DisablePlayerInput, TRUE)
        Call(N(GetItemNameInSocket), GB_ISK11_ItemSocket5, LVar0)
        Call(SetMessageText, LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_ISK11_TakeItemPrompt, 160, 40)
        Call(ShowChoice, MSG_Choice_000D)
        Call(CloseMessage)
        IfEq(LVar0, 0)
            Call(PlaySoundAtCollider, COLLIDER_o2088, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
            Call(AddKeyItem, GB_ISK11_ItemSocket5)
            Set(LVar0, GB_ISK11_ItemSocket5)
            Set(GB_ISK11_ItemSocket5, 0)
            Call(RemoveItemEntity, MV_Socket5_ItemEntity)
            Set(MV_Socket5_ItemEntity, -1)
            Call(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_SOUND)
        EndIf
        Call(DisablePlayerInput, FALSE)
        Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        Return
    EndIf
    Call(ShowKeyChoicePopup)
    Set(LVar2, LVar0)
    Switch(LVar2)
        CaseEq(0)
            Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_ChompStatue, 160, 40)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
        CaseEq(-1)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            Return
    EndSwitch
    Set(GB_ISK11_ItemSocket5, LVar2)
    Call(RemoveKeyItemAt, LVar1)
    Call(MakeItemEntity, GB_ISK11_ItemSocket5, 88, -508, 502, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(MV_Socket5_ItemEntity, LVar0)
    Call(CloseChoicePopup)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Call(PlaySoundAtCollider, COLLIDER_o2088, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
    Return
    End
};
