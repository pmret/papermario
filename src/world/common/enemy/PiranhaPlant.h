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
    .idle   = ANIM_SmallPiranha_Idle, \
    .walk   = ANIM_SmallPiranha_Idle, \
    .run    = ANIM_SmallPiranha_Idle, \
    .chase  = ANIM_SmallPiranha_Idle, \
    .anim_4 = ANIM_SmallPiranha_Idle, \
    .anim_5 = ANIM_SmallPiranha_Idle, \
    .death  = ANIM_SmallPiranha_Hurt, \
    .hit    = ANIM_SmallPiranha_Hurt, \
    .anim_8 = ANIM_SmallPiranha_Burrow, \
    .anim_9 = ANIM_SmallPiranha_Emerge, \
    .anim_A = ANIM_SmallPiranha_BiteSide, \
    .anim_B = ANIM_SmallPiranha_BiteSide, \
    .anim_C = ANIM_SmallPiranha_ResetSide, \
    .anim_D = ANIM_SmallPiranha_Idle, \
    .anim_E = ANIM_SmallPiranha_Idle, \
    .anim_F = ANIM_SmallPiranha_Idle, \
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
        .idle   = ANIM_SmallPiranha_Idle, \
        .walk   = ANIM_SmallPiranha_Idle, \
        .run    = ANIM_SmallPiranha_Idle, \
        .chase  = ANIM_SmallPiranha_Idle, \
        .anim_4 = ANIM_SmallPiranha_Idle, \
        .anim_5 = ANIM_SmallPiranha_Idle, \
        .death  = ANIM_SmallPiranha_Hurt, \
        .hit    = ANIM_SmallPiranha_Hurt, \
        .anim_8 = ANIM_SmallPiranha_Burrow, \
        .anim_9 = ANIM_SmallPiranha_Emerge, \
        .anim_A = ANIM_SmallPiranha_BiteSide, \
        .anim_B = ANIM_SmallPiranha_BiteSide, \
        .anim_C = ANIM_SmallPiranha_ResetSide, \
        .anim_D = ANIM_SmallPiranha_Idle, \
        .anim_E = ANIM_SmallPiranha_Idle, \
        .anim_F = ANIM_SmallPiranha_Idle, \
    }, \
}
