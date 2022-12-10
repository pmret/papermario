#include "mac_01.h"

EvtScript N(EVS_SetDoorRot_PostOffice) = {
    EVT_SETF(LVar1, LVar0)
    EVT_DIVF(LVar1, EVT_FLOAT(45.0))
    EVT_CALL(TranslateModel, MODEL_o189, LVar1, 0, 0)
    EVT_SETF(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(0.95))
    EVT_CALL(RotateModel, MODEL_o189, LVar1, 0, -1, 0)
    EVT_RETURN
    EVT_END
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

EvtScript N(EVS_MoveWalls_PostOffice) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_k11, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k12, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k13, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k14, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k15, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k16, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k17, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k18, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k21, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k22, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k23, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_k24, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_y1, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_y2, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_y3, LVar1, -1, 0, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(90)
            EVT_CALL(EnableGroup, MODEL_po_mtx, FALSE)
        EVT_CASE_DEFAULT
            EVT_CALL(EnableGroup, MODEL_po_mtx, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_PostOffice) = {
    EVT_CALL(RotateModel, MODEL_o189, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToggleVis_PostOffice) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_yubin_in, 1)
            EVT_EXEC_WAIT(N(EVS_80257844))
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_yubin_in, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    EVT_CALL(RotateModel, MODEL_door_k, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
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

EvtScript N(EVS_MoveWalls_ToadHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(1.0))
    EVT_CALL(RotateModel, MODEL_kk11, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_kk12, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_kk13, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_kk14, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_kk21, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_kk22, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_kk23, LVar1, 1, 0, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(90)
            EVT_CALL(EnableGroup, MODEL_kino_out, FALSE)
        EVT_CASE_DEFAULT
            EVT_CALL(EnableGroup, MODEL_kino_out, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToggleVis_ToadHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_kino_in, 1)
            EVT_SET(MF_Unk_0F, TRUE)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_kino_in, 0)
            EVT_SET(MF_Unk_0F, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_MerlonHouse) = {
    EVT_CALL(RotateModel, MODEL_door, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MoveWalls_MerlonHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_MUL(LVar1, 2)
    EVT_CALL(RotateGroup, MODEL_off_kabe, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToggleVis_MerlonHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_LT(STORY_CH1_SPOKE_WITH_MERLIN)
                    EVT_EXEC_WAIT(N(EVS_802502AC))
                    EVT_SET(LVar0, -1)
                    EVT_RETURN
                EVT_CASE_RANGE(STORY_CH6_RETURNED_TO_TOAD_TOWN, STORY_CH7_INVITED_TO_STARBORN_VALLEY)
                    EVT_EXEC(N(EVS_80252EB0))
                EVT_CASE_RANGE(STORY_CH3_GOT_SUPER_BOOTS, STORY_CH8_REACHED_PEACHS_CASTLE)
                    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
                        EVT_BREAK_SWITCH
                    EVT_END_IF
                    EVT_IF_EQ(GF_MAC01_Merlon_HeardAboutDream, FALSE)
                        EVT_CALL(SpeakToPlayer, NPC_Luigi, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_003C)
                        EVT_SET(LVar0, -1)
                        EVT_RETURN
                    EVT_END_IF
                EVT_CASE_GE(STORY_EPILOGUE)
                    EVT_CALL(ShowMessageAtScreenPos, MSG_Outro_003F, 160, 40)
                    EVT_SET(LVar0, -1)
                    EVT_RETURN
            EVT_END_SWITCH
            EVT_CALL(SetGroupEnabled, MODEL_dr_in, 1)
            EVT_SET(MF_MusicMixTrigger1, TRUE)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_dr_in, 0)
            EVT_SET(MF_MusicMixTrigger1, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpinRoof) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
        EVT_ADDF(LVar0, EVT_FLOAT(3.0))
        EVT_IF_GT(LVar0, 360)
            EVT_SUBF(LVar0, EVT_FLOAT(360.0))
        EVT_END_IF
        EVT_CALL(RotateGroup, MODEL_yane, LVar0, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_off_yane, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
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
    EVT_CALL(MakeDoorAdvanced,
        VIS_GROUP_PAIR(VIS_GROUP_0, VIS_GROUP_2),
        EVT_PTR(N(EVS_SetDoorRot_PostOffice)),
        EVT_PTR(N(EVS_MoveWalls_PostOffice)),
        EVT_PTR(N(EVS_DropDoor_PostOffice)),
        EVT_PTR(N(EVS_ToggleVis_PostOffice)),
        COLLIDER_deilit1,
        COLLIDER_deilit1u,
        MODEL_post_office,
        EVT_PTR(N(InsideNPCs_PostOffice)))
    // toad house
    EVT_CALL(MakeDoorAdvanced,
        VIS_GROUP_PAIR(VIS_GROUP_0, VIS_GROUP_2),
        EVT_PTR(N(EVS_SetDoorRot_ToadHouse)),
        EVT_PTR(N(EVS_MoveWalls_ToadHouse)),
        NULL,
        EVT_PTR(N(EVS_ToggleVis_ToadHouse)),
        COLLIDER_deilit2,
        COLLIDER_deilit2u,
        MODEL_kinopi, 
        EVT_PTR(N(InsideNPCs_ToadHouse)))
    // merlon's house
    EVT_CALL(MakeDoorAdvanced,
        VIS_GROUP_PAIR(VIS_GROUP_0, VIS_GROUP_2),
        EVT_PTR(N(EVS_SetDoorRot_MerlonHouse)),
        EVT_PTR(N(EVS_MoveWalls_MerlonHouse)),
        NULL,
        EVT_PTR(N(EVS_ToggleVis_MerlonHouse)),
        COLLIDER_deilitd,
        COLLIDER_deilitud,
        MODEL_de_aru,
        EVT_PTR(N(InsideNPCs_MerlonHouse)))
    // initial visibility
    EVT_EXEC(N(EVS_SpinRoof))
    EVT_SET(LVar0, VIS_GROUP_3)
    EVT_EXEC(N(EVS_ToggleVis_PostOffice))
    EVT_EXEC(N(EVS_ToggleVis_ToadHouse))
    EVT_EXEC(N(EVS_ToggleVis_MerlonHouse))
    EVT_RETURN
    EVT_END
};
