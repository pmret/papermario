#include "common.h"
#include "sprite/npc/LavaBubble.h"

#define LAVA_BUBBLE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define LAVA_BUBBLE_ANIMS \
{ \
    .idle   = ANIM_LavaBubble_Idle, \
    .walk   = ANIM_LavaBubble_FlySlow, \
    .run    = ANIM_LavaBubble_FlyFast, \
    .chase  = ANIM_LavaBubble_FlyFast, \
    .anim_4 = ANIM_LavaBubble_Idle, \
    .anim_5 = ANIM_LavaBubble_Idle, \
    .death  = ANIM_LavaBubble_Hurt, \
    .hit    = ANIM_LavaBubble_Hurt, \
    .anim_8 = ANIM_LavaBubble_Confused, \
    .anim_9 = ANIM_LavaBubble_Idle, \
    .anim_A = ANIM_LavaBubble_Idle, \
    .anim_B = ANIM_LavaBubble_Idle, \
    .anim_C = ANIM_LavaBubble_Idle, \
    .anim_D = ANIM_LavaBubble_Idle, \
    .anim_E = ANIM_LavaBubble_Idle, \
    .anim_F = ANIM_LavaBubble_Idle, \
}
