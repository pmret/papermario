#include "StarRod.h"

EvtScript N(EVS_NpcAuxAI_StarRod) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_StarRod) = {
    .height = 24,
    .radius = 24,
    .level = 99,
    .otherAI = &N(EVS_NpcAuxAI_StarRod),
};
