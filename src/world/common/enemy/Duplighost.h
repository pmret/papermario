#include "common.h"
#include "sprite/npc/Duplighost.h"

#define DUPLIGHOST_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_MYSTERY, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(3), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define DUPLIGHOST_ANIMS \
{ \
    .idle   = ANIM_Duplighost_Idle, \
    .walk   = ANIM_Duplighost_Walk, \
    .run    = ANIM_Duplighost_Run, \
    .chase  = ANIM_Duplighost_Run, \
    .anim_4 = ANIM_Duplighost_Idle, \
    .anim_5 = ANIM_Duplighost_Idle, \
    .death  = ANIM_Duplighost_Hurt, \
    .hit    = ANIM_Duplighost_Hurt, \
    .anim_8 = ANIM_Duplighost_Idle, \
    .anim_9 = ANIM_Duplighost_Idle, \
    .anim_A = ANIM_Duplighost_Idle, \
    .anim_B = ANIM_Duplighost_Idle, \
    .anim_C = ANIM_Duplighost_Idle, \
    .anim_D = ANIM_Duplighost_Idle, \
    .anim_E = ANIM_Duplighost_Idle, \
    .anim_F = ANIM_Duplighost_Idle, \
}
