#include "common.h"
#include "sprite/npc/Goomba.h"

#define HYPER_GOOMBA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 20, \
    .itemDrops = { \
        { ITEM_DRIED_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define HYPER_GOOMBA_ANIMS \
{ \
    .idle   = ANIM_Goomba_Hyper_Idle, \
    .walk   = ANIM_Goomba_Hyper_Walk, \
    .run    = ANIM_Goomba_Hyper_Run, \
    .chase  = ANIM_Goomba_Hyper_Run, \
    .anim_4 = ANIM_Goomba_Hyper_Idle, \
    .anim_5 = ANIM_Goomba_Hyper_Idle, \
    .death  = ANIM_Goomba_Hyper_Hurt, \
    .hit    = ANIM_Goomba_Hyper_Hurt, \
    .anim_8 = ANIM_Goomba_Hyper_Run, \
    .anim_9 = ANIM_Goomba_Hyper_Run, \
    .anim_A = ANIM_Goomba_Hyper_Run, \
    .anim_B = ANIM_Goomba_Hyper_Run, \
    .anim_C = ANIM_Goomba_Hyper_Run, \
    .anim_D = ANIM_Goomba_Hyper_Run, \
    .anim_E = ANIM_Goomba_Hyper_Run, \
    .anim_F = ANIM_Goomba_Hyper_Run, \
}
