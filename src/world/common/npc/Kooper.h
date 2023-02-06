#include "common.h"
#include "sprite/npc/WorldKooper.h"

#define KOOPER_ANIMS \
{ \
    .idle   = ANIM_WorldKooper_Idle, \
    .walk   = ANIM_WorldKooper_Walk, \
    .run    = ANIM_WorldKooper_Walk, \
    .chase  = ANIM_WorldKooper_Walk, \
    .anim_4 = ANIM_WorldKooper_Walk, \
    .anim_5 = ANIM_WorldKooper_Walk, \
    .death  = ANIM_WorldKooper_Still, \
    .hit    = ANIM_WorldKooper_Still, \
    .anim_8 = ANIM_WorldKooper_Still, \
    .anim_9 = ANIM_WorldKooper_Still, \
    .anim_A = ANIM_WorldKooper_Still, \
    .anim_B = ANIM_WorldKooper_Still, \
    .anim_C = ANIM_WorldKooper_Still, \
    .anim_D = ANIM_WorldKooper_Still, \
    .anim_E = ANIM_WorldKooper_Still, \
    .anim_F = ANIM_WorldKooper_Still, \
}
