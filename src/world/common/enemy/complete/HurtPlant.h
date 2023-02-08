#include "common.h"
#include "sprite/npc/HurtPlant.h"

#define HURT_PLANT_DROPS \
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

#define HURT_PLANT_ANIMS \
{ \
    .idle   = ANIM_HurtPlant_Anim01, \
    .walk   = ANIM_HurtPlant_Anim01, \
    .run    = ANIM_HurtPlant_Anim01, \
    .chase  = ANIM_HurtPlant_Anim01, \
    .anim_4 = ANIM_HurtPlant_Anim01, \
    .anim_5 = ANIM_HurtPlant_Anim01, \
    .death  = ANIM_HurtPlant_Anim0E, \
    .hit    = ANIM_HurtPlant_Anim0E, \
    .anim_8 = ANIM_HurtPlant_Anim01, \
    .anim_9 = ANIM_HurtPlant_Anim01, \
    .anim_A = ANIM_HurtPlant_Anim01, \
    .anim_B = ANIM_HurtPlant_Anim01, \
    .anim_C = ANIM_HurtPlant_Anim01, \
    .anim_D = ANIM_HurtPlant_Anim01, \
    .anim_E = ANIM_HurtPlant_Anim01, \
    .anim_F = ANIM_HurtPlant_Anim01, \
}
