#include "obk_05.h"
#include "model.h"

extern EvtScript N(EVS_SetupRockingChair);

#define ROCKING_CHAIR_CENTER_X 0.0
#include "../common/RockingChair.inc.c"

EvtScript N(EVS_SetupRockingChairs) = {
    Exec(N(EVS_SetupRockingChair))
    Return
    End
};

EvtScript N(EVS_SetupRockingChair) = {
    Call(ParentColliderToModel, COLLIDER_i1, MODEL_i1)
    Call(ParentColliderToModel, COLLIDER_i2, MODEL_i3)
    Call(ParentColliderToModel, COLLIDER_i3, MODEL_i3)
    Call(N(UpdateRockingChair))
    Return
    End
};
