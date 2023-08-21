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
    .idle   = ANIM_HammerBros_Anim02, \
    .walk   = ANIM_HammerBros_Anim04, \
    .run    = ANIM_HammerBros_Anim07, \
    .chase  = ANIM_HammerBros_Anim07, \
    .anim_4 = ANIM_HammerBros_Anim02, \
    .anim_5 = ANIM_HammerBros_Anim02, \
    .death  = ANIM_HammerBros_Anim0E, \
    .hit    = ANIM_HammerBros_Anim0E, \
    .anim_8 = ANIM_HammerBros_Anim18, \
    .anim_9 = ANIM_HammerBros_Anim19, \
    .anim_A = ANIM_HammerBros_Anim02, \
    .anim_B = ANIM_HammerBros_Anim02, \
    .anim_C = ANIM_HammerBros_Anim02, \
    .anim_D = ANIM_HammerBros_Anim02, \
    .anim_E = ANIM_HammerBros_Anim02, \
    .anim_F = ANIM_HammerBros_Anim02, \
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
    .animations = { \
        .idle   = ANIM_HammerBros_Anim0D, \
        .walk   = ANIM_HammerBros_Anim0D, \
        .run    = ANIM_HammerBros_Anim0D, \
        .chase  = ANIM_HammerBros_Anim0D, \
        .anim_4 = ANIM_HammerBros_Anim0D, \
        .anim_5 = ANIM_HammerBros_Anim0D, \
        .death  = ANIM_HammerBros_Anim0D, \
        .hit    = ANIM_HammerBros_Anim0D, \
        .anim_8 = ANIM_HammerBros_Anim0D, \
        .anim_9 = ANIM_HammerBros_Anim0D, \
        .anim_A = ANIM_HammerBros_Anim0D, \
        .anim_B = ANIM_HammerBros_Anim0D, \
        .anim_C = ANIM_HammerBros_Anim0D, \
        .anim_D = ANIM_HammerBros_Anim0D, \
        .anim_E = ANIM_HammerBros_Anim0D, \
        .anim_F = ANIM_HammerBros_Anim0D, \
    }, \
    .extraAnimations = N(ExtraAnims_HammerBros_Hammer), \
}
