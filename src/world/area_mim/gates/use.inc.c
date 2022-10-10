#include "common.h"

EvtScript N(EVS_UseGate_North) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, 0)
    EVT_SET(LVar8, 70)
    EVT_SET(LVar9, COLLIDER_monn)
    EVT_SET(LVarA, MODEL_monn)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_South) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, 0)
    EVT_SET(LVar8, -70)
    EVT_SET(LVar9, COLLIDER_mons)
    EVT_SET(LVarA, MODEL_mons)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_East) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, -70)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, COLLIDER_mone)
    EVT_SET(LVarA, MODEL_mone)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_West) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, 70)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, COLLIDER_monw)
    EVT_SET(LVarA, MODEL_monw)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
