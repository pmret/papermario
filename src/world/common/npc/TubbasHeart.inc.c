#include "TubbasHeart.h"

EvtScript N(EVS_NpcAuxAI_TubbasHeart) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_TubbasHeart) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_TubbasHeart) = {
    .height = 24,
    .radius = 24,
    .level = 13,
    .otherAI = &N(EVS_NpcAuxAI_TubbasHeart),
    .onDefeat = &N(EVS_NpcDefeat_TubbasHeart),
};
