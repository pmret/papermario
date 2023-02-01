#include "common.h"
#include "sprite/npc/KoopaTroopa.h"

#define KOOPA_TROOPA_NOK_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_MUSHROOM, 3, 0 }, \
        { ITEM_KOOPA_LEAF, 7, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 1, \
}

#define KOOPA_TROOPA_TRD_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_MUSHROOM, 5, 0 }, \
        { ITEM_POW_BLOCK, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 1, \
}

#define KOOPA_TROOPA_ANIMS \
{ \
    .idle   = ANIM_KoopaTroopa_Idle, \
    .walk   = ANIM_KoopaTroopa_Walk, \
    .run    = ANIM_KoopaTroopa_Run, \
    .chase  = ANIM_KoopaTroopa_Run, \
    .anim_4 = ANIM_KoopaTroopa_Idle, \
    .anim_5 = ANIM_KoopaTroopa_Idle, \
    .death  = ANIM_KoopaTroopa_Hurt, \
    .hit    = ANIM_KoopaTroopa_Hurt, \
    .anim_8 = ANIM_KoopaTroopa_ShellEnter, \
    .anim_9 = ANIM_KoopaTroopa_ShellSpin, \
    .anim_A = ANIM_KoopaTroopa_ShellExit, \
    .anim_B = ANIM_KoopaTroopa_Run, \
    .anim_C = ANIM_KoopaTroopa_Run, \
    .anim_D = ANIM_KoopaTroopa_Run, \
    .anim_E = ANIM_KoopaTroopa_Run, \
    .anim_F = ANIM_KoopaTroopa_Run, \
}
