#include "common.h"
#include "sprite/npc/Bobomb.h"

#define BOBOMB_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_HONEY_SYRUP, 5, 0 }, \
        { ITEM_FIRE_FLOWER, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 1, \
}

#define BOBOMB_ANIMS \
{ \
    .idle   = ANIM_Bobomb_Idle, \
    .walk   = ANIM_Bobomb_Walk, \
    .run    = ANIM_Bobomb_Run, \
    .chase  = ANIM_Bobomb_Run, \
    .anim_4 = ANIM_Bobomb_Idle, \
    .anim_5 = ANIM_Bobomb_Idle, \
    .death  = ANIM_Bobomb_Hurt, \
    .hit    = ANIM_Bobomb_Hurt, \
    .anim_8 = ANIM_Bobomb_Run, \
    .anim_9 = ANIM_Bobomb_Run, \
    .anim_A = ANIM_Bobomb_Run, \
    .anim_B = ANIM_Bobomb_Run, \
    .anim_C = ANIM_Bobomb_Run, \
    .anim_D = ANIM_Bobomb_Run, \
    .anim_E = ANIM_Bobomb_Run, \
    .anim_F = ANIM_Bobomb_Run, \
}
