#include "common.h"
#include "sprite/npc/Cleft.h"

#define CLEFT_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 3, \
}

#define CLEFT_ANIMS \
{ \
    .idle   = ANIM_Cleft_Anim02, \
    .walk   = ANIM_Cleft_Anim06, \
    .run    = ANIM_Cleft_Anim07, \
    .chase  = ANIM_Cleft_Anim07, \
    .anim_4 = ANIM_Cleft_Anim02, \
    .anim_5 = ANIM_Cleft_Anim02, \
    .death  = ANIM_Cleft_Anim08, \
    .hit    = ANIM_Cleft_Anim08, \
    .anim_8 = ANIM_Cleft_Anim14, \
    .anim_9 = ANIM_Cleft_Anim17, \
    .anim_A = ANIM_Cleft_Anim13, \
    .anim_B = ANIM_Cleft_Anim15, \
    .anim_C = ANIM_Cleft_Anim10, \
    .anim_D = ANIM_Cleft_Anim11, \
    .anim_E = ANIM_Cleft_Anim16, \
    .anim_F = ANIM_Cleft_Anim00, \
}
