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
    .idle   = ANIM_SkyGuy_WorldIdle, \
    .walk   = ANIM_SkyGuy_WorldIdle, \
    .run    = ANIM_SkyGuy_WorldRun, \
    .chase  = ANIM_SkyGuy_WorldRun, \
    .anim_4 = ANIM_SkyGuy_WorldAlert, \
    .anim_5 = ANIM_SkyGuy_WorldAlert, \
    .death  = ANIM_SkyGuy_WorldHurt, \
    .hit    = ANIM_SkyGuy_WorldHurt, \
    .anim_8 = ANIM_SkyGuy_WorldRun, \
    .anim_9 = ANIM_SkyGuy_WorldRun, \
    .anim_A = ANIM_SkyGuy_Idle, \
    .anim_B = ANIM_SkyGuy_Idle, \
    .anim_C = ANIM_SkyGuy_Idle, \
    .anim_D = ANIM_SkyGuy_Idle, \
    .anim_E = ANIM_SkyGuy_Idle, \
    .anim_F = ANIM_SkyGuy_Idle, \
}
