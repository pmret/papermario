#include "sam_11.h"

EvtScript N(EVS_SetDoorRot_LeftHouse) = {
    Call(RotateModel, MODEL_o541, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_LeftHouse) = {
    Call(RotateGroup, MODEL_g_ue, LVar0, 1, 0, 0)
    Call(RotateGroup, MODEL_g_sita, LVar0, 1, 0, 0)
    IfGt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_g_ue, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_g_sita, MODEL_GROUP_HIDDEN)
    EndIf
    IfLt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_g_ue, MODEL_GROUP_VISIBLE)
        Call(SetGroupVisibility, MODEL_g_sita, MODEL_GROUP_VISIBLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_DropDoor_LeftHouse) = {
    Call(RotateModel, MODEL_o541, LVar0, 1, 0, 0)
    IfGt(LVar0, 89)
    EndIf
    IfLt(LVar0, 89)
    EndIf
    Return
    End
};

EvtScript N(EVS_RoomListener_LeftHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Set(AF_SAM_Snowing, FALSE)
            Call(SetGroupVisibility, MODEL_g_naiso, MODEL_GROUP_VISIBLE)
            IfLt(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
            Else
                Call(EnableModel, MODEL_ana, FALSE)
            EndIf
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            IfEq(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
                IfEq(GF_SAM11_LeftHerringwaysHouse, FALSE)
                    Thread
                        Wait(30 * DT)
                        Call(MakeLerp, 0, 255, 20, EASING_LINEAR)
                        Loop(0)
                            Call(UpdateLerp)
                            Call(SetNpcImgFXParams, NPC_Herringway, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
                            Wait(1)
                            IfEq(LVar1, 0)
                                BreakLoop
                            EndIf
                        EndLoop
                        Wait(10 * DT)
                        Call(SetNpcAnimation, NPC_Herringway, ANIM_Herringway_Walk)
                        Call(PlayerFaceNpc, NPC_Herringway, FALSE)
                        Call(NpcMoveTo, NPC_Herringway, -500, 0, 50 * DT)
                        Call(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_GRAVITY, FALSE)
                        Call(SetNpcPos, NPC_Herringway, NPC_DISPOSE_LOCATION)
                    EndThread
                EndIf
            EndIf
        CaseEq(ROOM_UPDATE_EXIT_END)
            Set(AF_SAM_Snowing, TRUE)
            Call(SetGroupVisibility, MODEL_g_naiso, MODEL_GROUP_HIDDEN)
            Call(EnableModel, MODEL_gn_dan1, TRUE)
            IfEq(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
                IfEq(GF_SAM11_LeftHerringwaysHouse, FALSE)
                    Thread
                    EndThread
                    Set(GF_SAM11_LeftHerringwaysHouse, TRUE)
                EndIf
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_RightHouse) = {
    Call(RotateModel, MODEL_o540, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_RightHouse) = {
    Call(RotateGroup, MODEL_s_ue, LVar0, 1, 0, 0)
    Call(RotateGroup, MODEL_s_sita, LVar0, 1, 0, 0)
    IfGt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_s_ue, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_s_sita, MODEL_GROUP_HIDDEN)
    EndIf
    IfLt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_s_ue, MODEL_GROUP_VISIBLE)
        Call(SetGroupVisibility, MODEL_s_sita, MODEL_GROUP_VISIBLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_DropDoor_RightHouse) = {
    Call(RotateModel, MODEL_o540, LVar0, 1, 0, 0)
    Return
    End
};

s32 N(KeyList)[] = {
    ITEM_WAREHOUSE_KEY,
    ITEM_NONE
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_UnlockPrompt_LeftHouse) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    SuspendGroup(EVT_GROUP_FLAG_INTERACT)
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_FLAG_INTERACT)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_FLAG_INTERACT)
        Return
    EndIf
    Call(RemoveKeyItemAt, LVar1)
    Call(CloseChoicePopup)
    Set(GF_SAM11_UnlockedDoor, TRUE)
    Call(N(GetEntityPosition), MV_PadlockEntityID, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_PadlockEntityID)
    Call(N(RemovePadlock))
    ResumeGroup(EVT_GROUP_FLAG_INTERACT)
    Unbind
    Return
    End
};

EvtScript N(EVS_RoomListener_RightHouse) = {
    Switch(LVar0)
        CaseEq(0)
            Set(AF_SAM_Snowing, FALSE)
            Call(SetGroupVisibility, MODEL_s_naiso, MODEL_GROUP_VISIBLE)
        CaseEq(3)
            Set(AF_SAM_Snowing, TRUE)
            Call(SetGroupVisibility, MODEL_s_naiso, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

s32 N(InteriorNPCs_LeftHouse)[] = {
    NPC_Herringway,
    NPC_0B,
    -1
};

s32 N(InteriorNPCs_RightHouse)[] = {
    NPC_Herringway,
    -1
};

EvtScript N(EVS_SetupLockedHouse) = {
    // lower right house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_RightHouse)),
        Ref(N(EVS_SetWallRot_RightHouse)),
        Ref(N(EVS_DropDoor_RightHouse)),
        Ref(N(EVS_RoomListener_RightHouse)),
        COLLIDER_o540,
        COLLIDER_o591,
        MODEL_sou,
        Ref(N(InteriorNPCs_RightHouse)))
    Return
    End
};

EvtScript N(EVS_SetupRooms) = {
    Call(SetGroupVisibility, MODEL_g_naiso, MODEL_GROUP_HIDDEN)
    Call(EnableModel, MODEL_gn_dan1, TRUE)
    // lower left house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_LeftHouse)),
        Ref(N(EVS_SetWallRot_LeftHouse)),
        Ref(N(EVS_DropDoor_LeftHouse)),
        Ref(N(EVS_RoomListener_LeftHouse)),
        COLLIDER_o541,
        COLLIDER_o590,
        MODEL_gon,
        Ref(N(InteriorNPCs_LeftHouse)))
    Call(SetGroupVisibility, MODEL_s_naiso, MODEL_GROUP_HIDDEN)
    IfEq(GF_SAM11_UnlockedDoor, TRUE)
        ExecWait(N(EVS_SetupLockedHouse))
    Else
        BindPadlock(Ref(N(EVS_UnlockPrompt_LeftHouse)), TRIGGER_WALL_PRESS_A,
            EVT_ENTITY_INDEX(0), Ref(N(KeyList)), 0, 1)
    EndIf
    Return
    End
};

EvtScript N(EVS_HideRightHouse) = {
    Set(LVar0, 0)
    ExecWait(N(EVS_DropDoor_RightHouse))
    Set(LVar0, 0)
    ExecWait(N(EVS_SetWallRot_RightHouse))
    Set(LVar0, 0)
    ExecWait(N(EVS_SetDoorRot_RightHouse))
    Set(LVar0, ROOM_UPDATE_EXIT_END)
    ExecWait(N(EVS_RoomListener_RightHouse))
    Return
    End
};

EvtScript N(EVS_RevealRightHouse) = {
    Set(LVar0, ROOM_UPDATE_ENTER_BEGIN)
    ExecWait(N(EVS_RoomListener_RightHouse))
    Set(LVar0, 0)
    ExecWait(N(EVS_SetDoorRot_RightHouse))
    Set(LVar0, 90)
    ExecWait(N(EVS_SetWallRot_RightHouse))
    Set(LVar0, 90)
    ExecWait(N(EVS_DropDoor_RightHouse))
    Return
    End
};

EvtScript N(EVS_RevealLeftHouse) = {
    Set(LVar0, ROOM_UPDATE_ENTER_BEGIN)
    ExecWait(N(EVS_RoomListener_LeftHouse))
    Set(LVar0, 0)
    ExecWait(N(EVS_SetDoorRot_LeftHouse))
    Set(LVar0, 90)
    ExecWait(N(EVS_SetWallRot_LeftHouse))
    Set(LVar0, 90)
    ExecWait(N(EVS_DropDoor_LeftHouse))
    Return
    End
};
