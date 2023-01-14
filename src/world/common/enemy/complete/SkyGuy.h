#include "common.h"
#include "sprite/npc/SkyGuy.h"

#define SKY_GUY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_MUSHROOM, 5, 0 }, \
        { ITEM_SUPER_SHROOM, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define SKY_GUY_ANIMS \
{ \
    .idle   = ANIM_SkyGuy_Anim34, \
    .walk   = ANIM_SkyGuy_Anim34, \
    .run    = ANIM_SkyGuy_Anim38, \
    .chase  = ANIM_SkyGuy_Anim38, \
    .anim_4 = ANIM_SkyGuy_Anim33, \
    .anim_5 = ANIM_SkyGuy_Anim33, \
    .death  = ANIM_SkyGuy_Anim39, \
    .hit    = ANIM_SkyGuy_Anim39, \
    .anim_8 = ANIM_SkyGuy_Anim38, \
    .anim_9 = ANIM_SkyGuy_Anim38, \
    .anim_A = ANIM_SkyGuy_Anim01, \
    .anim_B = ANIM_SkyGuy_Anim01, \
    .anim_C = ANIM_SkyGuy_Anim01, \
    .anim_D = ANIM_SkyGuy_Anim01, \
    .anim_E = ANIM_SkyGuy_Anim01, \
    .anim_F = ANIM_SkyGuy_Anim01, \
}
