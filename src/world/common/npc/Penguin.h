#include "common.h"
#include "sprite/npc/MayorPenguin.h"
#include "sprite/npc/MayorPenguinWife.h"
#include "sprite/npc/Penguin.h"

#define PENGUIN_ANIMS \
{ \
    .idle   = ANIM_Penguin_Idle, \
    .walk   = ANIM_Penguin_Walk, \
    .run    = ANIM_Penguin_Run, \
    .chase  = ANIM_Penguin_Run, \
    .anim_4 = ANIM_Penguin_Idle, \
    .anim_5 = ANIM_Penguin_Idle, \
    .death  = ANIM_Penguin_Idle, \
    .hit    = ANIM_Penguin_Idle, \
    .anim_8 = ANIM_Penguin_Idle, \
    .anim_9 = ANIM_Penguin_Idle, \
    .anim_A = ANIM_Penguin_Idle, \
    .anim_B = ANIM_Penguin_Idle, \
    .anim_C = ANIM_Penguin_Idle, \
    .anim_D = ANIM_Penguin_Idle, \
    .anim_E = ANIM_Penguin_Idle, \
    .anim_F = ANIM_Penguin_Idle, \
}

#define MAYOR_PENGUIN_ANIMS \
{ \
    .idle   = ANIM_MayorPenguin_Idle, \
    .walk   = ANIM_MayorPenguin_Walk, \
    .run    = ANIM_MayorPenguin_Idle, \
    .chase  = ANIM_MayorPenguin_Idle, \
    .anim_4 = ANIM_MayorPenguin_Idle, \
    .anim_5 = ANIM_MayorPenguin_Idle, \
    .death  = ANIM_MayorPenguin_Idle, \
    .hit    = ANIM_MayorPenguin_Idle, \
    .anim_8 = ANIM_MayorPenguin_Idle, \
    .anim_9 = ANIM_MayorPenguin_Idle, \
    .anim_A = ANIM_MayorPenguin_Idle, \
    .anim_B = ANIM_MayorPenguin_Idle, \
    .anim_C = ANIM_MayorPenguin_Idle, \
    .anim_D = ANIM_MayorPenguin_Idle, \
    .anim_E = ANIM_MayorPenguin_Idle, \
    .anim_F = ANIM_MayorPenguin_Idle, \
}

#define MAYOR_PENGUIN_WIFE_ANIMS \
{ \
    .idle   = ANIM_MayorPenguinWife_Idle, \
    .walk   = ANIM_MayorPenguinWife_Walk, \
    .run    = ANIM_MayorPenguinWife_Idle, \
    .chase  = ANIM_MayorPenguinWife_Idle, \
    .anim_4 = ANIM_MayorPenguinWife_Idle, \
    .anim_5 = ANIM_MayorPenguinWife_Idle, \
    .death  = ANIM_MayorPenguinWife_Idle, \
    .hit    = ANIM_MayorPenguinWife_Idle, \
    .anim_8 = ANIM_MayorPenguinWife_Idle, \
    .anim_9 = ANIM_MayorPenguinWife_Idle, \
    .anim_A = ANIM_MayorPenguinWife_Idle, \
    .anim_B = ANIM_MayorPenguinWife_Idle, \
    .anim_C = ANIM_MayorPenguinWife_Idle, \
    .anim_D = ANIM_MayorPenguinWife_Idle, \
    .anim_E = ANIM_MayorPenguinWife_Idle, \
    .anim_F = ANIM_MayorPenguinWife_Idle, \
}

#define PENGUIN_PATROL_ANIMS \
{ \
    .idle   = ANIM_PenguinPatrol_Idle, \
    .walk   = ANIM_PenguinPatrol_Walk, \
    .run    = ANIM_PenguinPatrol_Idle, \
    .chase  = ANIM_PenguinPatrol_Idle, \
    .anim_4 = ANIM_PenguinPatrol_Idle, \
    .anim_5 = ANIM_PenguinPatrol_Idle, \
    .death  = ANIM_PenguinPatrol_Idle, \
    .hit    = ANIM_PenguinPatrol_Idle, \
    .anim_8 = ANIM_PenguinPatrol_Idle, \
    .anim_9 = ANIM_PenguinPatrol_Idle, \
    .anim_A = ANIM_PenguinPatrol_Idle, \
    .anim_B = ANIM_PenguinPatrol_Idle, \
    .anim_C = ANIM_PenguinPatrol_Idle, \
    .anim_D = ANIM_PenguinPatrol_Idle, \
    .anim_E = ANIM_PenguinPatrol_Idle, \
    .anim_F = ANIM_PenguinPatrol_Idle, \
}

#define HERRINGWAY_ANIMS \
{ \
    .idle   = ANIM_Herringway_Idle, \
    .walk   = ANIM_Herringway_Walk, \
    .run    = ANIM_Herringway_Idle, \
    .chase  = ANIM_Herringway_Idle, \
    .anim_4 = ANIM_Herringway_Idle, \
    .anim_5 = ANIM_Herringway_Idle, \
    .death  = ANIM_Herringway_Idle, \
    .hit    = ANIM_Herringway_Idle, \
    .anim_8 = ANIM_Herringway_Idle, \
    .anim_9 = ANIM_Herringway_Idle, \
    .anim_A = ANIM_Herringway_Idle, \
    .anim_B = ANIM_Herringway_Idle, \
    .anim_C = ANIM_Herringway_Idle, \
    .anim_D = ANIM_Herringway_Idle, \
    .anim_E = ANIM_Herringway_Idle, \
    .anim_F = ANIM_Herringway_Idle, \
}
