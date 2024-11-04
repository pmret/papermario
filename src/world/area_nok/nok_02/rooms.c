#include "nok_02.h"
#include "effects.h"

API_CALLABLE(N(SpawnKooperFightingDust)) {
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    fx_walking_dust(2, rand_int(200) - 100, rand_int(150), -180.0f, 0.0f, 0.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SpinKooperCeilingFan) = {
    Label(0)
        Set(LVar0, 35)
        Loop(LVar0)
            Set(LVar1, LVar0)
            Mul(LVar1, 10)
            Call(RotateModel, MODEL_o184, LVar1, 0, -1, 0)
            Wait(1)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UpdateKooperFightSounds) = {
    Loop(0)
        IfEq(GF_Quizmo_TakingQuiz, FALSE)
            Call(PlaySoundAt, SOUND_NOK_HOUSE_CONFLICT, SOUND_SPACE_DEFAULT, 0, 0, -180)
        EndIf
        Call(RandInt, 30, LVar5)
        Add(LVar5, 30)
        Wait(LVar5)
    EndLoop
    Return
    End
};

EvtScript N(EVS_PlayKooperVsFuzzyEffects) = {
    SetGroup(EVT_GROUP_PASSIVE_NPC)
    ExecGetTID(N(EVS_UpdateKooperFightSounds), MV_KooperFightSoundsScript)
    Label(0)
        Switch(GB_StoryProgress)
            CaseRange(STORY_CH1_PROMISED_TO_HELP_KOOPER, STORY_CH4_BEGAN_PEACH_MISSION)
                KillThread(MV_KooperFightSoundsScript)
                Return
        EndSwitch
        IfEq(GF_NOK02_ConfrontedBobombs, TRUE)
            KillThread(MV_KooperFightSoundsScript)
            Return
        EndIf
        Call(RandInt, 30, LVar0)
        Add(LVar0, 10)
        Wait(LVar0)
        Call(RandInt, 10, LVar0)
        Add(LVar0, 5)
        IfEq(GF_Quizmo_TakingQuiz, FALSE)
            Call(N(SpawnKooperFightingDust))
        EndIf
        Loop(LVar0)
            IfEq(AF_NOK_12, TRUE)
                KillThread(MV_KooperFightSoundsScript)
                Call(TranslateGroup, MODEL_kameki, 0, 0, 0)
                Label(10)
                IfEq(AF_NOK_12, TRUE)
                    Wait(1)
                    Goto(10)
                EndIf
                ExecGetTID(N(EVS_UpdateKooperFightSounds), MV_KooperFightSoundsScript)
                BreakLoop
            EndIf
            Call(RandInt, 5, LVar1)
            Add(LVar1, 1)
            Mul(LVar1, -1)
            Call(TranslateGroup, MODEL_kameki, 0, LVar1, 0)
            Wait(1)
            Call(TranslateGroup, MODEL_kameki, 0, LVar1, 0)
            Wait(1)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_KoloradoHouse) = {
    Call(RotateModel, MODEL_o149, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_KoloradoHouse) = {
    MulF(LVar0, Float(-0.5))
    Call(RotateModel, MODEL_o151, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o152, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o153, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o150, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_KoloradoHouse) = {
    Set(LVar1, LVar0)
    DivF(LVar1, 45)
    Call(TranslateModel, MODEL_o149, 0, LVar1, 0)
    Call(RotateModel, MODEL_o149, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_KoloradoOffice) = {
    Call(RotateGroup, MODEL_g41, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_KoloradoOffice) = {
    Set(LVar1, LVar0)
    Sub(LVar1, 90)
    MulF(LVar0, Float(1.0))
    Call(RotateModel, MODEL_o156, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o154, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o155, LVar0, 0, 0, 1)
    MulF(LVar1, Float(0.5))
    Call(RotateModel, MODEL_o151, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o152, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o153, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o150, LVar1, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_KooperFrontDoor) = {
    Call(RotateModel, MODEL_o185, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_KooperBackDoor) = {
    Call(RotateModel, MODEL_o183, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallsRot_KooperHouse) = {
    Set(LVar2, LVar0)
    Set(LVar1, LVar0)
    Sub(LVar1, 90)
    DivF(LVar1, -90)
    MulF(LVar2, Float(0.5))
    Call(RotateModel, MODEL_o171, LVar2, 0, 0, 1)
    Call(RotateModel, MODEL_o181, LVar2, 0, 0, 1)
    Call(RotateModel, MODEL_o182, LVar2, 0, 0, 1)
    Call(RotateModel, MODEL_o180, LVar2, 0, 0, 1)
    IfNe(LVar1, 0)
        Call(ScaleModel, MODEL_o308, 1, LVar1, 1)
        Call(ScaleModel, MODEL_o307, 1, LVar1, 1)
        Call(EnableModel, MODEL_o308, TRUE)
        Call(EnableModel, MODEL_o307, TRUE)
    Else
        Call(EnableModel, MODEL_o308, FALSE)
        Call(EnableModel, MODEL_o307, FALSE)
    EndIf
    Return
    End
};

EvtScript N(EVS_SetWallRot_KooperHouse) = {
    Switch(LVar0)
        CaseEq(0)
            Wait(20)
            Set(LVar0, 0)
            Loop(18)
                Add(LVar0, 5)
                ExecWait(N(EVS_SetWallsRot_KooperHouse))
            EndLoop
        CaseEq(3)
            Set(LVar0, 90)
            Loop(18)
                Sub(LVar0, 5)
                ExecWait(N(EVS_SetWallsRot_KooperHouse))
            EndLoop
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_KootHouse) = {
    Call(RotateModel, MODEL_o226, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_KootHouse) = {
    MulF(LVar0, Float(0.5))
    Call(RotateModel, MODEL_o225, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_o224, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_o223, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_o222, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_KootHouse) = {
    Set(LVar1, LVar0)
    DivF(LVar1, 45)
    Call(TranslateModel, MODEL_o226, 0, LVar1, 0)
    Call(RotateModel, MODEL_o226, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_KooperHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Set(AF_NOK_12, TRUE)
            IfLt(GB_StoryProgress, STORY_CH1_PROMISED_TO_HELP_KOOPER)
                ExecWait(N(EVS_Scene_MeetKooper))
                Set(LVar0, ROOM_UPDATE_REQUEST_CANCEL)
                Return
            EndIf
            Call(SetGroupVisibility, MODEL_g111, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            Exec(N(EVS_FuzzyBoss_PlayerEntersKoopersHouse))
            Set(AF_NOK_10, TRUE)
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            Set(AF_NOK_10, FALSE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Set(AF_NOK_12, FALSE)
            Call(SetGroupVisibility, MODEL_g111, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_KoloradoHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_g45, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_g45, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_KootHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_g63, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_g63, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
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
    IfGe(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        // kolorado house
        Call(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
            Ref(N(EVS_SetDoorRot_KoloradoHouse)),
            Ref(N(EVS_SetWallRot_KoloradoHouse)),
            Ref(N(EVS_DropDoor_KoloradoHouse)),
            Ref(N(EVS_RoomListener_KoloradoHouse)),
            COLLIDER_o310,
            COLLIDER_o313,
            MODEL_sakuji,
            Ref(N(InteriorNPCs_AfterKentC)))
        // kolorado office
        Call(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
            Ref(N(EVS_SetDoorRot_KoloradoOffice)),
            Ref(N(EVS_SetWallRot_KoloradoOffice)),
            NULL,
            NULL,
            COLLIDER_o314,
            COLLIDER_o317,
            MODEL_o271,
            NULL)
    Else
        IfEq(GF_NOK11_Defeated_KentC, TRUE)
            // kolorado house
            Call(CreateMapRoom,
                PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
                Ref(N(EVS_SetDoorRot_KoloradoHouse)),
                Ref(N(EVS_SetWallRot_KoloradoHouse)),
                Ref(N(EVS_DropDoor_KoloradoHouse)),
                Ref(N(EVS_RoomListener_KoloradoHouse)),
                COLLIDER_o310,
                COLLIDER_o313,
                MODEL_sakuji,
                Ref(N(InteriorNPCs_AfterKentC)))
            // kolorado office
            Call(CreateMapRoom,
                PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
                Ref(N(EVS_SetDoorRot_KoloradoOffice)),
                Ref(N(EVS_SetWallRot_KoloradoOffice)),
                NULL,
                NULL,
                COLLIDER_o314,
                COLLIDER_o317,
                MODEL_o271,
                NULL)
        Else
            // kolorado house
            Call(CreateMapRoom,
                PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
                Ref(N(EVS_SetDoorRot_KoloradoHouse)),
                Ref(N(EVS_SetWallRot_KoloradoHouse)),
                Ref(N(EVS_DropDoor_KoloradoHouse)),
                Ref(N(EVS_RoomListener_KoloradoHouse)),
                COLLIDER_o310,
                COLLIDER_o313,
                MODEL_sakuji,
                Ref(N(InteriorNPCs_BeforeKentC)))
            // kolorado office
            Call(CreateMapRoom,
                PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
                Ref(N(EVS_SetDoorRot_KoloradoOffice)),
                Ref(N(EVS_SetWallRot_KoloradoOffice)),
                NULL,
                NULL,
                COLLIDER_o314,
                COLLIDER_o317,
                MODEL_o271,
                NULL)
        EndIf
    EndIf
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        // kooper front door
        Call(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            Ref(N(EVS_SetDoorRot_KooperFrontDoor)),
            Ref(N(EVS_SetWallRot_KooperHouse)),
            NULL,
            Ref(N(EVS_RoomListener_KooperHouse)),
            COLLIDER_o284,
            COLLIDER_o287,
            MODEL_kameki,
            Ref(N(InteriorNPCs_KooperHouse_BeforeJoin)))
        // kooper back door
        Call(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            Ref(N(EVS_SetDoorRot_KooperBackDoor)),
            Ref(N(EVS_SetWallRot_KooperHouse)),
            NULL,
            Ref(N(EVS_RoomListener_KooperHouse)),
            COLLIDER_o302,
            COLLIDER_o299,
            MODEL_kameki,
            Ref(N(InteriorNPCs_KooperHouse_BeforeJoin)))
    Else
        // kooper front door
        Call(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            Ref(N(EVS_SetDoorRot_KooperFrontDoor)),
            Ref(N(EVS_SetWallRot_KooperHouse)),
            NULL,
            Ref(N(EVS_RoomListener_KooperHouse)),
            COLLIDER_o284,
            COLLIDER_o287,
            MODEL_kameki,
            Ref(N(InteriorNPCs_KooperHouse_AfterJoin)))
        // kooper back door
        Call(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            Ref(N(EVS_SetDoorRot_KooperBackDoor)),
            Ref(N(EVS_SetWallRot_KooperHouse)),
            NULL,
            Ref(N(EVS_RoomListener_KooperHouse)),
            COLLIDER_o302,
            COLLIDER_o299,
            MODEL_kameki,
            Ref(N(InteriorNPCs_KooperHouse_AfterJoin)))
    EndIf
    // koot house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_KootHouse)),
        Ref(N(EVS_SetWallRot_KootHouse)),
        Ref(N(EVS_DropDoor_KootHouse)),
        Ref(N(EVS_RoomListener_KootHouse)),
        COLLIDER_o226,
        COLLIDER_o283,
        MODEL_mura,
        Ref(N(InteriorNPCs_KootHouse)))
    Set(LVar0, ROOM_UPDATE_EXIT_END)
    Exec(N(EVS_RoomListener_KoloradoHouse))
    Exec(N(EVS_RoomListener_KooperHouse))
    Exec(N(EVS_RoomListener_KootHouse))
    Exec(N(EVS_SpinKooperCeilingFan))
    Exec(N(EVS_PlayKooperVsFuzzyEffects))
    Return
    End
};
