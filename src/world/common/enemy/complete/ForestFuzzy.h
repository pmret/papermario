#include "common.h"
#include "sprite/npc/Fuzzy.h"

#define FOREST_FUZZY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
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
    .idle   = ANIM_Fuzzy_Forest_Walk, \
    .walk   = ANIM_Fuzzy_Forest_Walk, \
    .run    = ANIM_Fuzzy_Forest_Run, \
    .chase  = ANIM_Fuzzy_Forest_Run, \
    .anim_4 = ANIM_Fuzzy_Forest_Idle, \
    .anim_5 = ANIM_Fuzzy_Forest_Idle, \
    .death  = ANIM_Fuzzy_Forest_Hurt, \
    .hit    = ANIM_Fuzzy_Forest_Hurt, \
    .anim_8 = ANIM_Fuzzy_Forest_Run, \
    .anim_9 = ANIM_Fuzzy_Forest_Run, \
    .anim_A = ANIM_Fuzzy_Forest_Run, \
    .anim_B = ANIM_Fuzzy_Forest_Run, \
    .anim_C = ANIM_Fuzzy_Forest_Run, \
    .anim_D = ANIM_Fuzzy_Forest_Run, \
    .anim_E = ANIM_Fuzzy_Forest_Run, \
    .anim_F = ANIM_Fuzzy_Forest_Run, \
}
