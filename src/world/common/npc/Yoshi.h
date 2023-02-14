#include "common.h"

#include "sprite/npc/Yoshi.h"
#include "sprite/npc/VillageLeader.h"
#include "sprite/npc/LeadersFriend.h"

#define YOSHI_GREEN_ANIMS \
{ \
    .idle   = ANIM_Yoshi_Green_Idle, \
    .walk   = ANIM_Yoshi_Green_Walk, \
    .run    = ANIM_Yoshi_Green_Idle, \
    .chase  = ANIM_Yoshi_Green_Idle, \
    .anim_4 = ANIM_Yoshi_Green_Idle, \
    .anim_5 = ANIM_Yoshi_Green_Idle, \
    .death  = ANIM_Yoshi_Green_Idle, \
    .hit    = ANIM_Yoshi_Green_Idle, \
    .anim_8 = ANIM_Yoshi_Green_Idle, \
    .anim_9 = ANIM_Yoshi_Green_Idle, \
    .anim_A = ANIM_Yoshi_Green_Idle, \
    .anim_B = ANIM_Yoshi_Green_Idle, \
    .anim_C = ANIM_Yoshi_Green_Idle, \
    .anim_D = ANIM_Yoshi_Green_Idle, \
    .anim_E = ANIM_Yoshi_Green_Idle, \
    .anim_F = ANIM_Yoshi_Green_Idle, \
}

#define YOSHI_BLUE_ANIMS \
{ \
    .idle   = ANIM_Yoshi_Blue_Idle, \
    .walk   = ANIM_Yoshi_Blue_Walk, \
    .run    = ANIM_Yoshi_Blue_Idle, \
    .chase  = ANIM_Yoshi_Blue_Idle, \
    .anim_4 = ANIM_Yoshi_Blue_Idle, \
    .anim_5 = ANIM_Yoshi_Blue_Idle, \
    .death  = ANIM_Yoshi_Blue_Idle, \
    .hit    = ANIM_Yoshi_Blue_Idle, \
    .anim_8 = ANIM_Yoshi_Blue_Idle, \
    .anim_9 = ANIM_Yoshi_Blue_Idle, \
    .anim_A = ANIM_Yoshi_Blue_Idle, \
    .anim_B = ANIM_Yoshi_Blue_Idle, \
    .anim_C = ANIM_Yoshi_Blue_Idle, \
    .anim_D = ANIM_Yoshi_Blue_Idle, \
    .anim_E = ANIM_Yoshi_Blue_Idle, \
    .anim_F = ANIM_Yoshi_Blue_Idle, \
}

#define YOSHI_PURPLE_ANIMS \
{ \
    .idle   = ANIM_Yoshi_Purple_Idle, \
    .walk   = ANIM_Yoshi_Purple_Walk, \
    .run    = ANIM_Yoshi_Purple_Idle, \
    .chase  = ANIM_Yoshi_Purple_Idle, \
    .anim_4 = ANIM_Yoshi_Purple_Idle, \
    .anim_5 = ANIM_Yoshi_Purple_Idle, \
    .death  = ANIM_Yoshi_Purple_Idle, \
    .hit    = ANIM_Yoshi_Purple_Idle, \
    .anim_8 = ANIM_Yoshi_Purple_Idle, \
    .anim_9 = ANIM_Yoshi_Purple_Idle, \
    .anim_A = ANIM_Yoshi_Purple_Idle, \
    .anim_B = ANIM_Yoshi_Purple_Idle, \
    .anim_C = ANIM_Yoshi_Purple_Idle, \
    .anim_D = ANIM_Yoshi_Purple_Idle, \
    .anim_E = ANIM_Yoshi_Purple_Idle, \
    .anim_F = ANIM_Yoshi_Purple_Idle, \
}

#define YOSHI_YELLOW_ANIMS \
{ \
    .idle   = ANIM_Yoshi_Yellow_Idle, \
    .walk   = ANIM_Yoshi_Yellow_Walk, \
    .run    = ANIM_Yoshi_Yellow_Idle, \
    .chase  = ANIM_Yoshi_Yellow_Idle, \
    .anim_4 = ANIM_Yoshi_Yellow_Idle, \
    .anim_5 = ANIM_Yoshi_Yellow_Idle, \
    .death  = ANIM_Yoshi_Yellow_Idle, \
    .hit    = ANIM_Yoshi_Yellow_Idle, \
    .anim_8 = ANIM_Yoshi_Yellow_Idle, \
    .anim_9 = ANIM_Yoshi_Yellow_Idle, \
    .anim_A = ANIM_Yoshi_Yellow_Idle, \
    .anim_B = ANIM_Yoshi_Yellow_Idle, \
    .anim_C = ANIM_Yoshi_Yellow_Idle, \
    .anim_D = ANIM_Yoshi_Yellow_Idle, \
    .anim_E = ANIM_Yoshi_Yellow_Idle, \
    .anim_F = ANIM_Yoshi_Yellow_Idle, \
}

#define YOSHI_RED_ANIMS \
{ \
    .idle   = ANIM_Yoshi_Red_Idle, \
    .walk   = ANIM_Yoshi_Red_Walk, \
    .run    = ANIM_Yoshi_Red_Idle, \
    .chase  = ANIM_Yoshi_Red_Idle, \
    .anim_4 = ANIM_Yoshi_Red_Idle, \
    .anim_5 = ANIM_Yoshi_Red_Idle, \
    .death  = ANIM_Yoshi_Red_Idle, \
    .hit    = ANIM_Yoshi_Red_Idle, \
    .anim_8 = ANIM_Yoshi_Red_Idle, \
    .anim_9 = ANIM_Yoshi_Red_Idle, \
    .anim_A = ANIM_Yoshi_Red_Idle, \
    .anim_B = ANIM_Yoshi_Red_Idle, \
    .anim_C = ANIM_Yoshi_Red_Idle, \
    .anim_D = ANIM_Yoshi_Red_Idle, \
    .anim_E = ANIM_Yoshi_Red_Idle, \
    .anim_F = ANIM_Yoshi_Red_Idle, \
}

#define YOSHI_LEADER_ANIMS \
{ \
    .idle   = ANIM_VillageLeader_Idle, \
    .walk   = ANIM_VillageLeader_Idle, \
    .run    = ANIM_VillageLeader_Idle, \
    .chase  = ANIM_VillageLeader_Idle, \
    .anim_4 = ANIM_VillageLeader_Idle, \
    .anim_5 = ANIM_VillageLeader_Idle, \
    .death  = ANIM_VillageLeader_Idle, \
    .hit    = ANIM_VillageLeader_Idle, \
    .anim_8 = ANIM_VillageLeader_Idle, \
    .anim_9 = ANIM_VillageLeader_Idle, \
    .anim_A = ANIM_VillageLeader_Idle, \
    .anim_B = ANIM_VillageLeader_Idle, \
    .anim_C = ANIM_VillageLeader_Idle, \
    .anim_D = ANIM_VillageLeader_Idle, \
    .anim_E = ANIM_VillageLeader_Idle, \
    .anim_F = ANIM_VillageLeader_Idle, \
}

#define YOSHI_COUNCILLOR_ANIMS \
{ \
    .idle   = ANIM_LeadersFriend_Idle, \
    .walk   = ANIM_LeadersFriend_Idle, \
    .run    = ANIM_LeadersFriend_Idle, \
    .chase  = ANIM_LeadersFriend_Idle, \
    .anim_4 = ANIM_LeadersFriend_Idle, \
    .anim_5 = ANIM_LeadersFriend_Idle, \
    .death  = ANIM_LeadersFriend_Idle, \
    .hit    = ANIM_LeadersFriend_Idle, \
    .anim_8 = ANIM_LeadersFriend_Idle, \
    .anim_9 = ANIM_LeadersFriend_Idle, \
    .anim_A = ANIM_LeadersFriend_Idle, \
    .anim_B = ANIM_LeadersFriend_Idle, \
    .anim_C = ANIM_LeadersFriend_Idle, \
    .anim_D = ANIM_LeadersFriend_Idle, \
    .anim_E = ANIM_LeadersFriend_Idle, \
    .anim_F = ANIM_LeadersFriend_Idle, \
}
