#include "sam_02.h"

EvtScript N(EVS_SetDoorRot_LeftHouse) = {
    EVT_CALL(RotateModel, MODEL_c_doa, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_LeftHouse) = {
    EVT_CALL(RotateGroup, MODEL_mc_sita, LVar0, 1, 0, 0)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_mc_sita, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_mc_sita, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_LeftHouse) = {
    EVT_CALL(RotateModel, MODEL_c_doa, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_LeftHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Shop) = {
    EVT_CALL(RotateModel, MODEL_o382, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_Shop) = {
    EVT_CALL(RotateGroup, MODEL_t_ue, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_t_sita, LVar0, 0, 0, -1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_t_sita, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_t_sita, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_Shop) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_t_naiso, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
                EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
                EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_END_SWITCH
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupVisibility, MODEL_t_naiso, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    EVT_CALL(RotateModel, MODEL_k_doa, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    EVT_CALL(RotateGroup, MODEL_mk_ue, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_mk_sita, LVar0, 0, 0, -1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_mk_sita, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_mk_sita, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_k_naisou, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupVisibility, MODEL_k_naisou, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_LeftHouse)[] = {
    NPC_Penguin_02,
    -1
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_Penguin_ShopOwner,
    -1
};

s32 N(InteriorNPCs_ToadHouse)[] = {
    NPC_ShiverToad,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // left house
    EVT_CALL(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_LeftHouse)),
        EVT_PTR(N(EVS_SetWallRot_LeftHouse)),
        EVT_PTR(N(EVS_DropDoor_LeftHouse)),
        EVT_PTR(N(EVS_RoomListener_LeftHouse)),
        COLLIDER_c_doa,
        COLLIDER_o470,
        MODEL_min,
        EVT_PTR(N(InteriorNPCs_LeftHouse)))
    // shop
    EVT_CALL(SetGroupVisibility, MODEL_t_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_Shop)),
        EVT_PTR(N(EVS_SetWallRot_Shop)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_Shop)),
        COLLIDER_o382,
        COLLIDER_o471,
        MODEL_ten,
        EVT_PTR(N(InteriorNPCs_Shop)))
    // toad house
    EVT_CALL(SetGroupVisibility, MODEL_k_naisou, MODEL_GROUP_HIDDEN)
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_ToadHouse)),
        EVT_PTR(N(EVS_SetWallRot_ToadHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_k_doa,
        COLLIDER_o472,
        MODEL_kino,
        EVT_PTR(N(InteriorNPCs_ToadHouse)))
    EVT_RETURN
    EVT_END
};
