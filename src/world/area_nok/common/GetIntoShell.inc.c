#include "common.h"

EvtScript N(EVS_GetIntoShell) = {
    Call(GetNpcYaw, LVar4, LVar1)
    Set(LVar2, 30)
    IfGt(LVar1, 151)
        IfLe(LVar1, 331)
            Set(LVar2, -30)
        EndIf
    EndIf
    Set(LVar0, 0)
    Loop(15)
        Add(LVar0, LVar2)
        Call(SetNpcRotation, LVar3, 0, 0, LVar0)
        Wait(1)
    EndLoop
    Return
    End
};
