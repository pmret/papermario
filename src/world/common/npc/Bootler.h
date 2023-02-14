#include "common.h"
#include "sprite/npc/Bootler.h"

#define BOOTLER_ANIMS \
{ \
    .idle   = ANIM_Bootler_Idle, \
    .walk   = ANIM_Bootler_Walk, \
    .run    = ANIM_Bootler_Run, \
    .chase  = ANIM_Bootler_Run, \
    .anim_4 = ANIM_Bootler_Idle, \
    .anim_5 = ANIM_Bootler_Idle, \
    .death  = ANIM_Bootler_Still, \
    .hit    = ANIM_Bootler_Still, \
    .anim_8 = ANIM_Bootler_Shock, \
    .anim_9 = ANIM_Bootler_Panic, \
    .anim_A = ANIM_Bootler_Dejected, \
    .anim_B = ANIM_Bootler_Quaver, \
    .anim_C = ANIM_Bootler_Shock, \
    .anim_D = ANIM_Bootler_Panic, \
    .anim_E = ANIM_Bootler_Dejected, \
    .anim_F = ANIM_Bootler_Quaver, \
}
