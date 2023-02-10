#include "common.h"

#include "sprite/npc/YoshiKid.h"

#define YOSHI_KID_GREEN_ANIMS \
{ \
    .idle   = ANIM_YoshiKid_Green_Idle, \
    .walk   = ANIM_YoshiKid_Green_Walk, \
    .run    = ANIM_YoshiKid_Green_Run, \
    .chase  = ANIM_YoshiKid_Green_Run, \
    .anim_4 = ANIM_YoshiKid_Green_Idle, \
    .anim_5 = ANIM_YoshiKid_Green_Idle, \
    .death  = ANIM_YoshiKid_Green_Idle, \
    .hit    = ANIM_YoshiKid_Green_Idle, \
    .anim_8 = ANIM_YoshiKid_Green_Idle, \
    .anim_9 = ANIM_YoshiKid_Green_Idle, \
    .anim_A = ANIM_YoshiKid_Green_Idle, \
    .anim_B = ANIM_YoshiKid_Green_Idle, \
    .anim_C = ANIM_YoshiKid_Green_Idle, \
    .anim_D = ANIM_YoshiKid_Green_Idle, \
    .anim_E = ANIM_YoshiKid_Green_Idle, \
    .anim_F = ANIM_YoshiKid_Green_Idle, \
}

#define YOSHI_KID_BLUE_ANIMS \
{ \
    .idle   = ANIM_YoshiKid_Blue_Idle, \
    .walk   = ANIM_YoshiKid_Blue_Walk, \
    .run    = ANIM_YoshiKid_Blue_Run, \
    .chase  = ANIM_YoshiKid_Blue_Run, \
    .anim_4 = ANIM_YoshiKid_Blue_Idle, \
    .anim_5 = ANIM_YoshiKid_Blue_Idle, \
    .death  = ANIM_YoshiKid_Blue_Idle, \
    .hit    = ANIM_YoshiKid_Blue_Idle, \
    .anim_8 = ANIM_YoshiKid_Blue_Idle, \
    .anim_9 = ANIM_YoshiKid_Blue_Idle, \
    .anim_A = ANIM_YoshiKid_Blue_Idle, \
    .anim_B = ANIM_YoshiKid_Blue_Idle, \
    .anim_C = ANIM_YoshiKid_Blue_Idle, \
    .anim_D = ANIM_YoshiKid_Blue_Idle, \
    .anim_E = ANIM_YoshiKid_Blue_Idle, \
    .anim_F = ANIM_YoshiKid_Blue_Idle, \
}

#define YOSHI_KID_PURPLE_ANIMS \
{ \
    .idle   = ANIM_YoshiKid_Purple_Idle, \
    .walk   = ANIM_YoshiKid_Purple_Walk, \
    .run    = ANIM_YoshiKid_Purple_Run, \
    .chase  = ANIM_YoshiKid_Purple_Run, \
    .anim_4 = ANIM_YoshiKid_Purple_Idle, \
    .anim_5 = ANIM_YoshiKid_Purple_Idle, \
    .death  = ANIM_YoshiKid_Purple_Idle, \
    .hit    = ANIM_YoshiKid_Purple_Idle, \
    .anim_8 = ANIM_YoshiKid_Purple_Idle, \
    .anim_9 = ANIM_YoshiKid_Purple_Idle, \
    .anim_A = ANIM_YoshiKid_Purple_Idle, \
    .anim_B = ANIM_YoshiKid_Purple_Idle, \
    .anim_C = ANIM_YoshiKid_Purple_Idle, \
    .anim_D = ANIM_YoshiKid_Purple_Idle, \
    .anim_E = ANIM_YoshiKid_Purple_Idle, \
    .anim_F = ANIM_YoshiKid_Purple_Idle, \
}

#define YOSHI_KID_YELLOW_ANIMS \
{ \
    .idle   = ANIM_YoshiKid_Yellow_Idle, \
    .walk   = ANIM_YoshiKid_Yellow_Walk, \
    .run    = ANIM_YoshiKid_Yellow_Run, \
    .chase  = ANIM_YoshiKid_Yellow_Run, \
    .anim_4 = ANIM_YoshiKid_Yellow_Idle, \
    .anim_5 = ANIM_YoshiKid_Yellow_Idle, \
    .death  = ANIM_YoshiKid_Yellow_Idle, \
    .hit    = ANIM_YoshiKid_Yellow_Idle, \
    .anim_8 = ANIM_YoshiKid_Yellow_Idle, \
    .anim_9 = ANIM_YoshiKid_Yellow_Idle, \
    .anim_A = ANIM_YoshiKid_Yellow_Idle, \
    .anim_B = ANIM_YoshiKid_Yellow_Idle, \
    .anim_C = ANIM_YoshiKid_Yellow_Idle, \
    .anim_D = ANIM_YoshiKid_Yellow_Idle, \
    .anim_E = ANIM_YoshiKid_Yellow_Idle, \
    .anim_F = ANIM_YoshiKid_Yellow_Idle, \
}

#define YOSHI_KID_RED_ANIMS \
{ \
    .idle   = ANIM_YoshiKid_Red_Idle, \
    .walk   = ANIM_YoshiKid_Red_Walk, \
    .run    = ANIM_YoshiKid_Red_Run, \
    .chase  = ANIM_YoshiKid_Red_Run, \
    .anim_4 = ANIM_YoshiKid_Red_Idle, \
    .anim_5 = ANIM_YoshiKid_Red_Idle, \
    .death  = ANIM_YoshiKid_Red_Idle, \
    .hit    = ANIM_YoshiKid_Red_Idle, \
    .anim_8 = ANIM_YoshiKid_Red_Idle, \
    .anim_9 = ANIM_YoshiKid_Red_Idle, \
    .anim_A = ANIM_YoshiKid_Red_Idle, \
    .anim_B = ANIM_YoshiKid_Red_Idle, \
    .anim_C = ANIM_YoshiKid_Red_Idle, \
    .anim_D = ANIM_YoshiKid_Red_Idle, \
    .anim_E = ANIM_YoshiKid_Red_Idle, \
    .anim_F = ANIM_YoshiKid_Red_Idle, \
}
