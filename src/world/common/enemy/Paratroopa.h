#include "common.h"
#include "sprite/npc/ParaTroopa.h"

#define PARATROOPA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_POW_BLOCK, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 1, \
}

#define PARATROOPA_ANIMS \
{ \
    .idle   = ANIM_ParaTroopa_Idle, \
    .walk   = ANIM_ParaTroopa_Walk, \
    .run    = ANIM_ParaTroopa_Run, \
    .chase  = ANIM_ParaTroopa_Run, \
    .anim_4 = ANIM_ParaTroopa_Idle, \
    .anim_5 = ANIM_ParaTroopa_Idle, \
    .death  = ANIM_ParaTroopa_HurtStill, \
    .hit    = ANIM_ParaTroopa_HurtStill, \
    .anim_8 = ANIM_ParaTroopa_Windup, \
    .anim_9 = ANIM_ParaTroopa_ShellDive, \
    .anim_A = ANIM_ParaTroopa_ShellIdle, \
    .anim_B = ANIM_ParaTroopa_ShellExit, \
    .anim_C = ANIM_ParaTroopa_Run, \
    .anim_D = ANIM_ParaTroopa_Run, \
    .anim_E = ANIM_ParaTroopa_Run, \
    .anim_F = ANIM_ParaTroopa_Run, \
}
