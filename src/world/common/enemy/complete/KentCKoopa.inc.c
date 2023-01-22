#include "KentCKoopa.h"

NpcSettings N(NpcSettings_KentCKoopa) = {
    .height = 68,
    .radius = 80,
    .level = 99,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
