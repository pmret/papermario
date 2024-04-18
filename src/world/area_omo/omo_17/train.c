#include "omo_17.h"

#include "../common/ToyTrain.inc.c"

EvtScript N(D_80245CEC_DF4B8C) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, -600)
            Set(LVar0, -600)
        EndIf
        IfGt(LVar0, 600)
            Set(LVar0, 600)
        EndIf
        Call(SetCamTarget, CAM_DEFAULT, LVar0, Float(50.0), LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

s32 N(EVS_TrainPath_LeftToRight)[] = {
    Float(-720.0), Float(0.0), Float(90.0),
    Float(720.0), Float(0.0),
    -1, -1, -1,
};

s32 N(EVS_TrainPath_RightToLeft)[] = {
    Float(720.0), Float(0.0), Float(270.0),
    Float(-720.0), Float(0.0),
    -1, -1, -1,
};

EvtScript N(EVS_EnterTrain) = {
    Call(ParentColliderToModel, COLLIDER_p1, MODEL_o1)
    Call(ParentColliderToModel, COLLIDER_pp1, MODEL_o1)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Exec(N(D_80245CEC_DF4B8C))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(omo_17_ENTRY_4)
            Set(MV_TrainUnk_00, 0)
            Set(MV_TrainUnk_01, Ref(N(EVS_TrainPath_LeftToRight)))
            Set(MV_TrainUnk_02, 0)
            Exec(N(EVS_Scene_RideTrain))
            Set(MF_TrainUnk_00, TRUE)
            Thread
                Label(10)
                IfLt(MV_TrainPos, 600)
                    Wait(1)
                    Goto(10)
                EndIf
                Call(GotoMap, Ref("omo_06"), omo_06_ENTRY_0)
                Wait(100)
            EndThread
        CaseEq(omo_17_ENTRY_5)
            Set(MV_TrainUnk_00, 0)
            Set(MV_TrainUnk_01, Ref(N(EVS_TrainPath_RightToLeft)))
            Set(MV_TrainUnk_02, 0)
            Exec(N(EVS_Scene_RideTrain))
            Set(MF_TrainUnk_00, TRUE)
            Thread
                Label(20)
                IfGt(MV_TrainPos, -600)
                    Wait(1)
                    Goto(20)
                EndIf
                Call(GotoMap, Ref("omo_05"), omo_05_ENTRY_1)
                Wait(100)
            EndThread
    EndSwitch
    Return
    End
};

MAP_RODATA_PAD(1, strings);
