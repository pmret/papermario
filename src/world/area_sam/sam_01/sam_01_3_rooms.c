#include "sam_01.h"

EvtScript N(EVS_SetDoorRot_MayorFoyer) = {
    Call(RotateModel, MODEL_o235, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_MayorFoyer) = {
    Call(RotateGroup, MODEL_s_mae, LVar0, 1, 0, 0)
    IfGt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_s_mae, MODEL_GROUP_HIDDEN)
    EndIf
    IfLt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_s_mae, MODEL_GROUP_VISIBLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_DropDoor_MayorFoyer) = {
    Call(RotateModel, MODEL_o235, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_MayorFoyer) = {
    Call(UseRoomDoorSounds, DOOR_SOUNDS_BASIC)
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Set(AF_SAM_04, TRUE)
            Set(AF_SAM_Snowing, FALSE)
            Call(SetGroupVisibility, MODEL_s_naisou, MODEL_GROUP_VISIBLE)
            IfGe(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
                Call(SetNpcPos, NPC_MayorPenguin, -275, 0, -200)
                Call(InterpNpcYaw, NPC_MayorPenguin, 180, 0)
                Call(SetNpcPos, NPC_MayorPenguinWife, -300, 0, -50)
                Call(InterpNpcYaw, NPC_MayorPenguinWife, 0, 0)
            EndIf
        CaseEq(ROOM_UPDATE_EXIT_END)
            Set(AF_SAM_04, FALSE)
            Set(AF_SAM_Snowing, TRUE)
            Call(SetGroupVisibility, MODEL_s_naisou, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_MayorOffice) = {
    Call(RotateModel, MODEL_o236, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_MayorOffice) = {
    Call(RotateGroup, MODEL_s_yane, LVar0, 0, 0, 1)
    Call(RotateGroup, MODEL_s_yoko, LVar0, 0, 0, -1)
    IfGt(LVar0, 89)
        Call(EnableGroup, MODEL_s_yoko, FALSE)
    EndIf
    IfLt(LVar0, 89)
        Call(EnableGroup, MODEL_s_yoko, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_RoomListener_MayorOffice) = {
    Call(UseRoomDoorSounds, DOOR_SOUNDS_BASIC)
    IfEq(GB_StoryProgress, STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
        IfEq(AF_SAM_03, TRUE)
            Set(LVar0, -1)
            Return
        EndIf
    EndIf
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            IfEq(GB_StoryProgress, STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
                Thread
                    Call(BindNpcInteract, NPC_Herringway, 0)
                    Call(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                    Call(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
                    Call(SetNpcAnimation, NPC_Herringway, ANIM_Penguin_Walk)
                    Call(SetNpcSpeed, NPC_Herringway, Float(1.5 / DT))
                    Call(NpcMoveTo, NPC_Herringway, -252, -55, 0)
                    Call(SetNpcAnimation, NPC_Herringway, ANIM_Penguin_Idle)
                    Call(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                    Call(BindNpcInteract, NPC_Herringway, Ref(N(EVS_NpcInteract_Herringway)))
                EndThread
            EndIf
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            IfEq(GB_StoryProgress, STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
                Call(SetMusicTrack, 0, SONG_PENGUIN_WHODUNIT, 1, 8)
            EndIf
            Set(AF_SAM_03, TRUE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            IfEq(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_MYSTERY)
                Exec(N(EVS_SetupMusic))
            EndIf
            Set(AF_SAM_03, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_MiddleHouse) = {
    Call(RotateModel, MODEL_o253, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_MiddleHouse) = {
    Call(RotateGroup, MODEL_f_ue, LVar0, 0, 0, -1)
    Call(RotateGroup, MODEL_f_sita, LVar0, 0, 0, 1)
    IfGt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_f_sita, MODEL_GROUP_HIDDEN)
    EndIf
    IfLt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_f_sita, MODEL_GROUP_VISIBLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_RoomListener_MiddleHouse) = {
    Call(UseRoomDoorSounds, DOOR_SOUNDS_DOOR)
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Set(AF_SAM_Snowing, FALSE)
            Call(SetGroupVisibility, MODEL_f_naiso, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_END)
            Set(AF_SAM_Snowing, TRUE)
            Call(SetGroupVisibility, MODEL_f_naiso, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_UpperRightHouse) = {
    Call(RotateModel, MODEL_o336, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_LowerRightHouse) = {
    Call(RotateModel, MODEL_o402, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_RightHouse) = {
    Call(RotateGroup, MODEL_m_ue, LVar0, 0, 0, 1)
    Call(RotateGroup, MODEL_m_mae, LVar0, 0, 0, -1)
    IfGt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_m_mae, MODEL_GROUP_HIDDEN)
    EndIf
    IfLt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_m_mae, MODEL_GROUP_VISIBLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_RoomListener_UpperRightHouse) = {
    Call(UseRoomDoorSounds, DOOR_SOUNDS_BASIC)
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Set(AF_SAM_Snowing, FALSE)
            Call(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Set(AF_SAM_Snowing, TRUE)
            Call(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_LowerRightHouse) = {
    Call(UseRoomDoorSounds, DOOR_SOUNDS_DOOR)
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Set(AF_SAM_Snowing, FALSE)
            Call(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Set(AF_SAM_Snowing, TRUE)
            Call(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
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
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Set(LVar0, Ref(N(InteriorNPCs_MayorBefore)))
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Set(LVar0, Ref(N(InteriorNPCs_MayorBefore)))
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Set(LVar0, Ref(N(InteriorNPCs_MayorAfter)))
    EndSwitch
    // mayor's foyer
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_MayorFoyer)),
        Ref(N(EVS_SetWallRot_MayorFoyer)),
        Ref(N(EVS_DropDoor_MayorFoyer)),
        Ref(N(EVS_RoomListener_MayorFoyer)),
        COLLIDER_tts,
        COLLIDER_o352,
        MODEL_son,
        LVar0)
    // mayor's office
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_MayorOffice)),
        Ref(N(EVS_SetWallRot_MayorOffice)),
        NULL,
        Ref(N(EVS_RoomListener_MayorOffice)),
        COLLIDER_ttsn,
        COLLIDER_o353,
        MODEL_o430,
        NULL)
    Return
    End
};

EvtScript N(EVS_SetupRooms) = {
    Call(SetGroupVisibility, MODEL_s_naisou, MODEL_GROUP_HIDDEN)
    IfNe(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
        ExecWait(N(EVS_SetupMayorRooms))
    EndIf
    // upper middle house
    Call(SetGroupVisibility, MODEL_f_naiso, MODEL_GROUP_HIDDEN)
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_MiddleHouse)),
        Ref(N(EVS_SetWallRot_MiddleHouse)),
        NULL,
        Ref(N(EVS_RoomListener_MiddleHouse)),
        COLLIDER_ttf2,
        COLLIDER_o354,
        MODEL_f2,
        Ref(N(InteriorNPCs_MiddleHouse)))
    // lower right house
    Call(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_HIDDEN)
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_UpperRightHouse)),
        Ref(N(EVS_SetWallRot_RightHouse)),
        NULL,
        Ref(N(EVS_RoomListener_UpperRightHouse)),
        COLLIDER_ttm,
        COLLIDER_o355,
        MODEL_min,
        Ref(N(InteriorNPCs_RightHouse)))
    // upper right house
    Call(SetGroupVisibility, MODEL_m_naiso, MODEL_GROUP_HIDDEN)
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_LowerRightHouse)),
        Ref(N(EVS_SetWallRot_RightHouse)),
        NULL,
        Ref(N(EVS_RoomListener_LowerRightHouse)),
        COLLIDER_o376,
        COLLIDER_o390,
        MODEL_min,
        Ref(N(InteriorNPCs_RightHouse)))
    Return
    End
};
