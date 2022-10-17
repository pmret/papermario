#include "Whacka.h"

NpcSettings N(NpcSettings_Whacka) = {
    .height = 30,
    .radius = 26,
    .level = 99,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
