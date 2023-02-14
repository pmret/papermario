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
    .idle   = ANIM_StoneChomp_Anim01, \
    .walk   = ANIM_StoneChomp_Anim05, \
    .run    = ANIM_StoneChomp_Anim04, \
    .chase  = ANIM_StoneChomp_Anim04, \
    .anim_4 = ANIM_StoneChomp_Anim01, \
    .anim_5 = ANIM_StoneChomp_Anim01, \
    .death  = ANIM_StoneChomp_Anim06, \
    .hit    = ANIM_StoneChomp_Anim06, \
    .anim_8 = ANIM_StoneChomp_Anim00, \
    .anim_9 = ANIM_StoneChomp_Anim00, \
    .anim_A = ANIM_StoneChomp_Anim00, \
    .anim_B = ANIM_StoneChomp_Anim00, \
    .anim_C = ANIM_StoneChomp_Anim00, \
    .anim_D = ANIM_StoneChomp_Anim00, \
    .anim_E = ANIM_StoneChomp_Anim00, \
    .anim_F = ANIM_StoneChomp_Anim00, \
}
