#include "arn_08.h"

EvtScript N(EVS_AnimateGears) = {
    Call(PlaySound, SOUND_LOOP_WINDMILL_GEARS)
    Thread
        Set(LVar0, 0)
        Label(10)
            Call(RotateModel, MODEL_o45, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_o47, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_o46, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_o44, LVar0, 0, 0, -1)
            Call(RotateModel, MODEL_o48, LVar0, 0, 0, -1)
            Add(LVar0, 1)
            Wait(1)
            Goto(10)
    EndThread
    Return
    End
};
