#include "common.h"
#include "sprite/npc/SmallPiranha.h"

#define PIRANHA_PLANT_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_FIRE_FLOWER, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(3), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define PIRANHA_PLANT_ANIMS \
{ \
    .idle   = ANIM_SmallPiranha_Anim01, \
    .walk   = ANIM_SmallPiranha_Anim01, \
    .run    = ANIM_SmallPiranha_Anim01, \
    .chase  = ANIM_SmallPiranha_Anim01, \
    .anim_4 = ANIM_SmallPiranha_Anim01, \
    .anim_5 = ANIM_SmallPiranha_Anim01, \
    .death  = ANIM_SmallPiranha_Anim09, \
    .hit    = ANIM_SmallPiranha_Anim09, \
    .anim_8 = ANIM_SmallPiranha_Anim04, \
    .anim_9 = ANIM_SmallPiranha_Anim03, \
    .anim_A = ANIM_SmallPiranha_Anim07, \
    .anim_B = ANIM_SmallPiranha_Anim07, \
    .anim_C = ANIM_SmallPiranha_Anim08, \
    .anim_D = ANIM_SmallPiranha_Anim01, \
    .anim_E = ANIM_SmallPiranha_Anim01, \
    .anim_F = ANIM_SmallPiranha_Anim01, \
}

#define PIRANHA_PLANT_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_PiranhaPlant_Hitbox), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 0, \
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .animations = { \
        .idle   = ANIM_SmallPiranha_Anim01, \
        .walk   = ANIM_SmallPiranha_Anim01, \
        .run    = ANIM_SmallPiranha_Anim01, \
        .chase  = ANIM_SmallPiranha_Anim01, \
        .anim_4 = ANIM_SmallPiranha_Anim01, \
        .anim_5 = ANIM_SmallPiranha_Anim01, \
        .death  = ANIM_SmallPiranha_Anim09, \
        .hit    = ANIM_SmallPiranha_Anim09, \
        .anim_8 = ANIM_SmallPiranha_Anim04, \
        .anim_9 = ANIM_SmallPiranha_Anim03, \
        .anim_A = ANIM_SmallPiranha_Anim07, \
        .anim_B = ANIM_SmallPiranha_Anim07, \
        .anim_C = ANIM_SmallPiranha_Anim08, \
        .anim_D = ANIM_SmallPiranha_Anim01, \
        .anim_E = ANIM_SmallPiranha_Anim01, \
        .anim_F = ANIM_SmallPiranha_Anim01, \
    }, \
}
