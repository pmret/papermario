#include "kpa_133.h"

EvtScript N(D_80241A90_AA8F10) = {
    EVT_CALL(MakeLerp, 0, 90, 45, EASING_COS_FAST_OVERSHOOT)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};
