#include "common.h"
#include "sprite/npc/ToadGuard.h"

#define TOAD_GUARD_RED_ANIMS \
{ \
    .idle   = ANIM_ToadGuard_Red_Idle, \
    .walk   = ANIM_ToadGuard_Red_Idle, \
    .run    = ANIM_ToadGuard_Red_Idle, \
    .chase  = ANIM_ToadGuard_Red_Idle, \
    .anim_4 = ANIM_ToadGuard_Red_Idle, \
    .anim_5 = ANIM_ToadGuard_Red_Idle, \
    .death  = ANIM_ToadGuard_Red_Idle, \
    .hit    = ANIM_ToadGuard_Red_Idle, \
    .anim_8 = ANIM_ToadGuard_Red_Idle, \
    .anim_9 = ANIM_ToadGuard_Red_Idle, \
    .anim_A = ANIM_ToadGuard_Red_Idle, \
    .anim_B = ANIM_ToadGuard_Red_Idle, \
    .anim_C = ANIM_ToadGuard_Red_Idle, \
    .anim_D = ANIM_ToadGuard_Red_Idle, \
    .anim_E = ANIM_ToadGuard_Red_Idle, \
    .anim_F = ANIM_ToadGuard_Red_Idle, \
}

#define TOAD_GUARD_GREEN_ANIMS \
{ \
    .idle   = ANIM_ToadGuard_Green_Idle, \
    .walk   = ANIM_ToadGuard_Green_Idle, \
    .run    = ANIM_ToadGuard_Green_Idle, \
    .chase  = ANIM_ToadGuard_Green_Idle, \
    .anim_4 = ANIM_ToadGuard_Green_Idle, \
    .anim_5 = ANIM_ToadGuard_Green_Idle, \
    .death  = ANIM_ToadGuard_Green_Idle, \
    .hit    = ANIM_ToadGuard_Green_Idle, \
    .anim_8 = ANIM_ToadGuard_Green_Idle, \
    .anim_9 = ANIM_ToadGuard_Green_Idle, \
    .anim_A = ANIM_ToadGuard_Green_Idle, \
    .anim_B = ANIM_ToadGuard_Green_Idle, \
    .anim_C = ANIM_ToadGuard_Green_Idle, \
    .anim_D = ANIM_ToadGuard_Green_Idle, \
    .anim_E = ANIM_ToadGuard_Green_Idle, \
    .anim_F = ANIM_ToadGuard_Green_Idle, \
}

#define TOAD_GUARD_BLUE_ANIMS \
{ \
    .idle   = ANIM_ToadGuard_Blue_Idle, \
    .walk   = ANIM_ToadGuard_Blue_Idle, \
    .run    = ANIM_ToadGuard_Blue_Idle, \
    .chase  = ANIM_ToadGuard_Blue_Idle, \
    .anim_4 = ANIM_ToadGuard_Blue_Idle, \
    .anim_5 = ANIM_ToadGuard_Blue_Idle, \
    .death  = ANIM_ToadGuard_Blue_Idle, \
    .hit    = ANIM_ToadGuard_Blue_Idle, \
    .anim_8 = ANIM_ToadGuard_Blue_Idle, \
    .anim_9 = ANIM_ToadGuard_Blue_Idle, \
    .anim_A = ANIM_ToadGuard_Blue_Idle, \
    .anim_B = ANIM_ToadGuard_Blue_Idle, \
    .anim_C = ANIM_ToadGuard_Blue_Idle, \
    .anim_D = ANIM_ToadGuard_Blue_Idle, \
    .anim_E = ANIM_ToadGuard_Blue_Idle, \
    .anim_F = ANIM_ToadGuard_Blue_Idle, \
}

#define TOAD_GUARD_YELLOW_ANIMS \
{ \
    .idle   = ANIM_ToadGuard_Yellow_Idle, \
    .walk   = ANIM_ToadGuard_Yellow_Idle, \
    .run    = ANIM_ToadGuard_Yellow_Idle, \
    .chase  = ANIM_ToadGuard_Yellow_Idle, \
    .anim_4 = ANIM_ToadGuard_Yellow_Idle, \
    .anim_5 = ANIM_ToadGuard_Yellow_Idle, \
    .death  = ANIM_ToadGuard_Yellow_Idle, \
    .hit    = ANIM_ToadGuard_Yellow_Idle, \
    .anim_8 = ANIM_ToadGuard_Yellow_Idle, \
    .anim_9 = ANIM_ToadGuard_Yellow_Idle, \
    .anim_A = ANIM_ToadGuard_Yellow_Idle, \
    .anim_B = ANIM_ToadGuard_Yellow_Idle, \
    .anim_C = ANIM_ToadGuard_Yellow_Idle, \
    .anim_D = ANIM_ToadGuard_Yellow_Idle, \
    .anim_E = ANIM_ToadGuard_Yellow_Idle, \
    .anim_F = ANIM_ToadGuard_Yellow_Idle, \
}
