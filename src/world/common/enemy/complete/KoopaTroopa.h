#include "common.h"
#include "sprite/npc/KoopaTroopa.h"

#define KOOPA_TROOPA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
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
    .idle   = ANIM_KoopaTroopa_Anim01, \
    .walk   = ANIM_KoopaTroopa_Anim03, \
    .run    = ANIM_KoopaTroopa_Anim04, \
    .chase  = ANIM_KoopaTroopa_Anim04, \
    .anim_4 = ANIM_KoopaTroopa_Anim01, \
    .anim_5 = ANIM_KoopaTroopa_Anim01, \
    .death  = ANIM_KoopaTroopa_Anim0B, \
    .hit    = ANIM_KoopaTroopa_Anim0B, \
    .anim_8 = ANIM_KoopaTroopa_Anim07, \
    .anim_9 = ANIM_KoopaTroopa_Anim06, \
    .anim_A = ANIM_KoopaTroopa_Anim08, \
    .anim_B = ANIM_KoopaTroopa_Anim04, \
    .anim_C = ANIM_KoopaTroopa_Anim04, \
    .anim_D = ANIM_KoopaTroopa_Anim04, \
    .anim_E = ANIM_KoopaTroopa_Anim04, \
    .anim_F = ANIM_KoopaTroopa_Anim04, \
}
