#include "flo_21.h"

s32 N(UnusedScaleVectors)[] = {
    EVT_FLOAT(1.0), EVT_FLOAT(1.0),
    EVT_FLOAT(1.0), EVT_FLOAT(1.0),
    EVT_FLOAT(1.0), EVT_FLOAT(1.0),
    EVT_FLOAT(1.1), EVT_FLOAT(1.1),
    EVT_FLOAT(1.1), EVT_FLOAT(1.1),
    EVT_FLOAT(1.1), EVT_FLOAT(1.1),
    EVT_FLOAT(1.0), EVT_FLOAT(1.0),
    EVT_FLOAT(1.0), EVT_FLOAT(1.0),
    EVT_FLOAT(1.0), EVT_FLOAT(1.0),
    EVT_FLOAT(0.9), EVT_FLOAT(0.9),
    EVT_FLOAT(0.9), EVT_FLOAT(0.9),
    EVT_FLOAT(0.9), EVT_FLOAT(0.9),
};

EvtScript N(EVS_UnkInit_00) = {
    EVT_ADDF(MV_Unk_00, EVT_FLOAT(-1.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UnkInit_01) = {
    EVT_ADDF(MV_Unk_01, EVT_FLOAT(-1.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UnkInit_02) = {
    EVT_ADDF(MV_Unk_02, EVT_FLOAT(-1.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UnkInit_03) = {
    EVT_ADDF(MV_Unk_03, EVT_FLOAT(-1.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UnkInit_04) = {
    EVT_ADDF(MV_Unk_04, EVT_FLOAT(-1.5))
    EVT_RETURN
    EVT_END
};

#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_SetupCloudPuffs) = {
    EVT_THREAD
        EVT_SET(LVarF, 0)
        EVT_LABEL(0)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.968), EVT_FLOAT(1.031), 15, 0, 0)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(1.031), EVT_FLOAT(0.968), 15, 0, 0)
            EVT_CALL(ScaleModel, MODEL_o1, LVar1, LVar0, 1)
            EVT_CALL(ScaleModel, MODEL_o2, LVar1, LVar0, 1)
            EVT_CALL(ScaleModel, MODEL_o3, LVar0, LVar1, 1)
            EVT_CALL(ScaleModel, MODEL_o4, LVar0, LVar1, 1)
            EVT_CALL(ScaleModel, MODEL_o9, LVar0, LVar1, 1)
            EVT_CALL(ScaleModel, MODEL_o14, LVar1, LVar0, 1)
            EVT_CALL(ScaleModel, MODEL_o15, LVar0, LVar1, 1)
            EVT_CALL(ScaleModel, MODEL_o16, LVar0, LVar1, 1)
            EVT_ADD(LVarF, 1)
            EVT_IF_GE(LVarF, 30)
                EVT_SET(LVarF, 0)
            EVT_END_IF
            EVT_WAIT(1)
            EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
