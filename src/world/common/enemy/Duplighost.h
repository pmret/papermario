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
    .idle   = ANIM_Duplighost_Anim02, \
    .walk   = ANIM_Duplighost_Anim03, \
    .run    = ANIM_Duplighost_Anim04, \
    .chase  = ANIM_Duplighost_Anim04, \
    .anim_4 = ANIM_Duplighost_Anim02, \
    .anim_5 = ANIM_Duplighost_Anim02, \
    .death  = ANIM_Duplighost_Anim0A, \
    .hit    = ANIM_Duplighost_Anim0A, \
    .anim_8 = ANIM_Duplighost_Anim02, \
    .anim_9 = ANIM_Duplighost_Anim02, \
    .anim_A = ANIM_Duplighost_Anim02, \
    .anim_B = ANIM_Duplighost_Anim02, \
    .anim_C = ANIM_Duplighost_Anim02, \
    .anim_D = ANIM_Duplighost_Anim02, \
    .anim_E = ANIM_Duplighost_Anim02, \
    .anim_F = ANIM_Duplighost_Anim02, \
}
