#include "Kammy.h"

NpcSettings N(NpcSettings_Kammy) = {
    .height = 40,
    .radius = 30,
    .level = 26,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
