#include "CrystalKing.h"

NpcSettings N(NpcSettings_CrystalKing) = {
    .height = 50,
    .radius = 55,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
