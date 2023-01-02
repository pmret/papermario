#include "kpa_111.h"

#include "world/common/enemy/complete/DryBones.inc.c"

StaticNpc N(NpcData_DryBones)[] = {
    {
        .id = NPC_DryBones_01,
        .settings = &N(NpcSettings_DryBones),
        .pos = { -10.0f, 0.0f, 100.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_800,
        .drops = DRY_BONES_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -10, 0, 100 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -10, 0, 100 },
                .detectSize = { 180 },
            }
        },
        .animations = DRY_BONES_ANIMS,
    },
    DRY_BONES_BONE_HITBOX(NPC_DryBones_01 + 1),
    DRY_BONES_BONE_HITBOX(NPC_DryBones_01 + 2),
    DRY_BONES_BONE_HITBOX(NPC_DryBones_01 + 3),
};

StaticNpc N(NpcData_DryBones_02)[] = {
    {
        .id = NPC_DryBones_02,
        .settings = &N(NpcSettings_DryBones),
        .pos = { 200.0f, 0.0f, 140.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_800,
        .drops = DRY_BONES_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 200, 0, 140 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 200, 0, 140 },
                .detectSize = { 180 },
            }
        },
        .animations = DRY_BONES_ANIMS,
    },
    DRY_BONES_BONE_HITBOX(NPC_DryBones_02 + 1),
    DRY_BONES_BONE_HITBOX(NPC_DryBones_02 + 2),
    DRY_BONES_BONE_HITBOX(NPC_DryBones_02 + 3),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_DryBones), BTL_KPA_FORMATION_07, BTL_KPA_STAGE_0C),
    NPC_GROUP(N(NpcData_DryBones_02), BTL_KPA_FORMATION_0C, BTL_KPA_STAGE_0C),
    {}
};
