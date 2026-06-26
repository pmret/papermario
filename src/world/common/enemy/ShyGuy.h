#include "common.h"
#include "sprite/npc/ShyGuy.h"

#define SHY_GUY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_DIZZY_DIAL, 2, 0 }, \
        { ITEM_SUPER_SHROOM, 2, 0 }, \
        { ITEM_THUNDER_BOLT, 2, 0 }, \
        { ITEM_DRIED_SHROOM, 2, 0 }, \
        { ITEM_SLEEPY_SHEEP, 2, 0 }, \
        { ITEM_POW_BLOCK, 2, 0 }, \
        { ITEM_FRIGHT_JAR, 2, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

// standard shy guys

#define RED_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Red_Idle, \
    .walk   = ANIM_ShyGuy_Red_Walk, \
    .run    = ANIM_ShyGuy_Red_Run, \
    .chase  = ANIM_ShyGuy_Red_Run, \
    .anim_4 = ANIM_ShyGuy_Red_Idle, \
    .anim_5 = ANIM_ShyGuy_Red_Idle, \
    .death  = ANIM_ShyGuy_Red_Hurt, \
    .hit    = ANIM_ShyGuy_Red_Hurt, \
    .anim_8 = ANIM_ShyGuy_Red_Hiding, \
    .anim_9 = ANIM_ShyGuy_Red_Slouch, \
    .anim_A = ANIM_ShyGuy_Red_Excited, \
    .anim_B = ANIM_ShyGuy_Red_Crashed, \
    .anim_C = ANIM_ShyGuy_Red_Tackle, \
    .anim_D = ANIM_ShyGuy_Red_Idle, \
    .anim_E = ANIM_ShyGuy_Red_Idle, \
    .anim_F = ANIM_ShyGuy_Red_Idle, \
}

#define BLUE_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Blue_Idle, \
    .walk   = ANIM_ShyGuy_Blue_Walk, \
    .run    = ANIM_ShyGuy_Blue_Run, \
    .chase  = ANIM_ShyGuy_Blue_Run, \
    .anim_4 = ANIM_ShyGuy_Blue_Idle, \
    .anim_5 = ANIM_ShyGuy_Blue_Idle, \
    .death  = ANIM_ShyGuy_Blue_Hurt, \
    .hit    = ANIM_ShyGuy_Blue_Hurt, \
    .anim_8 = ANIM_ShyGuy_Blue_Hiding, \
    .anim_9 = ANIM_ShyGuy_Blue_Slouch, \
    .anim_A = ANIM_ShyGuy_Blue_Excited, \
    .anim_B = ANIM_ShyGuy_Blue_Crashed, \
    .anim_C = ANIM_ShyGuy_Blue_Tackle, \
    .anim_D = ANIM_ShyGuy_Blue_Idle, \
    .anim_E = ANIM_ShyGuy_Blue_Idle, \
    .anim_F = ANIM_ShyGuy_Blue_Idle, \
}

#define GREEN_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Green_Idle, \
    .walk   = ANIM_ShyGuy_Green_Walk, \
    .run    = ANIM_ShyGuy_Green_Run, \
    .chase  = ANIM_ShyGuy_Green_Run, \
    .anim_4 = ANIM_ShyGuy_Green_Idle, \
    .anim_5 = ANIM_ShyGuy_Green_Idle, \
    .death  = ANIM_ShyGuy_Green_Hurt, \
    .hit    = ANIM_ShyGuy_Green_Hurt, \
    .anim_8 = ANIM_ShyGuy_Green_Hiding, \
    .anim_9 = ANIM_ShyGuy_Green_Slouch, \
    .anim_A = ANIM_ShyGuy_Green_Excited, \
    .anim_B = ANIM_ShyGuy_Green_Crashed, \
    .anim_C = ANIM_ShyGuy_Green_Tackle, \
    .anim_D = ANIM_ShyGuy_Green_Idle, \
    .anim_E = ANIM_ShyGuy_Green_Idle, \
    .anim_F = ANIM_ShyGuy_Green_Idle, \
}

#define PINK_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Pink_Idle, \
    .walk   = ANIM_ShyGuy_Pink_Walk, \
    .run    = ANIM_ShyGuy_Pink_Run, \
    .chase  = ANIM_ShyGuy_Pink_Run, \
    .anim_4 = ANIM_ShyGuy_Pink_Idle, \
    .anim_5 = ANIM_ShyGuy_Pink_Idle, \
    .death  = ANIM_ShyGuy_Pink_Hurt, \
    .hit    = ANIM_ShyGuy_Pink_Hurt, \
    .anim_8 = ANIM_ShyGuy_Pink_Hiding, \
    .anim_9 = ANIM_ShyGuy_Pink_Slouch, \
    .anim_A = ANIM_ShyGuy_Pink_Excited, \
    .anim_B = ANIM_ShyGuy_Pink_Crashed, \
    .anim_C = ANIM_ShyGuy_Pink_Tackle, \
    .anim_D = ANIM_ShyGuy_Pink_Idle, \
    .anim_E = ANIM_ShyGuy_Pink_Idle, \
    .anim_F = ANIM_ShyGuy_Pink_Idle, \
}

#define YELLOW_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Yellow_Idle, \
    .walk   = ANIM_ShyGuy_Yellow_Walk, \
    .run    = ANIM_ShyGuy_Yellow_Run, \
    .chase  = ANIM_ShyGuy_Yellow_Run, \
    .anim_4 = ANIM_ShyGuy_Yellow_Idle, \
    .anim_5 = ANIM_ShyGuy_Yellow_Idle, \
    .death  = ANIM_ShyGuy_Yellow_Hurt, \
    .hit    = ANIM_ShyGuy_Yellow_Hurt, \
    .anim_8 = ANIM_ShyGuy_Yellow_Hiding, \
    .anim_9 = ANIM_ShyGuy_Yellow_Slouch, \
    .anim_A = ANIM_ShyGuy_Yellow_Excited, \
    .anim_B = ANIM_ShyGuy_Yellow_Crashed, \
    .anim_C = ANIM_ShyGuy_Yellow_Tackle, \
    .anim_D = ANIM_ShyGuy_Yellow_Idle, \
    .anim_E = ANIM_ShyGuy_Yellow_Idle, \
    .anim_F = ANIM_ShyGuy_Yellow_Idle, \
}

#define ANTI_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Black_Idle, \
    .walk   = ANIM_ShyGuy_Black_Walk, \
    .run    = ANIM_ShyGuy_Black_Run, \
    .chase  = ANIM_ShyGuy_Black_Walk, \
    .anim_4 = ANIM_ShyGuy_Black_Idle, \
    .anim_5 = ANIM_ShyGuy_Black_Idle, \
    .death  = ANIM_ShyGuy_Black_Hurt, \
    .hit    = ANIM_ShyGuy_Black_Hurt, \
    .anim_8 = ANIM_ShyGuy_Black_Hiding, \
    .anim_9 = ANIM_ShyGuy_Black_Slouch, \
    .anim_A = ANIM_ShyGuy_Black_Excited, \
    .anim_B = ANIM_ShyGuy_Black_Crashed, \
    .anim_C = ANIM_ShyGuy_Black_Tackle, \
    .anim_D = ANIM_ShyGuy_Black_Idle, \
    .anim_E = ANIM_ShyGuy_Black_Idle, \
    .anim_F = ANIM_ShyGuy_Black_Idle, \
}

// shy guys who avoid the player

#define RED_AVOID_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Red_Idle, \
    .walk   = ANIM_ShyGuy_Red_Walk, \
    .run    = ANIM_ShyGuy_Red_Dash, \
    .chase  = ANIM_ShyGuy_Red_Dash, \
    .anim_4 = ANIM_ShyGuy_Red_Idle, \
    .anim_5 = ANIM_ShyGuy_Red_Idle, \
    .death  = ANIM_ShyGuy_Red_Hurt, \
    .hit    = ANIM_ShyGuy_Red_Hurt, \
    .anim_8 = ANIM_ShyGuy_Red_Hiding, \
    .anim_9 = ANIM_ShyGuy_Red_Slouch, \
    .anim_A = ANIM_ShyGuy_Red_Excited, \
    .anim_B = ANIM_ShyGuy_Red_Crashed, \
    .anim_C = ANIM_ShyGuy_Red_Tackle, \
    .anim_D = ANIM_ShyGuy_Red_Idle, \
    .anim_E = ANIM_ShyGuy_Red_Idle, \
    .anim_F = ANIM_ShyGuy_Red_Idle, \
}

#define BLUE_AVOID_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Blue_Idle, \
    .walk   = ANIM_ShyGuy_Blue_Walk, \
    .run    = ANIM_ShyGuy_Blue_Dash, \
    .chase  = ANIM_ShyGuy_Blue_Dash, \
    .anim_4 = ANIM_ShyGuy_Blue_Idle, \
    .anim_5 = ANIM_ShyGuy_Blue_Idle, \
    .death  = ANIM_ShyGuy_Blue_Hurt, \
    .hit    = ANIM_ShyGuy_Blue_Hurt, \
    .anim_8 = ANIM_ShyGuy_Blue_Hiding, \
    .anim_9 = ANIM_ShyGuy_Blue_Slouch, \
    .anim_A = ANIM_ShyGuy_Blue_Excited, \
    .anim_B = ANIM_ShyGuy_Blue_Crashed, \
    .anim_C = ANIM_ShyGuy_Blue_Tackle, \
    .anim_D = ANIM_ShyGuy_Blue_Idle, \
    .anim_E = ANIM_ShyGuy_Blue_Idle, \
    .anim_F = ANIM_ShyGuy_Blue_Idle, \
}

#define GREEN_AVOID_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Green_Idle, \
    .walk   = ANIM_ShyGuy_Green_Walk, \
    .run    = ANIM_ShyGuy_Green_Dash, \
    .chase  = ANIM_ShyGuy_Green_Dash, \
    .anim_4 = ANIM_ShyGuy_Green_Idle, \
    .anim_5 = ANIM_ShyGuy_Green_Idle, \
    .death  = ANIM_ShyGuy_Green_Hurt, \
    .hit    = ANIM_ShyGuy_Green_Hurt, \
    .anim_8 = ANIM_ShyGuy_Green_Hiding, \
    .anim_9 = ANIM_ShyGuy_Green_Slouch, \
    .anim_A = ANIM_ShyGuy_Green_Excited, \
    .anim_B = ANIM_ShyGuy_Green_Crashed, \
    .anim_C = ANIM_ShyGuy_Green_Tackle, \
    .anim_D = ANIM_ShyGuy_Green_Idle, \
    .anim_E = ANIM_ShyGuy_Green_Idle, \
    .anim_F = ANIM_ShyGuy_Green_Idle, \
}

#define PINK_AVOID_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Pink_Idle, \
    .walk   = ANIM_ShyGuy_Pink_Walk, \
    .run    = ANIM_ShyGuy_Pink_Dash, \
    .chase  = ANIM_ShyGuy_Pink_Dash, \
    .anim_4 = ANIM_ShyGuy_Pink_Idle, \
    .anim_5 = ANIM_ShyGuy_Pink_Idle, \
    .death  = ANIM_ShyGuy_Pink_Hurt, \
    .hit    = ANIM_ShyGuy_Pink_Hurt, \
    .anim_8 = ANIM_ShyGuy_Pink_Hiding, \
    .anim_9 = ANIM_ShyGuy_Pink_Slouch, \
    .anim_A = ANIM_ShyGuy_Pink_Excited, \
    .anim_B = ANIM_ShyGuy_Pink_Crashed, \
    .anim_C = ANIM_ShyGuy_Pink_Tackle, \
    .anim_D = ANIM_ShyGuy_Pink_Idle, \
    .anim_E = ANIM_ShyGuy_Pink_Idle, \
    .anim_F = ANIM_ShyGuy_Pink_Idle, \
}

#define YELLOW_AVOID_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Yellow_Idle, \
    .walk   = ANIM_ShyGuy_Yellow_Walk, \
    .run    = ANIM_ShyGuy_Yellow_Dash, \
    .chase  = ANIM_ShyGuy_Yellow_Dash, \
    .anim_4 = ANIM_ShyGuy_Yellow_Idle, \
    .anim_5 = ANIM_ShyGuy_Yellow_Idle, \
    .death  = ANIM_ShyGuy_Yellow_Hurt, \
    .hit    = ANIM_ShyGuy_Yellow_Hurt, \
    .anim_8 = ANIM_ShyGuy_Yellow_Hiding, \
    .anim_9 = ANIM_ShyGuy_Yellow_Slouch, \
    .anim_A = ANIM_ShyGuy_Yellow_Excited, \
    .anim_B = ANIM_ShyGuy_Yellow_Crashed, \
    .anim_C = ANIM_ShyGuy_Yellow_Tackle, \
    .anim_D = ANIM_ShyGuy_Yellow_Idle, \
    .anim_E = ANIM_ShyGuy_Yellow_Idle, \
    .anim_F = ANIM_ShyGuy_Yellow_Idle, \
}
