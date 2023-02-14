#include "common.h"
#include "sprite/npc/WorldBow.h"

#define BOW_ANIMS \
{ \
    .idle   = ANIM_WorldBow_Idle, \
    .walk   = ANIM_WorldBow_Walk, \
    .run    = ANIM_WorldBow_Run, \
    .chase  = ANIM_WorldBow_Run, \
    .anim_4 = ANIM_WorldBow_Idle, \
    .anim_5 = ANIM_WorldBow_Idle, \
    .death  = ANIM_WorldBow_Still, \
    .hit    = ANIM_WorldBow_Still, \
    .anim_8 = ANIM_WorldBow_Run, \
    .anim_9 = ANIM_WorldBow_Run, \
    .anim_A = ANIM_WorldBow_Run, \
    .anim_B = ANIM_WorldBow_Run, \
    .anim_C = ANIM_WorldBow_Run, \
    .anim_D = ANIM_WorldBow_Run, \
    .anim_E = ANIM_WorldBow_Run, \
    .anim_F = ANIM_WorldBow_Run, \
}
