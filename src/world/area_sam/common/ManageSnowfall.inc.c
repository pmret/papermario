#include "common.h"
#include "../sam.h"
#include "effects.h"

EvtScript N(EVS_ManageSnowfall) = {
    EVT_SET(AF_SAM_Snowing, TRUE)
    EVT_SET(AF_SAM_LastSnowing, FALSE)
    EVT_LABEL(10)
        EVT_IF_NE(AF_SAM_Snowing, AF_SAM_LastSnowing)
            EVT_IF_EQ(AF_SAM_Snowing, FALSE)
                EVT_CALL(RemoveEffect, LVarF)
            EVT_ELSE
                EVT_PLAY_EFFECT(EFFECT_SNOWFALL, 0, 10)
            EVT_END_IF
            EVT_SET(AF_SAM_LastSnowing, AF_SAM_Snowing)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};
