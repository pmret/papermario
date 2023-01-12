#include "common.h"
#include "sprite/npc/BuzzyBeetle.h"
#include "sprite/npc/SpikeTop.h"
#include "sprite/npc/BonyBeetle.h"

#define TIK_BUZZY_BEETLE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SODA, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(4), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 2, \
    .maxCoinBonus = 3, \
}

#define ISK_BUZZY_BEETLE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = GENEROUS_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 2, \
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
    .dropFlags = NPC_DROP_FLAG_80, \
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

#define BONY_BEETLE_DROPS_ALT \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(5), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define BONY_BEETLE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(4), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 4, \
}

#define BONY_BEETLE_ANIMS \
{ \
    .idle   = ANIM_BonyBeetle_Anim04, \
    .walk   = ANIM_BonyBeetle_Anim0C, \
    .run    = ANIM_BonyBeetle_Anim0E, \
    .chase  = ANIM_BonyBeetle_Anim0E, \
    .anim_4 = ANIM_BonyBeetle_Anim04, \
    .anim_5 = ANIM_BonyBeetle_Anim04, \
    .death  = ANIM_BonyBeetle_Anim18, \
    .hit    = ANIM_BonyBeetle_Anim18, \
    .anim_8 = ANIM_BonyBeetle_Anim10, \
    .anim_9 = ANIM_BonyBeetle_Anim16, \
    .anim_A = ANIM_BonyBeetle_Anim12, \
    .anim_B = ANIM_BonyBeetle_Anim04, \
    .anim_C = ANIM_BonyBeetle_Anim04, \
    .anim_D = ANIM_BonyBeetle_Anim04, \
    .anim_E = ANIM_BonyBeetle_Anim04, \
    .anim_F = ANIM_BonyBeetle_Anim04, \
}
