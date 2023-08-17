#include "common.h"
#include "Bobomb.h"

NpcSettings N(NpcSettings_Bobomb) = {
    .height = 23,
    .radius = 20,
    .level = ACTOR_LEVEL_BOB_OMB,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
