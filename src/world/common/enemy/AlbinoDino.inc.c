#include "AlbinoDino.h"

EvtScript N(EVS_NpcAuxAI_AlbinoDino) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_AlbinoDino) = {
    .height = 70,
    .radius = 50,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_AlbinoDino),
    .onDefeat = &EnemyNpcDefeat,
};
