#include "TrainToad.h"

EvtScript N(EVS_NpcAuxAI_TrainToad) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_TrainToad) = {
    .height = 32,
    .radius = 24,
    .level = 99,
    .otherAI = &N(EVS_NpcAuxAI_TrainToad),
};
