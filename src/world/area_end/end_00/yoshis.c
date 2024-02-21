#include "end_00.h"

EvtScript N(EVS_ParadePhase_Yoshis) = {
    ChildThread
        Call(EnableTexPanning, MODEL_o119, TRUE)
        Set(LVar0, 0)
        Loop(0)
            Add(LVar0, 512)
            Call(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_AUX, LVar0, 0)
            Wait(1)
        EndLoop
    EndChildThread
    ChildThread
        Call(SetNpcScale, NPC_RaphaelRaven, Float(2.0), Float(2.0), 1)
        Loop(0)
            Call(NpcFlyTo, NPC_RaphaelRaven, 357, 0, -30, 10, 0, EASING_LINEAR)
            Wait(60)
            Call(NpcFlyTo, NPC_RaphaelRaven, 357, -120, -30, 10, 0, EASING_LINEAR)
            Wait(60)
        EndLoop
    EndChildThread
    ChildThread
        Call(GetNpcPos, NPC_LavaPiranha, LVar0, LVar1, LVar2)
        Loop(0)
            Wait(60)
            Loop(10)
                Add(LVar0, 5)
                Add(LVar1, 5)
                Call(SetNpcPos, NPC_LavaPiranha, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
            Wait(60)
            Loop(10)
                Sub(LVar0, 5)
                Sub(LVar1, 5)
                Call(SetNpcPos, NPC_LavaPiranha, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
        EndLoop
    EndChildThread
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, 800)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};
