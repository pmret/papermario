#include "common.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/ToadKid.h"
#include "sprite/npc/Toadette.h"
#include "sprite/npc/ToadGuard.h"
#include "sprite/npc/ToadMinister.h"

#define TOAD_DROPS NO_DROPS

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

#define TOAD_KID_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = NO_STAT_DROPS, \
    .flowerDrops = NO_STAT_DROPS, \
}

#define TOAD_KID_RED_ANIMS \
{ \
    .idle   = ANIM_ToadKid_Red_Idle, \
    .walk   = ANIM_ToadKid_Red_Walk, \
    .run    = ANIM_ToadKid_Red_Run, \
    .chase  = ANIM_ToadKid_Red_Run, \
    .anim_4 = ANIM_ToadKid_Red_Idle, \
    .anim_5 = ANIM_ToadKid_Red_Idle, \
    .death  = ANIM_ToadKid_Red_Still, \
    .hit    = ANIM_ToadKid_Red_Still, \
    .anim_8 = ANIM_ToadKid_Red_Still, \
    .anim_9 = ANIM_ToadKid_Red_Still, \
    .anim_A = ANIM_ToadKid_Red_Still, \
    .anim_B = ANIM_ToadKid_Red_Still, \
    .anim_C = ANIM_ToadKid_Red_Still, \
    .anim_D = ANIM_ToadKid_Red_Still, \
    .anim_E = ANIM_ToadKid_Red_Still, \
    .anim_F = ANIM_ToadKid_Red_Still, \
}

#define TOAD_KID_GREEN_ANIMS \
{ \
    .idle   = ANIM_ToadKid_Green_Idle, \
    .walk   = ANIM_ToadKid_Green_Walk, \
    .run    = ANIM_ToadKid_Green_Run, \
    .chase  = ANIM_ToadKid_Green_Run, \
    .anim_4 = ANIM_ToadKid_Green_Idle, \
    .anim_5 = ANIM_ToadKid_Green_Idle, \
    .death  = ANIM_ToadKid_Green_Still, \
    .hit    = ANIM_ToadKid_Green_Still, \
    .anim_8 = ANIM_ToadKid_Green_Still, \
    .anim_9 = ANIM_ToadKid_Green_Still, \
    .anim_A = ANIM_ToadKid_Green_Still, \
    .anim_B = ANIM_ToadKid_Green_Still, \
    .anim_C = ANIM_ToadKid_Green_Still, \
    .anim_D = ANIM_ToadKid_Green_Still, \
    .anim_E = ANIM_ToadKid_Green_Still, \
    .anim_F = ANIM_ToadKid_Green_Still, \
}

#define TOAD_KID_BLUE_ANIMS \
{ \
    .idle   = ANIM_ToadKid_Blue_Idle, \
    .walk   = ANIM_ToadKid_Blue_Walk, \
    .run    = ANIM_ToadKid_Blue_Run, \
    .chase  = ANIM_ToadKid_Blue_Run, \
    .anim_4 = ANIM_ToadKid_Blue_Idle, \
    .anim_5 = ANIM_ToadKid_Blue_Idle, \
    .death  = ANIM_ToadKid_Blue_Still, \
    .hit    = ANIM_ToadKid_Blue_Still, \
    .anim_8 = ANIM_ToadKid_Blue_Still, \
    .anim_9 = ANIM_ToadKid_Blue_Still, \
    .anim_A = ANIM_ToadKid_Blue_Still, \
    .anim_B = ANIM_ToadKid_Blue_Still, \
    .anim_C = ANIM_ToadKid_Blue_Still, \
    .anim_D = ANIM_ToadKid_Blue_Still, \
    .anim_E = ANIM_ToadKid_Blue_Still, \
    .anim_F = ANIM_ToadKid_Blue_Still, \
}

#define TOAD_KID_YELLOW_ANIMS \
{ \
    .idle   = ANIM_ToadKid_Yellow_Idle, \
    .walk   = ANIM_ToadKid_Yellow_Walk, \
    .run    = ANIM_ToadKid_Yellow_Run, \
    .chase  = ANIM_ToadKid_Yellow_Run, \
    .anim_4 = ANIM_ToadKid_Yellow_Idle, \
    .anim_5 = ANIM_ToadKid_Yellow_Idle, \
    .death  = ANIM_ToadKid_Yellow_Still, \
    .hit    = ANIM_ToadKid_Yellow_Still, \
    .anim_8 = ANIM_ToadKid_Yellow_Still, \
    .anim_9 = ANIM_ToadKid_Yellow_Still, \
    .anim_A = ANIM_ToadKid_Yellow_Still, \
    .anim_B = ANIM_ToadKid_Yellow_Still, \
    .anim_C = ANIM_ToadKid_Yellow_Still, \
    .anim_D = ANIM_ToadKid_Yellow_Still, \
    .anim_E = ANIM_ToadKid_Yellow_Still, \
    .anim_F = ANIM_ToadKid_Yellow_Still, \
}

#define TOADETTE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = NO_STAT_DROPS, \
    .flowerDrops = NO_STAT_DROPS, \
}

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

#define TOAD_GUARD_RED_ANIMS \
{ \
    .idle   = ANIM_ToadGuard_Red_Idle, \
    .walk   = ANIM_ToadGuard_Red_Idle, \
    .run    = ANIM_ToadGuard_Red_Idle, \
    .chase  = ANIM_ToadGuard_Red_Idle, \
    .anim_4 = ANIM_ToadGuard_Red_Idle, \
    .anim_5 = ANIM_ToadGuard_Red_Idle, \
    .death  = ANIM_ToadGuard_Red_Idle, \
    .hit    = ANIM_ToadGuard_Red_Idle, \
    .anim_8 = ANIM_ToadGuard_Red_Idle, \
    .anim_9 = ANIM_ToadGuard_Red_Idle, \
    .anim_A = ANIM_ToadGuard_Red_Idle, \
    .anim_B = ANIM_ToadGuard_Red_Idle, \
    .anim_C = ANIM_ToadGuard_Red_Idle, \
    .anim_D = ANIM_ToadGuard_Red_Idle, \
    .anim_E = ANIM_ToadGuard_Red_Idle, \
    .anim_F = ANIM_ToadGuard_Red_Idle, \
}

#define TOAD_GUARD_GREEN_ANIMS \
{ \
    .idle   = ANIM_ToadGuard_Green_Idle, \
    .walk   = ANIM_ToadGuard_Green_Idle, \
    .run    = ANIM_ToadGuard_Green_Idle, \
    .chase  = ANIM_ToadGuard_Green_Idle, \
    .anim_4 = ANIM_ToadGuard_Green_Idle, \
    .anim_5 = ANIM_ToadGuard_Green_Idle, \
    .death  = ANIM_ToadGuard_Green_Idle, \
    .hit    = ANIM_ToadGuard_Green_Idle, \
    .anim_8 = ANIM_ToadGuard_Green_Idle, \
    .anim_9 = ANIM_ToadGuard_Green_Idle, \
    .anim_A = ANIM_ToadGuard_Green_Idle, \
    .anim_B = ANIM_ToadGuard_Green_Idle, \
    .anim_C = ANIM_ToadGuard_Green_Idle, \
    .anim_D = ANIM_ToadGuard_Green_Idle, \
    .anim_E = ANIM_ToadGuard_Green_Idle, \
    .anim_F = ANIM_ToadGuard_Green_Idle, \
}

#define TOAD_GUARD_BLUE_ANIMS \
{ \
    .idle   = ANIM_ToadGuard_Blue_Idle, \
    .walk   = ANIM_ToadGuard_Blue_Idle, \
    .run    = ANIM_ToadGuard_Blue_Idle, \
    .chase  = ANIM_ToadGuard_Blue_Idle, \
    .anim_4 = ANIM_ToadGuard_Blue_Idle, \
    .anim_5 = ANIM_ToadGuard_Blue_Idle, \
    .death  = ANIM_ToadGuard_Blue_Idle, \
    .hit    = ANIM_ToadGuard_Blue_Idle, \
    .anim_8 = ANIM_ToadGuard_Blue_Idle, \
    .anim_9 = ANIM_ToadGuard_Blue_Idle, \
    .anim_A = ANIM_ToadGuard_Blue_Idle, \
    .anim_B = ANIM_ToadGuard_Blue_Idle, \
    .anim_C = ANIM_ToadGuard_Blue_Idle, \
    .anim_D = ANIM_ToadGuard_Blue_Idle, \
    .anim_E = ANIM_ToadGuard_Blue_Idle, \
    .anim_F = ANIM_ToadGuard_Blue_Idle, \
}

#define TOAD_GUARD_YELLOW_ANIMS \
{ \
    .idle   = ANIM_ToadGuard_Yellow_Idle, \
    .walk   = ANIM_ToadGuard_Yellow_Idle, \
    .run    = ANIM_ToadGuard_Yellow_Idle, \
    .chase  = ANIM_ToadGuard_Yellow_Idle, \
    .anim_4 = ANIM_ToadGuard_Yellow_Idle, \
    .anim_5 = ANIM_ToadGuard_Yellow_Idle, \
    .death  = ANIM_ToadGuard_Yellow_Idle, \
    .hit    = ANIM_ToadGuard_Yellow_Idle, \
    .anim_8 = ANIM_ToadGuard_Yellow_Idle, \
    .anim_9 = ANIM_ToadGuard_Yellow_Idle, \
    .anim_A = ANIM_ToadGuard_Yellow_Idle, \
    .anim_B = ANIM_ToadGuard_Yellow_Idle, \
    .anim_C = ANIM_ToadGuard_Yellow_Idle, \
    .anim_D = ANIM_ToadGuard_Yellow_Idle, \
    .anim_E = ANIM_ToadGuard_Yellow_Idle, \
    .anim_F = ANIM_ToadGuard_Yellow_Idle, \
}

#define TOAD_MINISTER_ANIMS \
{ \
    .idle   = ANIM_ToadMinister_Idle, \
    .walk   = ANIM_ToadMinister_Idle, \
    .run    = ANIM_ToadMinister_Idle, \
    .chase  = ANIM_ToadMinister_Idle, \
    .anim_4 = ANIM_ToadMinister_Idle, \
    .anim_5 = ANIM_ToadMinister_Idle, \
    .death  = ANIM_ToadMinister_Idle, \
    .hit    = ANIM_ToadMinister_Idle, \
    .anim_8 = ANIM_ToadMinister_Idle, \
    .anim_9 = ANIM_ToadMinister_Idle, \
    .anim_A = ANIM_ToadMinister_Idle, \
    .anim_B = ANIM_ToadMinister_Idle, \
    .anim_C = ANIM_ToadMinister_Idle, \
    .anim_D = ANIM_ToadMinister_Idle, \
    .anim_E = ANIM_ToadMinister_Idle, \
    .anim_F = ANIM_ToadMinister_Idle, \
}
