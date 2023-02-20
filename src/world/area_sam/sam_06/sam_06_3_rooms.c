#include "sam_06.h"

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    EVT_CALL(RotateModel, MODEL_khm_doa, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    EVT_CALL(RotateGroup, MODEL_khm_yane, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_khm_sita, LVar0, 0, 0, -1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_khm_sita, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_khm_sita, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_kh_naiso, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupVisibility, MODEL_kh_naiso, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_MerleHouse) = {
    EVT_CALL(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_MerleHouse) = {
    EVT_CALL(RotateGroup, MODEL_km_yane, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_km_sita, LVar0, 0, 0, -1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_km_sita, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_km_sita, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_MerleHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_VISIBLE)
            EVT_CALL(EnableModel, MODEL_k_naiso, TRUE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            EVT_IF_LT(GB_StoryProgress, STORY_CH7_GOT_SNOWMAN_SCARF)
                EVT_CALL(DisablePlayerInput, TRUE)
            EVT_END_IF
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_HIDDEN)
            EVT_IF_LT(GB_StoryProgress, STORY_CH7_GOT_SNOWMAN_SCARF)
                EVT_EXEC_WAIT(N(EVS_Scene_Merle_OneLastThing))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_CookHouse) = {
    EVT_CALL(RotateModel, MODEL_o122, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_CookHouse) = {
    EVT_CALL(RotateGroup, MODEL_hm_yane, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_hm_sita, LVar0, 0, 0, -1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_hm_sita, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_hm_yane, MODEL_GROUP_HIDDEN)
        EVT_CALL(EnableModel, MODEL_h_yuki1, FALSE)
        EVT_CALL(EnableModel, MODEL_h_yuki2, FALSE)
        EVT_CALL(EnableModel, MODEL_hm_entotu, FALSE)
        EVT_CALL(EnableModel, MODEL_hm_ento2, FALSE)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_hm_sita, MODEL_GROUP_VISIBLE)
        EVT_CALL(SetGroupVisibility, MODEL_hm_yane, MODEL_GROUP_VISIBLE)
        EVT_CALL(EnableModel, MODEL_h_yuki1, TRUE)
        EVT_CALL(EnableModel, MODEL_h_yuki2, TRUE)
        EVT_CALL(EnableModel, MODEL_hm_entotu, TRUE)
        EVT_CALL(EnableModel, MODEL_hm_ento2, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_CookHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_h_naiso, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupVisibility, MODEL_h_naiso, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_ToadHouse)[] = {
    NPC_ShiverToad_04,
    -1
};

s32 N(InteriorNPCs_MerleHouse)[] = {
    NPC_Merle,
    -1
};

s32 N(InteriorNPCs_CookHouse)[] = {
    NPC_Ninji_04,
    NPC_StarKid_04,
    NPC_StarKid_05,
    NPC_StarKid_06,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // toad house
    EVT_CALL(SetGroupVisibility, MODEL_kh_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_ToadHouse)),
        EVT_PTR(N(EVS_SetWallRot_ToadHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_kh_d1,
        COLLIDER_kh_d2,
        MODEL_kinohuse,
        EVT_PTR(N(InteriorNPCs_ToadHouse)))
    // merle's house
    EVT_CALL(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_MerleHouse)),
        EVT_PTR(N(EVS_SetWallRot_MerleHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_MerleHouse)),
        COLLIDER_k_d1,
        COLLIDER_k_d2,
        MODEL_k,
        EVT_PTR(N(InteriorNPCs_MerleHouse)))
    // cooking house
    EVT_CALL(SetGroupVisibility, MODEL_h_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_CookHouse)),
        EVT_PTR(N(EVS_SetWallRot_CookHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_CookHouse)),
        COLLIDER_h_doa1,
        COLLIDER_h_doa2,
        MODEL_hakun,
        EVT_PTR(N(InteriorNPCs_CookHouse)))
    EVT_RETURN
    EVT_END
};
