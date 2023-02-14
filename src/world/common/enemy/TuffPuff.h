#include "common.h"
#include "sprite/npc/TuffPuff.h"

#define TUFF_PUFF_DROPS \
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

#define TUFF_PUFF_ANIMS \
{ \
    .idle   = ANIM_TuffPuff_Still, \
    .walk   = ANIM_TuffPuff_Still, \
    .run    = ANIM_TuffPuff_Grin, \
    .chase  = ANIM_TuffPuff_Grin, \
    .anim_4 = ANIM_TuffPuff_Still, \
    .anim_5 = ANIM_TuffPuff_Still, \
    .death  = ANIM_TuffPuff_Hurt, \
    .hit    = ANIM_TuffPuff_Hurt, \
    .anim_8 = ANIM_TuffPuff_Grin, \
    .anim_9 = ANIM_TuffPuff_Idle, \
    .anim_A = ANIM_TuffPuff_Idle, \
    .anim_B = ANIM_TuffPuff_Idle, \
    .anim_C = ANIM_TuffPuff_Idle, \
    .anim_D = ANIM_TuffPuff_Idle, \
    .anim_E = ANIM_TuffPuff_Idle, \
    .anim_F = ANIM_TuffPuff_Idle, \
}
