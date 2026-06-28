#include "common.h"
#include "sprite/npc/LavaBubble.h"

#define EMBER_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SHOOTING_STAR, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 4, \
}

#define EMBER_ANIMS \
{ \
    .idle   = ANIM_LavaBubble_Blue_Idle, \
    .walk   = ANIM_LavaBubble_Blue_FlySlow, \
    .run    = ANIM_LavaBubble_Blue_FlyFast, \
    .chase  = ANIM_LavaBubble_Blue_FlyFast, \
    .anim_4 = ANIM_LavaBubble_Blue_Idle, \
    .anim_5 = ANIM_LavaBubble_Blue_Idle, \
    .death  = ANIM_LavaBubble_Blue_Hurt, \
    .hit    = ANIM_LavaBubble_Blue_Hurt, \
    .anim_8 = ANIM_LavaBubble_Blue_Confused, \
    .anim_9 = ANIM_LavaBubble_Blue_Idle, \
    .anim_A = ANIM_LavaBubble_Blue_Idle, \
    .anim_B = ANIM_LavaBubble_Blue_Idle, \
    .anim_C = ANIM_LavaBubble_Blue_Idle, \
    .anim_D = ANIM_LavaBubble_Blue_Idle, \
    .anim_E = ANIM_LavaBubble_Blue_Idle, \
    .anim_F = ANIM_LavaBubble_Blue_Idle, \
}
