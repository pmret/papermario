#include "dro_02.h"

EvtScript N(EVS_SwingToadHouseSign) = {
    Label(9)
        Call(MakeLerp, 10, -10, 30, EASING_COS_IN_OUT)
        Label(10)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o852, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Call(MakeLerp, -10, 10, 30, EASING_COS_IN_OUT)
        Label(11)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o852, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(11)
            EndIf
        Goto(9)
    Return
    End
};

EvtScript N(EVS_UnusedDoorSetup) = {
    Div(LVar0, 2)
    Add(LVar0, 18)
    Call(RotateModel, MODEL_1_doa, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Hideout) = {
    Call(RotateModel, MODEL_o769, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_o770, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Hideout) = {
    Set(LVar1, LVar0)
    DivF(LVar1, 50)
    Call(TranslateModel, MODEL_6_kabe, 0, LVar1, 0)
    Call(TranslateModel, MODEL_6_waku, 0, LVar1, 0)
    Call(TranslateModel, MODEL_6_moyou, 0, LVar1, 0)
    Call(RotateModel, MODEL_6_kabe, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_6_waku, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_6_moyou, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_Hideout) = {
    Set(LVar1, LVar0)
    DivF(LVar1, 50)
    Call(TranslateModel, MODEL_o769, 0, LVar1, 0)
    Call(TranslateModel, MODEL_o770, 0, LVar1, 0)
    Call(RotateModel, MODEL_o769, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o770, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    Call(RotateModel, MODEL_4_doa, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    Set(LVar1, LVar0)
    DivF(LVar1, 50)
    Call(RotateGroup, MODEL_mobe, LVar0, 0, 0, -1)
    Return
    End
};

EvtScript N(EVS_SetupCamSpeed) = {
    Switch(LVar0)
        CaseEq(0)
            Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
        CaseEq(3)
            Call(SetCamSpeed, CAM_DEFAULT, Float(1.334))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_ie4_naka, MODEL_GROUP_VISIBLE)
            Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_ie4_naka, MODEL_GROUP_HIDDEN)
            Call(SetCamSpeed, CAM_DEFAULT, Float(1.334))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_Hideout) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_ie5_naka, MODEL_GROUP_VISIBLE)
            Call(SetCamType, CAM_DEFAULT, 0, FALSE)
            Call(SetCamDistance, CAM_DEFAULT, 260)
            Call(SetCamPitch, CAM_DEFAULT, 22, -13)
            Call(SetCamPosA, CAM_DEFAULT, 0, 290)
            Call(SetCamPosB, CAM_DEFAULT, 0, -290)
            Call(SetCamPosC, CAM_DEFAULT, 0, 0)
            Call(SetPanTarget, CAM_DEFAULT, -395, 140, -150)
            Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            Call(SetPanTarget, CAM_DEFAULT, -365, 140, -145)
            Call(SetCamPitch, CAM_DEFAULT, 20, -7)
            Call(SetCamDistance, CAM_DEFAULT, 400)
            Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_ie5_naka, MODEL_GROUP_HIDDEN)
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
            Call(SetCamSpeed, CAM_DEFAULT, Float(1.334))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_OpenSecretDoor_FromOutside) = {
    SetGroup(EVT_GROUP_00)
    Call(DisablePlayerInput, TRUE)
    Call(func_802D2C14, 1)
    Call(PlayerMoveTo, 230, 10, 20)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1287, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_o1287, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 18, 80, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_1_doa, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlayerMoveTo, 230, -70, 15)
    Call(MakeLerp, 80, 18, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_1_doa, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_o1287, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1287, COLLIDER_FLAGS_UPPER_MASK)
    Call(func_802D2C14, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_OpenSecretDoor_FromInside) = {
    SetGroup(EVT_GROUP_00)
    Call(DisablePlayerInput, TRUE)
    Call(func_802D2C14, 1)
    Call(PlayerMoveTo, 230, -70, 20)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1289, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_o1289, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 18, 80, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_1_doa, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlayerMoveTo, 230, 10, 15)
    Call(MakeLerp, 80, 18, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_1_doa, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_o1289, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1289, COLLIDER_FLAGS_UPPER_MASK)
    Call(func_802D2C14, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

s32 N(InsideNPCs_Hideout)[] = {
    NPC_DisguisedMoustafa,
    NPC_Moustafa,
    -1
};

s32 N(InsideNPCs_ToadHouse)[] = {
    NPC_Toad,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    Exec(N(EVS_SwingToadHouseSign))
    Call(ParentColliderToModel, COLLIDER_o1287, MODEL_1_doa)
    IfGe(GB_StoryProgress, STORY_CH2_BOUGHT_SECRET_ITEMS)
        Call(RotateModel, MODEL_1_doa, 18, 0, 1, 0)
        Call(UpdateColliderTransform, COLLIDER_o1287)
    EndIf
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_STRAIGHT_THROUGH),
        Ref(N(EVS_SetDoorRot_Hideout)),
        Ref(N(EVS_SetWallRot_Hideout)),
        Ref(N(EVS_DropDoor_Hideout)),
        Ref(N(EVS_RoomListener_Hideout)),
        COLLIDER_o1252,
        COLLIDER_o1253,
        MODEL_k_i5,
        Ref(N(InsideNPCs_Hideout)))
    IfGe(GB_StoryProgress, STORY_CH2_BOUGHT_SECRET_ITEMS)
        BindTrigger(Ref(N(EVS_OpenSecretDoor_FromOutside)), TRIGGER_WALL_PRESS_A, COLLIDER_o1287, 1, 0)
        BindTrigger(Ref(N(EVS_OpenSecretDoor_FromInside)), TRIGGER_WALL_PRESS_A, COLLIDER_o1289, 1, 0)
    EndIf
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_ToadHouse)),
        Ref(N(EVS_SetWallRot_ToadHouse)),
        NULL,
        Ref(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_o1204,
        COLLIDER_o1261,
        MODEL_k_i4,
        Ref(N(InsideNPCs_ToadHouse)))
    Set(LVar0, ROOM_UPDATE_EXIT_END)
    Exec(N(EVS_RoomListener_Hideout))
    Exec(N(EVS_SetupCamSpeed))
    Exec(N(EVS_RoomListener_ToadHouse))
    Return
    End
};
