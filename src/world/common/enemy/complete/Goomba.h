#include "common.h"
#include "sprite/npc/Goomba.h"

#define GOOMBA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_MUSHROOM, 10, 0 }, \
    }, \
    .heartDrops  = GENEROUS_WHEN_LOW_HEART_DROPS(2), \
    .flowerDrops = GENEROUS_WHEN_LOW_FLOWER_DROPS(2), \
}

#define GOOMBA_ANIMS \
{ \
    .idle   = ANIM_Goomba_Idle, \
    .walk   = ANIM_Goomba_Walk, \
    .run    = ANIM_Goomba_Run, \
    .chase  = ANIM_Goomba_Run, \
    .anim_4 = ANIM_Goomba_Idle, \
    .anim_5 = ANIM_Goomba_Idle, \
    .death  = ANIM_Goomba_Hurt, \
    .hit    = ANIM_Goomba_Hurt, \
    .anim_8 = ANIM_Goomba_Run, \
    .anim_9 = ANIM_Goomba_Run, \
    .anim_A = ANIM_Goomba_Run, \
    .anim_B = ANIM_Goomba_Run, \
    .anim_C = ANIM_Goomba_Run, \
    .anim_D = ANIM_Goomba_Run, \
    .anim_E = ANIM_Goomba_Run, \
    .anim_F = ANIM_Goomba_Run, \
}
