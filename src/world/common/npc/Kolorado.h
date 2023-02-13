#include "common.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/Archeologist.h"

#define KOLORADO_ANIMS \
{ \
    .idle   = ANIM_Kolorado_Idle, \
    .walk   = ANIM_Kolorado_Walk, \
    .run    = ANIM_Kolorado_Run, \
    .chase  = ANIM_Kolorado_Run, \
    .anim_4 = ANIM_Kolorado_Idle, \
    .anim_5 = ANIM_Kolorado_Idle, \
    .death  = ANIM_Kolorado_Idle, \
    .hit    = ANIM_Kolorado_Idle, \
    .anim_8 = ANIM_Kolorado_Idle, \
    .anim_9 = ANIM_Kolorado_Idle, \
    .anim_A = ANIM_Kolorado_Idle, \
    .anim_B = ANIM_Kolorado_Idle, \
    .anim_C = ANIM_Kolorado_Idle, \
    .anim_D = ANIM_Kolorado_Idle, \
    .anim_E = ANIM_Kolorado_Idle, \
    .anim_F = ANIM_Kolorado_Idle, \
}

#define ARCHEOLOGIST_ANIMS \
{ \
    .idle   = ANIM_Archeologist_Idle, \
    .walk   = ANIM_Archeologist_Walk, \
    .run    = ANIM_Archeologist_Run, \
    .chase  = ANIM_Archeologist_Run, \
    .anim_4 = ANIM_Archeologist_Idle, \
    .anim_5 = ANIM_Archeologist_Idle, \
    .death  = ANIM_Archeologist_Idle, \
    .hit    = ANIM_Archeologist_Idle, \
    .anim_8 = ANIM_Archeologist_Idle, \
    .anim_9 = ANIM_Archeologist_Idle, \
    .anim_A = ANIM_Archeologist_Idle, \
    .anim_B = ANIM_Archeologist_Idle, \
    .anim_C = ANIM_Archeologist_Idle, \
    .anim_D = ANIM_Archeologist_Idle, \
    .anim_E = ANIM_Archeologist_Idle, \
    .anim_F = ANIM_Archeologist_Idle, \
}
