#include "common.h"
#include "sprite/npc/ToadKid.h"

#define TOAD_KID_RED_ANIMS \
{ \
    .idle   = ANIM_ToadKid_Red_Idle, \
    .walk   = ANIM_ToadKid_Red_Walk, \
    .run    = ANIM_ToadKid_Red_Run, \
    .chase  = ANIM_ToadKid_Red_Run, \
    .anim_4 = ANIM_ToadKid_Red_Idle, \
    .anim_5 = ANIM_ToadKid_Red_Idle, \
    .death  = ANIM_ToadKid_Red_Still, \
    .hit    = ANIM_ToadKid_Red_Still, \
    .anim_8 = ANIM_ToadKid_Red_Still, \
    .anim_9 = ANIM_ToadKid_Red_Still, \
    .anim_A = ANIM_ToadKid_Red_Still, \
    .anim_B = ANIM_ToadKid_Red_Still, \
    .anim_C = ANIM_ToadKid_Red_Still, \
    .anim_D = ANIM_ToadKid_Red_Still, \
    .anim_E = ANIM_ToadKid_Red_Still, \
    .anim_F = ANIM_ToadKid_Red_Still, \
}

#define TOAD_KID_GREEN_ANIMS \
{ \
    .idle   = ANIM_ToadKid_Green_Idle, \
    .walk   = ANIM_ToadKid_Green_Walk, \
    .run    = ANIM_ToadKid_Green_Run, \
    .chase  = ANIM_ToadKid_Green_Run, \
    .anim_4 = ANIM_ToadKid_Green_Idle, \
    .anim_5 = ANIM_ToadKid_Green_Idle, \
    .death  = ANIM_ToadKid_Green_Still, \
    .hit    = ANIM_ToadKid_Green_Still, \
    .anim_8 = ANIM_ToadKid_Green_Still, \
    .anim_9 = ANIM_ToadKid_Green_Still, \
    .anim_A = ANIM_ToadKid_Green_Still, \
    .anim_B = ANIM_ToadKid_Green_Still, \
    .anim_C = ANIM_ToadKid_Green_Still, \
    .anim_D = ANIM_ToadKid_Green_Still, \
    .anim_E = ANIM_ToadKid_Green_Still, \
    .anim_F = ANIM_ToadKid_Green_Still, \
}

#define TOAD_KID_BLUE_ANIMS \
{ \
    .idle   = ANIM_ToadKid_Blue_Idle, \
    .walk   = ANIM_ToadKid_Blue_Walk, \
    .run    = ANIM_ToadKid_Blue_Run, \
    .chase  = ANIM_ToadKid_Blue_Run, \
    .anim_4 = ANIM_ToadKid_Blue_Idle, \
    .anim_5 = ANIM_ToadKid_Blue_Idle, \
    .death  = ANIM_ToadKid_Blue_Still, \
    .hit    = ANIM_ToadKid_Blue_Still, \
    .anim_8 = ANIM_ToadKid_Blue_Still, \
    .anim_9 = ANIM_ToadKid_Blue_Still, \
    .anim_A = ANIM_ToadKid_Blue_Still, \
    .anim_B = ANIM_ToadKid_Blue_Still, \
    .anim_C = ANIM_ToadKid_Blue_Still, \
    .anim_D = ANIM_ToadKid_Blue_Still, \
    .anim_E = ANIM_ToadKid_Blue_Still, \
    .anim_F = ANIM_ToadKid_Blue_Still, \
}

#define TOAD_KID_YELLOW_ANIMS \
{ \
    .idle   = ANIM_ToadKid_Yellow_Idle, \
    .walk   = ANIM_ToadKid_Yellow_Walk, \
    .run    = ANIM_ToadKid_Yellow_Run, \
    .chase  = ANIM_ToadKid_Yellow_Run, \
    .anim_4 = ANIM_ToadKid_Yellow_Idle, \
    .anim_5 = ANIM_ToadKid_Yellow_Idle, \
    .death  = ANIM_ToadKid_Yellow_Still, \
    .hit    = ANIM_ToadKid_Yellow_Still, \
    .anim_8 = ANIM_ToadKid_Yellow_Still, \
    .anim_9 = ANIM_ToadKid_Yellow_Still, \
    .anim_A = ANIM_ToadKid_Yellow_Still, \
    .anim_B = ANIM_ToadKid_Yellow_Still, \
    .anim_C = ANIM_ToadKid_Yellow_Still, \
    .anim_D = ANIM_ToadKid_Yellow_Still, \
    .anim_E = ANIM_ToadKid_Yellow_Still, \
    .anim_F = ANIM_ToadKid_Yellow_Still, \
}
