#include "common.h"
#include "sprite/npc/Bzzap.h"

#define BZZAP_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 15, \
    .itemDrops = { \
        { ITEM_MAPLE_SYRUP, 6, 0 }, \
        { ITEM_HONEY_SYRUP, 4, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 4, \
}

#define BZZAP_ANIMS \
{ \
    .idle   = ANIM_Bzzap_FlySlow, \
    .walk   = ANIM_Bzzap_FlySlow, \
    .run    = ANIM_Bzzap_FlyFast, \
    .chase  = ANIM_Bzzap_FlyFast, \
    .anim_4 = ANIM_Bzzap_Idle, \
    .anim_5 = ANIM_Bzzap_FlySlow, \
    .death  = ANIM_Bzzap_Hurt, \
    .hit    = ANIM_Bzzap_Hurt, \
    .anim_8 = ANIM_Bzzap_Sting, \
    .anim_9 = ANIM_Bzzap_FlySlow, \
    .anim_A = ANIM_Bzzap_Idle, \
    .anim_B = ANIM_Bzzap_Idle, \
    .anim_C = ANIM_Bzzap_Idle, \
    .anim_D = ANIM_Bzzap_Idle, \
    .anim_E = ANIM_Bzzap_Idle, \
    .anim_F = ANIM_Bzzap_Idle, \
}
