#include "common.h"

#include "sprite/npc/Mouser.h"
#include "sprite/npc/DisguisedMoustafa.h"
#include "sprite/npc/Moustafa.h"

#define MOUSER_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define MOUSER_BLUE_ANIMS \
{ \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Run, \
    ANIM_Mouser_Blue_Run, \
    ANIM_Mouser_Blue_Run, \ 
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
    ANIM_Mouser_Blue_Idle, \
}

#define MOUSER_PURPLE_ANIMS \
{ \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Run, \
    ANIM_Mouser_Purple_Run, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
    ANIM_Mouser_Purple_Idle, \
}

#define MOUSTAFA_ANIMS \
{ \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Run, \
    ANIM_Moustafa_Run, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
    ANIM_Moustafa_Idle, \
}

#define DISGUISED_MOUSTAFA_ANIMS \
{ \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
    ANIM_DisguisedMoustafa_Idle, \
}
