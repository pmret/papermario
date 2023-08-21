#include "KentCKoopa.h"

NpcSettings N(NpcSettings_KentCKoopa) = {
    .height = 68,
    .radius = 80,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
