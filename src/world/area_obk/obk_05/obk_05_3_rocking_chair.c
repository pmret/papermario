#include "obk_05.h"
#include "model.h"

extern EvtScript N(EVS_SetupRockingChair);

#define ROCKING_CHAIR_CENTER_X 0.0
#include "../common/RockingChair.inc.c"

EvtScript N(EVS_SetupRockingChairs) = {
    EVT_EXEC(N(EVS_SetupRockingChair))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupRockingChair) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_i1, MODEL_i1)
    EVT_CALL(ParentColliderToModel, COLLIDER_i2, MODEL_i3)
    EVT_CALL(ParentColliderToModel, COLLIDER_i3, MODEL_i3)
    EVT_CALL(N(UpdateRockingChair))
    EVT_RETURN
    EVT_END
};
