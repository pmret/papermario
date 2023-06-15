#include "common.h"
#include "sprite/npc/Bandit.h"

#define BANDIT_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_HONEY_SYRUP, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 3, \
}

#define BANDIT_ANIMS \
{ \
    .idle   = ANIM_Bandit_Idle, \
    .walk   = ANIM_Bandit_Walk, \
    .run    = ANIM_Bandit_Run, \
    .chase  = ANIM_Bandit_Run, \
    .anim_4 = ANIM_Bandit_Idle, \
    .anim_5 = ANIM_Bandit_Idle, \
    .death  = ANIM_Bandit_Hurt, \
    .hit    = ANIM_Bandit_Hurt, \
    .anim_8 = ANIM_Bandit_Still, \
    .anim_9 = ANIM_Bandit_Still, \
    .anim_A = ANIM_Bandit_Still, \
    .anim_B = ANIM_Bandit_Still, \
    .anim_C = ANIM_Bandit_Still, \
    .anim_D = ANIM_Bandit_Still, \
    .anim_E = ANIM_Bandit_Still, \
    .anim_F = ANIM_Bandit_Still, \
}
