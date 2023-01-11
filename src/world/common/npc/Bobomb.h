#include "common.h"
#include "sprite/npc/WorldBobomb.h"

#define BOBOMB_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define BOBOMB_ANIMS \
{ \
    .idle   = ANIM_WorldBobomb_Blue_Idle, \
    .walk   = ANIM_WorldBobomb_Blue_Walk, \
    .run    = ANIM_WorldBobomb_Blue_Run, \
    .chase  = ANIM_WorldBobomb_Blue_Run, \
    .anim_4 = ANIM_WorldBobomb_Blue_Idle, \
    .anim_5 = ANIM_WorldBobomb_Blue_Idle, \
    .death  = ANIM_WorldBobomb_Blue_Still, \
    .hit    = ANIM_WorldBobomb_Blue_Still, \
    .anim_8 = ANIM_WorldBobomb_Blue_Still, \
    .anim_9 = ANIM_WorldBobomb_Blue_Still, \
    .anim_A = ANIM_WorldBobomb_Blue_Still, \
    .anim_B = ANIM_WorldBobomb_Blue_Still, \
    .anim_C = ANIM_WorldBobomb_Blue_Still, \
    .anim_D = ANIM_WorldBobomb_Blue_Still, \
    .anim_E = ANIM_WorldBobomb_Blue_Still, \
    .anim_F = ANIM_WorldBobomb_Blue_Still, \
}
