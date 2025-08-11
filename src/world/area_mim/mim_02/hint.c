#include "mim_02.h"

EvtScript N(EVS_SetupExitHint) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Set(LVar0, 0)
    Call(EnableModel, MODEL_o414, true)
    Call(EnableModel, MODEL_me, false)
    Label(10)
        Call(AwaitPlayerApproach, 20, -340, 50)
        Call(RandInt, 1, LVar2)
        Add(LVar2, 1)
        Call(EnableModel, MODEL_o414, false)
        Call(EnableModel, MODEL_me, true)
        Call(PlaySoundAt, SOUND_IMPISH_LAUGH, SOUND_SPACE_DEFAULT, 10, 110, -200)
        Loop(LVar2)
            Call(EnableModel, MODEL_o414, true)
            Call(EnableModel, MODEL_me, false)
            Wait(2)
            Call(EnableModel, MODEL_o414, false)
            Call(EnableModel, MODEL_me, true)
            Call(RandInt, 5, LVar3)
            Add(LVar3, 2)
            Wait(LVar3)
        EndLoop
        Wait(20)
        Call(EnableModel, MODEL_o414, true)
        Call(EnableModel, MODEL_me, false)
        Wait(60)
        Goto(10)
    Return
    End
};
