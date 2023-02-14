#include "common.h"
#include "KoopaTroopa.h"

NpcSettings N(NpcSettings_KoopaTroopa_Stationary) = {
    .height = 35,
    .radius = 24,
    .level = 6,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
