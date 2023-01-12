#include "common.h"
#include "sprite/npc/Dayzee.h"

#define AMAZY_DAYZEE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 20, \
    .itemDrops = { \
        { ITEM_HONEY_SYRUP, 24, 0 }, \
        { ITEM_MAPLE_SYRUP, 25, 0 }, \
        { ITEM_JAMMIN_JELLY, 1, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(6), \
    .minCoinBonus = 5, \
    .maxCoinBonus = 8, \
}

#define AMAZY_DAYZEE_ANIMS \
{ \
    .idle   = ANIM_Dayzee_Amazy_Anim01, \
    .walk   = ANIM_Dayzee_Amazy_Anim02, \
    .run    = ANIM_Dayzee_Amazy_Anim03, \
    .chase  = ANIM_Dayzee_Amazy_Anim03, \
    .anim_4 = ANIM_Dayzee_Amazy_Anim01, \
    .anim_5 = ANIM_Dayzee_Amazy_Anim01, \
    .death  = ANIM_Dayzee_Amazy_Anim08, \
    .hit    = ANIM_Dayzee_Amazy_Anim08, \
    .anim_8 = ANIM_Dayzee_Amazy_Anim06, \
    .anim_9 = ANIM_Dayzee_Amazy_Anim07, \
    .anim_A = ANIM_Dayzee_Amazy_Anim01, \
    .anim_B = ANIM_Dayzee_Amazy_Anim01, \
    .anim_C = ANIM_Dayzee_Amazy_Anim01, \
    .anim_D = ANIM_Dayzee_Amazy_Anim01, \
    .anim_E = ANIM_Dayzee_Amazy_Anim01, \
    .anim_F = ANIM_Dayzee_Amazy_Anim01, \
}
