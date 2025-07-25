#include "omo_16.h"

#include "../common/ToyTrain.inc.c"

EvtScript N(D_8024262C_DEE4FC) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, omo_16_ENTRY_0)
#if VERSION_JP
        Wait(200)
#else
        Wait(140)
#endif
        Switch(GB_OMO_TrainDestination)
            CaseEq(0)
                IfEq(AB_OMO_6, 1)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000B)
                EndIf
            CaseEq(1)
                IfEq(AB_OMO_6, 2)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000C)
                EndIf
            CaseEq(2)
                IfEq(AB_OMO_6, 3)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000D)
                EndIf
            CaseEq(3)
                IfEq(AB_OMO_6, 0)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000A)
                EndIf
        EndSwitch
    Else
#if VERSION_JP
        Wait(200)
#else
        Wait(140)
#endif
        Switch(GB_OMO_TrainDestination)
            CaseEq(0)
                IfEq(AB_OMO_6, 0)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000A)
                EndIf
            CaseEq(1)
                IfEq(AB_OMO_6, 1)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000B)
                EndIf
            CaseEq(2)
                IfEq(AB_OMO_6, 2)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000C)
                EndIf
            CaseEq(3)
                IfEq(AB_OMO_6, 3)
                    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_000D)
                EndIf
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(D_802428CC_DEE79C) = {
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, -2000)
        Set(LVar0, -2000)
    EndIf
    IfGt(LVar0, 2000)
        Set(LVar0, 2000)
    EndIf
    Call(SetCamTarget, CAM_DEFAULT, LVar0, Float(50.0), LVar2)
    Wait(1)
    Goto(0)
    Return
    End
};

s32 N(D_80242984_DEE854)[] = {
    -1550, Float(0.0), Float(90.0), 1550, Float(0.0),
    -1, -1, -1
};

s32 N(D_802429A4_DEE874)[] = {
    1550, Float(0.0), Float(270.0), -1550, Float(0.0),
    -1, -1, -1
};

API_CALLABLE(N(CheckForSceneSkip)) {
    f32 trainPos = evt_get_float_variable(script, MV_TrainPos);

    script->varTable[0] = 0;
    if (fabsf(trainPos) < 2000.0f && (gGameStatusPtr->pressedButtons[0] & BUTTON_A)) {
        script->varTable[0] = 1;
    }

    if (fabsf(trainPos) < 2000.0f && (gGameStatusPtr->pressedButtons[0] & BUTTON_B)) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_802429C4) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(DisablePartnerAI, 0)
    Exec(N(D_802428CC_DEE79C))
    Exec(N(D_8024262C_DEE4FC))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, omo_16_ENTRY_0)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80242984_DEE854)))
        Set(MV_TrainUnk_02, 0)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, true)
        Thread
            Label(10)
            Call(N(CheckForSceneSkip))
            IfEq(LVar0, 1)
                Goto(11)
            EndIf
            Wait(1)
            IfLt(MV_TrainPos, 1400)
                Goto(10)
            EndIf
            Switch(GB_OMO_TrainDestination)
                CaseEq(0)
                    Call(GotoMap, Ref("omo_06"), omo_06_ENTRY_2)
                CaseEq(1)
                    Call(GotoMap, Ref("omo_08"), omo_08_ENTRY_1)
                CaseEq(2)
                    Call(GotoMap, Ref("omo_10"), omo_10_ENTRY_2)
                CaseEq(3)
                    Call(GotoMap, Ref("omo_03"), omo_03_ENTRY_2)
            EndSwitch
            Wait(100)
            Return
            Label(11)
            ExecWait(N(EVS_TrainUnk_G))
        EndThread
    Else
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_802429A4_DEE874)))
        Set(MV_TrainUnk_02, 0)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, true)
        Thread
            Label(30)
            Call(N(CheckForSceneSkip))
            IfEq(LVar0, 1)
                Goto(31)
            EndIf
            Wait(1)
            IfGt(MV_TrainPos, -1400)
                Goto(30)
            EndIf
            Switch(GB_OMO_TrainDestination)
                CaseEq(0)
                    Call(GotoMap, Ref("omo_03"), omo_03_ENTRY_3)
                CaseEq(1)
                    Call(GotoMap, Ref("omo_06"), omo_06_ENTRY_3)
                CaseEq(2)
                    Call(GotoMap, Ref("omo_08"), omo_08_ENTRY_2)
                CaseEq(3)
                    Call(GotoMap, Ref("omo_10"), omo_10_ENTRY_3)
            EndSwitch
            Wait(100)
            Return
            Label(31)
            ExecWait(N(EVS_TrainUnk_F))
        EndThread
    EndIf
    Return
    End
};
