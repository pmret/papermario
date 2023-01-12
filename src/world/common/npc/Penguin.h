#include "common.h"
#include "sprite/npc/MayorPenguin.h"
#include "sprite/npc/MayorPenguinWife.h"
#include "sprite/npc/Penguin.h"

#define PENGUIN_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

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
