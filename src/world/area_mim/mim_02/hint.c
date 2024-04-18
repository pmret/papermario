#include "mim_02.h"

EvtScript N(EVS_SetupExitHint) = {
    SetGroup(EVT_GROUP_00)
    Set(LVar0, 0)
    Call(EnableModel, MODEL_o414, TRUE)
    Call(EnableModel, MODEL_me, FALSE)
    Label(10)
        Call(AwaitPlayerApproach, 20, -340, 50)
        Call(RandInt, 1, LVar2)
        Add(LVar2, 1)
        Call(EnableModel, MODEL_o414, FALSE)
        Call(EnableModel, MODEL_me, TRUE)
        Call(PlaySoundAt, SOUND_IMPISH_LAUGH, SOUND_SPACE_DEFAULT, 10, 110, -200)
        Loop(LVar2)
            Call(EnableModel, MODEL_o414, TRUE)
            Call(EnableModel, MODEL_me, FALSE)
            Wait(2)
            Call(EnableModel, MODEL_o414, FALSE)
            Call(EnableModel, MODEL_me, TRUE)
            Call(RandInt, 5, LVar3)
            Add(LVar3, 2)
            Wait(LVar3)
        EndLoop
        Wait(20)
        Call(EnableModel, MODEL_o414, TRUE)
        Call(EnableModel, MODEL_me, FALSE)
        Wait(60)
        Goto(10)
    Return
    End
};
