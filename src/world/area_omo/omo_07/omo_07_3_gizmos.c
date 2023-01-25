#include "omo_07.h"

EvtScript N(EVS_Gizmos_Shutters) = {
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, 160, 60, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, 160, 0, 60, EASING_COS_IN_OUT)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            EVT_WAIT(2)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
        EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Clocks) = {
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, -360, 100, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_hari1, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_hari2, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGizmos) = {
    EVT_EXEC(N(EVS_Gizmos_Shutters))
    EVT_EXEC(N(EVS_Gizmos_Clocks))
    EVT_RETURN
    EVT_END
};
