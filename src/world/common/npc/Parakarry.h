#include "common.h"
#include "sprite/npc/WorldParakarry.h"

#define PARAKARRY_ANIMS \
{ \
    .idle   = ANIM_WorldParakarry_Idle, \
    .walk   = ANIM_WorldParakarry_Walk, \
    .run    = ANIM_WorldParakarry_Run, \
    .chase  = ANIM_WorldParakarry_Run, \
    .anim_4 = ANIM_WorldParakarry_Idle, \
    .anim_5 = ANIM_WorldParakarry_Idle, \
    .death  = ANIM_WorldParakarry_Still, \
    .hit    = ANIM_WorldParakarry_Still, \
    .anim_8 = ANIM_WorldParakarry_Idle, \
    .anim_9 = ANIM_WorldParakarry_Idle, \
    .anim_A = ANIM_WorldParakarry_Idle, \
    .anim_B = ANIM_WorldParakarry_Idle, \
    .anim_C = ANIM_WorldParakarry_Idle, \
    .anim_D = ANIM_WorldParakarry_Idle, \
    .anim_E = ANIM_WorldParakarry_Idle, \
    .anim_F = ANIM_WorldParakarry_Idle, \
}
