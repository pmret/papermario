#include "dro_02.h"

EvtScript N(EVS_SwingToadHouseSign) = {
    EVT_LABEL(9)
        EVT_CALL(MakeLerp, 10, -10, 30, EASING_COS_IN_OUT)
        EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o852, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_CALL(MakeLerp, -10, 10, 30, EASING_COS_IN_OUT)
        EVT_LABEL(11)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o852, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(11)
            EVT_END_IF
        EVT_GOTO(9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UnusedDoorSetup) = {
    EVT_DIV(LVar0, 2)
    EVT_ADD(LVar0, 18)
    EVT_CALL(RotateModel, MODEL_1_doa, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Hideout) = {
    EVT_CALL(RotateModel, MODEL_o769, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o770, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_Hideout) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(TranslateModel, MODEL_6_kabe, 0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_6_waku, 0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_6_moyou, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_6_kabe, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_6_waku, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_6_moyou, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_Hideout) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(TranslateModel, MODEL_o769, 0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_o770, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o769, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o770, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    EVT_CALL(RotateModel, MODEL_4_doa, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(RotateGroup, MODEL_mobe, LVar0, 0, 0, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupCamSpeed) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
        EVT_CASE_EQ(3)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.334))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_ie4_naka, MODEL_GROUP_VISIBLE)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_ie4_naka, MODEL_GROUP_HIDDEN)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.334))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_Hideout) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_ie5_naka, MODEL_GROUP_VISIBLE)
            EVT_CALL(SetCamType, CAM_DEFAULT, 0, FALSE)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 260)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, 22, -13)
            EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 290)
            EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -290)
            EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, -395, 140, -150)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, -365, 140, -145)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, 20, -7)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_ie5_naka, MODEL_GROUP_HIDDEN)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.334))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenSecretDoor_FromOutside) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(PlayerMoveTo, 230, 10, 20)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1287, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o1287, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 18, 80, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_1_doa, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlayerMoveTo, 230, -70, 15)
    EVT_CALL(MakeLerp, 80, 18, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_1_doa, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o1287, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1287, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenSecretDoor_FromInside) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(PlayerMoveTo, 230, -70, 20)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1289, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o1289, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 18, 80, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_1_doa, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlayerMoveTo, 230, 10, 15)
    EVT_CALL(MakeLerp, 80, 18, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_1_doa, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o1289, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1289, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
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
    EVT_EXEC(N(EVS_SwingToadHouseSign))
    EVT_CALL(ParentColliderToModel, COLLIDER_o1287, MODEL_1_doa)
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_BOUGHT_SECRET_ITEMS)
        EVT_CALL(RotateModel, MODEL_1_doa, 18, 0, 1, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o1287)
    EVT_END_IF
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_STRAIGHT_THROUGH),
        EVT_PTR(N(EVS_SetDoorRot_Hideout)),
        EVT_PTR(N(EVS_SetWallRot_Hideout)),
        EVT_PTR(N(EVS_DropDoor_Hideout)),
        EVT_PTR(N(EVS_RoomListener_Hideout)),
        COLLIDER_o1252,
        COLLIDER_o1253,
        MODEL_k_i5,
        EVT_PTR(N(InsideNPCs_Hideout)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH2_BOUGHT_SECRET_ITEMS)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OpenSecretDoor_FromOutside)), TRIGGER_WALL_PRESS_A, COLLIDER_o1287, 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OpenSecretDoor_FromInside)), TRIGGER_WALL_PRESS_A, COLLIDER_o1289, 1, 0)
    EVT_END_IF
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_ToadHouse)),
        EVT_PTR(N(EVS_SetWallRot_ToadHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_o1204,
        COLLIDER_o1261,
        MODEL_k_i4,
        EVT_PTR(N(InsideNPCs_ToadHouse)))
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_END)
    EVT_EXEC(N(EVS_RoomListener_Hideout))
    EVT_EXEC(N(EVS_SetupCamSpeed))
    EVT_EXEC(N(EVS_RoomListener_ToadHouse))
    EVT_RETURN
    EVT_END
};
