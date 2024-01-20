#include "omo_08.h"

#include "../common/ToyTrain.inc.c"
#include "../common/TrainStationSwitches.inc.c"

Vec2i N(D_80246740_DCAB10) = {
    -145, -110
};

s32 N(D_80246748_DCAB18)[] = {
    Float(-131.227), Float(-210.271), Float(105.004),
    Float(0.0), Float(-175.0), Float(262.5),
    Float(-245.336), Float(479.165), Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_80246778_DCAB48) = {
    Call(FadeOutMusic, 0, 3000)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    Exec(N(EVS_TrainUnk_C))
    Set(AB_OMO_5, 2)
    Set(LVar0, Ref(N(D_80246748_DCAB18)))
    ExecWait(N(EVS_TrainUnk_D))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1074, COLLIDER_FLAGS_UPPER_MASK)
    Set(MV_TrainUnk_00, 0)
    Set(MV_TrainUnk_01, Ref(N(D_80246748_DCAB18)))
    Set(MV_TrainUnk_02, 1)
    Set(MF_TrainUnk_00, TRUE)
    Label(10)
    IfLt(MV_TrainPos, 350)
        Wait(1)
        Goto(10)
    EndIf
    Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_0)
    Set(GB_OMO_TrainDestination, 2)
    Wait(100)
    Return
    End
};

s32 N(D_802468E8_DCACB8)[] = {
    Float(-131.227), Float(-210.271), Float(285.004),
    Float(-262.5), Float(-245.336), Float(-353.418),
    Float(-353.688), Float(-479.165), Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_80246918_DCACE8) = {
    Call(FadeOutMusic, 0, 3000)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    Exec(N(EVS_TrainUnk_C))
    Set(AB_OMO_5, 2)
    Set(LVar0, Ref(N(D_802468E8_DCACB8)))
    ExecWait(N(EVS_TrainUnk_D))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1074, COLLIDER_FLAGS_UPPER_MASK)
    Set(MV_TrainUnk_00, 0)
    Set(MV_TrainUnk_01, Ref(N(D_802468E8_DCACB8)))
    Set(MV_TrainUnk_02, 1)
    Set(MF_TrainUnk_00, TRUE)
    Label(10)
    IfGt(MV_TrainPos, -350)
        Wait(1)
        Goto(10)
    EndIf
    Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_1)
    Set(GB_OMO_TrainDestination, 1)
    Wait(100)
    Return
    End
};

s32 N(D_80246A88_DCAE58)[] = {
    Float(414.885), Float(-426.942), Float(219.92),
    Float(353.553), Float(-353.553), Float(262.5),
    Float(-245.336), Float(0.0), Float(-175.0),
    Float(-169.87), Float(-220.59),
    -1, -1, -1
};

s32 N(D_80246AC0_DCAE90)[] = {
    Float(414.885), Float(-426.942), Float(219.92),
    Float(353.553), Float(-353.553), Float(262.5),
    Float(-245.336), Float(0.0), Float(-175.0),
    Float(-262.5), Float(-245.336), Float(-353.418),
    Float(-353.688), Float(-479.165), Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_80246B08_DCAED8) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1074, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(AB_OMO_6, 2)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80246A88_DCAE58)))
        Set(MV_TrainUnk_02, 2)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
        Wait(1)
        ExecGetTID(N(EVS_TrainUnk_A), LVarB)
        Label(10)
        IfEq(MF_TrainUnk_00, TRUE)
            Wait(1)
            Goto(10)
        EndIf
        Wait(20)
        KillThread(LVarB)
        Exec(N(EVS_TrainUnk_B))
        Call(N(EnableCameraFollowPlayerY))
        Set(LVar9, Ref(N(D_80246740_DCAB10)))
        ExecWait(N(EVS_TrainUnk_E))
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0010)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1074, COLLIDER_FLAGS_UPPER_MASK)
        Call(DisablePlayerPhysics, FALSE)
        Call(EnablePartnerAI)
        Call(DisablePlayerInput, FALSE)
    Else
        Exec(N(EVS_TrainUnk_A))
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80246AC0_DCAE90)))
        Set(MV_TrainUnk_02, 0)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
        Wait(1)
        Exec(N(EVS_TrainUnk_H))
        Label(20)
        IfGt(MV_TrainPos, -350)
            Wait(1)
            Goto(20)
        EndIf
        Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_1)
        Set(GB_OMO_TrainDestination, 1)
        Wait(100)
    EndIf
    Return
    End
};

s32 N(D_80246DC0_DCB190)[] = {
    Float(-414.885), Float(-426.942), Float(140.075),
    Float(-353.418), Float(-353.688), Float(-262.5),
    Float(-245.336), Float(-92.58), Float(-199.95),
    -1, -1, -1
};

s32 N(D_80246DF0_DCB1C0)[] = {
    Float(-414.885), Float(-426.942), Float(140.075),
    Float(-353.418), Float(-353.688), Float(-262.5),
    Float(-245.336), Float(0.0), Float(-175.0),
    Float(262.5), Float(-245.336), Float(479.165),
    Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_80246E30_DCB200) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1074, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(AB_OMO_6, 2)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80246DC0_DCB190)))
        Set(MV_TrainUnk_02, 2)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
        Wait(1)
        ExecGetTID(N(EVS_TrainUnk_A), LVarB)
        Label(10)
        IfEq(MF_TrainUnk_00, TRUE)
            Wait(1)
            Goto(10)
        EndIf
        Wait(20)
        KillThread(LVarB)
        Exec(N(EVS_TrainUnk_B))
        Call(N(EnableCameraFollowPlayerY))
        Set(LVar9, Ref(N(D_80246740_DCAB10)))
        ExecWait(N(EVS_TrainUnk_E))
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0010)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1074, COLLIDER_FLAGS_UPPER_MASK)
        Call(DisablePlayerPhysics, FALSE)
        Call(EnablePartnerAI)
        Call(DisablePlayerInput, FALSE)
    Else
        Exec(N(EVS_TrainUnk_A))
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80246DF0_DCB1C0)))
        Set(MV_TrainUnk_02, 0)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
        Wait(1)
        Exec(N(EVS_TrainUnk_H))
        Label(20)
        IfLt(MV_TrainPos, 350)
            Wait(1)
            Goto(20)
        EndIf
        Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_0)
        Set(GB_OMO_TrainDestination, 2)
        Wait(100)
    EndIf
    Return
    End
};

s32 N(D_802470E8_DCB4B8)[] = {
    1, 0, 3,
};

s32 N(D_802470F4_DCB4C4)[] = {
    3, 0, 1,
};

EvtScript N(EVS_80247100) = {
    IfEq(MF_EitherSwitchPressed, FALSE)
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0006)
    Else
        IfEq(AF_OMO_UsingRightSwitch, FALSE)
            Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
            IfEq(GF_OMO03_BlueSwitchActivated, FALSE)
                Call(ShowChoice, MSG_Choice_0040)
                IfNe(LVar0, 2)
                    Call(CloseMessage)
                    UseBuf(Ref(N(D_802470E8_DCB4B8)))
                    Add(LVar0, 1)
                    Loop(LVar0)
                        BufRead1(LVar1)
                    EndLoop
                    Set(AB_OMO_6, LVar1)
                    ExecWait(N(D_80246918_DCACE8))
                Else
                    Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                EndIf
            Else
                Call(ShowChoice, MSG_Choice_0041)
                IfNe(LVar0, 3)
                    Call(CloseMessage)
                    UseBuf(Ref(N(D_802470E8_DCB4B8)))
                    Add(LVar0, 1)
                    Loop(LVar0)
                        BufRead1(LVar1)
                    EndLoop
                    Set(AB_OMO_6, LVar1)
                    ExecWait(N(D_80246918_DCACE8))
                Else
                    Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                EndIf
            EndIf
        Else
            Switch(GB_StoryProgress)
                CaseLt(STORY_CH4_SOLVED_COLOR_PUZZLE)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0016)
                CaseGe(STORY_CH4_SOLVED_COLOR_PUZZLE)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
                    Call(ShowChoice, MSG_Choice_003F)
                    IfNe(LVar0, 3)
                        Call(CloseMessage)
                        UseBuf(Ref(N(D_802470F4_DCB4C4)))
                        Add(LVar0, 1)
                        Loop(LVar0)
                            BufRead1(LVar1)
                        EndLoop
                        Set(AB_OMO_6, LVar1)
                        ExecWait(N(D_80246778_DCAB48))
                    Else
                        Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EndIf
            EndSwitch
        EndIf
    EndIf
    Return
    End
};

s32 N(D_80247438_DCB808)[] = {
    Float(-131.227), Float(-210.271), Float(105.004),
    -1, -1, -1
};

EvtScript N(EVS_SetupTrain) = {
    ExecWait(N(EVS_SetupSwitches))
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80247438_DCB808)))
        Set(MV_TrainUnk_02, 0)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
    Else
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseEq(omo_08_ENTRY_1)
                Exec(N(D_80246E30_DCB200))
            CaseEq(omo_08_ENTRY_2)
                Exec(N(D_80246B08_DCAED8))
            CaseDefault
                Set(MV_TrainUnk_00, 0)
                Set(MV_TrainUnk_01, Ref(N(D_80247438_DCB808)))
                Set(MV_TrainUnk_02, 0)
                Exec(N(EVS_Scene_RideTrain))
                Set(MF_TrainUnk_00, TRUE)
        EndSwitch
    EndIf
    Return
    End
};
