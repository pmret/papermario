#include "common.h"
#include "sprite/npc/PyroGuy.h"

#define PYRO_GUY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_FIRE_FLOWER, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define PYRO_GUY_ANIMS \
{ \
    .idle   = ANIM_PyroGuy_Idle, \
    .walk   = ANIM_PyroGuy_Walk, \
    .run    = ANIM_PyroGuy_Run, \
    .chase  = ANIM_PyroGuy_Walk, \
    .anim_4 = ANIM_PyroGuy_Idle, \
    .anim_5 = ANIM_PyroGuy_Idle, \
    .death  = ANIM_PyroGuy_Hurt, \
    .hit    = ANIM_PyroGuy_Hurt, \
    .anim_8 = ANIM_PyroGuy_Idle, \
    .anim_9 = ANIM_PyroGuy_Idle, \
    .anim_A = ANIM_PyroGuy_Idle, \
    .anim_B = ANIM_PyroGuy_Idle, \
    .anim_C = ANIM_PyroGuy_Idle, \
    .anim_D = ANIM_PyroGuy_Idle, \
    .anim_E = ANIM_PyroGuy_Idle, \
    .anim_F = ANIM_PyroGuy_Idle, \
}
