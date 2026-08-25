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
    .idle   = ANIM_LargePiranha_Putrid_Idle, \
    .walk   = ANIM_LargePiranha_Putrid_Walk, \
    .run    = ANIM_LargePiranha_Putrid_Run, \
    .chase  = ANIM_LargePiranha_Putrid_Run, \
    .anim_4 = ANIM_LargePiranha_Putrid_Idle, \
    .anim_5 = ANIM_LargePiranha_Putrid_Idle, \
    .death  = ANIM_LargePiranha_Putrid_Hurt, \
    .hit    = ANIM_LargePiranha_Putrid_Hurt, \
    .anim_8 = ANIM_LargePiranha_Putrid_Burrow, \
    .anim_9 = ANIM_LargePiranha_Putrid_Emerge, \
    .anim_A = ANIM_LargePiranha_Putrid_Windup, \
    .anim_B = ANIM_LargePiranha_Putrid_Bite, \
    .anim_C = ANIM_LargePiranha_Putrid_PostBite, \
    .anim_D = ANIM_LargePiranha_Putrid_Idle, \
    .anim_E = ANIM_LargePiranha_Putrid_Idle, \
    .anim_F = ANIM_LargePiranha_Putrid_Idle, \
}
