#include "common.h"
#include "sprite/npc/Bubulb.h"

#define BUBULB_PINK_ANIMS \
{ \
    .idle   = ANIM_Bubulb_Pink_Idle, \
    .walk   = ANIM_Bubulb_Pink_Walk, \
    .run    = ANIM_Bubulb_Pink_Walk, \
    .chase  = ANIM_Bubulb_Pink_Idle, \
    .anim_4 = ANIM_Bubulb_Pink_Idle, \
    .anim_5 = ANIM_Bubulb_Pink_Idle, \
    .death  = ANIM_Bubulb_Pink_Idle, \
    .hit    = ANIM_Bubulb_Pink_Idle, \
    .anim_8 = ANIM_Bubulb_Pink_Idle, \
    .anim_9 = ANIM_Bubulb_Pink_Idle, \
    .anim_A = ANIM_Bubulb_Pink_Idle, \
    .anim_B = ANIM_Bubulb_Pink_Idle, \
    .anim_C = ANIM_Bubulb_Pink_Idle, \
    .anim_D = ANIM_Bubulb_Pink_Idle, \
    .anim_E = ANIM_Bubulb_Pink_Idle, \
    .anim_F = ANIM_Bubulb_Pink_Idle, \
}

#define BUBULB_PURPLE_ANIMS \
{ \
    .idle   = ANIM_Bubulb_Purple_Idle, \
    .walk   = ANIM_Bubulb_Purple_Walk, \
    .run    = ANIM_Bubulb_Purple_Walk, \
    .chase  = ANIM_Bubulb_Purple_Idle, \
    .anim_4 = ANIM_Bubulb_Purple_Idle, \
    .anim_5 = ANIM_Bubulb_Purple_Idle, \
    .death  = ANIM_Bubulb_Purple_Idle, \
    .hit    = ANIM_Bubulb_Purple_Idle, \
    .anim_8 = ANIM_Bubulb_Purple_Idle, \
    .anim_9 = ANIM_Bubulb_Purple_Idle, \
    .anim_A = ANIM_Bubulb_Purple_Idle, \
    .anim_B = ANIM_Bubulb_Purple_Idle, \
    .anim_C = ANIM_Bubulb_Purple_Idle, \
    .anim_D = ANIM_Bubulb_Purple_Idle, \
    .anim_E = ANIM_Bubulb_Purple_Idle, \
    .anim_F = ANIM_Bubulb_Purple_Idle, \
}

#define BUBULB_GREEN_ANIMS \
{ \
    .idle   = ANIM_Bubulb_Green_Idle, \
    .walk   = ANIM_Bubulb_Green_Walk, \
    .run    = ANIM_Bubulb_Green_Walk, \
    .chase  = ANIM_Bubulb_Green_Idle, \
    .anim_4 = ANIM_Bubulb_Green_Idle, \
    .anim_5 = ANIM_Bubulb_Green_Idle, \
    .death  = ANIM_Bubulb_Green_Idle, \
    .hit    = ANIM_Bubulb_Green_Idle, \
    .anim_8 = ANIM_Bubulb_Green_Idle, \
    .anim_9 = ANIM_Bubulb_Green_Idle, \
    .anim_A = ANIM_Bubulb_Green_Idle, \
    .anim_B = ANIM_Bubulb_Green_Idle, \
    .anim_C = ANIM_Bubulb_Green_Idle, \
    .anim_D = ANIM_Bubulb_Green_Idle, \
    .anim_E = ANIM_Bubulb_Green_Idle, \
    .anim_F = ANIM_Bubulb_Green_Idle, \
}

#define BUBULB_YELLOW_ANIMS \
{ \
    .idle   = ANIM_Bubulb_Yellow_Idle, \
    .walk   = ANIM_Bubulb_Yellow_Walk, \
    .run    = ANIM_Bubulb_Yellow_Walk, \
    .chase  = ANIM_Bubulb_Yellow_Idle, \
    .anim_4 = ANIM_Bubulb_Yellow_Idle, \
    .anim_5 = ANIM_Bubulb_Yellow_Idle, \
    .death  = ANIM_Bubulb_Yellow_Idle, \
    .hit    = ANIM_Bubulb_Yellow_Idle, \
    .anim_8 = ANIM_Bubulb_Yellow_Idle, \
    .anim_9 = ANIM_Bubulb_Yellow_Idle, \
    .anim_A = ANIM_Bubulb_Yellow_Idle, \
    .anim_B = ANIM_Bubulb_Yellow_Idle, \
    .anim_C = ANIM_Bubulb_Yellow_Idle, \
    .anim_D = ANIM_Bubulb_Yellow_Idle, \
    .anim_E = ANIM_Bubulb_Yellow_Idle, \
    .anim_F = ANIM_Bubulb_Yellow_Idle, \
}
