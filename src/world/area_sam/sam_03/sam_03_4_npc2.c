#include "sam_03.h"

#include "world/common/enemy/Gulpit.inc.c"

NpcData N(NpcData_Gulpit_01)[] = {
    {
        .id = NPC_Gulpit_01,
        .pos = { -345.0f, 0.0f, 115.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -345, 0, 115 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -345, 0, 115 },
                .detectSize = { 250 },
            }
        },
        .settings = &N(NpcSettings_Gulpit),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = GULPIT_DROPS,
        .animations = GULPIT_ANIMS,
        .extraAnimations = N(ExtraAnims_Gulpit),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    GULPIT_HITBOX(NPC_Gulpit_01_Hitbox),
};

NpcData N(NpcData_Gulpit_02)[] = {
    {
        .id = NPC_Gulpit_02,
        .pos = { 200.0f, 0.0f, 0.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 200, 0, 0 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 200, 0, 0 },
                .detectSize = { 250 },
            }
        },
        .settings = &N(NpcSettings_Gulpit),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = GULPIT_DROPS,
        .animations = GULPIT_ANIMS,
        .extraAnimations = N(ExtraAnims_Gulpit),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    GULPIT_HITBOX(NPC_Gulpit_02_Hitbox),
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_Gulpit_01), BTL_SAM_FORMATION_01, BTL_SAM_STAGE_00),
    NPC_GROUP(N(NpcData_Gulpit_02), BTL_SAM_FORMATION_02, BTL_SAM_STAGE_00),
    {}
};
