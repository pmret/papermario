#include "common.h"

// LVar0 wall 1 model ID
// LVar1 wall 2 model ID
// LVar2 tex panner ID
EvtScript N(EVS_GlassShimmer) = {
    EVT_CALL(SetTexPanner, LVar0, LVar2)
    EVT_CALL(SetTexPanner, LVar1, LVar2)
    EVT_LOOP(0)
        EVT_CALL(EnableModel, LVar0, TRUE)
        EVT_CALL(EnableModel, LVar1, TRUE)
        EVT_SET(LVarA, 0)
        EVT_LOOP(20)
            EVT_CALL(SetTexPanOffset, LVar2, 0, LVarA, 0)
            EVT_ADD(LVarA, 3000)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(EnableModel, LVar0, FALSE)
        EVT_CALL(EnableModel, LVar1, FALSE)
        EVT_WAIT(160)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
