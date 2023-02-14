#include "common.h"
#include "sprite/npc/Lakitu.h"

#define LAKITU_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 25, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 2, 0 }, \
        { ITEM_MAPLE_SYRUP, 2, 0 }, \
        { ITEM_THUNDER_RAGE, 2, 0 }, \
        { ITEM_STOP_WATCH, 2, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(3), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define LAKITU_ANIMS \
{ \
    .idle   = ANIM_Lakitu_Anim01, \
    .walk   = ANIM_Lakitu_Anim02, \
    .run    = ANIM_Lakitu_Anim03, \
    .chase  = ANIM_Lakitu_Anim03, \
    .anim_4 = ANIM_Lakitu_Anim01, \
    .anim_5 = ANIM_Lakitu_Anim01, \
    .death  = ANIM_Lakitu_Anim04, \
    .hit    = ANIM_Lakitu_Anim04, \
    .anim_8 = ANIM_Lakitu_Anim03, \
    .anim_9 = ANIM_Lakitu_Anim01, \
    .anim_A = ANIM_Lakitu_Anim01, \
    .anim_B = ANIM_Lakitu_Anim01, \
    .anim_C = ANIM_Lakitu_Anim01, \
    .anim_D = ANIM_Lakitu_Anim01, \
    .anim_E = ANIM_Lakitu_Anim01, \
    .anim_F = ANIM_Lakitu_Anim01, \
}
