#include "arn_07.h"

MAP_RODATA_PAD(1,windmill);

API_CALLABLE(N(WrapWindmillAngle)) {
    f32 angle = evt_get_float_variable(script, LVar0);

    if (angle >= 360.0) {
        angle -= 360.0;
    }
    evt_set_float_variable(script, LVar0, angle);
    return ApiStatus_DONE2;
}

extern EvtScript(N(EVS_UpdateWindmill));

EvtScript N(EVS_SetupWindmill) = {
    Exec(N(EVS_UpdateWindmill))
    Return
    End
};

EvtScript N(EVS_UpdateWindmill) = {
    SetF(LVar0, Float(0.0))
    Set(LVar1, 30)
    Call(PlaySoundAtModel, MODEL_o36, SOUND_LOOP_WINDMILL_EXT, SOUND_SPACE_DEFAULT)
    Label(0)
        AddF(LVar0, Float(1.0))
        Call(N(WrapWindmillAngle))
        Call(RotateModel, MODEL_o40, LVar0, 0, 0, 1)
        Wait(1)
        Sub(LVar1, 1)
        IfGt(LVar1, 0)
            Goto(0)
        EndIf
        Set(LVar1, 30)
        Call(RandInt, 100, LVar2)
        IfGt(LVar2, 10)
            Goto(0)
        EndIf
        SetF(LVar2, Float(1.0))
        Loop(50)
            SubF(LVar2, Float(0.01))
            AddF(LVar0, LVar2)
            Call(RotateModel, MODEL_o40, LVar0, 0, 0, 1)
            Wait(1)
        EndLoop
        Loop(50)
            AddF(LVar2, Float(0.01))
            AddF(LVar0, LVar2)
            Call(RotateModel, MODEL_o40, LVar0, 0, 0, 1)
            Wait(1)
        EndLoop
        Set(LVar1, 30)
        Goto(0)
    Return
    End
};
