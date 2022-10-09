#include "common.h"
#include "sprite/npc/ParaTroopa.h"

#define PARATROOPA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
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
    .idle   = ANIM_ParaTroopa_Anim01, \
    .walk   = ANIM_ParaTroopa_Anim02, \
    .run    = ANIM_ParaTroopa_Anim03, \
    .chase  = ANIM_ParaTroopa_Anim03, \
    .anim_4 = ANIM_ParaTroopa_Anim01, \
    .anim_5 = ANIM_ParaTroopa_Anim01, \
    .death  = ANIM_ParaTroopa_Anim06, \
    .hit    = ANIM_ParaTroopa_Anim06, \
    .anim_8 = ANIM_ParaTroopa_Anim04, \
    .anim_9 = ANIM_ParaTroopa_Anim0C, \
    .anim_A = ANIM_ParaTroopa_Anim0A, \
    .anim_B = ANIM_ParaTroopa_Anim0E, \
    .anim_C = ANIM_ParaTroopa_Anim03, \
    .anim_D = ANIM_ParaTroopa_Anim03, \
    .anim_E = ANIM_ParaTroopa_Anim03, \
    .anim_F = ANIM_ParaTroopa_Anim03, \
}
