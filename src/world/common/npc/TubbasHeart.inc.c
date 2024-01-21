#include "TubbasHeart.h"

EvtScript N(EVS_NpcAuxAI_TubbasHeart) = {
    Return
    End
};

EvtScript N(EVS_NpcDefeat_TubbasHeart) = {
    Return
    End
};

NpcSettings N(NpcSettings_TubbasHeart) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_CLUBBA,
    .otherAI = &N(EVS_NpcAuxAI_TubbasHeart),
    .onDefeat = &N(EVS_NpcDefeat_TubbasHeart),
};
