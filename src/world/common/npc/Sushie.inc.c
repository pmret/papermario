#include "common.h"
#include "Sushie.h"

NpcSettings N(NpcSettings_Sushie) = {
    .height = 23,
    .radius = 22,
    .level = 14,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
