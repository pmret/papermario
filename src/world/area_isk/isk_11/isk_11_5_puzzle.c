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
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_Socket1)), TRIGGER_WALL_PRESS_A, COLLIDER_o2087, EVT_PTR(N(ItemList_Artifacts)), 0, 1)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_Socket2)), TRIGGER_WALL_PRESS_A, COLLIDER_o2091, EVT_PTR(N(ItemList_Artifacts)), 0, 1)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_Socket3)), TRIGGER_WALL_PRESS_A, COLLIDER_o2090, EVT_PTR(N(ItemList_Artifacts)), 0, 1)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_Socket4)), TRIGGER_WALL_PRESS_A, COLLIDER_o2089, EVT_PTR(N(ItemList_Artifacts)), 0, 1)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_Socket5)), TRIGGER_WALL_PRESS_A, COLLIDER_o2088, EVT_PTR(N(ItemList_Artifacts)), 0, 1)
    EVT_END_IF
    EVT_SET(MV_Socket1_ItemEntity, -1)
    EVT_SET(MV_Socket2_ItemEntity, -1)
    EVT_SET(MV_Socket3_ItemEntity, -1)
    EVT_SET(MV_Socket4_ItemEntity, -1)
    EVT_SET(MV_Socket5_ItemEntity, -1)
    EVT_IF_NE(GB_ISK11_ItemSocket1, 0)
        EVT_CALL(MakeItemEntity, GB_ISK11_ItemSocket1, -88, -508, 502, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket1_ItemEntity, LVar0)
    EVT_END_IF
    EVT_IF_NE(GB_ISK11_ItemSocket2, 0)
        EVT_CALL(MakeItemEntity, GB_ISK11_ItemSocket2, -44, -508, 508, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket2_ItemEntity, LVar0)
    EVT_END_IF
    EVT_IF_NE(GB_ISK11_ItemSocket3, 0)
        EVT_CALL(MakeItemEntity, GB_ISK11_ItemSocket3, 0, -508, 510, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket3_ItemEntity, LVar0)
    EVT_END_IF
    EVT_IF_NE(GB_ISK11_ItemSocket4, 0)
        EVT_CALL(MakeItemEntity, GB_ISK11_ItemSocket4, 44, -508, 508, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket4_ItemEntity, LVar0)
    EVT_END_IF
    EVT_IF_NE(GB_ISK11_ItemSocket5, 0)
        EVT_CALL(MakeItemEntity, GB_ISK11_ItemSocket5, 88, -508, 502, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket5_ItemEntity, LVar0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ItemPrompt_Socket1) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        EVT_UNBIND
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_IF_NE(GB_ISK11_ItemSocket1, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(N(GetItemNameInSocket), GB_ISK11_ItemSocket1, LVar0)
        EVT_CALL(SetMessageText, LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_ISK11_TakeItemPrompt, 160, 40)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_CALL(CloseMessage)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o2087, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
            EVT_CALL(AddKeyItem, GB_ISK11_ItemSocket1)
            EVT_SET(LVar0, GB_ISK11_ItemSocket1)
            EVT_SET(GB_ISK11_ItemSocket1, 0)
            EVT_CALL(RemoveItemEntity, MV_Socket1_ItemEntity)
            EVT_SET(MV_Socket1_ItemEntity, -1)
            EVT_CALL(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_SOUND)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVar2, LVar0)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_ChompStatue, 160, 40)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
        EVT_CASE_EQ(-1)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SET(GB_ISK11_ItemSocket1, LVar2)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(MakeItemEntity, GB_ISK11_ItemSocket1, -88, -508, 502, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(MV_Socket1_ItemEntity, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2087, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ItemPrompt_Socket2) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        EVT_UNBIND
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_IF_NE(GB_ISK11_ItemSocket2, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(N(GetItemNameInSocket), GB_ISK11_ItemSocket2, LVar0)
        EVT_CALL(SetMessageText, LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_ISK11_TakeItemPrompt, 160, 40)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_CALL(CloseMessage)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o2091, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
            EVT_CALL(AddKeyItem, GB_ISK11_ItemSocket2)
            EVT_SET(LVar0, GB_ISK11_ItemSocket2)
            EVT_SET(GB_ISK11_ItemSocket2, 0)
            EVT_CALL(RemoveItemEntity, MV_Socket2_ItemEntity)
            EVT_SET(MV_Socket2_ItemEntity, -1)
            EVT_CALL(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_SOUND)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVar2, LVar0)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_ChompStatue, 160, 40)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
        EVT_CASE_EQ(-1)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SET(GB_ISK11_ItemSocket2, LVar2)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(MakeItemEntity, GB_ISK11_ItemSocket2, -44, -508, 508, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(MV_Socket2_ItemEntity, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2091, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ItemPrompt_Socket3) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        EVT_UNBIND
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_IF_NE(GB_ISK11_ItemSocket3, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(N(GetItemNameInSocket), GB_ISK11_ItemSocket3, LVar0)
        EVT_CALL(SetMessageText, LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_ISK11_TakeItemPrompt, 160, 40)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_CALL(CloseMessage)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o2090, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
            EVT_CALL(AddKeyItem, GB_ISK11_ItemSocket3)
            EVT_SET(LVar0, GB_ISK11_ItemSocket3)
            EVT_SET(GB_ISK11_ItemSocket3, 0)
            EVT_CALL(RemoveItemEntity, MV_Socket3_ItemEntity)
            EVT_SET(MV_Socket3_ItemEntity, -1)
            EVT_CALL(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_SOUND)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVar2, LVar0)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_ChompStatue, 160, 40)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
        EVT_CASE_EQ(-1)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SET(GB_ISK11_ItemSocket3, LVar2)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(MakeItemEntity, GB_ISK11_ItemSocket3, 0, -508, 510, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(MV_Socket3_ItemEntity, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2090, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ItemPrompt_Socket4) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        EVT_UNBIND
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_IF_NE(GB_ISK11_ItemSocket4, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(N(GetItemNameInSocket), GB_ISK11_ItemSocket4, LVar0)
        EVT_CALL(SetMessageText, LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_ISK11_TakeItemPrompt, 160, 40)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_CALL(CloseMessage)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o2089, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
            EVT_CALL(AddKeyItem, GB_ISK11_ItemSocket4)
            EVT_SET(LVar0, GB_ISK11_ItemSocket4)
            EVT_SET(GB_ISK11_ItemSocket4, 0)
            EVT_CALL(RemoveItemEntity, MV_Socket4_ItemEntity)
            EVT_SET(MV_Socket4_ItemEntity, -1)
            EVT_CALL(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_SOUND)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVar2, LVar0)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_ChompStatue, 160, 40)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
        EVT_CASE_EQ(-1)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SET(GB_ISK11_ItemSocket4, LVar2)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(MakeItemEntity, GB_ISK11_ItemSocket4, 44, -508, 508, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(MV_Socket4_ItemEntity, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2089, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ItemPrompt_Socket5) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        EVT_UNBIND
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_IF_NE(GB_ISK11_ItemSocket5, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(N(GetItemNameInSocket), GB_ISK11_ItemSocket5, LVar0)
        EVT_CALL(SetMessageText, LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_ISK11_TakeItemPrompt, 160, 40)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_CALL(CloseMessage)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o2088, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
            EVT_CALL(AddKeyItem, GB_ISK11_ItemSocket5)
            EVT_SET(LVar0, GB_ISK11_ItemSocket5)
            EVT_SET(GB_ISK11_ItemSocket5, 0)
            EVT_CALL(RemoveItemEntity, MV_Socket5_ItemEntity)
            EVT_SET(MV_Socket5_ItemEntity, -1)
            EVT_CALL(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_NO_SOUND)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVar2, LVar0)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_ChompStatue, 160, 40)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
        EVT_CASE_EQ(-1)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SET(GB_ISK11_ItemSocket5, LVar2)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(MakeItemEntity, GB_ISK11_ItemSocket5, 88, -508, 502, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(MV_Socket5_ItemEntity, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2088, SOUND_ISK_PLACE_IN_SOCKET, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};
