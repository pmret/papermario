#include "flo_17.h"

#include "world/area_flo/common/LogBridge.inc.c"

EvtScript N(EVS_SetupLogBridges) = {
    EVT_MAKE_LOG_BRIDGE(COLLIDER_o22, COLLIDER_o138, MODEL_o19, MODEL_o20, MV_RotAngle_Log_01, MV_RotVelocity_Log_01)
    EVT_MAKE_LOG_BRIDGE(COLLIDER_o15, COLLIDER_o139, MODEL_o17, MODEL_o18, MV_RotAngle_Log_02, MV_RotVelocity_Log_02)
    EVT_MAKE_LOG_BRIDGE(COLLIDER_o13, COLLIDER_o140, MODEL_o11, MODEL_o12, MV_RotAngle_Log_03, MV_RotVelocity_Log_03)
    Return
    End
};
