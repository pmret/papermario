#include "common.h"
#include "sprite/npc/Dryite.h"

#define DRYITE_GREEN_ANIMS \
{ \
    .idle   = ANIM_Dryite_Green_Idle, \
    .walk   = ANIM_Dryite_Green_Walk, \
    .run    = ANIM_Dryite_Green_Run, \
    .chase  = ANIM_Dryite_Green_Run, \
    .anim_4 = ANIM_Dryite_Green_Idle, \
    .anim_5 = ANIM_Dryite_Green_Idle, \
    .death  = ANIM_Dryite_Green_Still, \
    .hit    = ANIM_Dryite_Green_Still, \
    .anim_8 = ANIM_Dryite_Green_Idle, \
    .anim_9 = ANIM_Dryite_Green_Idle, \
    .anim_A = ANIM_Dryite_Green_Idle, \
    .anim_B = ANIM_Dryite_Green_Idle, \
    .anim_C = ANIM_Dryite_Green_Idle, \
    .anim_D = ANIM_Dryite_Green_Idle, \
    .anim_E = ANIM_Dryite_Green_Idle, \
    .anim_F = ANIM_Dryite_Green_Idle, \
}

#define DRYITE_BROWN_ANIMS \
{ \
    .idle   = ANIM_Dryite_Brown_Idle, \
    .walk   = ANIM_Dryite_Brown_Walk, \
    .run    = ANIM_Dryite_Brown_Run, \
    .chase  = ANIM_Dryite_Brown_Run, \
    .anim_4 = ANIM_Dryite_Brown_Idle, \
    .anim_5 = ANIM_Dryite_Brown_Idle, \
    .death  = ANIM_Dryite_Brown_Still, \
    .hit    = ANIM_Dryite_Brown_Still, \
    .anim_8 = ANIM_Dryite_Brown_Idle, \
    .anim_9 = ANIM_Dryite_Brown_Idle, \
    .anim_A = ANIM_Dryite_Brown_Idle, \
    .anim_B = ANIM_Dryite_Brown_Idle, \
    .anim_C = ANIM_Dryite_Brown_Idle, \
    .anim_D = ANIM_Dryite_Brown_Idle, \
    .anim_E = ANIM_Dryite_Brown_Idle, \
    .anim_F = ANIM_Dryite_Brown_Idle, \
}

#define DRYITE_BLUE_ANIMS \
{ \
    .idle   = ANIM_Dryite_Blue_Idle, \
    .walk   = ANIM_Dryite_Blue_Walk, \
    .run    = ANIM_Dryite_Blue_Run, \
    .chase  = ANIM_Dryite_Blue_Run, \
    .anim_4 = ANIM_Dryite_Blue_Idle, \
    .anim_5 = ANIM_Dryite_Blue_Idle, \
    .death  = ANIM_Dryite_Blue_Still, \
    .hit    = ANIM_Dryite_Blue_Still, \
    .anim_8 = ANIM_Dryite_Blue_Idle, \
    .anim_9 = ANIM_Dryite_Blue_Idle, \
    .anim_A = ANIM_Dryite_Blue_Idle, \
    .anim_B = ANIM_Dryite_Blue_Idle, \
    .anim_C = ANIM_Dryite_Blue_Idle, \
    .anim_D = ANIM_Dryite_Blue_Idle, \
    .anim_E = ANIM_Dryite_Blue_Idle, \
    .anim_F = ANIM_Dryite_Blue_Idle, \
}

#define DRYITE_YELLOW_ANIMS \
{ \
    .idle   = ANIM_Dryite_Yellow_Idle, \
    .walk   = ANIM_Dryite_Yellow_Walk, \
    .run    = ANIM_Dryite_Yellow_Run, \
    .chase  = ANIM_Dryite_Yellow_Run, \
    .anim_4 = ANIM_Dryite_Yellow_Idle, \
    .anim_5 = ANIM_Dryite_Yellow_Idle, \
    .death  = ANIM_Dryite_Yellow_Still, \
    .hit    = ANIM_Dryite_Yellow_Still, \
    .anim_8 = ANIM_Dryite_Yellow_Idle, \
    .anim_9 = ANIM_Dryite_Yellow_Idle, \
    .anim_A = ANIM_Dryite_Yellow_Idle, \
    .anim_B = ANIM_Dryite_Yellow_Idle, \
    .anim_C = ANIM_Dryite_Yellow_Idle, \
    .anim_D = ANIM_Dryite_Yellow_Idle, \
    .anim_E = ANIM_Dryite_Yellow_Idle, \
    .anim_F = ANIM_Dryite_Yellow_Idle, \
}
