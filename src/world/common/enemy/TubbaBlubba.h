#include "common.h"
#include "sprite/npc/WorldTubba.h"

#define TUBBA_ANIMS \
{ \
    .idle   = ANIM_WorldTubba_Idle, \
    .walk   = ANIM_WorldTubba_Walk, \
    .run    = ANIM_WorldTubba_Run, \
    .chase  = ANIM_WorldTubba_Run, \
    .anim_4 = ANIM_WorldTubba_Still, \
    .anim_5 = ANIM_WorldTubba_Still, \
    .death  = ANIM_WorldTubba_Still, \
    .hit    = ANIM_WorldTubba_Still, \
    .anim_8 = ANIM_WorldTubba_Still, \
    .anim_9 = ANIM_WorldTubba_Still, \
    .anim_A = ANIM_WorldTubba_Still, \
    .anim_B = ANIM_WorldTubba_Still, \
    .anim_C = ANIM_WorldTubba_Still, \
    .anim_D = ANIM_WorldTubba_Still, \
    .anim_E = ANIM_WorldTubba_Still, \
    .anim_F = ANIM_WorldTubba_Still, \
}

#define TUBBA_ANGRY_ANIMS \
{ \
    .idle   = ANIM_WorldTubba_IdleAngry, \
    .walk   = ANIM_WorldTubba_WalkAngry, \
    .run    = ANIM_WorldTubba_RunAngry, \
    .chase  = ANIM_WorldTubba_RunAngry, \
    .anim_4 = ANIM_WorldTubba_LeanAngry, \
    .anim_5 = ANIM_WorldTubba_IdleAngry, \
    .death  = ANIM_WorldTubba_IdleAngry, \
    .hit    = ANIM_WorldTubba_IdleAngry, \
    .anim_8 = ANIM_WorldTubba_IdleAngry, \
    .anim_9 = ANIM_WorldTubba_IdleAngry, \
    .anim_A = ANIM_WorldTubba_IdleAngry, \
    .anim_B = ANIM_WorldTubba_IdleAngry, \
    .anim_C = ANIM_WorldTubba_IdleAngry, \
    .anim_D = ANIM_WorldTubba_IdleAngry, \
    .anim_E = ANIM_WorldTubba_IdleAngry, \
    .anim_F = ANIM_WorldTubba_IdleAngry, \
}
