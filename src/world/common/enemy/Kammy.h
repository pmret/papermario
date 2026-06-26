#include "common.h"
#include "sprite/npc/WorldKammy.h"

#define KAMMY_ANIMS \
{ \
    .idle   = ANIM_WorldKammy_Idle, \
    .walk   = ANIM_WorldKammy_Walk, \
    .run    = ANIM_WorldKammy_Run, \
    .chase  = ANIM_WorldKammy_Run, \
    .anim_4 = ANIM_WorldKammy_Idle, \
    .anim_5 = ANIM_WorldKammy_Idle, \
    .death  = ANIM_WorldKammy_Still, \
    .hit    = ANIM_WorldKammy_Still, \
    .anim_8 = ANIM_WorldKammy_Run, \
    .anim_9 = ANIM_WorldKammy_Run, \
    .anim_A = ANIM_WorldKammy_Run, \
    .anim_B = ANIM_WorldKammy_Run, \
    .anim_C = ANIM_WorldKammy_Run, \
    .anim_D = ANIM_WorldKammy_Run, \
    .anim_E = ANIM_WorldKammy_Run, \
    .anim_F = ANIM_WorldKammy_Run, \
}
