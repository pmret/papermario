#include "Bombette.h"

NpcSettings N(NpcSettings_Bombette) = {
    .height = 23,
    .radius = 20,
    .level = ACTOR_LEVEL_BOB_OMB,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
