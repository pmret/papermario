#include "CrystalKing.h"

NpcSettings N(NpcSettings_CrystalKing) = {
    .height = 50,
    .radius = 55,
    .level = 99,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
