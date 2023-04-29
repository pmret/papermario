#include "sam_01.h"

EvtScript N(EVS_SetDoorRot_MayorFoyer) = {
    EVT_CALL(RotateModel, MODEL_o235, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_MayorFoyer) = {
    EVT_CALL(RotateGroup, MODEL_s_mae, LVar0, 1, 0, 0)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_s_mae, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_s_mae, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_MayorFoyer) = {
    EVT_CALL(RotateModel, MODEL_o235, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_MayorFoyer) = {
    EVT_CALL(UseRoomDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SET(AF_SAM_04, TRUE)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_s_naisou, MODEL_GROUP_VISIBLE)
            EVT_IF_GE(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
                EVT_CALL(SetNpcPos, NPC_MayorPenguin, -275, 0, -200)
                EVT_CALL(InterpNpcYaw, NPC_MayorPenguin, 180, 0)
                EVT_CALL(SetNpcPos, NPC_MayorPenguinWife, -300, 0, -50)
                EVT_CALL(InterpNpcYaw, NPC_MayorPenguinWife, 0, 0)
            EVT_END_IF
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_SET(AF_SAM_04, FALSE)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupVisibility, MODEL_s_naisou, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_MayorOffice) = {
    EVT_CALL(RotateModel, MODEL_o236, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_MayorOffice) = {
    EVT_CALL(RotateGroup, MODEL_s_yane, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_s_yoko, LVar0, 0, 0, -1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(EnableGroup, MODEL_s_yoko, FALSE)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(EnableGroup, MODEL_s_yoko, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_MayorOffice) = {
    EVT_CALL(UseRoomDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
        EVT_IF_EQ(AF_SAM_03, TRUE)
            EVT_SET(LVar0, -1)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
                EVT_THREAD
                    EVT_CALL(BindNpcInteract, NPC_Herringway, 0)
                    EVT_CALL(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                    EVT_CALL(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
                    EVT_CALL(SetNpcAnimation, NPC_Herringway, ANIM_Penguin_Walk)
                    EVT_CALL(SetNpcSpeed, NPC_Herringway, EVT_FLOAT(1.5 / DT))
                    EVT_CALL(NpcMoveTo, NPC_Herringway, -252, -55, 0)
                    EVT_CALL(SetNpcAnimation, NPC_Herringway, ANIM_Penguin_Idle)
                    EVT_CALL(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                    EVT_CALL(BindNpcInteract, NPC_Herringway, EVT_PTR(N(EVS_NpcInteract_Herringway)))
                EVT_END_THREAD
            EVT_END_IF
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_DONE)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
                EVT_CALL(SetMusicTrack, 0, SONG_PENGUIN_WHODUNIT, 1, 8)
            EVT_END_IF
            EVT_SET(AF_SAM_03, TRUE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_MYSTERY)
                EVT_EXEC(N(EVS_SetupMusic))
            EVT_END_IF
            EVT_SET(AF_SAM_03, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_MiddleHouse) = {
    EVT_CALL(RotateModel, MODEL_o253, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_MiddleHouse) = {
    EVT_CALL(RotateGroup, MODEL_f_ue, LVar0, 0, 0, -1)
    EVT_CALL(RotateGroup, MODEL_f_sita, LVar0, 0, 0, 1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_f_sita, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_f_sita, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_MiddleHouse) = {
    EVT_CALL(UseRoomDoorSounds, DOOR_SOUNDS_DOOR)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_f_naiso, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupVisibility, MODEL_f_naiso, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_UpperRightHouse) = {
    EVT_CALL(RotateModel, MODEL_o336, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_LowerRightHouse) = {
    EVT_CALL(RotateModel, MODEL_o402, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_RightHouse) = {
    EVT_CALL(RotateGroup, MODEL_m_ue, LVar0, 0, 0, 1)
    EVT_CALL(RotateGroup, MODEL_m_mae, LVar0, 0, 0, -1)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_m_mae, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_m_mae, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_UpperRightHouse) = {
    EVT_CALL(UseRoomDoorSounds, DOOR_SOUNDS_BASIC)
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

EvtScript N(EVS_RoomListener_LowerRightHouse) = {
    EVT_CALL(UseRoomDoorSounds, DOOR_SOUNDS_DOOR)
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

s32 N(InteriorNPCs_MayorBefore)[] = {
    NPC_MayorPenguin,
    NPC_MayorDummy,
    NPC_MayorPenguinWife,
    NPC_PenguinPatrol,
    NPC_Herringway,
    NPC_Penguin_09,
    -1
};

s32 N(InteriorNPCs_MayorAfter)[] = {
    NPC_MayorPenguin,
    NPC_MayorPenguinWife,
    NPC_PenguinPatrol,
    NPC_Herringway,
    -1
};

s32 N(InteriorNPCs_MiddleHouse)[] = {
    NPC_Herringway,
    -1
};

s32 N(InteriorNPCs_RightHouse)[] = {
    NPC_Herringway,
    NPC_Penguin_04,
    -1
};

EvtScript N(EVS_SetupMayorRooms) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SET(LVar0, EVT_PTR(N(InteriorNPCs_MayorBefore)))
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SET(LVar0, EVT_PTR(N(InteriorNPCs_MayorBefore)))
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SET(LVar0, EVT_PTR(N(InteriorNPCs_MayorAfter)))
    EVT_END_SWITCH
    // mayor's foyer
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_MayorFoyer)),
        EVT_PTR(N(EVS_SetWallRot_MayorFoyer)),
        EVT_PTR(N(EVS_DropDoor_MayorFoyer)),
        EVT_PTR(N(EVS_RoomListener_MayorFoyer)),
        COLLIDER_tts,
        COLLIDER_o352,
        MODEL_son,
        LVar0)
    // mayor's office
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_MayorOffice)),
        EVT_PTR(N(EVS_SetWallRot_MayorOffice)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_MayorOffice)),
        COLLIDER_ttsn,
        COLLIDER_o353,
        MODEL_o430,
        NULL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupRooms) = {
    EVT_CALL(SetGroupVisibility, MODEL_s_naisou, MODEL_GROUP_HIDDEN)
    EVT_IF_NE(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
        EVT_EXEC_WAIT(N(EVS_SetupMayorRooms))
    EVT_END_IF
    // upper middle house
    EVT_CALL(SetGroupVisibility, MODEL_f_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_MiddleHouse)),
        EVT_PTR(N(EVS_SetWallRot_MiddleHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_MiddleHouse)),
        COLLIDER_ttf2,
        COLLIDER_o354,
        MODEL_f2,
        EVT_PTR(N(InteriorNPCs_MiddleHouse)))
    // lower right house
    EVT_CALL(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_UpperRightHouse)),
        EVT_PTR(N(EVS_SetWallRot_RightHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_UpperRightHouse)),
        COLLIDER_ttm,
        COLLIDER_o355,
        MODEL_min,
        EVT_PTR(N(InteriorNPCs_RightHouse)))
    // upper right house
    EVT_CALL(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_LowerRightHouse)),
        EVT_PTR(N(EVS_SetWallRot_RightHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_LowerRightHouse)),
        COLLIDER_o376,
        COLLIDER_o390,
        MODEL_min,
        EVT_PTR(N(InteriorNPCs_RightHouse)))
    EVT_RETURN
    EVT_END
};
