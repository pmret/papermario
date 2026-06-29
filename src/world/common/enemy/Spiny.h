#include "common.h"
#include "sprite/npc/Spiny.h"

#define SPINY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 1, \
}

#define SPINY_ANIMS \
{ \
    .idle   = ANIM_Spiny_Idle, \
    .walk   = ANIM_Spiny_Walk, \
    .run    = ANIM_Spiny_Run, \
    .chase  = ANIM_Spiny_Run, \
    .anim_4 = ANIM_Spiny_Idle, \
    .anim_5 = ANIM_Spiny_Idle, \
    .death  = ANIM_Spiny_Hurt, \
    .hit    = ANIM_Spiny_Hurt, \
    .anim_8 = ANIM_Spiny_ShellEnter, \
    .anim_9 = ANIM_Spiny_ShellSpin, \
    .anim_A = ANIM_Spiny_ShellExit, \
    .anim_B = ANIM_Spiny_Idle, \
    .anim_C = ANIM_Spiny_Idle, \
    .anim_D = ANIM_Spiny_Idle, \
    .anim_E = ANIM_Spiny_Idle, \
    .anim_F = ANIM_Spiny_Idle, \
}
