#include "common.h"
#include "sprite/npc/SpikedGoomba.h"

#define SPIKED_GOOMBA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_MUSHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 1, \
}

#define SPIKED_GOOMBA_ANIMS \
{ \
    .idle   = ANIM_SpikedGoomba_Idle, \
    .walk   = ANIM_SpikedGoomba_Walk, \
    .run    = ANIM_SpikedGoomba_Run, \
    .chase  = ANIM_SpikedGoomba_Run, \
    .anim_4 = ANIM_SpikedGoomba_Idle, \
    .anim_5 = ANIM_SpikedGoomba_Idle, \
    .death  = ANIM_SpikedGoomba_HurtStill, \
    .hit    = ANIM_SpikedGoomba_HurtStill, \
    .anim_8 = ANIM_SpikedGoomba_Run, \
    .anim_9 = ANIM_SpikedGoomba_Run, \
    .anim_A = ANIM_SpikedGoomba_Run, \
    .anim_B = ANIM_SpikedGoomba_Run, \
    .anim_C = ANIM_SpikedGoomba_Run, \
    .anim_D = ANIM_SpikedGoomba_Run, \
    .anim_E = ANIM_SpikedGoomba_Run, \
    .anim_F = ANIM_SpikedGoomba_Run, \
}
