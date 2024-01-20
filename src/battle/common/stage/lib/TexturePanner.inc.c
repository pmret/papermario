#include "common.h"

// pan the main tile along U and V
// (in) LVar0 : modelID
// (in) LVar1 : tex panner ID
// (in) LVar2 : main du
// (in) LVar3 : main dv
EvtScript N(EVS_TexturePanMain) = {
    Set(LVarA, LVar1)
    Set(LVarB, LVar2)
    Set(LVarC, LVar3)
    Call(SetTexPanner, LVar0, LVar1)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        Call(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, LVar0, LVar1)
        Add(LVar0, LVarB)
        Add(LVar1, LVarC)
        Wait(1)
    EndLoop
    Return
    End
};

// pan the main and aux tiles along U
// (in) LVar0 : modelID
// (in) LVar1 : tex panner ID
// (in) LVar2 : main du
// (in) LVar3 : aux du
EvtScript N(EVS_TexturePanBothU) = {
    Set(LVarA, LVar1)
    Set(LVarB, LVar2)
    Set(LVarC, LVar3)
    Call(SetTexPanner, LVar0, LVar1)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        Call(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, LVarA, TEX_PANNER_AUX,  LVar1, 0)
        Add(LVar0, LVarB)
        Add(LVar1, LVarC)
        Wait(1)
    EndLoop
    Return
    End
};

// pan the main and aux tiles along V
// (in) LVar0 : modelID
// (in) LVar1 : tex panner ID
// (in) LVar2 : main dv
// (in) LVar3 : aux dv
EvtScript N(EVS_TexturePanBothV) = {
    Set(LVarA, LVar1)
    Set(LVarB, LVar2)
    Set(LVarC, LVar3)
    Call(SetTexPanner, LVar0, LVar1)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        Call(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, 0, LVar0)
        Call(SetTexPanOffset, LVarA, TEX_PANNER_AUX,  0, LVar1)
        Add(LVar0, LVarB)
        Add(LVar1, LVarC)
        Wait(1)
    EndLoop
    Return
    End
};
