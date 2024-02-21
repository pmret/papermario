#include "obk_02.h"

API_CALLABLE(N(GetPendulumAngle)) {
    script->varTable[0] = sin_deg(script->varTable[1]) * 10.0f;
    script->varTable[1] = clamp_angle(script->varTable[1] + (s32)(6 * DT));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ClockDoNothing) = {
    Return
    End
};

EvtScript N(EVS_UpdateClock) = {
    Thread
        Set(LVar0, 0)
        Label(10)
        Call(RotateModel, MODEL_na, LVar0, 0, 0, 1)
        Add(LVar0, -6)
        Wait(30 * DT)
        Goto(10)
    EndThread
    Thread
        Set(LVar0, 0)
        Label(20)
        Call(RotateModel, MODEL_mi, LVar0, 0, 0, 1)
        Add(LVar0, -1)
        Wait(60 * DT)
        Goto(20)
    EndThread
    Thread
        Set(LVar1, 0)
        Label(30)
        Call(N(GetPendulumAngle))
        Call(RotateModel, MODEL_fu, LVar0, 0, 0, 1)
        Wait(1)
        Goto(30)
    EndThread
    Return
    End
};
