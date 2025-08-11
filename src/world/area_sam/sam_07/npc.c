#include "sam_07.h"

#include "world/common/enemy/Gulpit.inc.c"
#include "world/common/enemy/FrostPiranha.inc.c"

NpcData N(NpcData_Gulpit)[] = {
    {
        .id = NPC_Gulpit,
        .pos = { -500.0f, -150.0f, -75.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = true,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -500, -150, -75 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -500, -150, -75 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_Gulpit),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = GULPIT_DROPS,
        .animations = GULPIT_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    GULPIT_HITBOX(NPC_Gulpit_Hitbox),
};

NpcData N(NpcData_FrostPiranha_01)[] = {
    {
        .id = NPC_FrostPiranha_01,
        .pos = { 250.0f, 120.0f, -75.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = true,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 250, 120, -75 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 330, 120, -65 },
                .detectSize = { 260, 65 },
            }
        },
        .settings = &N(NpcSettings_FrostPiranha),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = FROST_PIRANHA_DROPS,
        .animations = FROST_PIRANHA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_PIRANHA_HITBOX(NPC_FrostPiranha_01_Hitbox),
};

NpcData N(NpcData_FrostPiranha_02)[] = {
    {
        .id = NPC_FrostPiranha_02,
        .pos = { 400.0f, 120.0f, -75.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = true,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 400, 120, -75 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 330, 120, -65 },
                .detectSize = { 260, 65 },
            }
        },
        .settings = &N(NpcSettings_FrostPiranha),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = FROST_PIRANHA_DROPS,
        .animations = FROST_PIRANHA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_PIRANHA_HITBOX(NPC_FrostPiranha_02_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Gulpit), BTL_SAM_FORMATION_03, BTL_SAM_STAGE_02),
    NPC_GROUP(N(NpcData_FrostPiranha_01), BTL_SAM_FORMATION_09, BTL_SAM_STAGE_02),
    NPC_GROUP(N(NpcData_FrostPiranha_02), BTL_SAM_FORMATION_07, BTL_SAM_STAGE_02),
    {}
};
