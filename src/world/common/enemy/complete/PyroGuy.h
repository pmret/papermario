#include "common.h"
#include "sprite/npc/PyroGuy.h"

#define PYRO_GUY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_FIRE_FLOWER, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define PYRO_GUY_ANIMS \
{ \
    .idle   = ANIM_PyroGuy_Anim01, \
    .walk   = ANIM_PyroGuy_Anim02, \
    .run    = ANIM_PyroGuy_Anim03, \
    .chase  = ANIM_PyroGuy_Anim02, \
    .anim_4 = ANIM_PyroGuy_Anim01, \
    .anim_5 = ANIM_PyroGuy_Anim01, \
    .death  = ANIM_PyroGuy_Anim06, \
    .hit    = ANIM_PyroGuy_Anim06, \
    .anim_8 = ANIM_PyroGuy_Anim01, \
    .anim_9 = ANIM_PyroGuy_Anim01, \
    .anim_A = ANIM_PyroGuy_Anim01, \
    .anim_B = ANIM_PyroGuy_Anim01, \
    .anim_C = ANIM_PyroGuy_Anim01, \
    .anim_D = ANIM_PyroGuy_Anim01, \
    .anim_E = ANIM_PyroGuy_Anim01, \
    .anim_F = ANIM_PyroGuy_Anim01, \
}
