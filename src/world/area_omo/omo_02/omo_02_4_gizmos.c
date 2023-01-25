#include "omo_02.h"

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
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Shutters) = {
    EVT_LABEL(0)
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, 160, 60, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m3_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m3_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m4_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m4_2, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, 160, 0, 60, EASING_COS_IN_OUT)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m3_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m3_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m4_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m4_2, LVar0, 0, 1, 0)
            EVT_WAIT(2)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Empty1) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Empty2) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Unused) = {
    EVT_RETURN
    EVT_END
};

s32 N(RockingHorseModels)[] = {
    MODEL_o568,
    MODEL_o569,
};

#define ROCKING_SOUND_LOCATION -706.0f, 0.0f, 102.0f
#import "../common/RockingHorse.inc.c"

EvtScript N(EVS_SetupGizmos) = {
    EVT_EXEC(N(EVS_Gizmos_Wheels))
    EVT_EXEC(N(EVS_Gizmos_Shutters))
    EVT_EXEC(N(EVS_Gizmos_Empty1))
    EVT_EXEC(N(EVS_Gizmos_Empty2))
    EVT_EXEC(N(EVS_Gizmos_RockingHorses))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
