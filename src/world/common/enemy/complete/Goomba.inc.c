#include "Goomba.h"

NpcSettings N(NpcSettings_Goomba) = {
    .height = 23,
    .radius = 22,
    .level = 5,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
