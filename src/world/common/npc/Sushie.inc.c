#include "common.h"
#include "Sushie.h"

NpcSettings N(NpcSettings_Sushie) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
