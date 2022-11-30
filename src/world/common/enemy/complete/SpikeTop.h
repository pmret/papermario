#include "common.h"
#include "sprite/npc/BuzzyBeetle.h"
#include "sprite/npc/SpikeTop.h"

#define BUZZY_BEETLE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SODA, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(4), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 2, \
    .maxCoinBonus = 3, \
}

#define BUZZY_BEETLE_ANIMS \
{ \
    .idle   = ANIM_BuzzyBeetle_Anim01, \
    .walk   = ANIM_BuzzyBeetle_Anim03, \
    .run    = ANIM_BuzzyBeetle_Anim04, \
    .chase  = ANIM_BuzzyBeetle_Anim04, \
    .anim_4 = ANIM_BuzzyBeetle_Anim00, \
    .anim_5 = ANIM_BuzzyBeetle_Anim00, \
    .death  = ANIM_BuzzyBeetle_Anim07, \
    .hit    = ANIM_BuzzyBeetle_Anim07, \
    .anim_8 = ANIM_BuzzyBeetle_Anim0C, \
    .anim_9 = ANIM_BuzzyBeetle_Anim05, \
    .anim_A = ANIM_BuzzyBeetle_Anim0D, \
    .anim_B = ANIM_BuzzyBeetle_Anim00, \
    .anim_C = ANIM_BuzzyBeetle_Anim00, \
    .anim_D = ANIM_BuzzyBeetle_Anim00, \
    .anim_E = ANIM_BuzzyBeetle_Anim00, \
    .anim_F = ANIM_BuzzyBeetle_Anim00, \
}


#define SPIKE_TOP_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SODA, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(4), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 2, \
    .maxCoinBonus = 3, \
}

#define SPIKE_TOP_ANIMS \
{ \
    .idle   = ANIM_SpikeTop_Anim03, \
    .walk   = ANIM_SpikeTop_Anim06, \
    .run    = ANIM_SpikeTop_Anim08, \
    .chase  = ANIM_SpikeTop_Anim08, \
    .anim_4 = ANIM_SpikeTop_Anim03, \
    .anim_5 = ANIM_SpikeTop_Anim03, \
    .death  = ANIM_SpikeTop_Anim13, \
    .hit    = ANIM_SpikeTop_Anim13, \
    .anim_8 = ANIM_SpikeTop_Anim0B, \
    .anim_9 = ANIM_SpikeTop_Anim0A, \
    .anim_A = ANIM_SpikeTop_Anim0C, \
    .anim_B = ANIM_SpikeTop_Anim03, \
    .anim_C = ANIM_SpikeTop_Anim03, \
    .anim_D = ANIM_SpikeTop_Anim03, \
    .anim_E = ANIM_SpikeTop_Anim03, \
    .anim_F = ANIM_SpikeTop_Anim03, \
}
