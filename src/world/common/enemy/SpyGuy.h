#include "common.h"
#include "sprite/npc/SpyGuy.h"

#define SPY_GUY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_FIRE_FLOWER, 2, 0 }, \
        { ITEM_THUNDER_RAGE, 2, 0 }, \
        { ITEM_THUNDER_BOLT, 2, 0 }, \
        { ITEM_DUSTY_HAMMER, 2, 0 }, \
        { ITEM_PEBBLE, 2, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define SPY_GUY_ANIMS \
{ \
    .idle   = ANIM_SpyGuy_Anim02, \
    .walk   = ANIM_SpyGuy_Anim04, \
    .run    = ANIM_SpyGuy_Anim05, \
    .chase  = ANIM_SpyGuy_Anim04, \
    .anim_4 = ANIM_SpyGuy_Anim02, \
    .anim_5 = ANIM_SpyGuy_Anim02, \
    .death  = ANIM_SpyGuy_Anim0B, \
    .hit    = ANIM_SpyGuy_Anim0B, \
    .anim_8 = ANIM_SpyGuy_Anim15, \
    .anim_9 = ANIM_SpyGuy_Anim16, \
    .anim_A = ANIM_SpyGuy_Anim02, \
    .anim_B = ANIM_SpyGuy_Anim02, \
    .anim_C = ANIM_SpyGuy_Anim02, \
    .anim_D = ANIM_SpyGuy_Anim02, \
    .anim_E = ANIM_SpyGuy_Anim02, \
    .anim_F = ANIM_SpyGuy_Anim02, \
}

#define SPY_GUY_ROCK_ANIMS \
{ \
    .idle   = ANIM_SpyGuy_Anim10, \
    .walk   = ANIM_SpyGuy_Anim10, \
    .run    = ANIM_SpyGuy_Anim10, \
    .chase  = ANIM_SpyGuy_Anim10, \
    .anim_4 = ANIM_SpyGuy_Anim10, \
    .anim_5 = ANIM_SpyGuy_Anim10, \
    .death  = ANIM_SpyGuy_Anim10, \
    .hit    = ANIM_SpyGuy_Anim10, \
    .anim_8 = ANIM_SpyGuy_Anim10, \
    .anim_9 = ANIM_SpyGuy_Anim10, \
    .anim_A = ANIM_SpyGuy_Anim10, \
    .anim_B = ANIM_SpyGuy_Anim10, \
    .anim_C = ANIM_SpyGuy_Anim10, \
    .anim_D = ANIM_SpyGuy_Anim10, \
    .anim_E = ANIM_SpyGuy_Anim10, \
    .anim_F = ANIM_SpyGuy_Anim10, \
}

#define SPY_GUY_ROCK_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_SpyGuyRock), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 90, \
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .territory = { \
        .wander = { \
            .isFlying = TRUE, \
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED, \
            .wanderShape = SHAPE_CYLINDER, \
            .centerPos  = { NPC_DISPOSE_LOCATION }, \
            .wanderSize = { 0 }, \
            .detectShape = SHAPE_CYLINDER, \
            .detectPos  = { NPC_DISPOSE_LOCATION }, \
            .detectSize = { 0 }, \
        } \
    }, \
    .animations = SPY_GUY_ROCK_ANIMS, \
}
