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
    .idle   = ANIM_Lakitu_Idle, \
    .walk   = ANIM_Lakitu_FlySlow, \
    .run    = ANIM_Lakitu_FlyFast, \
    .chase  = ANIM_Lakitu_FlyFast, \
    .anim_4 = ANIM_Lakitu_Idle, \
    .anim_5 = ANIM_Lakitu_Idle, \
    .death  = ANIM_Lakitu_Horror, \
    .hit    = ANIM_Lakitu_Horror, \
    .anim_8 = ANIM_Lakitu_FlyFast, \
    .anim_9 = ANIM_Lakitu_Idle, \
    .anim_A = ANIM_Lakitu_Idle, \
    .anim_B = ANIM_Lakitu_Idle, \
    .anim_C = ANIM_Lakitu_Idle, \
    .anim_D = ANIM_Lakitu_Idle, \
    .anim_E = ANIM_Lakitu_Idle, \
    .anim_F = ANIM_Lakitu_Idle, \
}
