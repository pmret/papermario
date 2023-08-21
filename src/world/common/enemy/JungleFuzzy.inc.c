#include "Fuzzy.h"

NpcSettings N(NpcSettings_JungleFuzzy) = {
    .height = 20,
    .radius = 22,
    .level = ACTOR_LEVEL_FUZZY, // @bug should be ACTOR_LEVEL_JUNGLE_FUZZY
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
