#include "common.h"
#include "sprite/npc/Boo.h"

#define NORMAL_BOO_ANIMS \
{ \
    .idle   = ANIM_Boo_Idle, \
    .walk   = ANIM_Boo_Walk, \
    .run    = ANIM_Boo_Run, \
    .chase  = ANIM_Boo_Run, \
    .anim_4 = ANIM_Boo_Idle, \
    .anim_5 = ANIM_Boo_Idle, \
    .death  = ANIM_Boo_Still, \
    .hit    = ANIM_Boo_Still, \
    .anim_8 = ANIM_Boo_Run, \
    .anim_9 = ANIM_Boo_Run, \
    .anim_A = ANIM_Boo_Run, \
    .anim_B = ANIM_Boo_Run, \
    .anim_C = ANIM_Boo_Run, \
    .anim_D = ANIM_Boo_Run, \
    .anim_E = ANIM_Boo_Run, \
    .anim_F = ANIM_Boo_Run, \
}

#define GUSTY_BOO_ANIMS \
{ \
    .idle   = ANIM_Boo_Tan_Idle, \
    .walk   = ANIM_Boo_Tan_Walk, \
    .run    = ANIM_Boo_Tan_Run, \
    .chase  = ANIM_Boo_Tan_Run, \
    .anim_4 = ANIM_Boo_Tan_Idle, \
    .anim_5 = ANIM_Boo_Tan_Idle, \
    .death  = ANIM_Boo_Tan_Still, \
    .hit    = ANIM_Boo_Tan_Still, \
    .anim_8 = ANIM_Boo_Tan_Confused, \
    .anim_9 = ANIM_Boo_Tan_Run, \
    .anim_A = ANIM_Boo_Tan_Run, \
    .anim_B = ANIM_Boo_Tan_Run, \
    .anim_C = ANIM_Boo_Tan_Run, \
    .anim_D = ANIM_Boo_Tan_Run, \
    .anim_E = ANIM_Boo_Tan_Run, \
    .anim_F = ANIM_Boo_Tan_Run, \
}
