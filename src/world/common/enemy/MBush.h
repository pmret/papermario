#include "common.h"
#include "sprite/npc/MBush.h"

#define MBUSH_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 10, \
    .itemDrops = { \
        { ITEM_TASTY_TONIC, 5, 0 }, \
        { ITEM_SUPER_SODA, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define MBUSH_ANIMS \
{ \
    .idle   = ANIM_MBush_Anim02, \
    .walk   = ANIM_MBush_Anim02, \
    .run    = ANIM_MBush_Anim02, \
    .chase  = ANIM_MBush_Anim02, \
    .anim_4 = ANIM_MBush_Anim02, \
    .anim_5 = ANIM_MBush_Anim02, \
    .death  = ANIM_MBush_Anim07, \
    .hit    = ANIM_MBush_Anim07, \
    .anim_8 = ANIM_MBush_Anim02, \
    .anim_9 = ANIM_MBush_Anim02, \
    .anim_A = ANIM_MBush_Anim02, \
    .anim_B = ANIM_MBush_Anim02, \
    .anim_C = ANIM_MBush_Anim02, \
    .anim_D = ANIM_MBush_Anim02, \
    .anim_E = ANIM_MBush_Anim02, \
    .anim_F = ANIM_MBush_Anim02, \
}
