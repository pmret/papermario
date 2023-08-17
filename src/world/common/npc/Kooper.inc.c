#include "common.h"
#include "Kooper.h"

NpcSettings N(NpcSettings_Kooper) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};
