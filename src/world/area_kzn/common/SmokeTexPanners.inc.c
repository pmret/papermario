#include "common.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_StartTexPanner_SmokeLeft) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_3)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(-200, 0, 600, -400)
        TEX_PAN_PARAMS_FREQ(   1, 0,   1,    1)
        TEX_PAN_PARAMS_INIT(   0, 0,   0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartTexPanner_SmokeRight) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_4)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(500, 0, 0, -400)
        TEX_PAN_PARAMS_FREQ(  1, 0, 0,    1)
        TEX_PAN_PARAMS_INIT(  0, 0, 0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
