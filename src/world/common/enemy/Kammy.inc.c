#include "Kammy.h"

NpcSettings N(NpcSettings_Kammy) = {
    .height = 40,
    .radius = 30,
    .level = ACTOR_LEVEL_MAGIKOOPA,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
