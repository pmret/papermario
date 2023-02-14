#include "Fuzzy.h"

NpcSettings N(NpcSettings_Fuzzy) = {
    .height = 20,
    .radius = 22,
    .level = 6,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
