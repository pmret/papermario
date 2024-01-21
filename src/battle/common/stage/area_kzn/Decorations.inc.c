#include "battle/battle.h"

EvtScript N(EVS_TexPan_Lava) = {
    Set(LVarA, LVar1)
    Call(SetTexPanner, LVar0, LVar1)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        Call(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, LVarA, TEX_PANNER_AUX, LVar1, 0)
        Sub(LVar0, -300)
        Sub(LVar1, -500)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexAnim_LavaBubble) = {
    Set(LVarA, LVar1)
    Call(SetTexPanner, LVar0, LVar1)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        Call(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, LVar0, LVar1)
        Add(LVar0, 0x4000)
        Add(LVar1, 0)
        Wait(5)
    EndLoop
    Return
    End
};

EvtScript N(EVS_MovingPlatform) = {
    Set(LVarA, LVar0) // modelID
    Set(LVar9, LVar1) // start X
    Set(LVar8, LVar2) // end X
    Set(LVar7, LVar3) // move time
    Label(0)
        Set(LVar2, LVar8)
        Add(LVar2, LVar9)
        Call(MakeLerp, LVar8, LVar2, LVar7, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, LVarA, LVar0, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Set(LVar2, LVar8)
        Add(LVar2, LVar9)
        Call(MakeLerp, LVar2, LVar8, LVar7, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, LVarA, LVar0, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Goto(0)
    Return
    End
};
