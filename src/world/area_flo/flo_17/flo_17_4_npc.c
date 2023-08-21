#include "flo_17.h"

#include "world/common/npc/Dummy.inc.c"

#define AI_LAKITU_FIRST_SPINY_ID    NPC_Spiny_01
#define AI_LAKITU_LAST_SPINY_ID     NPC_Spiny_04
#include "world/common/enemy/Lakitu_SpinySpawner.inc.c"

NpcData N(NpcData_Lakitu_01) = {
    .id = NPC_Lakitu_01,
    .pos = { -185.0f, 90.0f, 10.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -185, 90, 10 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -185, 90, 0 },
            .detectSize = { 85, 120 },
        }
    },
    .settings = &N(NpcSettings_Lakitu_SpinySpawner),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = LAKITU_DROPS,
    .animations = LAKITU_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Lakitu_02) = {
    .id = NPC_Lakitu_02,
    .pos = { 200.0f, 90.0f, -25.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 200, 90, -25 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 200, 90, 0 },
            .detectSize = { 85, 120 },
        }
    },
    .settings = &N(NpcSettings_Lakitu_SpinySpawner),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = LAKITU_DROPS,
    .animations = LAKITU_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_01) = {
    .id = NPC_Spiny_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_02) = {
    .id = NPC_Spiny_02,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_03) = {
    .id = NPC_Spiny_03,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_04) = {
    .id = NPC_Spiny_04,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .settings = &N(NpcSettings_SpawnedSpiny),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Lakitu_01), BTL_FLO_FORMATION_09, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Lakitu_02), BTL_FLO_FORMATION_0A, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_01), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_02), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_03), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_04), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    {}
};
