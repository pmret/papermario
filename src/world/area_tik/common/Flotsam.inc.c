#include "common.h"

EvtScript N(EVS_Flotsam_Bobbing) = {
    Loop(0)
        Call(MakeLerp, 0, -10, 25, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, LVar2, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, -10, 0, 30, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, LVar2, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};
