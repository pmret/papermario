#include "dro_01.h"

EvtScript N(EVS_SetDoorRot_LeftHouse) = {
    EVT_CALL(RotateModel, MODEL_doa1, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_LeftHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(TranslateModel, MODEL_1_m_kabe, 0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_mado1, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_1_m_kabe, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_mado1, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_1_m_moyou, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_1_m_waku, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_LeftHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(TranslateModel, MODEL_doa1, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_doa1, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Shop) = {
    EVT_CALL(RotateModel, MODEL_m_m_doa, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_Shop) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 50)
    EVT_CALL(TranslateModel, MODEL_m_m_kabe, 0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_m_m_mado, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_m_m_kabe, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_m_m_mado, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_m_m_hari, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_m_m_moyou, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_m_m_waku, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_m_m_mado2, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_m_m_kabe2, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_RightHouse) = {
    EVT_CALL(RotateModel, MODEL_doa2, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_RightHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIV(LVar1, 45)
    EVT_CALL(TranslateModel, MODEL_doa2, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_doa2, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_RightHouse) = {
    EVT_IF_EQ(LVar0, 90)
        EVT_CALL(EnableModel, MODEL_nuno, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_nuno, TRUE)
    EVT_END_IF
    EVT_SET(LVar1, LVar0)
    EVT_DIV(LVar1, 45)
    EVT_SET(LVar2, LVar0)
    EVT_SUB(LVar2, -90)
    EVT_DIV(LVar2, -90)
    EVT_CALL(TranslateModel, MODEL_si_ksbe, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_si_ksbe, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ue_waku, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_mado2, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ue_kabe, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ue_moyou, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_bou1, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_nuno, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_LeftHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_ie_naka, TRUE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_ie_naka, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_Shop) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_LT(STORY_CH2_SPOKE_WITH_SHEEK)
                    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_017B, 160, 40)
                    EVT_SET(LVar0, -1)
                    EVT_RETURN
                EVT_CASE_LT(STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
                    EVT_SET(LVar0, -1)
                    EVT_RETURN
            EVT_END_SWITCH
            EVT_CALL(SetGroupVisibility, MODEL_mise_naka, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            EVT_THREAD
                EVT_WAIT(45)
                EVT_CALL(SetNpcPos, NPC_Mouser_ShopOwner, 33, 0, -375)
                EVT_CALL(SetNpcYaw, NPC_Mouser_ShopOwner, 180)
            EVT_END_THREAD
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_mise_naka, MODEL_GROUP_HIDDEN)
            EVT_SET(AB_DRO_SHOP_PREV1, 0)
            EVT_SET(AB_DRO_SHOP_PREV2, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_RightHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_ie2_naka, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_ie2_naka, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_LeftHouse)[] = {
    NPC_Dryite_02,
    -1
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_Mouser_ShopOwner,
    -1
};

s32 N(InteriorNPCs_RightHouse)[] = {
    NPC_ArtistToad,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_LeftHouse)),
        EVT_PTR(N(EVS_SetWallRot_LeftHouse)),
        EVT_PTR(N(EVS_DropDoor_LeftHouse)),
        EVT_PTR(N(EVS_RoomListener_LeftHouse)),
        COLLIDER_ei1_1,
        COLLIDER_ei1_2,
        MODEL_k_i1,
        EVT_PTR(N(InteriorNPCs_LeftHouse)))
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_Shop)),
        EVT_PTR(N(EVS_SetWallRot_Shop)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_Shop)),
        COLLIDER_em_1,
        COLLIDER_em_2,
        MODEL_k_m1,
        EVT_PTR(N(InteriorNPCs_Shop)))
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_RightHouse)),
        EVT_PTR(N(EVS_SetWallRot_RightHouse)),
        EVT_PTR(N(EVS_DropDoor_RightHouse)),
        EVT_PTR(N(EVS_RoomListener_RightHouse)),
        COLLIDER_ei2_1,
        COLLIDER_ei_2,
        MODEL_k_i2,
        EVT_PTR(N(InteriorNPCs_RightHouse)))
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_END)
    EVT_EXEC(N(EVS_RoomListener_LeftHouse))
    EVT_EXEC(N(EVS_RoomListener_Shop))
    EVT_EXEC(N(EVS_RoomListener_RightHouse))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SwingSign_Shop) = {
    EVT_LABEL(9)
        EVT_CALL(MakeLerp, 10, -10, 30, EASING_COS_IN_OUT)
        EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o499, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_CALL(MakeLerp, -10, 10, 30, EASING_COS_IN_OUT)
        EVT_LABEL(11)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o499, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(11)
            EVT_END_IF
        EVT_GOTO(9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenShopDoor) = {
    EVT_CALL(SetGroupVisibility, MODEL_mise_naka, MODEL_GROUP_VISIBLE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_em_1, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 100, 15, EASING_QUADRATIC_OUT)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_EXEC(N(EVS_SetDoorRot_Shop))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseShopDoor) = {
    EVT_CALL(MakeLerp, 100, 0, 15, EASING_QUADRATIC_OUT)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_EXEC(N(EVS_SetDoorRot_Shop))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_em_1, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetGroupVisibility, MODEL_mise_naka, MODEL_GROUP_HIDDEN)
    EVT_RETURN
    EVT_END
};
