#include "Lakitu.h"

NpcSettings N(NpcSettings_Lakitu) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_LAKITU,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
