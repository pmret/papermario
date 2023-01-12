#include "common.h"
#include "sprite/npc/KoopaTroopa.h"

#define DARK_TROOPA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 20, \
    .itemDrops = { \
        { ITEM_POW_BLOCK, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 2, \
}

#define DARK_TROOPA_ANIMS \
{ \
    .idle   = ANIM_KoopaTroopa_Dark_Scramble, \
    .walk   = ANIM_KoopaTroopa_Dark_Scramble, \
    .run    = ANIM_KoopaTroopa_Dark_Scramble, \
    .chase  = ANIM_KoopaTroopa_Dark_Scramble, \
    .anim_4 = ANIM_KoopaTroopa_Dark_Scramble, \
    .anim_5 = ANIM_KoopaTroopa_Dark_Scramble, \
    .death  = ANIM_KoopaTroopa_Dark_Hurt, \
    .hit    = ANIM_KoopaTroopa_Dark_Hurt, \
    .anim_8 = ANIM_KoopaTroopa_Dark_ShellEnter, \
    .anim_9 = ANIM_KoopaTroopa_Dark_ShellSpin, \
    .anim_A = ANIM_KoopaTroopa_Dark_ShellExit, \
    .anim_B = ANIM_KoopaTroopa_Dark_Still, \
    .anim_C = ANIM_KoopaTroopa_Dark_Run, \
    .anim_D = ANIM_KoopaTroopa_Dark_Run, \
    .anim_E = ANIM_KoopaTroopa_Dark_Run, \
    .anim_F = ANIM_KoopaTroopa_Dark_Run, \
}
