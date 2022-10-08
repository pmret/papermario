#include "arn_09.h"
#include "entity.h"

EvtScript N(EVS_UseSpring) = {
    EVT_IF_EQ(AF_ARN_01, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AF_ARN_01, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, 0, 200, 0, 30)
    EVT_CALL(GotoMap, EVT_PTR("arn_08"), arn_08_ENTRY_1)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 0, 0, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_RETURN
    EVT_END
};
