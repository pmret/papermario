#include "common.h"
#include "sprite/npc/DryBones.h"

#define DRY_BONES_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(4), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 4, \
}

#define DRY_BONES_ANIMS \
{ \
    .idle   = ANIM_DryBones_Anim02, \
    .walk   = ANIM_DryBones_Anim03, \
    .run    = ANIM_DryBones_Anim04, \
    .chase  = ANIM_DryBones_Anim04, \
    .anim_4 = ANIM_DryBones_Anim02, \
    .anim_5 = ANIM_DryBones_Anim02, \
    .death  = ANIM_DryBones_Anim07, \
    .hit    = ANIM_DryBones_Anim07, \
    .anim_8 = ANIM_DryBones_Anim05, \
    .anim_9 = ANIM_DryBones_Anim06, \
    .anim_A = ANIM_DryBones_Anim02, \
    .anim_B = ANIM_DryBones_Anim02, \
    .anim_C = ANIM_DryBones_Anim02, \
    .anim_D = ANIM_DryBones_Anim02, \
    .anim_E = ANIM_DryBones_Anim02, \
    .anim_F = ANIM_DryBones_Anim02, \
}

#define DRY_BONES_BONE_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_ThrownBone), \
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
    .animations = { \
        .idle   = ANIM_ThrownBone_Still, \
        .walk   = ANIM_ThrownBone_Still, \
        .run    = ANIM_ThrownBone_Still, \
        .chase  = ANIM_ThrownBone_Still, \
        .anim_4 = ANIM_ThrownBone_Still, \
        .anim_5 = ANIM_ThrownBone_Still, \
        .death  = ANIM_ThrownBone_Still, \
        .hit    = ANIM_ThrownBone_Still, \
        .anim_8 = ANIM_ThrownBone_Still, \
        .anim_9 = ANIM_ThrownBone_Still, \
        .anim_A = ANIM_ThrownBone_Still, \
        .anim_B = ANIM_ThrownBone_Still, \
        .anim_C = ANIM_ThrownBone_Still, \
        .anim_D = ANIM_ThrownBone_Still, \
        .anim_E = ANIM_ThrownBone_Still, \
        .anim_F = ANIM_ThrownBone_Still, \
    }, \
}
