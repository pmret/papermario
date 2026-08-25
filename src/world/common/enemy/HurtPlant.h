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
    .idle   = ANIM_HurtPlant_Hiding, \
    .walk   = ANIM_HurtPlant_Hiding, \
    .run    = ANIM_HurtPlant_Hiding, \
    .chase  = ANIM_HurtPlant_Hiding, \
    .anim_4 = ANIM_HurtPlant_Hiding, \
    .anim_5 = ANIM_HurtPlant_Hiding, \
    .death  = ANIM_HurtPlant_Hurt, \
    .hit    = ANIM_HurtPlant_Hurt, \
    .anim_8 = ANIM_HurtPlant_Hiding, \
    .anim_9 = ANIM_HurtPlant_Hiding, \
    .anim_A = ANIM_HurtPlant_Hiding, \
    .anim_B = ANIM_HurtPlant_Hiding, \
    .anim_C = ANIM_HurtPlant_Hiding, \
    .anim_D = ANIM_HurtPlant_Hiding, \
    .anim_E = ANIM_HurtPlant_Hiding, \
    .anim_F = ANIM_HurtPlant_Hiding, \
}
