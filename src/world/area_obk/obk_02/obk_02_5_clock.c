#include "obk_02.h"

API_CALLABLE(N(GetPendulumAngle)) {
    script->varTable[0] = sin_deg(script->varTable[1]) * 10.0f;
    script->varTable[1] = clamp_angle(script->varTable[1] + (s32)(6 * DT));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ClockDoNothing) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateClock) = {
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LABEL(10)
        EVT_CALL(RotateModel, MODEL_na, LVar0, 0, 0, 1)
        EVT_ADD(LVar0, -6)
        EVT_WAIT(30 * DT)
        EVT_GOTO(10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LABEL(20)
        EVT_CALL(RotateModel, MODEL_mi, LVar0, 0, 0, 1)
        EVT_ADD(LVar0, -1)
        EVT_WAIT(60 * DT)
        EVT_GOTO(20)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar1, 0)
        EVT_LABEL(30)
        EVT_CALL(N(GetPendulumAngle))
        EVT_CALL(RotateModel, MODEL_fu, LVar0, 0, 0, 1)
        EVT_WAIT(1)
        EVT_GOTO(30)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
