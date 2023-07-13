#include "common.h"
#include "sprite/npc/KoopaBros.h"

#define BLACK_KOOPA_BROS_ANIMS \
{ \
    .idle   = ANIM_KoopaBros_Black_Idle, \
    .walk   = ANIM_KoopaBros_Black_Walk, \
    .run    = ANIM_KoopaBros_Black_Run, \
    .chase  = ANIM_KoopaBros_Black_Run, \
    .anim_4 = ANIM_KoopaBros_Black_Idle, \
    .anim_5 = ANIM_KoopaBros_Black_Idle, \
    .death  = ANIM_KoopaBros_Black_HurtStill, \
    .hit    = ANIM_KoopaBros_Black_HurtStill, \
    .anim_8 = ANIM_KoopaBros_Black_Run, \
    .anim_9 = ANIM_KoopaBros_Black_Run, \
    .anim_A = ANIM_KoopaBros_Black_Run, \
    .anim_B = ANIM_KoopaBros_Black_Run, \
    .anim_C = ANIM_KoopaBros_Black_Run, \
    .anim_D = ANIM_KoopaBros_Black_Run, \
    .anim_E = ANIM_KoopaBros_Black_Run, \
    .anim_F = ANIM_KoopaBros_Black_Run, \
}

#define RED_KOOPA_BROS_ANIMS \
{ \
    .idle   = ANIM_KoopaBros_Red_Idle, \
    .walk   = ANIM_KoopaBros_Red_Walk, \
    .run    = ANIM_KoopaBros_Red_Run, \
    .chase  = ANIM_KoopaBros_Red_Run, \
    .anim_4 = ANIM_KoopaBros_Red_Idle, \
    .anim_5 = ANIM_KoopaBros_Red_Idle, \
    .death  = ANIM_KoopaBros_Red_HurtStill, \
    .hit    = ANIM_KoopaBros_Red_HurtStill, \
    .anim_8 = ANIM_KoopaBros_Red_Run, \
    .anim_9 = ANIM_KoopaBros_Red_Run, \
    .anim_A = ANIM_KoopaBros_Red_Run, \
    .anim_B = ANIM_KoopaBros_Red_Run, \
    .anim_C = ANIM_KoopaBros_Red_Run, \
    .anim_D = ANIM_KoopaBros_Red_Run, \
    .anim_E = ANIM_KoopaBros_Red_Run, \
    .anim_F = ANIM_KoopaBros_Red_Run, \
}

#define YELLOW_KOOPA_BROS_ANIMS \
{ \
    .idle   = ANIM_KoopaBros_Yellow_Idle, \
    .walk   = ANIM_KoopaBros_Yellow_Walk, \
    .run    = ANIM_KoopaBros_Yellow_Run, \
    .chase  = ANIM_KoopaBros_Yellow_Run, \
    .anim_4 = ANIM_KoopaBros_Yellow_Idle, \
    .anim_5 = ANIM_KoopaBros_Yellow_Idle, \
    .death  = ANIM_KoopaBros_Yellow_HurtStill, \
    .hit    = ANIM_KoopaBros_Yellow_HurtStill, \
    .anim_8 = ANIM_KoopaBros_Yellow_Run, \
    .anim_9 = ANIM_KoopaBros_Yellow_Run, \
    .anim_A = ANIM_KoopaBros_Yellow_Run, \
    .anim_B = ANIM_KoopaBros_Yellow_Run, \
    .anim_C = ANIM_KoopaBros_Yellow_Run, \
    .anim_D = ANIM_KoopaBros_Yellow_Run, \
    .anim_E = ANIM_KoopaBros_Yellow_Run, \
    .anim_F = ANIM_KoopaBros_Yellow_Run, \
}

#define GREEN_KOOPA_BROS_ANIMS \
{ \
    .idle   = ANIM_KoopaBros_Green_Idle, \
    .walk   = ANIM_KoopaBros_Green_Walk, \
    .run    = ANIM_KoopaBros_Green_Run, \
    .chase  = ANIM_KoopaBros_Green_Run, \
    .anim_4 = ANIM_KoopaBros_Green_Idle, \
    .anim_5 = ANIM_KoopaBros_Green_Idle, \
    .death  = ANIM_KoopaBros_Green_HurtStill, \
    .hit    = ANIM_KoopaBros_Green_HurtStill, \
    .anim_8 = ANIM_KoopaBros_Green_Run, \
    .anim_9 = ANIM_KoopaBros_Green_Run, \
    .anim_A = ANIM_KoopaBros_Green_Run, \
    .anim_B = ANIM_KoopaBros_Green_Run, \
    .anim_C = ANIM_KoopaBros_Green_Run, \
    .anim_D = ANIM_KoopaBros_Green_Run, \
    .anim_E = ANIM_KoopaBros_Green_Run, \
    .anim_F = ANIM_KoopaBros_Green_Run, \
}
