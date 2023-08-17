#include "Kammy.h"

NpcSettings N(NpcSettings_Kammy_Flying) = {
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_MAGIKOOPA,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
