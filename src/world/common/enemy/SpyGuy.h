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
    .idle   = ANIM_SpyGuy_IdleSling, \
    .walk   = ANIM_SpyGuy_WalkSling, \
    .run    = ANIM_SpyGuy_RunSling, \
    .chase  = ANIM_SpyGuy_WalkSling, \
    .anim_4 = ANIM_SpyGuy_IdleSling, \
    .anim_5 = ANIM_SpyGuy_IdleSling, \
    .death  = ANIM_SpyGuy_Hurt, \
    .hit    = ANIM_SpyGuy_Hurt, \
    .anim_8 = ANIM_SpyGuy_DrawSling, \
    .anim_9 = ANIM_SpyGuy_FireSling, \
    .anim_A = ANIM_SpyGuy_IdleSling, \
    .anim_B = ANIM_SpyGuy_IdleSling, \
    .anim_C = ANIM_SpyGuy_IdleSling, \
    .anim_D = ANIM_SpyGuy_IdleSling, \
    .anim_E = ANIM_SpyGuy_IdleSling, \
    .anim_F = ANIM_SpyGuy_IdleSling, \
}

#define SPY_GUY_ROCK_ANIMS \
{ \
    .idle   = ANIM_SpyGuy_Stone, \
    .walk   = ANIM_SpyGuy_Stone, \
    .run    = ANIM_SpyGuy_Stone, \
    .chase  = ANIM_SpyGuy_Stone, \
    .anim_4 = ANIM_SpyGuy_Stone, \
    .anim_5 = ANIM_SpyGuy_Stone, \
    .death  = ANIM_SpyGuy_Stone, \
    .hit    = ANIM_SpyGuy_Stone, \
    .anim_8 = ANIM_SpyGuy_Stone, \
    .anim_9 = ANIM_SpyGuy_Stone, \
    .anim_A = ANIM_SpyGuy_Stone, \
    .anim_B = ANIM_SpyGuy_Stone, \
    .anim_C = ANIM_SpyGuy_Stone, \
    .anim_D = ANIM_SpyGuy_Stone, \
    .anim_E = ANIM_SpyGuy_Stone, \
    .anim_F = ANIM_SpyGuy_Stone, \
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
            .isFlying = true, \
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
