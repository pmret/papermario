#include "common.h"
#include "sprite/npc/Paragoomba.h"

#define PARAGLOOMBA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 20, \
    .itemDrops = { \
        { ITEM_DIZZY_DIAL, 5, 0 }, \
        { ITEM_SLEEPY_SHEEP, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define PARAGLOOMBA_ANIMS \
{ \
    .idle   = ANIM_Paragoomba_Dark_Idle, \
    .walk   = ANIM_Paragoomba_Dark_Walk, \
    .run    = ANIM_Paragoomba_Dark_Run, \
    .chase  = ANIM_Paragoomba_Dark_Run, \
    .anim_4 = ANIM_Paragoomba_Dark_Idle, \
    .anim_5 = ANIM_Paragoomba_Dark_Idle, \
    .death  = ANIM_Paragoomba_Dark_Hurt, \
    .hit    = ANIM_Paragoomba_Dark_Hurt, \
    .anim_8 = ANIM_Paragoomba_Dark_Dive, \
    .anim_9 = ANIM_Paragoomba_Dark_Run, \
    .anim_A = ANIM_Paragoomba_Dark_Still, \
    .anim_B = ANIM_Paragoomba_Dark_Still, \
    .anim_C = ANIM_Paragoomba_Dark_Still, \
    .anim_D = ANIM_Paragoomba_Dark_Still, \
    .anim_E = ANIM_Paragoomba_Dark_Still, \
    .anim_F = ANIM_Paragoomba_Dark_Still, \
}
