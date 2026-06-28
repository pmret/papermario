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
    .idle   = ANIM_MBush_Idle, \
    .walk   = ANIM_MBush_Idle, \
    .run    = ANIM_MBush_Idle, \
    .chase  = ANIM_MBush_Idle, \
    .anim_4 = ANIM_MBush_Idle, \
    .anim_5 = ANIM_MBush_Idle, \
    .death  = ANIM_MBush_Hurt, \
    .hit    = ANIM_MBush_Hurt, \
    .anim_8 = ANIM_MBush_Idle, \
    .anim_9 = ANIM_MBush_Idle, \
    .anim_A = ANIM_MBush_Idle, \
    .anim_B = ANIM_MBush_Idle, \
    .anim_C = ANIM_MBush_Idle, \
    .anim_D = ANIM_MBush_Idle, \
    .anim_E = ANIM_MBush_Idle, \
    .anim_F = ANIM_MBush_Idle, \
}
