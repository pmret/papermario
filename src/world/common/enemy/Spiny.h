#include "common.h"
#include "sprite/npc/Spiny.h"

#define SPINY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 1, \
}

#define SPINY_ANIMS \
{ \
    .idle   = ANIM_Spiny_Anim01, \
    .walk   = ANIM_Spiny_Anim03, \
    .run    = ANIM_Spiny_Anim04, \
    .chase  = ANIM_Spiny_Anim04, \
    .anim_4 = ANIM_Spiny_Anim01, \
    .anim_5 = ANIM_Spiny_Anim01, \
    .death  = ANIM_Spiny_Anim09, \
    .hit    = ANIM_Spiny_Anim09, \
    .anim_8 = ANIM_Spiny_Anim06, \
    .anim_9 = ANIM_Spiny_Anim08, \
    .anim_A = ANIM_Spiny_Anim07, \
    .anim_B = ANIM_Spiny_Anim01, \
    .anim_C = ANIM_Spiny_Anim01, \
    .anim_D = ANIM_Spiny_Anim01, \
    .anim_E = ANIM_Spiny_Anim01, \
    .anim_F = ANIM_Spiny_Anim01, \
}
