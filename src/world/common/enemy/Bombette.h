#include "common.h"
#include "sprite/npc/WorldBombette.h"

#define BOMBETTE_ANIMS \
{ \
    .idle   = ANIM_WorldBombette_Idle, \
    .walk   = ANIM_WorldBombette_Walk, \
    .run    = ANIM_WorldBombette_Walk, \
    .chase  = ANIM_WorldBombette_Walk, \
    .anim_4 = ANIM_WorldBombette_Walk, \
    .anim_5 = ANIM_WorldBombette_Walk, \
    .death  = ANIM_WorldBombette_Still, \
    .hit    = ANIM_WorldBombette_Still, \
    .anim_8 = ANIM_WorldBombette_Still, \
    .anim_9 = ANIM_WorldBombette_Still, \
    .anim_A = ANIM_WorldBombette_Still, \
    .anim_B = ANIM_WorldBombette_Still, \
    .anim_C = ANIM_WorldBombette_Still, \
    .anim_D = ANIM_WorldBombette_Still, \
    .anim_E = ANIM_WorldBombette_Still, \
    .anim_F = ANIM_WorldBombette_Still, \
}
