#include "common.h"
#include "sprite/npc/WorldBobomb.h"

#define BOBOMB_GREEN_ANIMS \
{ \
    .idle   = ANIM_WorldBobomb_Green_Idle, \
    .walk   = ANIM_WorldBobomb_Green_Walk, \
    .run    = ANIM_WorldBobomb_Green_Run, \
    .chase  = ANIM_WorldBobomb_Green_Run, \
    .anim_4 = ANIM_WorldBobomb_Green_Idle, \
    .anim_5 = ANIM_WorldBobomb_Green_Idle, \
    .death  = ANIM_WorldBobomb_Green_Still, \
    .hit    = ANIM_WorldBobomb_Green_Still, \
    .anim_8 = ANIM_WorldBobomb_Green_Still, \
    .anim_9 = ANIM_WorldBobomb_Green_Still, \
    .anim_A = ANIM_WorldBobomb_Green_Still, \
    .anim_B = ANIM_WorldBobomb_Green_Still, \
    .anim_C = ANIM_WorldBobomb_Green_Still, \
    .anim_D = ANIM_WorldBobomb_Green_Still, \
    .anim_E = ANIM_WorldBobomb_Green_Still, \
    .anim_F = ANIM_WorldBobomb_Green_Still, \
}

#define BOBOMB_RED_ANIMS \
{ \
    .idle   = ANIM_WorldBobomb_Red_Idle, \
    .walk   = ANIM_WorldBobomb_Red_Walk, \
    .run    = ANIM_WorldBobomb_Red_Run, \
    .chase  = ANIM_WorldBobomb_Red_Run, \
    .anim_4 = ANIM_WorldBobomb_Red_Idle, \
    .anim_5 = ANIM_WorldBobomb_Red_Idle, \
    .death  = ANIM_WorldBobomb_Red_Still, \
    .hit    = ANIM_WorldBobomb_Red_Still, \
    .anim_8 = ANIM_WorldBobomb_Red_Still, \
    .anim_9 = ANIM_WorldBobomb_Red_Still, \
    .anim_A = ANIM_WorldBobomb_Red_Still, \
    .anim_B = ANIM_WorldBobomb_Red_Still, \
    .anim_C = ANIM_WorldBobomb_Red_Still, \
    .anim_D = ANIM_WorldBobomb_Red_Still, \
    .anim_E = ANIM_WorldBobomb_Red_Still, \
    .anim_F = ANIM_WorldBobomb_Red_Still, \
}

#define BOBOMB_BLUE_ANIMS \
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
