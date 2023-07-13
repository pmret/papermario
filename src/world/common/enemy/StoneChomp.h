#include "common.h"
#include "sprite/npc/StoneChomp.h"

#define STONE_CHOMP_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_HONEY_SYRUP, 10, 0 }, \
    }, \
    .heartDrops  = GENEROUS_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
}

#define STONE_CHOMP_ANIMS \
{ \
    .idle   = ANIM_StoneChomp_Idle, \
    .walk   = ANIM_StoneChomp_SlowBite, \
    .run    = ANIM_StoneChomp_Bite, \
    .chase  = ANIM_StoneChomp_Bite, \
    .anim_4 = ANIM_StoneChomp_Idle, \
    .anim_5 = ANIM_StoneChomp_Idle, \
    .death  = ANIM_StoneChomp_Hurt, \
    .hit    = ANIM_StoneChomp_Hurt, \
    .anim_8 = ANIM_StoneChomp_Still, \
    .anim_9 = ANIM_StoneChomp_Still, \
    .anim_A = ANIM_StoneChomp_Still, \
    .anim_B = ANIM_StoneChomp_Still, \
    .anim_C = ANIM_StoneChomp_Still, \
    .anim_D = ANIM_StoneChomp_Still, \
    .anim_E = ANIM_StoneChomp_Still, \
    .anim_F = ANIM_StoneChomp_Still, \
}
