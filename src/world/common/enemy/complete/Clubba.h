#include "common.h"
#include "sprite/npc/WorldClubba.h"

#define CLUBBA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
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

#define CLUBBA_ANIMS \
{ \
    .idle   = ANIM_WorldClubba_Anim02, \
    .walk   = ANIM_WorldClubba_Anim03, \
    .run    = ANIM_WorldClubba_Anim04, \
    .chase  = ANIM_WorldClubba_Anim04, \
    .anim_4 = ANIM_WorldClubba_Anim02, \
    .anim_5 = ANIM_WorldClubba_Anim02, \
    .death  = ANIM_WorldClubba_Anim0C, \
    .hit    = ANIM_WorldClubba_Anim0C, \
    .anim_8 = ANIM_WorldClubba_Anim11, \
    .anim_9 = ANIM_WorldClubba_Anim12, \
    .anim_A = ANIM_WorldClubba_Anim07, \
    .anim_B = ANIM_WorldClubba_Anim08, \
    .anim_C = ANIM_WorldClubba_Anim01, \
    .anim_D = ANIM_WorldClubba_Anim02, \
    .anim_E = ANIM_WorldClubba_Anim02, \
    .anim_F = ANIM_WorldClubba_Anim02, \
}
