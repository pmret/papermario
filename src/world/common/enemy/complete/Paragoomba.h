#include "common.h"
#include "sprite/npc/Paragoomba.h"

#define PARAGOOMBA_DROPS \
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

#define PARAGOOMBA_ANIMS \
{ \
    .idle   = ANIM_Paragoomba_Idle, \
    .walk   = ANIM_Paragoomba_Walk, \
    .run    = ANIM_Paragoomba_Run, \
    .chase  = ANIM_Paragoomba_Run, \
    .anim_4 = ANIM_Paragoomba_Idle, \
    .anim_5 = ANIM_Paragoomba_Idle, \
    .death  = ANIM_Paragoomba_Hurt, \
    .hit    = ANIM_Paragoomba_Hurt, \
    .anim_8 = ANIM_Paragoomba_Run, \
    .anim_9 = ANIM_Paragoomba_Run, \
    .anim_A = ANIM_Paragoomba_Run, \
    .anim_B = ANIM_Paragoomba_Run, \
    .anim_C = ANIM_Paragoomba_Run, \
    .anim_D = ANIM_Paragoomba_Run, \
    .anim_E = ANIM_Paragoomba_Run, \
    .anim_F = ANIM_Paragoomba_Run, \
}
