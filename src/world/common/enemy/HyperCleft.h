#include "common.h"
#include "sprite/npc/Cleft.h"

#define HYPER_CLEFT_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 3, \
}

#define HYPER_CLEFT_ANIMS \
{ \
    .idle   = ANIM_Cleft_Hyper_Idle, \
    .walk   = ANIM_Cleft_Hyper_Walk, \
    .run    = ANIM_Cleft_Hyper_Run, \
    .chase  = ANIM_Cleft_Hyper_Run, \
    .anim_4 = ANIM_Cleft_Hyper_Idle, \
    .anim_5 = ANIM_Cleft_Hyper_Idle, \
    .death  = ANIM_Cleft_Hyper_Hurt, \
    .hit    = ANIM_Cleft_Hyper_Hurt, \
    .anim_8 = ANIM_Cleft_Hyper_Hiding, \
    .anim_9 = ANIM_Cleft_Hyper_CamoOff, \
    .anim_A = ANIM_Cleft_Hyper_Reveal, \
    .anim_B = ANIM_Cleft_Hyper_Disguise, \
    .anim_C = ANIM_Cleft_Hyper_Crouch, \
    .anim_D = ANIM_Cleft_Hyper_Charge, \
    .anim_E = ANIM_Cleft_Hyper_CamoOn, \
    .anim_F = ANIM_Cleft_Hyper_Still, \
}
