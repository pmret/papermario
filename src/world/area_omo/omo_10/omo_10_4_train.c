#include "omo_10.h"

#include "../common/ToyTrain.inc.c"
#include "../common/TrainStationSwitches.inc.c"

Vec2i N(D_80243AC0_DDB470) = {
    10, -105
};

s32 N(D_80243AC8_DDB478)[] = {
    Float(-2.266),   Float(-209.494), Float(90.0),
    Float(124.202),  Float(-209.494), Float(262.5),
    Float(-245.336), Float(479.165),  Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_80243AF8_DDB4A8) = {
    Call(FadeOutMusic, 0, 3000)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    Exec(N(EVS_TrainUnk_C))
    Set(AB_OMO_5, 3)
    Set(LVar0, Ref(N(D_80243AC8_DDB478)))
    ExecWait(N(EVS_TrainUnk_D))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
    Set(MV_TrainUnk_00, 0)
    Set(MV_TrainUnk_01, Ref(N(D_80243AC8_DDB478)))
    Set(MV_TrainUnk_02, 1)
    Set(MF_TrainUnk_00, TRUE)
    Label(10)
    IfLt(MV_TrainPos, 350)
        Wait(1)
        Goto(10)
    EndIf
    Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_0)
    Set(GB_OMO_TrainDestination, 3)
    Wait(100)
    Return
    End
};

s32 N(D_80243C68_DDB618)[] = {
    Float(-2.266),   Float(-209.494), Float(270.0),
    Float(-128.733), Float(-209.494), Float(-262.5),
    Float(-245.336), Float(-353.418), Float(-353.688),
    Float(-479.165), Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_80243CA0_DDB650) = {
    Call(FadeOutMusic, 0, 3000)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    Exec(N(EVS_TrainUnk_C))
    Set(AB_OMO_5, 3)
    Set(LVar0, Ref(N(D_80243C68_DDB618)))
    ExecWait(N(EVS_TrainUnk_D))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
    Set(MV_TrainUnk_00, 0)
    Set(MV_TrainUnk_01, Ref(N(D_80243C68_DDB618)))
    Set(MV_TrainUnk_02, 1)
    Set(MF_TrainUnk_00, TRUE)
    Label(10)
    IfGt(MV_TrainPos, -350)
        Wait(1)
        Goto(10)
    EndIf
    Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_1)
    Set(GB_OMO_TrainDestination, 2)
    Wait(100)
    Return
    End
};

s32 N(D_80243E10_DDB7C0)[] = {
    Float(414.885),  Float(-426.942), Float(219.92),
    Float(353.553),  Float(-353.553), Float(262.5),
    Float(-245.336), Float(124.202),  Float(-209.494),
    Float(-42.27),   Float(-209.49),
    -1, -1, -1
};

s32 N(D_80243E48_DDB7F8)[] = {
    Float(414.885),  Float(-426.942), Float(219.92),
    Float(353.553),  Float(-353.553), Float(262.5),
    Float(-245.336), Float(124.202),  Float(-209.494),
    Float(-128.733), Float(-209.494), Float(-262.5),
    Float(-245.336), Float(-353.418), Float(-353.688),
    Float(-479.165), Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_80243E98_DDB848) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(AB_OMO_6, 3)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80243E10_DDB7C0)))
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
        Set(LVar9, Ref(N(D_80243AC0_DDB470)))
        ExecWait(N(EVS_TrainUnk_E))
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0011)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
        Call(DisablePlayerPhysics, FALSE)
        Call(EnablePartnerAI)
        Call(DisablePlayerInput, FALSE)
    Else
        Exec(N(EVS_TrainUnk_A))
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80243E48_DDB7F8)))
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
        Set(GB_OMO_TrainDestination, 2)
        Wait(100)
    EndIf
    Return
    End
};

s32 N(D_80244150_DDBB00)[] = {
    Float(-414.885), Float(-426.942), Float(140.075),
    Float(-353.418), Float(-353.688), Float(-262.5),
    Float(-245.336), Float(-128.733), Float(-209.494),
    Float(37.73), Float(-209.49),
    -1, -1, -1
};

s32 N(D_80244188_DDBB38)[] = {
    Float(-414.885), Float(-426.942), Float(140.075),
    Float(-353.418), Float(-353.688), Float(-262.5),
    Float(-245.336), Float(-128.733), Float(-209.494),
    Float(124.202),  Float(-209.494), Float(262.5),
    Float(-245.336), Float(479.165),  Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_802441D0_DDBB80) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(AB_OMO_6, 3)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80244150_DDBB00)))
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
        Set(LVar9, Ref(N(D_80243AC0_DDB470)))
        ExecWait(N(EVS_TrainUnk_E))
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0011)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o961, COLLIDER_FLAGS_UPPER_MASK)
        Call(DisablePlayerPhysics, FALSE)
        Call(EnablePartnerAI)
        Call(DisablePlayerInput, FALSE)
    Else
        Exec(N(EVS_TrainUnk_A))
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80244188_DDBB38)))
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
        Set(GB_OMO_TrainDestination, 3)
        Wait(100)
    EndIf
    Return
    End
};

s32 N(D_80244488_DDBE38)[] = {
    2, 1, 0,
};

s32 N(D_80244494_DDBE44)[] = {
    0, 1, 2,
};

EvtScript N(D_802444A0_DDBE50) = {
    IfEq(MF_EitherSwitchPressed, FALSE)
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0006)
    Else
        IfEq(AF_OMO_UsingRightSwitch, FALSE)
            Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
            Call(ShowChoice, MSG_Choice_0043)
            IfNe(LVar0, 3)
                Call(CloseMessage)
                UseBuf(Ref(N(D_80244488_DDBE38)))
                Add(LVar0, 1)
                Loop(LVar0)
                    BufRead1(LVar1)
                EndLoop
                Set(AB_OMO_6, LVar1)
                ExecWait(N(D_80243CA0_DDB650))
            Else
                Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
            EndIf
        Else
            Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
            Call(ShowChoice, MSG_Choice_0042)
            IfNe(LVar0, 3)
                Call(CloseMessage)
                UseBuf(Ref(N(D_80244494_DDBE44)))
                Add(LVar0, 1)
                Loop(LVar0)
                    BufRead1(LVar1)
                EndLoop
                Set(AB_OMO_6, LVar1)
                ExecWait(N(D_80243AF8_DDB4A8))
            Else
                Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
            EndIf
        EndIf
    EndIf
    Return
    End
};

s32 N(D_802446B8_DDC068)[] = {
    Float(-2.266), Float(-209.494), Float(90.0),
    -1, -1, -1
};

EvtScript N(EVS_SetupTrain) = {
    ExecWait(N(EVS_SetupSwitches))
    Call(GetLoadType, LVar1)
    IfEq(LVar1, 1)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_802446B8_DDC068)))
        Set(MV_TrainUnk_02, 0)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
    Else
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseEq(omo_10_ENTRY_2)
                Exec(N(D_802441D0_DDBB80))
            CaseEq(omo_10_ENTRY_3)
                Exec(N(D_80243E98_DDB848))
            CaseDefault
                Set(MV_TrainUnk_00, 0)
                Set(MV_TrainUnk_01, Ref(N(D_802446B8_DDC068)))
                Set(MV_TrainUnk_02, 0)
                Exec(N(EVS_Scene_RideTrain))
                Set(MF_TrainUnk_00, TRUE)
        EndSwitch
    EndIf
    Return
    End
};
