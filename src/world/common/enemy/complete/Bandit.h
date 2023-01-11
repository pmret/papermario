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
    .idle   = ANIM_Bandit_Anim01, \
    .walk   = ANIM_Bandit_Anim05, \
    .run    = ANIM_Bandit_Anim07, \
    .chase  = ANIM_Bandit_Anim07, \
    .anim_4 = ANIM_Bandit_Anim01, \
    .anim_5 = ANIM_Bandit_Anim01, \
    .death  = ANIM_Bandit_Anim09, \
    .hit    = ANIM_Bandit_Anim09, \
    .anim_8 = ANIM_Bandit_Anim00, \
    .anim_9 = ANIM_Bandit_Anim00, \
    .anim_A = ANIM_Bandit_Anim00, \
    .anim_B = ANIM_Bandit_Anim00, \
    .anim_C = ANIM_Bandit_Anim00, \
    .anim_D = ANIM_Bandit_Anim00, \
    .anim_E = ANIM_Bandit_Anim00, \
    .anim_F = ANIM_Bandit_Anim00, \
}
