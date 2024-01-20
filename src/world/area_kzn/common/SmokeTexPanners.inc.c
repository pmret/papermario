#include "common.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_StartTexPanner_SmokeLeft) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, LVar0, TEX_PANNER_3)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(-200, 0, 600, -400)
        TEX_PAN_PARAMS_FREQ(   1, 0,   1,    1)
        TEX_PAN_PARAMS_INIT(   0, 0,   0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};

EvtScript N(EVS_StartTexPanner_SmokeRight) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, LVar0, TEX_PANNER_4)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(500, 0, 0, -400)
        TEX_PAN_PARAMS_FREQ(  1, 0, 0,    1)
        TEX_PAN_PARAMS_INIT(  0, 0, 0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};
