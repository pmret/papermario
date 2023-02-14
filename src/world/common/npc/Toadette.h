#include "common.h"
#include "sprite/npc/Toadette.h"

#define TOADETTE_ORANGE_ANIMS \
{ \
    .idle   = ANIM_Toadette_Orange_Idle, \
    .walk   = ANIM_Toadette_Orange_Walk, \
    .run    = ANIM_Toadette_Orange_Run, \
    .chase  = ANIM_Toadette_Orange_Run, \
    .anim_4 = ANIM_Toadette_Orange_Idle, \
    .anim_5 = ANIM_Toadette_Orange_Idle, \
    .death  = ANIM_Toadette_Orange_Disappointed, \
    .hit    = ANIM_Toadette_Orange_Disappointed, \
    .anim_8 = ANIM_Toadette_Orange_Run, \
    .anim_9 = ANIM_Toadette_Orange_Run, \
    .anim_A = ANIM_Toadette_Orange_Run, \
    .anim_B = ANIM_Toadette_Orange_Run, \
    .anim_C = ANIM_Toadette_Orange_Run, \
    .anim_D = ANIM_Toadette_Orange_Run, \
    .anim_E = ANIM_Toadette_Orange_Run, \
    .anim_F = ANIM_Toadette_Orange_Run, \
}

#define TOADETTE_PINK_ANIMS \
{ \
    .idle   = ANIM_Toadette_Pink_Idle, \
    .walk   = ANIM_Toadette_Pink_Walk, \
    .run    = ANIM_Toadette_Pink_Run, \
    .chase  = ANIM_Toadette_Pink_Run, \
    .anim_4 = ANIM_Toadette_Pink_Idle, \
    .anim_5 = ANIM_Toadette_Pink_Idle, \
    .death  = ANIM_Toadette_Pink_Disappointed, \
    .hit    = ANIM_Toadette_Pink_Disappointed, \
    .anim_8 = ANIM_Toadette_Pink_Run, \
    .anim_9 = ANIM_Toadette_Pink_Run, \
    .anim_A = ANIM_Toadette_Pink_Run, \
    .anim_B = ANIM_Toadette_Pink_Run, \
    .anim_C = ANIM_Toadette_Pink_Run, \
    .anim_D = ANIM_Toadette_Pink_Run, \
    .anim_E = ANIM_Toadette_Pink_Run, \
    .anim_F = ANIM_Toadette_Pink_Run, \
}

#define TOADETTE_GREEN_ANIMS \
{ \
    .idle   = ANIM_Toadette_Green_Idle, \
    .walk   = ANIM_Toadette_Green_Walk, \
    .run    = ANIM_Toadette_Green_Run, \
    .chase  = ANIM_Toadette_Green_Run, \
    .anim_4 = ANIM_Toadette_Green_Idle, \
    .anim_5 = ANIM_Toadette_Green_Idle, \
    .death  = ANIM_Toadette_Green_Disappointed, \
    .hit    = ANIM_Toadette_Green_Disappointed, \
    .anim_8 = ANIM_Toadette_Green_Run, \
    .anim_9 = ANIM_Toadette_Green_Run, \
    .anim_A = ANIM_Toadette_Green_Run, \
    .anim_B = ANIM_Toadette_Green_Run, \
    .anim_C = ANIM_Toadette_Green_Run, \
    .anim_D = ANIM_Toadette_Green_Run, \
    .anim_E = ANIM_Toadette_Green_Run, \
    .anim_F = ANIM_Toadette_Green_Run, \
}

#define TOADETTE_PURPLE_ANIMS \
{ \
    .idle   = ANIM_Toadette_Purple_Idle, \
    .walk   = ANIM_Toadette_Purple_Walk, \
    .run    = ANIM_Toadette_Purple_Run, \
    .chase  = ANIM_Toadette_Purple_Run, \
    .anim_4 = ANIM_Toadette_Purple_Idle, \
    .anim_5 = ANIM_Toadette_Purple_Idle, \
    .death  = ANIM_Toadette_Purple_Disappointed, \
    .hit    = ANIM_Toadette_Purple_Disappointed, \
    .anim_8 = ANIM_Toadette_Purple_Run, \
    .anim_9 = ANIM_Toadette_Purple_Run, \
    .anim_A = ANIM_Toadette_Purple_Run, \
    .anim_B = ANIM_Toadette_Purple_Run, \
    .anim_C = ANIM_Toadette_Purple_Run, \
    .anim_D = ANIM_Toadette_Purple_Run, \
    .anim_E = ANIM_Toadette_Purple_Run, \
    .anim_F = ANIM_Toadette_Purple_Run, \
}
