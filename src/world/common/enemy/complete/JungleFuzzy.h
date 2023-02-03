#include "common.h"
#include "sprite/npc/Fuzzy.h"

#define JUNGLE_FUZZY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 10, \
    .itemDrops = { \
        { ITEM_DIZZY_DIAL, 5, 0 }, \
        { ITEM_VOLT_SHROOM, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define JUNGLE_FUZZY_ANIMS \
{ \
    .idle   = ANIM_Fuzzy_Jungle_Walk, \
    .walk   = ANIM_Fuzzy_Jungle_Walk, \
    .run    = ANIM_Fuzzy_Jungle_Run, \
    .chase  = ANIM_Fuzzy_Jungle_Run, \
    .anim_4 = ANIM_Fuzzy_Jungle_Idle, \
    .anim_5 = ANIM_Fuzzy_Jungle_Idle, \
    .death  = ANIM_Fuzzy_Jungle_Hurt, \
    .hit    = ANIM_Fuzzy_Jungle_Hurt, \
    .anim_8 = ANIM_Fuzzy_Jungle_Run, \
    .anim_9 = ANIM_Fuzzy_Jungle_Run, \
    .anim_A = ANIM_Fuzzy_Jungle_Run, \
    .anim_B = ANIM_Fuzzy_Jungle_Run, \
    .anim_C = ANIM_Fuzzy_Jungle_Run, \
    .anim_D = ANIM_Fuzzy_Jungle_Run, \
    .anim_E = ANIM_Fuzzy_Jungle_Run, \
    .anim_F = ANIM_Fuzzy_Jungle_Run, \
}
