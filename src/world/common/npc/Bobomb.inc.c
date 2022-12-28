#include "common.h"
#include "Bobomb.h"

NpcSettings N(NpcSettings_Bobomb) = {
    .height = 23,
    .radius = 20,
    .level = 6,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
