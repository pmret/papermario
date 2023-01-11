#include "common.h"
#include "sprite/npc/Dayzee.h"

#define CRAZY_DAYZEE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 15, \
    .itemDrops = { \
        { ITEM_MAPLE_SYRUP, 6, 0 }, \
        { ITEM_HONEY_SYRUP, 4, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(4), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define CRAZY_DAYZEE_ANIMS \
{ \
    .idle   = ANIM_Dayzee_Anim01, \
    .walk   = ANIM_Dayzee_Anim02, \
    .run    = ANIM_Dayzee_Anim03, \
    .chase  = ANIM_Dayzee_Anim03, \
    .anim_4 = ANIM_Dayzee_Anim01, \
    .anim_5 = ANIM_Dayzee_Anim01, \
    .death  = ANIM_Dayzee_Anim08, \
    .hit    = ANIM_Dayzee_Anim08, \
    .anim_8 = ANIM_Dayzee_Anim06, \
    .anim_9 = ANIM_Dayzee_Anim07, \
    .anim_A = ANIM_Dayzee_Anim01, \
    .anim_B = ANIM_Dayzee_Anim01, \
    .anim_C = ANIM_Dayzee_Anim01, \
    .anim_D = ANIM_Dayzee_Anim01, \
    .anim_E = ANIM_Dayzee_Anim01, \
    .anim_F = ANIM_Dayzee_Anim01, \
}
