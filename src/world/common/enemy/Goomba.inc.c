#include "Goomba.h"

NpcSettings N(NpcSettings_Goomba) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_GOOMBA,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
