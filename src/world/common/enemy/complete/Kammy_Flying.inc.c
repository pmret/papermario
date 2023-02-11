#include "Kammy.h"

NpcSettings N(NpcSettings_Kammy_Flying) = {
    .height = 34,
    .radius = 24,
    .level = 26,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
