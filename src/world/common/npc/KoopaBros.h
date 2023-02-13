#include "common.h"
#include "sprite/npc/KoopaBros.h"

#define BLACK_KOOPA_BROS_ANIMS \
{ \
    .idle   = ANIM_KoopaBros_Black_Anim04, \
    .walk   = ANIM_KoopaBros_Black_Anim02, \
    .run    = ANIM_KoopaBros_Black_Anim03, \
    .chase  = ANIM_KoopaBros_Black_Anim03, \
    .anim_4 = ANIM_KoopaBros_Black_Anim04, \
    .anim_5 = ANIM_KoopaBros_Black_Anim04, \
    .death  = ANIM_KoopaBros_Black_Anim0A, \
    .hit    = ANIM_KoopaBros_Black_Anim0A, \
    .anim_8 = ANIM_KoopaBros_Black_Anim03, \
    .anim_9 = ANIM_KoopaBros_Black_Anim03, \
    .anim_A = ANIM_KoopaBros_Black_Anim03, \
    .anim_B = ANIM_KoopaBros_Black_Anim03, \
    .anim_C = ANIM_KoopaBros_Black_Anim03, \
    .anim_D = ANIM_KoopaBros_Black_Anim03, \
    .anim_E = ANIM_KoopaBros_Black_Anim03, \
    .anim_F = ANIM_KoopaBros_Black_Anim03, \
}

#define RED_KOOPA_BROS_ANIMS \
{ \
    .idle   = ANIM_KoopaBros_Red_Anim04, \
    .walk   = ANIM_KoopaBros_Red_Anim02, \
    .run    = ANIM_KoopaBros_Red_Anim03, \
    .chase  = ANIM_KoopaBros_Red_Anim03, \
    .anim_4 = ANIM_KoopaBros_Red_Anim04, \
    .anim_5 = ANIM_KoopaBros_Red_Anim04, \
    .death  = ANIM_KoopaBros_Red_Anim0A, \
    .hit    = ANIM_KoopaBros_Red_Anim0A, \
    .anim_8 = ANIM_KoopaBros_Red_Anim03, \
    .anim_9 = ANIM_KoopaBros_Red_Anim03, \
    .anim_A = ANIM_KoopaBros_Red_Anim03, \
    .anim_B = ANIM_KoopaBros_Red_Anim03, \
    .anim_C = ANIM_KoopaBros_Red_Anim03, \
    .anim_D = ANIM_KoopaBros_Red_Anim03, \
    .anim_E = ANIM_KoopaBros_Red_Anim03, \
    .anim_F = ANIM_KoopaBros_Red_Anim03, \
}

#define YELLOW_KOOPA_BROS_ANIMS \
{ \
    .idle   = ANIM_KoopaBros_Yellow_Anim04, \
    .walk   = ANIM_KoopaBros_Yellow_Anim02, \
    .run    = ANIM_KoopaBros_Yellow_Anim03, \
    .chase  = ANIM_KoopaBros_Yellow_Anim03, \
    .anim_4 = ANIM_KoopaBros_Yellow_Anim04, \
    .anim_5 = ANIM_KoopaBros_Yellow_Anim04, \
    .death  = ANIM_KoopaBros_Yellow_Anim0A, \
    .hit    = ANIM_KoopaBros_Yellow_Anim0A, \
    .anim_8 = ANIM_KoopaBros_Yellow_Anim03, \
    .anim_9 = ANIM_KoopaBros_Yellow_Anim03, \
    .anim_A = ANIM_KoopaBros_Yellow_Anim03, \
    .anim_B = ANIM_KoopaBros_Yellow_Anim03, \
    .anim_C = ANIM_KoopaBros_Yellow_Anim03, \
    .anim_D = ANIM_KoopaBros_Yellow_Anim03, \
    .anim_E = ANIM_KoopaBros_Yellow_Anim03, \
    .anim_F = ANIM_KoopaBros_Yellow_Anim03, \
}

#define GREEN_KOOPA_BROS_ANIMS \
{ \
    .idle   = ANIM_KoopaBros_Green_Anim04, \
    .walk   = ANIM_KoopaBros_Green_Anim02, \
    .run    = ANIM_KoopaBros_Green_Anim03, \
    .chase  = ANIM_KoopaBros_Green_Anim03, \
    .anim_4 = ANIM_KoopaBros_Green_Anim04, \
    .anim_5 = ANIM_KoopaBros_Green_Anim04, \
    .death  = ANIM_KoopaBros_Green_Anim0A, \
    .hit    = ANIM_KoopaBros_Green_Anim0A, \
    .anim_8 = ANIM_KoopaBros_Green_Anim03, \
    .anim_9 = ANIM_KoopaBros_Green_Anim03, \
    .anim_A = ANIM_KoopaBros_Green_Anim03, \
    .anim_B = ANIM_KoopaBros_Green_Anim03, \
    .anim_C = ANIM_KoopaBros_Green_Anim03, \
    .anim_D = ANIM_KoopaBros_Green_Anim03, \
    .anim_E = ANIM_KoopaBros_Green_Anim03, \
    .anim_F = ANIM_KoopaBros_Green_Anim03, \
}
