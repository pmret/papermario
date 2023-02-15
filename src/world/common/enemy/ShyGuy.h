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
    .idle   = ANIM_ShyGuy_Red_Anim01, \
    .walk   = ANIM_ShyGuy_Red_Anim02, \
    .run    = ANIM_ShyGuy_Red_Anim03, \
    .chase  = ANIM_ShyGuy_Red_Anim03, \
    .anim_4 = ANIM_ShyGuy_Red_Anim01, \
    .anim_5 = ANIM_ShyGuy_Red_Anim01, \
    .death  = ANIM_ShyGuy_Red_Anim0C, \
    .hit    = ANIM_ShyGuy_Red_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Red_Anim15, \
    .anim_9 = ANIM_ShyGuy_Red_Anim12, \
    .anim_A = ANIM_ShyGuy_Red_Anim11, \
    .anim_B = ANIM_ShyGuy_Red_Anim10, \
    .anim_C = ANIM_ShyGuy_Red_Anim05, \
    .anim_D = ANIM_ShyGuy_Red_Anim01, \
    .anim_E = ANIM_ShyGuy_Red_Anim01, \
    .anim_F = ANIM_ShyGuy_Red_Anim01, \
}

#define BLUE_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Blue_Anim01, \
    .walk   = ANIM_ShyGuy_Blue_Anim02, \
    .run    = ANIM_ShyGuy_Blue_Anim03, \
    .chase  = ANIM_ShyGuy_Blue_Anim03, \
    .anim_4 = ANIM_ShyGuy_Blue_Anim01, \
    .anim_5 = ANIM_ShyGuy_Blue_Anim01, \
    .death  = ANIM_ShyGuy_Blue_Anim0C, \
    .hit    = ANIM_ShyGuy_Blue_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Blue_Anim15, \
    .anim_9 = ANIM_ShyGuy_Blue_Anim12, \
    .anim_A = ANIM_ShyGuy_Blue_Anim11, \
    .anim_B = ANIM_ShyGuy_Blue_Anim10, \
    .anim_C = ANIM_ShyGuy_Blue_Anim05, \
    .anim_D = ANIM_ShyGuy_Blue_Anim01, \
    .anim_E = ANIM_ShyGuy_Blue_Anim01, \
    .anim_F = ANIM_ShyGuy_Blue_Anim01, \
}

#define GREEN_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Green_Anim01, \
    .walk   = ANIM_ShyGuy_Green_Anim02, \
    .run    = ANIM_ShyGuy_Green_Anim03, \
    .chase  = ANIM_ShyGuy_Green_Anim03, \
    .anim_4 = ANIM_ShyGuy_Green_Anim01, \
    .anim_5 = ANIM_ShyGuy_Green_Anim01, \
    .death  = ANIM_ShyGuy_Green_Anim0C, \
    .hit    = ANIM_ShyGuy_Green_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Green_Anim15, \
    .anim_9 = ANIM_ShyGuy_Green_Anim12, \
    .anim_A = ANIM_ShyGuy_Green_Anim11, \
    .anim_B = ANIM_ShyGuy_Green_Anim10, \
    .anim_C = ANIM_ShyGuy_Green_Anim05, \
    .anim_D = ANIM_ShyGuy_Green_Anim01, \
    .anim_E = ANIM_ShyGuy_Green_Anim01, \
    .anim_F = ANIM_ShyGuy_Green_Anim01, \
}

#define PINK_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Pink_Anim01, \
    .walk   = ANIM_ShyGuy_Pink_Anim02, \
    .run    = ANIM_ShyGuy_Pink_Anim03, \
    .chase  = ANIM_ShyGuy_Pink_Anim03, \
    .anim_4 = ANIM_ShyGuy_Pink_Anim01, \
    .anim_5 = ANIM_ShyGuy_Pink_Anim01, \
    .death  = ANIM_ShyGuy_Pink_Anim0C, \
    .hit    = ANIM_ShyGuy_Pink_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Pink_Anim15, \
    .anim_9 = ANIM_ShyGuy_Pink_Anim12, \
    .anim_A = ANIM_ShyGuy_Pink_Anim11, \
    .anim_B = ANIM_ShyGuy_Pink_Anim10, \
    .anim_C = ANIM_ShyGuy_Pink_Anim05, \
    .anim_D = ANIM_ShyGuy_Pink_Anim01, \
    .anim_E = ANIM_ShyGuy_Pink_Anim01, \
    .anim_F = ANIM_ShyGuy_Pink_Anim01, \
}

#define YELLOW_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Yellow_Anim01, \
    .walk   = ANIM_ShyGuy_Yellow_Anim02, \
    .run    = ANIM_ShyGuy_Yellow_Anim03, \
    .chase  = ANIM_ShyGuy_Yellow_Anim03, \
    .anim_4 = ANIM_ShyGuy_Yellow_Anim01, \
    .anim_5 = ANIM_ShyGuy_Yellow_Anim01, \
    .death  = ANIM_ShyGuy_Yellow_Anim0C, \
    .hit    = ANIM_ShyGuy_Yellow_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Yellow_Anim15, \
    .anim_9 = ANIM_ShyGuy_Yellow_Anim12, \
    .anim_A = ANIM_ShyGuy_Yellow_Anim11, \
    .anim_B = ANIM_ShyGuy_Yellow_Anim10, \
    .anim_C = ANIM_ShyGuy_Yellow_Anim05, \
    .anim_D = ANIM_ShyGuy_Yellow_Anim01, \
    .anim_E = ANIM_ShyGuy_Yellow_Anim01, \
    .anim_F = ANIM_ShyGuy_Yellow_Anim01, \
}

#define ANTI_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Black_Anim01, \
    .walk   = ANIM_ShyGuy_Black_Anim02, \
    .run    = ANIM_ShyGuy_Black_Anim03, \
    .chase  = ANIM_ShyGuy_Black_Anim02, \
    .anim_4 = ANIM_ShyGuy_Black_Anim01, \
    .anim_5 = ANIM_ShyGuy_Black_Anim01, \
    .death  = ANIM_ShyGuy_Black_Anim0C, \
    .hit    = ANIM_ShyGuy_Black_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Black_Anim15, \
    .anim_9 = ANIM_ShyGuy_Black_Anim12, \
    .anim_A = ANIM_ShyGuy_Black_Anim11, \
    .anim_B = ANIM_ShyGuy_Black_Anim10, \
    .anim_C = ANIM_ShyGuy_Black_Anim05, \
    .anim_D = ANIM_ShyGuy_Black_Anim01, \
    .anim_E = ANIM_ShyGuy_Black_Anim01, \
    .anim_F = ANIM_ShyGuy_Black_Anim01, \
}

// shy guys who avoid the player

#define RED_AVOID_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Red_Anim01, \
    .walk   = ANIM_ShyGuy_Red_Anim02, \
    .run    = ANIM_ShyGuy_Red_Anim04, \
    .chase  = ANIM_ShyGuy_Red_Anim04, \
    .anim_4 = ANIM_ShyGuy_Red_Anim01, \
    .anim_5 = ANIM_ShyGuy_Red_Anim01, \
    .death  = ANIM_ShyGuy_Red_Anim0C, \
    .hit    = ANIM_ShyGuy_Red_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Red_Anim15, \
    .anim_9 = ANIM_ShyGuy_Red_Anim12, \
    .anim_A = ANIM_ShyGuy_Red_Anim11, \
    .anim_B = ANIM_ShyGuy_Red_Anim10, \
    .anim_C = ANIM_ShyGuy_Red_Anim05, \
    .anim_D = ANIM_ShyGuy_Red_Anim01, \
    .anim_E = ANIM_ShyGuy_Red_Anim01, \
    .anim_F = ANIM_ShyGuy_Red_Anim01, \
}

#define BLUE_AVOID_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Blue_Anim01, \
    .walk   = ANIM_ShyGuy_Blue_Anim02, \
    .run    = ANIM_ShyGuy_Blue_Anim04, \
    .chase  = ANIM_ShyGuy_Blue_Anim04, \
    .anim_4 = ANIM_ShyGuy_Blue_Anim01, \
    .anim_5 = ANIM_ShyGuy_Blue_Anim01, \
    .death  = ANIM_ShyGuy_Blue_Anim0C, \
    .hit    = ANIM_ShyGuy_Blue_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Blue_Anim15, \
    .anim_9 = ANIM_ShyGuy_Blue_Anim12, \
    .anim_A = ANIM_ShyGuy_Blue_Anim11, \
    .anim_B = ANIM_ShyGuy_Blue_Anim10, \
    .anim_C = ANIM_ShyGuy_Blue_Anim05, \
    .anim_D = ANIM_ShyGuy_Blue_Anim01, \
    .anim_E = ANIM_ShyGuy_Blue_Anim01, \
    .anim_F = ANIM_ShyGuy_Blue_Anim01, \
}

#define GREEN_AVOID_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Green_Anim01, \
    .walk   = ANIM_ShyGuy_Green_Anim02, \
    .run    = ANIM_ShyGuy_Green_Anim04, \
    .chase  = ANIM_ShyGuy_Green_Anim04, \
    .anim_4 = ANIM_ShyGuy_Green_Anim01, \
    .anim_5 = ANIM_ShyGuy_Green_Anim01, \
    .death  = ANIM_ShyGuy_Green_Anim0C, \
    .hit    = ANIM_ShyGuy_Green_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Green_Anim15, \
    .anim_9 = ANIM_ShyGuy_Green_Anim12, \
    .anim_A = ANIM_ShyGuy_Green_Anim11, \
    .anim_B = ANIM_ShyGuy_Green_Anim10, \
    .anim_C = ANIM_ShyGuy_Green_Anim05, \
    .anim_D = ANIM_ShyGuy_Green_Anim01, \
    .anim_E = ANIM_ShyGuy_Green_Anim01, \
    .anim_F = ANIM_ShyGuy_Green_Anim01, \
}

#define PINK_AVOID_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Pink_Anim01, \
    .walk   = ANIM_ShyGuy_Pink_Anim02, \
    .run    = ANIM_ShyGuy_Pink_Anim04, \
    .chase  = ANIM_ShyGuy_Pink_Anim04, \
    .anim_4 = ANIM_ShyGuy_Pink_Anim01, \
    .anim_5 = ANIM_ShyGuy_Pink_Anim01, \
    .death  = ANIM_ShyGuy_Pink_Anim0C, \
    .hit    = ANIM_ShyGuy_Pink_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Pink_Anim15, \
    .anim_9 = ANIM_ShyGuy_Pink_Anim12, \
    .anim_A = ANIM_ShyGuy_Pink_Anim11, \
    .anim_B = ANIM_ShyGuy_Pink_Anim10, \
    .anim_C = ANIM_ShyGuy_Pink_Anim05, \
    .anim_D = ANIM_ShyGuy_Pink_Anim01, \
    .anim_E = ANIM_ShyGuy_Pink_Anim01, \
    .anim_F = ANIM_ShyGuy_Pink_Anim01, \
}

#define YELLOW_AVOID_SHY_GUY_ANIMS \
{ \
    .idle   = ANIM_ShyGuy_Yellow_Anim01, \
    .walk   = ANIM_ShyGuy_Yellow_Anim02, \
    .run    = ANIM_ShyGuy_Yellow_Anim04, \
    .chase  = ANIM_ShyGuy_Yellow_Anim04, \
    .anim_4 = ANIM_ShyGuy_Yellow_Anim01, \
    .anim_5 = ANIM_ShyGuy_Yellow_Anim01, \
    .death  = ANIM_ShyGuy_Yellow_Anim0C, \
    .hit    = ANIM_ShyGuy_Yellow_Anim0C, \
    .anim_8 = ANIM_ShyGuy_Yellow_Anim15, \
    .anim_9 = ANIM_ShyGuy_Yellow_Anim12, \
    .anim_A = ANIM_ShyGuy_Yellow_Anim11, \
    .anim_B = ANIM_ShyGuy_Yellow_Anim10, \
    .anim_C = ANIM_ShyGuy_Yellow_Anim05, \
    .anim_D = ANIM_ShyGuy_Yellow_Anim01, \
    .anim_E = ANIM_ShyGuy_Yellow_Anim01, \
    .anim_F = ANIM_ShyGuy_Yellow_Anim01, \
}
