#include "flo_14.h"

#include "../common/LogBridge.inc.c"

EvtScript N(EVS_SetupLogBridges) = {
    EVT_MAKE_LOG_BRIDGE(COLLIDER_o162, COLLIDER_o166, MODEL_o15, MODEL_o16, MV_RotAngle_Log_01, MV_RotVelocity_Log_01)
    EVT_MAKE_LOG_BRIDGE(COLLIDER_o161, COLLIDER_o167, MODEL_o17, MODEL_o18, MV_RotAngle_Log_02, MV_RotVelocity_Log_02)
    Return
    End
};
