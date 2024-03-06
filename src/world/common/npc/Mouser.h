#include "common.h"

#include "sprite/npc/Mouser.h"
#include "sprite/npc/DisguisedMoustafa.h"
#include "sprite/npc/Moustafa.h"

#define MOUSER_BLUE_ANIMS \
{ \
    .idle   = ANIM_Mouser_Blue_Idle, \
    .walk   = ANIM_Mouser_Blue_Run, \
    .run    = ANIM_Mouser_Blue_Run, \
    .chase  = ANIM_Mouser_Blue_Run, \
    .anim_4 = ANIM_Mouser_Blue_Idle, \
    .anim_5 = ANIM_Mouser_Blue_Idle, \
    .death  = ANIM_Mouser_Blue_Idle, \
    .hit    = ANIM_Mouser_Blue_Idle, \
    .anim_8 = ANIM_Mouser_Blue_Idle, \
    .anim_9 = ANIM_Mouser_Blue_Idle, \
    .anim_A = ANIM_Mouser_Blue_Idle, \
    .anim_B = ANIM_Mouser_Blue_Idle, \
    .anim_C = ANIM_Mouser_Blue_Idle, \
    .anim_D = ANIM_Mouser_Blue_Idle, \
    .anim_E = ANIM_Mouser_Blue_Idle, \
    .anim_F = ANIM_Mouser_Blue_Idle, \
}

#define MOUSER_PURPLE_ANIMS \
{ \
    .idle   = ANIM_Mouser_Purple_Idle, \
    .walk   = ANIM_Mouser_Purple_Run, \
    .run    = ANIM_Mouser_Purple_Run, \
    .chase  = ANIM_Mouser_Purple_Idle, \
    .anim_4 = ANIM_Mouser_Purple_Idle, \
    .anim_5 = ANIM_Mouser_Purple_Idle, \
    .death  = ANIM_Mouser_Purple_Idle, \
    .hit    = ANIM_Mouser_Purple_Idle, \
    .anim_8 = ANIM_Mouser_Purple_Idle, \
    .anim_9 = ANIM_Mouser_Purple_Idle, \
    .anim_A = ANIM_Mouser_Purple_Idle, \
    .anim_B = ANIM_Mouser_Purple_Idle, \
    .anim_C = ANIM_Mouser_Purple_Idle, \
    .anim_D = ANIM_Mouser_Purple_Idle, \
    .anim_E = ANIM_Mouser_Purple_Idle, \
    .anim_F = ANIM_Mouser_Purple_Idle, \
}

#define MOUSTAFA_ANIMS \
{ \
    .idle   = ANIM_Moustafa_Idle, \
    .walk   = ANIM_Moustafa_Idle, \
    .run    = ANIM_Moustafa_Run, \
    .chase  = ANIM_Moustafa_Run, \
    .anim_4 = ANIM_Moustafa_Idle, \
    .anim_5 = ANIM_Moustafa_Idle, \
    .death  = ANIM_Moustafa_Idle, \
    .hit    = ANIM_Moustafa_Idle, \
    .anim_8 = ANIM_Moustafa_Idle, \
    .anim_9 = ANIM_Moustafa_Idle, \
    .anim_A = ANIM_Moustafa_Idle, \
    .anim_B = ANIM_Moustafa_Idle, \
    .anim_C = ANIM_Moustafa_Idle, \
    .anim_D = ANIM_Moustafa_Idle, \
    .anim_E = ANIM_Moustafa_Idle, \
    .anim_F = ANIM_Moustafa_Idle, \
}

#define DISGUISED_MOUSTAFA_ANIMS \
{ \
    .idle   = ANIM_DisguisedMoustafa_Idle, \
    .walk   = ANIM_DisguisedMoustafa_Idle, \
    .run    = ANIM_DisguisedMoustafa_Idle, \
    .chase  = ANIM_DisguisedMoustafa_Idle, \
    .anim_4 = ANIM_DisguisedMoustafa_Idle, \
    .anim_5 = ANIM_DisguisedMoustafa_Idle, \
    .death  = ANIM_DisguisedMoustafa_Idle, \
    .hit    = ANIM_DisguisedMoustafa_Idle, \
    .anim_8 = ANIM_DisguisedMoustafa_Idle, \
    .anim_9 = ANIM_DisguisedMoustafa_Idle, \
    .anim_A = ANIM_DisguisedMoustafa_Idle, \
    .anim_B = ANIM_DisguisedMoustafa_Idle, \
    .anim_C = ANIM_DisguisedMoustafa_Idle, \
    .anim_D = ANIM_DisguisedMoustafa_Idle, \
    .anim_E = ANIM_DisguisedMoustafa_Idle, \
    .anim_F = ANIM_DisguisedMoustafa_Idle, \
}
