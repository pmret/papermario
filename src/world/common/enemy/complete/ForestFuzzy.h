#include "common.h"
#include "sprite/npc/Fuzzy.h"

#define FOREST_FUZZY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_THUNDER_BOLT, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define FOREST_FUZZY_ANIMS \
{ \
    .idle   = ANIM_Fuzzy_Forest_Anim02, \
    .walk   = ANIM_Fuzzy_Forest_Anim02, \
    .run    = ANIM_Fuzzy_Forest_Anim03, \
    .chase  = ANIM_Fuzzy_Forest_Anim03, \
    .anim_4 = ANIM_Fuzzy_Forest_Anim01, \
    .anim_5 = ANIM_Fuzzy_Forest_Anim01, \
    .death  = ANIM_Fuzzy_Forest_Anim08, \
    .hit    = ANIM_Fuzzy_Forest_Anim08, \
    .anim_8 = ANIM_Fuzzy_Forest_Anim03, \
    .anim_9 = ANIM_Fuzzy_Forest_Anim03, \
    .anim_A = ANIM_Fuzzy_Forest_Anim03, \
    .anim_B = ANIM_Fuzzy_Forest_Anim03, \
    .anim_C = ANIM_Fuzzy_Forest_Anim03, \
    .anim_D = ANIM_Fuzzy_Forest_Anim03, \
    .anim_E = ANIM_Fuzzy_Forest_Anim03, \
    .anim_F = ANIM_Fuzzy_Forest_Anim03, \
}
