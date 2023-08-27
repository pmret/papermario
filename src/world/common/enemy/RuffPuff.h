#include "common.h"
#include "sprite/npc/RuffPuff.h"

#define RUFF_PUFF_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 10, \
    .itemDrops = { \
        { ITEM_THUNDER_RAGE, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define RUFF_PUFF_ANIMS \
{ \
    .idle   = ANIM_RuffPuff_Still, \
    .walk   = ANIM_RuffPuff_Still, \
    .run    = ANIM_RuffPuff_Grin, \
    .chase  = ANIM_RuffPuff_Grin, \
    .anim_4 = ANIM_RuffPuff_Still, \
    .anim_5 = ANIM_RuffPuff_Still, \
    .death  = ANIM_RuffPuff_Hurt, \
    .hit    = ANIM_RuffPuff_Hurt, \
    .anim_8 = ANIM_RuffPuff_Grin, \
    .anim_9 = ANIM_RuffPuff_Idle, \
    .anim_A = ANIM_RuffPuff_Idle, \
    .anim_B = ANIM_RuffPuff_Idle, \
    .anim_C = ANIM_RuffPuff_Idle, \
    .anim_D = ANIM_RuffPuff_Idle, \
    .anim_E = ANIM_RuffPuff_Idle, \
    .anim_F = ANIM_RuffPuff_Idle, \
}
