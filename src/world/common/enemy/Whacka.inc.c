#include "Whacka.h"

NpcSettings N(NpcSettings_Whacka) = {
    .height = 30,
    .radius = 26,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
