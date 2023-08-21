#include "kpa_09.h"

#include "world/common/enemy/DryBones.inc.c"

NpcData N(NpcData_DryBones)[] = {
    {
        .id = NPC_DryBones,
        .pos = { -73.0f, 0.0f, 0.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -73, 0, 0 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -73, 0, 0 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_DryBones),
        .flags = ENEMY_FLAG_FLYING,
        .drops = DRY_BONES_DROPS,
        .animations = DRY_BONES_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    DRY_BONES_BONE_HITBOX(NPC_DryBones_Bone1),
    DRY_BONES_BONE_HITBOX(NPC_DryBones_Bone2),
    DRY_BONES_BONE_HITBOX(NPC_DryBones_Bone3),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_DryBones), BTL_KPA_FORMATION_0B, BTL_KPA_STAGE_01),
    {}
};
