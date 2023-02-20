#include "mac_00.h"

EvtScript N(EVS_SetDoorRot_RussHouse) = {
    EVT_CALL(RotateModel, MODEL_o210, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_RussHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-2.0))
    EVT_CALL(RotateModel, MODEL_o201, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o467, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o466, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-1.11))
    EVT_CALL(RotateModel, MODEL_o194, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o463, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o469, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o335, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-0.328125))
    EVT_CALL(RotateModel, MODEL_o198, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o460, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o461, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.218))
    EVT_CALL(RotateModel, MODEL_o213, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o215, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_RussHouse) = {
    EVT_CALL(RotateModel, MODEL_o210, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_RussHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_intel_inn, MODEL_GROUP_VISIBLE)
            EVT_SET(MF_MusicMixTrigger1, TRUE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_intel_inn, MODEL_GROUP_HIDDEN)
            EVT_SET(MF_MusicMixTrigger1, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Shop) = {
    EVT_CALL(RotateModel, MODEL_o121, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_Shop) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_o370, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o371, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o373, LVar1, 1, 0, 0)
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_o396, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o397, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o155, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o146, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o398, LVar1, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_Shop) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_shop_in, MODEL_GROUP_VISIBLE)
            EVT_CALL(EnableModel, MODEL_o375, FALSE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_shop_in, MODEL_GROUP_HIDDEN)
            EVT_CALL(EnableModel, MODEL_o375, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Dojo) = {
    EVT_CALL(RotateModel, MODEL_o168, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_Dojo) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateModel, MODEL_o159, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o169, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o164, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o162, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_Dojo) = {
    EVT_CALL(RotateModel, MODEL_o168, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_Dojo) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_minka_inn, MODEL_GROUP_VISIBLE)
            EVT_SET(MF_MusicMixTrigger2, TRUE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_minka_inn, MODEL_GROUP_HIDDEN)
            EVT_CALL(EnableMusicProximityMix, 0)
            EVT_SET(MF_MusicMixTrigger2, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Waterfront) = {
    EVT_CALL(RotateModel, MODEL_o228, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_Waterfront) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_o437, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o453, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o454, LVar1, 1, 0, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-0.671875))
    EVT_CALL(RotateModel, MODEL_o242, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o239, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o243, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o245, LVar1, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_Waterfront) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_BEGAN_PEACH_MISSION)
                    EVT_EXEC(N(EVS_WaterfrontHouse_DoorLocked))
                    EVT_SET(LVar0, -1)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetGroupVisibility, MODEL_minka2_inn, MODEL_GROUP_VISIBLE)
            EVT_END_SWITCH
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_minka2_inn, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_RussHouse)[] = {
    NPC_RussT,
    -1
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_Toad_01,
    NPC_ShyGuy_02,
    NPC_HarryT,
    -1
};

s32 N(InteriorNPCs_Dojo)[] = {
    NPC_TheMaster,
    NPC_Chan,
    NPC_Lee,
    -1
};

s32 N(InteriorNPCs_WaterfrontHouse)[] = {
    NPC_Waterfront_Dad,
    NPC_Waterfront_Mom,
    NPC_Waterfront_Kid1,
    NPC_Waterfront_Kid2,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // RussT's house
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_RussHouse)),
        EVT_PTR(N(EVS_SetWallRot_RussHouse)),
        EVT_PTR(N(EVS_DropDoor_RussHouse)),
        EVT_PTR(N(EVS_RoomListener_RussHouse)),
        COLLIDER_deilit3,
        COLLIDER_deilit3u,
        MODEL_intel_house,
        EVT_PTR(N(InteriorNPCs_RussHouse)))
    // harry's shop
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_Shop)),
        EVT_PTR(N(EVS_SetWallRot_Shop)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_Shop)),
        COLLIDER_deilit5, COLLIDER_deilit5u, MODEL_omise, EVT_PTR(N(InteriorNPCs_Shop)))
    // the dojo
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_Dojo)),
        EVT_PTR(N(EVS_SetWallRot_Dojo)),
        EVT_PTR(N(EVS_DropDoor_Dojo)),
        EVT_PTR(N(EVS_RoomListener_Dojo)),
        COLLIDER_deilit6,
        COLLIDER_deilit6u,
        MODEL_minka_1,
        EVT_PTR(N(InteriorNPCs_Dojo)))
    // the waterfront house
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_Waterfront)),
        EVT_PTR(N(EVS_SetWallRot_Waterfront)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_Waterfront)),
        COLLIDER_deilit4,
        COLLIDER_deilit4u,
        MODEL_minka2,
        EVT_PTR(N(InteriorNPCs_WaterfrontHouse)))
    // initial visibility
    EVT_SET(LVar0, VIS_GROUP_3)
    EVT_EXEC(N(EVS_RoomListener_RussHouse))
    EVT_EXEC(N(EVS_RoomListener_Waterfront))
    EVT_EXEC(N(EVS_RoomListener_Shop))
    EVT_EXEC(N(EVS_RoomListener_Dojo))
    EVT_RETURN
    EVT_END
};
