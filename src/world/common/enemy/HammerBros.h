#include "common.h"
#include "sprite/npc/HammerBros.h"

#define HAMMER_BROS_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 5, 0 }, \
        { ITEM_MAPLE_SYRUP, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(4), \
    .flowerDrops = STANDARD_FLOWER_DROPS(3), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define HAMMER_BROS_ANIMS \
{ \
    .idle   = ANIM_HammerBros_Idle, \
    .walk   = ANIM_HammerBros_Walk, \
    .run    = ANIM_HammerBros_Run, \
    .chase  = ANIM_HammerBros_Run, \
    .anim_4 = ANIM_HammerBros_Idle, \
    .anim_5 = ANIM_HammerBros_Idle, \
    .death  = ANIM_HammerBros_Hurt, \
    .hit    = ANIM_HammerBros_Hurt, \
    .anim_8 = ANIM_HammerBros_WorldAim, \
    .anim_9 = ANIM_HammerBros_WorldThrow, \
    .anim_A = ANIM_HammerBros_Idle, \
    .anim_B = ANIM_HammerBros_Idle, \
    .anim_C = ANIM_HammerBros_Idle, \
    .anim_D = ANIM_HammerBros_Idle, \
    .anim_E = ANIM_HammerBros_Idle, \
    .anim_F = ANIM_HammerBros_Idle, \
}

#define HAMMER_BROS_HAMMER_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_HammerBros_Hammer), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 90, \
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
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
    .animations = { \
        .idle   = ANIM_HammerBros_Hammer, \
        .walk   = ANIM_HammerBros_Hammer, \
        .run    = ANIM_HammerBros_Hammer, \
        .chase  = ANIM_HammerBros_Hammer, \
        .anim_4 = ANIM_HammerBros_Hammer, \
        .anim_5 = ANIM_HammerBros_Hammer, \
        .death  = ANIM_HammerBros_Hammer, \
        .hit    = ANIM_HammerBros_Hammer, \
        .anim_8 = ANIM_HammerBros_Hammer, \
        .anim_9 = ANIM_HammerBros_Hammer, \
        .anim_A = ANIM_HammerBros_Hammer, \
        .anim_B = ANIM_HammerBros_Hammer, \
        .anim_C = ANIM_HammerBros_Hammer, \
        .anim_D = ANIM_HammerBros_Hammer, \
        .anim_E = ANIM_HammerBros_Hammer, \
        .anim_F = ANIM_HammerBros_Hammer, \
    }, \
    .extraAnimations = N(ExtraAnims_HammerBros_Hammer), \
}
