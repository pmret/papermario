#include "common.h"
#include "sprite/npc/Goomba.h"

#define GLOOMBA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 20, \
    .itemDrops = { \
        { ITEM_DIZZY_DIAL, 5, 0 }, \
        { ITEM_SLEEPY_SHEEP, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 2, \
}

#define GLOOMBA_ANIMS \
{ \
    .idle   = ANIM_Goomba_Dark_Idle, \
    .walk   = ANIM_Goomba_Dark_Run, \
    .run    = ANIM_Goomba_Dark_Run, \
    .chase  = ANIM_Goomba_Dark_Run, \
    .anim_4 = ANIM_Goomba_Dark_Run, \
    .anim_5 = ANIM_Goomba_Dark_Idle, \
    .death  = ANIM_Goomba_Dark_Hurt, \
    .hit    = ANIM_Goomba_Dark_Hurt, \
    .anim_8 = ANIM_Goomba_Dark_Still, \
    .anim_9 = ANIM_Goomba_Dark_Still, \
    .anim_A = ANIM_Goomba_Dark_Still, \
    .anim_B = ANIM_Goomba_Dark_Still, \
    .anim_C = ANIM_Goomba_Dark_Still, \
    .anim_D = ANIM_Goomba_Dark_Still, \
    .anim_E = ANIM_Goomba_Dark_Still, \
    .anim_F = ANIM_Goomba_Dark_Still, \
}
