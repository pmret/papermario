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
    .idle   = ANIM_Dayzee_Amazy_Idle, \
    .walk   = ANIM_Dayzee_Amazy_Walk, \
    .run    = ANIM_Dayzee_Amazy_Run, \
    .chase  = ANIM_Dayzee_Amazy_Run, \
    .anim_4 = ANIM_Dayzee_Amazy_Idle, \
    .anim_5 = ANIM_Dayzee_Amazy_Idle, \
    .death  = ANIM_Dayzee_Amazy_Hurt, \
    .hit    = ANIM_Dayzee_Amazy_Hurt, \
    .anim_8 = ANIM_Dayzee_Amazy_SingSlow, \
    .anim_9 = ANIM_Dayzee_Amazy_SingFast, \
    .anim_A = ANIM_Dayzee_Amazy_Idle, \
    .anim_B = ANIM_Dayzee_Amazy_Idle, \
    .anim_C = ANIM_Dayzee_Amazy_Idle, \
    .anim_D = ANIM_Dayzee_Amazy_Idle, \
    .anim_E = ANIM_Dayzee_Amazy_Idle, \
    .anim_F = ANIM_Dayzee_Amazy_Idle, \
}
