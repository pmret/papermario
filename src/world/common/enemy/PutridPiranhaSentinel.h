#include "common.h"
#include "sprite/npc/LargePiranha.h"

#define PIRANHA_NO_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_FIRE_FLOWER, 10, 0 } \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(3), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define PIRANHA_SENTINEL_ANIMS \
{ \
    .idle   = ANIM_LargePiranha_Putrid_Anim01, \
    .walk   = ANIM_LargePiranha_Putrid_Anim02, \
    .run    = ANIM_LargePiranha_Putrid_Anim03, \
    .chase  = ANIM_LargePiranha_Putrid_Anim03, \
    .anim_4 = ANIM_LargePiranha_Putrid_Anim01, \
    .anim_5 = ANIM_LargePiranha_Putrid_Anim01, \
    .death  = ANIM_LargePiranha_Putrid_Anim0E, \
    .hit    = ANIM_LargePiranha_Putrid_Anim0E, \
    .anim_8 = ANIM_LargePiranha_Putrid_Anim18, \
    .anim_9 = ANIM_LargePiranha_Putrid_Anim17, \
    .anim_A = ANIM_LargePiranha_Putrid_Anim05, \
    .anim_B = ANIM_LargePiranha_Putrid_Anim06, \
    .anim_C = ANIM_LargePiranha_Putrid_Anim07, \
    .anim_D = ANIM_LargePiranha_Putrid_Anim01, \
    .anim_E = ANIM_LargePiranha_Putrid_Anim01, \
    .anim_F = ANIM_LargePiranha_Putrid_Anim01, \
}
