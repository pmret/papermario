#include "omo_06.h"

#include "../common/ToyTrain.inc.c"
#include "../common/TrainStationSwitches.inc.c"

Vec2i N(D_80244160_DBBA70) = {
    50, 45
};

s32 N(D_80244168_DBBA78)[] = {
    Float(-1.825), Float(-35.275), Float(66.038),
    Float(162.917), Float(-108.494), Float(353.442),
    Float(-353.717), Float(414.885), Float(-426.942),
    -1, -1, -1
};

EvtScript N(D_80244198_DBBAA8) = {
    Call(FadeOutMusic, 0, 3000)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    Exec(N(EVS_TrainUnk_C))
    Set(AB_OMO_5, 1)
    Set(LVar0, Ref(N(D_80244168_DBBA78)))
    ExecWait(N(EVS_TrainUnk_D))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
    Set(MV_TrainUnk_00, 0)
    Set(MV_TrainUnk_01, Ref(N(D_80244168_DBBA78)))
    Set(MV_TrainUnk_02, 1)
    Set(MF_TrainUnk_00, TRUE)
    Label(10)
    IfLt(MV_TrainPos, 350)
        Wait(1)
        Goto(10)
    EndIf
    Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_0)
    Set(GB_OMO_TrainDestination, 1)
    Wait(100)
    Return
    End
};

s32 N(D_80244308_DBBC18)[] = {
    Float(-1.825), Float(-35.275), Float(246.038),
    Float(-166.506), Float(37.917), Float(-500.0),
    Float(0.279), Float(-600.0), Float(0.558),
    -1, -1, -1
};

EvtScript N(D_80244338_DBBC48) = {
    Call(FadeOutMusic, 0, 3000)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    Exec(N(EVS_TrainUnk_C))
    Set(AB_OMO_5, 1)
    Set(LVar0, Ref(N(D_80244308_DBBC18)))
    ExecWait(N(EVS_TrainUnk_D))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
    Set(MV_TrainUnk_00, 0)
    Set(MV_TrainUnk_01, Ref(N(D_80244308_DBBC18)))
    Set(MV_TrainUnk_02, 1)
    Set(MF_TrainUnk_00, TRUE)
    Label(10)
    IfGt(MV_TrainPos, -480)
        Wait(1)
        Goto(10)
    EndIf
    Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_1)
    Set(GB_OMO_TrainDestination, 0)
    Wait(100)
    Return
    End
};

s32 N(D_802444A8_DBBDB8)[] = {
    Float(414.885),  Float(-426.942), Float(219.925),
    Float(353.442),  Float(-353.717), Float(162.917),
    Float(-108.494), Float(-38.38),   Float(-19.05),
    -1, -1, -1
};

s32 N(D_802444D8_DBBDE8)[] = {
    Float(414.885), Float(-426.942), Float(219.925),
    Float(353.442), Float(-353.717), Float(162.917),
    Float(-108.494), Float(-166.506), Float(37.917),
    Float(-500.0), Float(0.279), Float(-600.0),
    Float(0.558),  -1, -1, -1
};

EvtScript N(D_80244518_DBBE28) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(AB_OMO_6, 1)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_802444A8_DBBDB8)))
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
        Set(LVar9, Ref(N(D_80244160_DBBA70)))
        ExecWait(N(EVS_TrainUnk_E))
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_000F)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
        Call(DisablePlayerPhysics, FALSE)
        Call(EnablePartnerAI)
        Call(DisablePlayerInput, FALSE)
    Else
        Exec(N(EVS_TrainUnk_A))
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_802444D8_DBBDE8)))
        Set(MV_TrainUnk_02, 0)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
        Wait(1)
        Exec(N(EVS_TrainUnk_H))
        Label(20)
        IfGt(MV_TrainPos, -480)
            Wait(1)
            Goto(20)
        EndIf
        Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_1)
        Set(GB_OMO_TrainDestination, 0)
        Wait(100)
    EndIf
    Return
    End
};

s32 N(D_802447D0_DBC0E0)[] = {
    Float(-600.0), Float(0.558), Float(89.875),
    Float(-500.0), Float(0.279), Float(-166.506),
    Float(37.917), Float(34.74), Float(-51.5),
    -1, -1, -1
};

s32 N(D_80244800_DBC110)[] = {
    Float(-600.0), Float(0.558), Float(89.875),
    Float(-500.0), Float(0.279), Float(-166.506),
    Float(37.917), Float(162.917), Float(-108.494),
    Float(353.442), Float(-353.717), Float(414.885),
    Float(-426.942),
    -1, -1, -1
};

EvtScript N(D_80244840_DBC150) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(AB_OMO_6, 1)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_802447D0_DBC0E0)))
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
        Set(LVar9, Ref(N(D_80244160_DBBA70)))
        ExecWait(N(EVS_TrainUnk_E))
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_000F)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o898, COLLIDER_FLAGS_UPPER_MASK)
        Call(DisablePlayerPhysics, FALSE)
        Call(EnablePartnerAI)
        Call(DisablePlayerInput, FALSE)
    Else
        Exec(N(EVS_TrainUnk_A))
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80244800_DBC110)))
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
        Set(GB_OMO_TrainDestination, 1)
        Wait(100)
    EndIf
    Return
    End
};

s32 N(D_80244AF8_DBC408)[] = {
    0, 3, 2,
};

s32 N(D_80244B04_DBC414)[] = {
    2, 3, 0,
};

EvtScript N(D_80244B10_DBC420) = {
    IfEq(MF_EitherSwitchPressed, FALSE)
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0006)
    Else
        IfEq(AF_OMO_UsingRightSwitch, FALSE)
            Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
            IfEq(GF_OMO03_BlueSwitchActivated, FALSE)
                Call(ShowChoice, MSG_Choice_003D)
                IfNe(LVar0, 1)
                    Call(CloseMessage)
                    UseBuf(Ref(N(D_80244AF8_DBC408)))
                    Add(LVar0, 1)
                    Loop(LVar0)
                        BufRead1(LVar1)
                    EndLoop
                    Set(AB_OMO_6, LVar1)
                    ExecWait(N(D_80244338_DBBC48))
                Else
                    Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                EndIf
            Else
                Call(ShowChoice, MSG_Choice_003E)
                IfNe(LVar0, 3)
                    Call(CloseMessage)
                    UseBuf(Ref(N(D_80244AF8_DBC408)))
                    Add(LVar0, 1)
                    Loop(LVar0)
                        BufRead1(LVar1)
                    EndLoop
                    Set(AB_OMO_6, LVar1)
                    ExecWait(N(D_80244338_DBBC48))
                Else
                    Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                EndIf
            EndIf
        Else
            Switch(GB_StoryProgress)
                CaseLt(STORY_CH4_PULLED_SWITCH_SWITCH)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0012)
                CaseLt(STORY_CH4_SOLVED_COLOR_PUZZLE)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
                    Call(ShowChoice, MSG_Choice_003B)
                    IfNe(LVar0, 1)
                        Call(CloseMessage)
                        UseBuf(Ref(N(D_80244B04_DBC414)))
                        Add(LVar0, 1)
                        Loop(LVar0)
                            BufRead1(LVar1)
                        EndLoop
                        Set(AB_OMO_6, LVar1)
                        ExecWait(N(D_80244198_DBBAA8))
                    Else
                        Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EndIf
                CaseGe(STORY_CH4_SOLVED_COLOR_PUZZLE)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
                    Call(ShowChoice, MSG_Choice_003C)
                    IfNe(LVar0, 3)
                        Call(CloseMessage)
                        UseBuf(Ref(N(D_80244B04_DBC414)))
                        Add(LVar0, 1)
                        Loop(LVar0)
                            BufRead1(LVar1)
                        EndLoop
                        Set(AB_OMO_6, LVar1)
                        ExecWait(N(D_80244198_DBBAA8))
                    Else
                        Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EndIf
            EndSwitch
        EndIf
    EndIf
    Return
    End
};

s32 N(D_80244F28_DBC838)[] = {
    Float(-1.825), Float(-35.275), Float(66.038),
    -1, -1, -1
};

EvtScript N(EVS_80244F40) = {
    ExecWait(N(EVS_SetupSwitches))
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80244F28_DBC838)))
        Set(MV_TrainUnk_02, 0)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
    Else
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseEq(omo_06_ENTRY_2)
                Exec(N(D_80244840_DBC150))
            CaseEq(omo_06_ENTRY_3)
                Exec(N(D_80244518_DBBE28))
            CaseDefault
                Set(MV_TrainUnk_00, 0)
                Set(MV_TrainUnk_01, Ref(N(D_80244F28_DBC838)))
                Set(MV_TrainUnk_02, 0)
                Exec(N(EVS_Scene_RideTrain))
                Set(MF_TrainUnk_00, TRUE)
        EndSwitch
    EndIf
    Return
    End
};
