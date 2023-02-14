#include "Lakitu.h"

NpcSettings N(NpcSettings_Lakitu) = {
    .height = 32,
    .radius = 24,
    .level = 20,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
