#include "common.h"
#include "TubbaBlubba.h"

NpcSettings N(NpcSettings_TubbaBlubba) = {
    .height = 90,
    .radius = 65,
    .level = 13,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
