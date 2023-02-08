#include "Bombette.h"

NpcSettings N(NpcSettings_Bombette) = {
    .height = 23,
    .radius = 20,
    .level = 6,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
