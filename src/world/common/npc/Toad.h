#include "common.h"
#include "sprite/npc/Toad.h"

#define TOAD_RED_ANIMS \
{ \
    .idle   = ANIM_Toad_Red_Idle, \
    .walk   = ANIM_Toad_Red_Walk, \
    .run    = ANIM_Toad_Red_Run, \
    .chase  = ANIM_Toad_Red_Run, \
    .anim_4 = ANIM_Toad_Red_Idle, \
    .anim_5 = ANIM_Toad_Red_Idle, \
    .death  = ANIM_Toad_Red_Disappointed, \
    .hit    = ANIM_Toad_Red_Disappointed, \
    .anim_8 = ANIM_Toad_Red_Run, \
    .anim_9 = ANIM_Toad_Red_Run, \
    .anim_A = ANIM_Toad_Red_Run, \
    .anim_B = ANIM_Toad_Red_Run, \
    .anim_C = ANIM_Toad_Red_Run, \
    .anim_D = ANIM_Toad_Red_Run, \
    .anim_E = ANIM_Toad_Red_Run, \
    .anim_F = ANIM_Toad_Red_Run, \
}

#define TOAD_GREEN_ANIMS \
{ \
    .idle   = ANIM_Toad_Green_Idle, \
    .walk   = ANIM_Toad_Green_Walk, \
    .run    = ANIM_Toad_Green_Run, \
    .chase  = ANIM_Toad_Green_Run, \
    .anim_4 = ANIM_Toad_Green_Idle, \
    .anim_5 = ANIM_Toad_Green_Idle, \
    .death  = ANIM_Toad_Green_Disappointed, \
    .hit    = ANIM_Toad_Green_Disappointed, \
    .anim_8 = ANIM_Toad_Green_Run, \
    .anim_9 = ANIM_Toad_Green_Run, \
    .anim_A = ANIM_Toad_Green_Run, \
    .anim_B = ANIM_Toad_Green_Run, \
    .anim_C = ANIM_Toad_Green_Run, \
    .anim_D = ANIM_Toad_Green_Run, \
    .anim_E = ANIM_Toad_Green_Run, \
    .anim_F = ANIM_Toad_Green_Run, \
}

#define TOAD_BLUE_ANIMS \
{ \
    .idle   = ANIM_Toad_Blue_Idle, \
    .walk   = ANIM_Toad_Blue_Walk, \
    .run    = ANIM_Toad_Blue_Run, \
    .chase  = ANIM_Toad_Blue_Run, \
    .anim_4 = ANIM_Toad_Blue_Idle, \
    .anim_5 = ANIM_Toad_Blue_Idle, \
    .death  = ANIM_Toad_Blue_Disappointed, \
    .hit    = ANIM_Toad_Blue_Disappointed, \
    .anim_8 = ANIM_Toad_Blue_Run, \
    .anim_9 = ANIM_Toad_Blue_Run, \
    .anim_A = ANIM_Toad_Blue_Run, \
    .anim_B = ANIM_Toad_Blue_Run, \
    .anim_C = ANIM_Toad_Blue_Run, \
    .anim_D = ANIM_Toad_Blue_Run, \
    .anim_E = ANIM_Toad_Blue_Run, \
    .anim_F = ANIM_Toad_Blue_Run, \
}

#define TOAD_YELLOW_ANIMS \
{ \
    .idle   = ANIM_Toad_Yellow_Idle, \
    .walk   = ANIM_Toad_Yellow_Walk, \
    .run    = ANIM_Toad_Yellow_Run, \
    .chase  = ANIM_Toad_Yellow_Run, \
    .anim_4 = ANIM_Toad_Yellow_Idle, \
    .anim_5 = ANIM_Toad_Yellow_Idle, \
    .death  = ANIM_Toad_Yellow_Disappointed, \
    .hit    = ANIM_Toad_Yellow_Disappointed, \
    .anim_8 = ANIM_Toad_Yellow_Run, \
    .anim_9 = ANIM_Toad_Yellow_Run, \
    .anim_A = ANIM_Toad_Yellow_Run, \
    .anim_B = ANIM_Toad_Yellow_Run, \
    .anim_C = ANIM_Toad_Yellow_Run, \
    .anim_D = ANIM_Toad_Yellow_Run, \
    .anim_E = ANIM_Toad_Yellow_Run, \
    .anim_F = ANIM_Toad_Yellow_Run, \
}

#define TOAD_PINK_ANIMS \
{ \
    .idle   = ANIM_Toad_Pink_Idle, \
    .walk   = ANIM_Toad_Pink_Walk, \
    .run    = ANIM_Toad_Pink_Run, \
    .chase  = ANIM_Toad_Pink_Run, \
    .anim_4 = ANIM_Toad_Pink_Idle, \
    .anim_5 = ANIM_Toad_Pink_Idle, \
    .death  = ANIM_Toad_Pink_Disappointed, \
    .hit    = ANIM_Toad_Pink_Disappointed, \
    .anim_8 = ANIM_Toad_Pink_Run, \
    .anim_9 = ANIM_Toad_Pink_Run, \
    .anim_A = ANIM_Toad_Pink_Run, \
    .anim_B = ANIM_Toad_Pink_Run, \
    .anim_C = ANIM_Toad_Pink_Run, \
    .anim_D = ANIM_Toad_Pink_Run, \
    .anim_E = ANIM_Toad_Pink_Run, \
    .anim_F = ANIM_Toad_Pink_Run, \
}
