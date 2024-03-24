#include "mac_01.h"

EvtScript N(EVS_SetDoorRot_PostOffice) = {
    SetF(LVar1, LVar0)
    DivF(LVar1, Float(45.0))
    Call(TranslateModel, MODEL_o189, LVar1, 0, 0)
    SetF(LVar1, LVar0)
    MulF(LVar1, Float(0.95))
    Call(RotateModel, MODEL_o189, LVar1, 0, -1, 0)
    Return
    End
};

s16 N(Models_PostOfficeWalls_Unused)[] = {
    MODEL_y1,
    MODEL_y2,
    MODEL_k14,
    MODEL_k15,
    MODEL_k16,
    MODEL_k17,
    MODEL_k18,
    MODEL_k21,
    MODEL_k22,
    MODEL_k23,
    MODEL_k24,
    MODEL_y3,
    MODEL_k11,
    MODEL_k12,
    MODEL_k13,
};

EvtScript N(EVS_SetWallRot_PostOffice) = {
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_k11, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k12, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k13, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k14, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k15, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k16, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k17, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k18, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k21, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k22, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k23, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_k24, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_y1, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_y2, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_y3, LVar1, -1, 0, 0)
    Switch(LVar0)
        CaseEq(90)
            Call(EnableGroup, MODEL_po_mtx, FALSE)
        CaseDefault
            Call(EnableGroup, MODEL_po_mtx, TRUE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_DropDoor_PostOffice) = {
    Call(RotateModel, MODEL_o189, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_PostOffice) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_yubin_in, MODEL_GROUP_VISIBLE)
            ExecWait(N(EVS_Scene_MailbagTheft))
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_yubin_in, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    Call(RotateModel, MODEL_door_k, LVar0, 0, -1, 0)
    Return
    End
};

s16 N(Models_ToadHouseWalls_Unused)[] = {
    MODEL_kk12,
    MODEL_kk13,
    MODEL_kk14,
    MODEL_kk21,
    MODEL_kk22,
    MODEL_kk23,
    MODEL_kk11,
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    Set(LVar1, LVar0)
    MulF(LVar1, Float(1.0))
    Call(RotateModel, MODEL_kk11, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_kk12, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_kk13, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_kk14, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_kk21, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_kk22, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_kk23, LVar1, 1, 0, 0)
    Switch(LVar0)
        CaseEq(90)
            Call(EnableGroup, MODEL_kino_out, FALSE)
        CaseDefault
            Call(EnableGroup, MODEL_kino_out, TRUE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_kino_in, MODEL_GROUP_VISIBLE)
            Set(MF_InsideToadHouse, TRUE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_kino_in, MODEL_GROUP_HIDDEN)
            Set(MF_InsideToadHouse, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_MerlonHouse) = {
    Call(RotateModel, MODEL_door, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_MerlonHouse) = {
    Set(LVar1, LVar0)
    Mul(LVar1, 2)
    Call(RotateGroup, MODEL_off_kabe, LVar1, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_MerlonHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Switch(GB_StoryProgress)
                CaseLt(STORY_CH1_SPOKE_WITH_MERLIN)
                    ExecWait(N(EVS_MerlonShooAway))
                    Set(LVar0, -1)
                    Return
                CaseRange(STORY_CH6_RETURNED_TO_TOAD_TOWN, STORY_CH7_INVITED_TO_STARBORN_VALLEY)
                    Exec(N(EVS_Scene_MerlonAndNinji))
                CaseRange(STORY_CH3_GOT_SUPER_BOOTS, STORY_CH8_REACHED_PEACHS_CASTLE)
                    IfEq(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
                        BreakSwitch
                    EndIf
                    IfEq(GF_MAC01_Merlon_HeardAboutDream, FALSE)
                        Call(SpeakToPlayer, NPC_Luigi, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_003C)
                        Set(LVar0, -1)
                        Return
                    EndIf
                CaseGe(STORY_EPILOGUE)
                    Call(ShowMessageAtScreenPos, MSG_Outro_003F, 160, 40)
                    Set(LVar0, -1)
                    Return
            EndSwitch
            Call(SetGroupVisibility, MODEL_dr_in, MODEL_GROUP_VISIBLE)
            Set(MF_MusicMixTrigger1, TRUE)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_dr_in, MODEL_GROUP_HIDDEN)
            Set(MF_MusicMixTrigger1, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SpinRoof) = {
    SetGroup(EVT_GROUP_00)
    Set(LVar0, 0)
    Label(0)
        AddF(LVar0, Float(3.0))
        IfGt(LVar0, 360)
            SubF(LVar0, Float(360.0))
        EndIf
        Call(RotateGroup, MODEL_yane, LVar0, 0, 1, 0)
        Call(RotateGroup, MODEL_off_yane, LVar0, 0, 1, 0)
        Wait(1)
        Goto(0)
    Return
    End
};

s32 N(InsideNPCs_PostOffice)[] = {
    NPC_Postmaster,
    NPC_Parakarry,
    NPC_PostOfficeShyGuy,
    -1
};

s32 N(InsideNPCs_ToadHouse)[] = {
    NPC_ToadHouseToad,
    NPC_ToadHouseShyGuy,
    -1
};

s32 N(InsideNPCs_MerlonHouse)[] = {
    NPC_Merlon,
    NPC_Ninji,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // post office
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_PostOffice)),
        Ref(N(EVS_SetWallRot_PostOffice)),
        Ref(N(EVS_DropDoor_PostOffice)),
        Ref(N(EVS_RoomListener_PostOffice)),
        COLLIDER_deilit1,
        COLLIDER_deilit1u,
        MODEL_post_office,
        Ref(N(InsideNPCs_PostOffice)))
    // toad house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_ToadHouse)),
        Ref(N(EVS_SetWallRot_ToadHouse)),
        NULL,
        Ref(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_deilit2,
        COLLIDER_deilit2u,
        MODEL_kinopi,
        Ref(N(InsideNPCs_ToadHouse)))
    // merlon's house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_MerlonHouse)),
        Ref(N(EVS_SetWallRot_MerlonHouse)),
        NULL,
        Ref(N(EVS_RoomListener_MerlonHouse)),
        COLLIDER_deilitd,
        COLLIDER_deilitud,
        MODEL_de_aru,
        Ref(N(InsideNPCs_MerlonHouse)))
    // initial visibility
    Exec(N(EVS_SpinRoof))
    Set(LVar0, ROOM_UPDATE_EXIT_END)
    Exec(N(EVS_RoomListener_PostOffice))
    Exec(N(EVS_RoomListener_ToadHouse))
    Exec(N(EVS_RoomListener_MerlonHouse))
    Return
    End
};
