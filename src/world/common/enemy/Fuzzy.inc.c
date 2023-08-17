#include "Fuzzy.h"

NpcSettings N(NpcSettings_Fuzzy) = {
    .height = 20,
    .radius = 22,
    .level = ACTOR_LEVEL_FUZZY,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
