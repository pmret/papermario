#include "omo_17.h"

EvtScript N(EVS_Gizmos_Wheels) = {
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, -360, 100, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ha1, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha2, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha3, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha4, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha5, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha6, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha7, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha8, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha9, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha10, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha11, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha12, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha13, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha14, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha15, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha16, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha17, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha18, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGizmos) = {
    EVT_EXEC(N(EVS_Gizmos_Wheels))
    EVT_RETURN
    EVT_END
};
