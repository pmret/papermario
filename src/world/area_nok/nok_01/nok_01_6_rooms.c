#include "nok_01.h"

API_CALLABLE(N(OnEnterShop)) {
    status_bar_always_show_on();
    status_bar_ignore_changes();
    open_status_bar_slowly();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(OnExitShop)) {
    status_bar_always_show_off();
    status_bar_respond_to_changes();
    close_status_bar();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateSwingingSigns) = {
    EVT_LABEL(9)
        EVT_CALL(MakeLerp, 10, -10, 30, EASING_COS_IN_OUT)
        EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o287, LVar0, 1, 0, 0)
            EVT_CALL(RotateModel, MODEL_o201, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_CALL(MakeLerp, -10, 10, 30, EASING_COS_IN_OUT)
        EVT_LABEL(11)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o287, LVar0, 1, 0, 0)
            EVT_CALL(RotateModel, MODEL_o201, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(11)
            EVT_END_IF
        EVT_GOTO(9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpinCeilingFan) = {
    EVT_LABEL(0)
        EVT_SET(LVar0, 35)
        EVT_LOOP(LVar0)
            EVT_SET(LVar1, LVar0)
            EVT_MUL(LVar1, 10)
            EVT_CALL(RotateModel, MODEL_o247, LVar1, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    EVT_CALL(RotateModel, MODEL_o200, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallsRot_ToadHouse) = {
    EVT_CALL(RotateModel, MODEL_o197, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o196, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o195, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o199, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o194, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o193, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o190, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o192, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_WAIT(20)
            EVT_SET(LVar0, 0)
            EVT_LOOP(18)
                EVT_ADD(LVar0, 5)
                EVT_EXEC_WAIT(N(EVS_SetWallsRot_ToadHouse))
            EVT_END_LOOP
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, 90)
            EVT_LOOP(18)
                EVT_SUB(LVar0, 5)
                EVT_EXEC_WAIT(N(EVS_SetWallsRot_ToadHouse))
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Shop) = {
    EVT_CALL(RotateModel, MODEL_o226, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallsRot_Shop) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 45)
    EVT_CALL(TranslateModel, MODEL_o225, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o225, LVar0, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o224, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o223, LVar0, 0, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_Shop) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_WAIT(20)
            EVT_CALL(N(OnEnterShop))
            EVT_SET(LVar0, 0)
            EVT_LOOP(18)
                EVT_ADD(LVar0, 5)
                EVT_EXEC_WAIT(N(EVS_SetWallsRot_Shop))
            EVT_END_LOOP
        EVT_CASE_EQ(3)
            EVT_CALL(N(OnExitShop))
            EVT_SET(LVar0, 90)
            EVT_LOOP(18)
                EVT_SUB(LVar0, 5)
                EVT_EXEC_WAIT(N(EVS_SetWallsRot_Shop))
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_BeachHouse) = {
    EVT_CALL(RotateModel, MODEL_o246, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallsRot_BeachHouse) = {
    EVT_SETF(LVar1, LVar0)
    EVT_DIVF(LVar1, 2)
    EVT_CALL(RotateModel, MODEL_o243, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o244, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o242, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o245, LVar1, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_BeachHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar0, 0)
            EVT_LOOP(18)
                EVT_ADD(LVar0, 5)
                EVT_EXEC_WAIT(N(EVS_SetWallsRot_BeachHouse))
            EVT_END_LOOP
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, 90)
            EVT_LOOP(18)
                EVT_SUB(LVar0, 5)
                EVT_EXEC_WAIT(N(EVS_SetWallsRot_BeachHouse))
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_BeachHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 45)
    EVT_CALL(TranslateModel, MODEL_o246, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o246, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_g111, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_g111, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_Shop) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_g114, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_g114, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_BeachHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_g79, MODEL_GROUP_VISIBLE)
            EVT_CALL(N(SetRadioVolumeMax), AB_NOK_0)
            EVT_EXEC(N(EVS_80242C38))
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            EVT_CALL(N(SetRadioVolumeMute), AB_NOK_0)
            EVT_EXEC(N(EVS_80242DE0))
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_g79, MODEL_GROUP_HIDDEN)
            EVT_CALL(N(func_80242898_9C7C78))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_ToadHouse)[] = {
    NPC_MortT,
    -1
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_Koopa_ShopOwner,
    -1
};

s32 N(InteriorNPCs_BeachHouse_Before)[] = {
    NPC_RelaxedKoopa,
    NPC_Bobomb_01,
    NPC_Bobomb_02,
    -1
};

s32 N(InteriorNPCs_BeachHouse_After)[] = {
    NPC_RelaxedKoopa,
    -1
};

EvtScript N(EVS_MakeRooms) = {
    // toad house
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
        EVT_PTR(N(EVS_SetDoorRot_ToadHouse)),
        EVT_PTR(N(EVS_SetWallRot_ToadHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_o200,
        COLLIDER_o284,
        MODEL_aka,
        EVT_PTR(N(InteriorNPCs_ToadHouse)))
    // shop
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
        EVT_PTR(N(EVS_SetDoorRot_Shop)),
        EVT_PTR(N(EVS_SetWallRot_Shop)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_Shop)),
        COLLIDER_o226,
        COLLIDER_o286,
        MODEL_ki,
        EVT_PTR(N(InteriorNPCs_Shop)))
    // beach house
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            EVT_PTR(N(EVS_SetDoorRot_BeachHouse)),
            EVT_PTR(N(EVS_SetWallRot_BeachHouse)),
            EVT_PTR(N(EVS_DropDoor_BeachHouse)),
            EVT_PTR(N(EVS_RoomListener_BeachHouse)),
            COLLIDER_o246,
            COLLIDER_o291,
            MODEL_ao,
            EVT_PTR(N(InteriorNPCs_BeachHouse_Before)))
    EVT_ELSE
        EVT_CALL(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            EVT_PTR(N(EVS_SetDoorRot_BeachHouse)),
            EVT_PTR(N(EVS_SetWallRot_BeachHouse)),
            EVT_PTR(N(EVS_DropDoor_BeachHouse)),
            EVT_PTR(N(EVS_RoomListener_BeachHouse)),
            COLLIDER_o246,
            COLLIDER_o291,
            MODEL_ao,
            EVT_PTR(N(InteriorNPCs_BeachHouse_After)))
    EVT_END_IF
    EVT_CALL(N(InitializeRadio))
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_END)
    EVT_EXEC(N(EVS_RoomListener_ToadHouse))
    EVT_EXEC(N(EVS_RoomListener_Shop))
    EVT_EXEC(N(EVS_RoomListener_BeachHouse))
    EVT_EXEC(N(EVS_AnimateSwingingSigns))
    EVT_EXEC(N(EVS_SpinCeilingFan))
    EVT_RETURN
    EVT_END
};
