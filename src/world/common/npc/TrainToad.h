#include "common.h"
#include "sprite/npc/TrainToad.h"

#define TRAIN_CONDUCTOR_ANIMS \
{ \
    .idle   = ANIM_TrainToad_Idle, \
    .walk   = ANIM_TrainToad_Walk, \
    .run    = ANIM_TrainToad_Idle, \
    .chase  = ANIM_TrainToad_Idle, \
    .anim_4 = ANIM_TrainToad_Idle, \
    .anim_5 = ANIM_TrainToad_Idle, \
    .death  = ANIM_TrainToad_Idle, \
    .hit    = ANIM_TrainToad_Idle, \
    .anim_8 = ANIM_TrainToad_Idle, \
    .anim_9 = ANIM_TrainToad_Idle, \
    .anim_A = ANIM_TrainToad_Idle, \
    .anim_B = ANIM_TrainToad_Idle, \
    .anim_C = ANIM_TrainToad_Idle, \
    .anim_D = ANIM_TrainToad_Idle, \
    .anim_E = ANIM_TrainToad_Idle, \
    .anim_F = ANIM_TrainToad_Idle, \
}

#define TRAIN_TOAD_PINK_ANIMS \
{ \
    .idle   = ANIM_TrainToad_Pink_Idle, \
    .walk   = ANIM_TrainToad_Pink_Idle, \
    .run    = ANIM_TrainToad_Pink_Idle, \
    .chase  = ANIM_TrainToad_Pink_Idle, \
    .anim_4 = ANIM_TrainToad_Pink_Idle, \
    .anim_5 = ANIM_TrainToad_Pink_Idle, \
    .death  = ANIM_TrainToad_Pink_Idle, \
    .hit    = ANIM_TrainToad_Pink_Idle, \
    .anim_8 = ANIM_TrainToad_Pink_Idle, \
    .anim_9 = ANIM_TrainToad_Pink_Idle, \
    .anim_A = ANIM_TrainToad_Pink_Idle, \
    .anim_B = ANIM_TrainToad_Pink_Idle, \
    .anim_C = ANIM_TrainToad_Pink_Idle, \
    .anim_D = ANIM_TrainToad_Pink_Idle, \
    .anim_E = ANIM_TrainToad_Pink_Idle, \
    .anim_F = ANIM_TrainToad_Pink_Idle, \
}

#define TRAIN_TOAD_BLUE_ANIMS \
{ \
    .idle   = ANIM_TrainToad_Blue_Idle, \
    .walk   = ANIM_TrainToad_Blue_Idle, \
    .run    = ANIM_TrainToad_Blue_Idle, \
    .chase  = ANIM_TrainToad_Blue_Idle, \
    .anim_4 = ANIM_TrainToad_Blue_Idle, \
    .anim_5 = ANIM_TrainToad_Blue_Idle, \
    .death  = ANIM_TrainToad_Blue_Idle, \
    .hit    = ANIM_TrainToad_Blue_Idle, \
    .anim_8 = ANIM_TrainToad_Blue_Idle, \
    .anim_9 = ANIM_TrainToad_Blue_Idle, \
    .anim_A = ANIM_TrainToad_Blue_Idle, \
    .anim_B = ANIM_TrainToad_Blue_Idle, \
    .anim_C = ANIM_TrainToad_Blue_Idle, \
    .anim_D = ANIM_TrainToad_Blue_Idle, \
    .anim_E = ANIM_TrainToad_Blue_Idle, \
    .anim_F = ANIM_TrainToad_Blue_Idle, \
}

#define TRAIN_TOAD_GREEN_ANIMS \
{ \
    .idle   = ANIM_TrainToad_Green_Idle, \
    .walk   = ANIM_TrainToad_Green_Idle, \
    .run    = ANIM_TrainToad_Green_Idle, \
    .chase  = ANIM_TrainToad_Green_Idle, \
    .anim_4 = ANIM_TrainToad_Green_Idle, \
    .anim_5 = ANIM_TrainToad_Green_Idle, \
    .death  = ANIM_TrainToad_Green_Idle, \
    .hit    = ANIM_TrainToad_Green_Idle, \
    .anim_8 = ANIM_TrainToad_Green_Idle, \
    .anim_9 = ANIM_TrainToad_Green_Idle, \
    .anim_A = ANIM_TrainToad_Green_Idle, \
    .anim_B = ANIM_TrainToad_Green_Idle, \
    .anim_C = ANIM_TrainToad_Green_Idle, \
    .anim_D = ANIM_TrainToad_Green_Idle, \
    .anim_E = ANIM_TrainToad_Green_Idle, \
    .anim_F = ANIM_TrainToad_Green_Idle, \
}

#define TRAIN_TOAD_RED_ANIMS \
{ \
    .idle   = ANIM_TrainToad_Red_Idle, \
    .walk   = ANIM_TrainToad_Red_Idle, \
    .run    = ANIM_TrainToad_Red_Idle, \
    .chase  = ANIM_TrainToad_Red_Idle, \
    .anim_4 = ANIM_TrainToad_Red_Idle, \
    .anim_5 = ANIM_TrainToad_Red_Idle, \
    .death  = ANIM_TrainToad_Red_Idle, \
    .hit    = ANIM_TrainToad_Red_Idle, \
    .anim_8 = ANIM_TrainToad_Red_Idle, \
    .anim_9 = ANIM_TrainToad_Red_Idle, \
    .anim_A = ANIM_TrainToad_Red_Idle, \
    .anim_B = ANIM_TrainToad_Red_Idle, \
    .anim_C = ANIM_TrainToad_Red_Idle, \
    .anim_D = ANIM_TrainToad_Red_Idle, \
    .anim_E = ANIM_TrainToad_Red_Idle, \
    .anim_F = ANIM_TrainToad_Red_Idle, \
}

#define TRAIN_TOAD_WHITE_ANIMS \
{ \
    .idle   = ANIM_TrainToad_White_Idle, \
    .walk   = ANIM_TrainToad_White_Idle, \
    .run    = ANIM_TrainToad_White_Idle, \
    .chase  = ANIM_TrainToad_White_Idle, \
    .anim_4 = ANIM_TrainToad_White_Idle, \
    .anim_5 = ANIM_TrainToad_White_Idle, \
    .death  = ANIM_TrainToad_White_Idle, \
    .hit    = ANIM_TrainToad_White_Idle, \
    .anim_8 = ANIM_TrainToad_White_Idle, \
    .anim_9 = ANIM_TrainToad_White_Idle, \
    .anim_A = ANIM_TrainToad_White_Idle, \
    .anim_B = ANIM_TrainToad_White_Idle, \
    .anim_C = ANIM_TrainToad_White_Idle, \
    .anim_D = ANIM_TrainToad_White_Idle, \
    .anim_E = ANIM_TrainToad_White_Idle, \
    .anim_F = ANIM_TrainToad_White_Idle, \
}

