#include "nok_02.h"
#include "effects.h"

API_CALLABLE(N(SpawnKooperFightingDust)) {
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SpinKooperCeilingFan) = {
    EVT_LABEL(0)
        EVT_SET(LVar0, 35)
        EVT_LOOP(LVar0)
            EVT_SET(LVar1, LVar0)
            EVT_MUL(LVar1, 10)
            EVT_CALL(RotateModel, MODEL_o184, LVar1, 0, -1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateKooperFightSounds) = {
    EVT_LOOP(0)
        EVT_IF_EQ(GF_Quizmo_TakingQuiz, FALSE)
            EVT_CALL(PlaySoundAt, SOUND_NOK_HOUSE_CONFLICT, SOUND_SPACE_DEFAULT, 0, 0, -180)
        EVT_END_IF
        EVT_CALL(RandInt, 30, LVar5)
        EVT_ADD(LVar5, 30)
        EVT_WAIT(LVar5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayKooperVsFuzzyEffects) = {
    EVT_SET_GROUP(EVT_GROUP_0A)
    EVT_EXEC_GET_TID(N(EVS_UpdateKooperFightSounds), MV_KooperFightSoundsScript)
    EVT_LABEL(0)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_RANGE(STORY_CH1_PROMISED_TO_HELP_KOOPER, STORY_CH4_BEGAN_PEACH_MISSION)
                EVT_KILL_THREAD(MV_KooperFightSoundsScript)
                EVT_RETURN
        EVT_END_SWITCH
        EVT_IF_EQ(GF_NOK02_ConfrontedBobombs, TRUE)
            EVT_KILL_THREAD(MV_KooperFightSoundsScript)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(RandInt, 30, LVar0)
        EVT_ADD(LVar0, 10)
        EVT_WAIT(LVar0)
        EVT_CALL(RandInt, 10, LVar0)
        EVT_ADD(LVar0, 5)
        EVT_IF_EQ(GF_Quizmo_TakingQuiz, FALSE)
            EVT_CALL(N(SpawnKooperFightingDust))
        EVT_END_IF
        EVT_LOOP(LVar0)
            EVT_IF_EQ(AF_NOK_12, TRUE)
                EVT_KILL_THREAD(MV_KooperFightSoundsScript)
                EVT_CALL(TranslateGroup, MODEL_kameki, 0, 0, 0)
                EVT_LABEL(10)
                EVT_IF_EQ(AF_NOK_12, TRUE)
                    EVT_WAIT(1)
                    EVT_GOTO(10)
                EVT_END_IF
                EVT_EXEC_GET_TID(N(EVS_UpdateKooperFightSounds), MV_KooperFightSoundsScript)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(RandInt, 5, LVar1)
            EVT_ADD(LVar1, 1)
            EVT_MUL(LVar1, -1)
            EVT_CALL(TranslateGroup, MODEL_kameki, 0, LVar1, 0)
            EVT_WAIT(1)
            EVT_CALL(TranslateGroup, MODEL_kameki, 0, LVar1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_KoloradoHouse) = {
    EVT_CALL(RotateModel, MODEL_o149, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_KoloradoHouse) = {
    EVT_MULF(LVar0, EVT_FLOAT(-0.5))
    EVT_CALL(RotateModel, MODEL_o151, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o152, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o153, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o150, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_KoloradoHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 45)
    EVT_CALL(TranslateModel, MODEL_o149, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o149, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_KoloradoOffice) = {
    EVT_CALL(RotateGroup, MODEL_g41, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_KoloradoOffice) = {
    EVT_SET(LVar1, LVar0)
    EVT_SUB(LVar1, 90)
    EVT_MULF(LVar0, EVT_FLOAT(1.0))
    EVT_CALL(RotateModel, MODEL_o156, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o154, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o155, LVar0, 0, 0, 1)
    EVT_MULF(LVar1, EVT_FLOAT(0.5))
    EVT_CALL(RotateModel, MODEL_o151, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o152, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o153, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o150, LVar1, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_KooperFrontDoor) = {
    EVT_CALL(RotateModel, MODEL_o185, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_KooperBackDoor) = {
    EVT_CALL(RotateModel, MODEL_o183, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallsRot_KooperHouse) = {
    EVT_SET(LVar2, LVar0)
    EVT_SET(LVar1, LVar0)
    EVT_SUB(LVar1, 90)
    EVT_DIVF(LVar1, -90)
    EVT_MULF(LVar2, EVT_FLOAT(0.5))
    EVT_CALL(RotateModel, MODEL_o171, LVar2, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o181, LVar2, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o182, LVar2, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o180, LVar2, 0, 0, 1)
    EVT_IF_NE(LVar1, 0)
        EVT_CALL(ScaleModel, MODEL_o308, 1, LVar1, 1)
        EVT_CALL(ScaleModel, MODEL_o307, 1, LVar1, 1)
        EVT_CALL(EnableModel, MODEL_o308, TRUE)
        EVT_CALL(EnableModel, MODEL_o307, TRUE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o308, FALSE)
        EVT_CALL(EnableModel, MODEL_o307, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_KooperHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_WAIT(20)
            EVT_SET(LVar0, 0)
            EVT_LOOP(18)
                EVT_ADD(LVar0, 5)
                EVT_EXEC_WAIT(N(EVS_SetWallsRot_KooperHouse))
            EVT_END_LOOP
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, 90)
            EVT_LOOP(18)
                EVT_SUB(LVar0, 5)
                EVT_EXEC_WAIT(N(EVS_SetWallsRot_KooperHouse))
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_KootHouse) = {
    EVT_CALL(RotateModel, MODEL_o226, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_KootHouse) = {
    EVT_MULF(LVar0, EVT_FLOAT(0.5))
    EVT_CALL(RotateModel, MODEL_o225, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o224, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o223, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o222, LVar0, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_KootHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_DIVF(LVar1, 45)
    EVT_CALL(TranslateModel, MODEL_o226, 0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o226, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_KooperHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SET(AF_NOK_12, TRUE)
            EVT_IF_LT(GB_StoryProgress, STORY_CH1_PROMISED_TO_HELP_KOOPER)
                EVT_EXEC_WAIT(N(EVS_Scene_MeetKooper))
                EVT_SET(LVar0, ROOM_UPDATE_REQUEST_CANCEL)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SetGroupVisibility, MODEL_g111, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_DONE)
            EVT_EXEC(N(EVS_FuzzyBoss_PlayerEntersKoopersHouse))
            EVT_SET(AF_NOK_10, TRUE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            EVT_SET(AF_NOK_10, FALSE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_SET(AF_NOK_12, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_g111, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_KoloradoHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_g45, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_g45, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_KootHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_g63, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_g63, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_BeforeKentC)[] = {
    NPC_KoloradoWife,
    -1
};

s32 N(InteriorNPCs_AfterKentC)[] = {
    -1
};

s32 N(InteriorNPCs_KooperHouse_BeforeJoin)[] = {
    NPC_FuzzyBoss,
    NPC_KoopersShell,
    -1
};

s32 N(InteriorNPCs_KooperHouse_AfterJoin)[] = {
    NPC_Bobomb_01,
    NPC_Bobomb_02,
    -1
};

s32 N(InteriorNPCs_KootHouse)[] = {
    NPC_KoopaKoot,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        // kolorado house
        EVT_CALL(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
            EVT_PTR(N(EVS_SetDoorRot_KoloradoHouse)),
            EVT_PTR(N(EVS_SetWallRot_KoloradoHouse)),
            EVT_PTR(N(EVS_DropDoor_KoloradoHouse)),
            EVT_PTR(N(EVS_RoomListener_KoloradoHouse)),
            COLLIDER_o310,
            COLLIDER_o313,
            MODEL_sakuji,
            EVT_PTR(N(InteriorNPCs_AfterKentC)))
        // kolorado office
        EVT_CALL(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
            EVT_PTR(N(EVS_SetDoorRot_KoloradoOffice)),
            EVT_PTR(N(EVS_SetWallRot_KoloradoOffice)),
            NULL,
            NULL,
            COLLIDER_o314,
            COLLIDER_o317,
            MODEL_o271,
            NULL)
    EVT_ELSE
        EVT_IF_EQ(GF_NOK11_Defeated_KentC, TRUE)
            // kolorado house
            EVT_CALL(CreateMapRoom,
                PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
                EVT_PTR(N(EVS_SetDoorRot_KoloradoHouse)),
                EVT_PTR(N(EVS_SetWallRot_KoloradoHouse)),
                EVT_PTR(N(EVS_DropDoor_KoloradoHouse)),
                EVT_PTR(N(EVS_RoomListener_KoloradoHouse)),
                COLLIDER_o310,
                COLLIDER_o313,
                MODEL_sakuji,
                EVT_PTR(N(InteriorNPCs_AfterKentC)))
            // kolorado office
            EVT_CALL(CreateMapRoom,
                PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
                EVT_PTR(N(EVS_SetDoorRot_KoloradoOffice)),
                EVT_PTR(N(EVS_SetWallRot_KoloradoOffice)),
                NULL,
                NULL,
                COLLIDER_o314,
                COLLIDER_o317,
                MODEL_o271,
                NULL)
        EVT_ELSE
            // kolorado house
            EVT_CALL(CreateMapRoom,
                PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
                EVT_PTR(N(EVS_SetDoorRot_KoloradoHouse)),
                EVT_PTR(N(EVS_SetWallRot_KoloradoHouse)),
                EVT_PTR(N(EVS_DropDoor_KoloradoHouse)),
                EVT_PTR(N(EVS_RoomListener_KoloradoHouse)),
                COLLIDER_o310,
                COLLIDER_o313,
                MODEL_sakuji,
                EVT_PTR(N(InteriorNPCs_BeforeKentC)))
            // kolorado office
            EVT_CALL(CreateMapRoom,
                PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
                EVT_PTR(N(EVS_SetDoorRot_KoloradoOffice)),
                EVT_PTR(N(EVS_SetWallRot_KoloradoOffice)),
                NULL,
                NULL,
                COLLIDER_o314,
                COLLIDER_o317,
                MODEL_o271,
                NULL)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        // kooper front door
        EVT_CALL(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            EVT_PTR(N(EVS_SetDoorRot_KooperFrontDoor)),
            EVT_PTR(N(EVS_SetWallRot_KooperHouse)),
            NULL,
            EVT_PTR(N(EVS_RoomListener_KooperHouse)),
            COLLIDER_o284,
            COLLIDER_o287,
            MODEL_kameki,
            EVT_PTR(N(InteriorNPCs_KooperHouse_BeforeJoin)))
        // kooper back door
        EVT_CALL(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            EVT_PTR(N(EVS_SetDoorRot_KooperBackDoor)),
            EVT_PTR(N(EVS_SetWallRot_KooperHouse)),
            NULL,
            EVT_PTR(N(EVS_RoomListener_KooperHouse)),
            COLLIDER_o302,
            COLLIDER_o299,
            MODEL_kameki,
            EVT_PTR(N(InteriorNPCs_KooperHouse_BeforeJoin)))
    EVT_ELSE
        // kooper front door
        EVT_CALL(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            EVT_PTR(N(EVS_SetDoorRot_KooperFrontDoor)),
            EVT_PTR(N(EVS_SetWallRot_KooperHouse)),
            NULL,
            EVT_PTR(N(EVS_RoomListener_KooperHouse)),
            COLLIDER_o284,
            COLLIDER_o287,
            MODEL_kameki,
            EVT_PTR(N(InteriorNPCs_KooperHouse_AfterJoin)))
        // kooper back door
        EVT_CALL(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            EVT_PTR(N(EVS_SetDoorRot_KooperBackDoor)),
            EVT_PTR(N(EVS_SetWallRot_KooperHouse)),
            NULL,
            EVT_PTR(N(EVS_RoomListener_KooperHouse)),
            COLLIDER_o302,
            COLLIDER_o299,
            MODEL_kameki,
            EVT_PTR(N(InteriorNPCs_KooperHouse_AfterJoin)))
    EVT_END_IF
    // koot house
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_KootHouse)),
        EVT_PTR(N(EVS_SetWallRot_KootHouse)),
        EVT_PTR(N(EVS_DropDoor_KootHouse)),
        EVT_PTR(N(EVS_RoomListener_KootHouse)),
        COLLIDER_o226,
        COLLIDER_o283,
        MODEL_mura,
        EVT_PTR(N(InteriorNPCs_KootHouse)))
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_END)
    EVT_EXEC(N(EVS_RoomListener_KoloradoHouse))
    EVT_EXEC(N(EVS_RoomListener_KooperHouse))
    EVT_EXEC(N(EVS_RoomListener_KootHouse))
    EVT_EXEC(N(EVS_SpinKooperCeilingFan))
    EVT_EXEC(N(EVS_PlayKooperVsFuzzyEffects))
    EVT_RETURN
    EVT_END
};
