#include "common.h"
#include "sprite/npc/Fuzzy.h"

#define FUZZY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = REDUCED_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 1, \
}

#define FUZZY_ANIMS \
{ \
    .idle   = ANIM_Fuzzy_Walk, \
    .walk   = ANIM_Fuzzy_Walk, \
    .run    = ANIM_Fuzzy_Run, \
    .chase  = ANIM_Fuzzy_Run, \
    .anim_4 = ANIM_Fuzzy_Idle, \
    .anim_5 = ANIM_Fuzzy_Idle, \
    .death  = ANIM_Fuzzy_Hurt, \
    .hit    = ANIM_Fuzzy_Hurt, \
    .anim_8 = ANIM_Fuzzy_Run, \
    .anim_9 = ANIM_Fuzzy_Run, \
    .anim_A = ANIM_Fuzzy_Run, \
    .anim_B = ANIM_Fuzzy_Run, \
    .anim_C = ANIM_Fuzzy_Run, \
    .anim_D = ANIM_Fuzzy_Run, \
    .anim_E = ANIM_Fuzzy_Run, \
    .anim_F = ANIM_Fuzzy_Run, \
}
