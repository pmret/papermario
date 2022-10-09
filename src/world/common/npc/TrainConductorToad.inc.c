#include "TrainConductorToad.h"

EvtScript N(EVS_NpcAuxAI_TrainConductorToad) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_TrainConductorToad) = {
    .height = 32,
    .radius = 24,
    .level = 99,
    .otherAI = &N(EVS_NpcAuxAI_TrainConductorToad),
};
