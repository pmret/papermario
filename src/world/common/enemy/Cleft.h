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
    .idle   = ANIM_Cleft_Idle, \
    .walk   = ANIM_Cleft_Walk, \
    .run    = ANIM_Cleft_Run, \
    .chase  = ANIM_Cleft_Run, \
    .anim_4 = ANIM_Cleft_Idle, \
    .anim_5 = ANIM_Cleft_Idle, \
    .death  = ANIM_Cleft_Hurt, \
    .hit    = ANIM_Cleft_Hurt, \
    .anim_8 = ANIM_Cleft_Hiding, \
    .anim_9 = ANIM_Cleft_CamoOff, \
    .anim_A = ANIM_Cleft_Reveal, \
    .anim_B = ANIM_Cleft_Disguise, \
    .anim_C = ANIM_Cleft_Crouch, \
    .anim_D = ANIM_Cleft_Charge, \
    .anim_E = ANIM_Cleft_CamoOn, \
    .anim_F = ANIM_Cleft_Still, \
}
