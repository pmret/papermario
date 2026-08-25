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
    .idle   = ANIM_Dayzee_Idle, \
    .walk   = ANIM_Dayzee_Walk, \
    .run    = ANIM_Dayzee_Run, \
    .chase  = ANIM_Dayzee_Run, \
    .anim_4 = ANIM_Dayzee_Idle, \
    .anim_5 = ANIM_Dayzee_Idle, \
    .death  = ANIM_Dayzee_Hurt, \
    .hit    = ANIM_Dayzee_Hurt, \
    .anim_8 = ANIM_Dayzee_SingSlow, \
    .anim_9 = ANIM_Dayzee_SingFast, \
    .anim_A = ANIM_Dayzee_Idle, \
    .anim_B = ANIM_Dayzee_Idle, \
    .anim_C = ANIM_Dayzee_Idle, \
    .anim_D = ANIM_Dayzee_Idle, \
    .anim_E = ANIM_Dayzee_Idle, \
    .anim_F = ANIM_Dayzee_Idle, \
}
