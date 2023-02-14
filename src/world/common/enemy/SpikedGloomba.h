#include "common.h"
#include "sprite/npc/SpikedGoomba.h"

#define SPIKED_GLOOMBA_DROPS \
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

#define SPIKED_GLOOMBA_ANIMS \
{ \
    .idle   = ANIM_SpikedGoomba_Dark_Idle, \
    .walk   = ANIM_SpikedGoomba_Dark_Run, \
    .run    = ANIM_SpikedGoomba_Dark_Run, \
    .chase  = ANIM_SpikedGoomba_Dark_Run, \
    .anim_4 = ANIM_SpikedGoomba_Dark_Run, \
    .anim_5 = ANIM_SpikedGoomba_Dark_Idle, \
    .death  = ANIM_SpikedGoomba_Dark_HurtStill, \
    .hit    = ANIM_SpikedGoomba_Dark_HurtStill, \
    .anim_8 = ANIM_SpikedGoomba_Dark_Still, \
    .anim_9 = ANIM_SpikedGoomba_Dark_Still, \
    .anim_A = ANIM_SpikedGoomba_Dark_Still, \
    .anim_B = ANIM_SpikedGoomba_Dark_Still, \
    .anim_C = ANIM_SpikedGoomba_Dark_Still, \
    .anim_D = ANIM_SpikedGoomba_Dark_Still, \
    .anim_E = ANIM_SpikedGoomba_Dark_Still, \
    .anim_F = ANIM_SpikedGoomba_Dark_Still, \
}
