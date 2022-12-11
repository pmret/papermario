#include "flo_17.h"

#include "world/common/npc/Dummy.inc.c"

#define AI_LAKITU_FIRST_SPINY_ID    NPC_Spiny_01
#define AI_LAKITU_LAST_SPINY_ID     NPC_Spiny_04
#include "world/common/enemy/complete/Lakitu_SpinySpawner.inc.c"

StaticNpc N(NpcData_Lakitu_01) = {
    .id = NPC_Lakitu_01,
    .settings = &N(NpcSettings_Lakitu_SpinySpawner),
    .pos = { -185.0f, 90.0f, 10.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = LAKITU_DROPS,
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
    .animations = LAKITU_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Lakitu_02) = {
    .id = NPC_Lakitu_02,
    .settings = &N(NpcSettings_Lakitu_SpinySpawner),
    .pos = { 200.0f, 90.0f, -25.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = LAKITU_DROPS,
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
    .animations = LAKITU_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Spiny_01) = {
    .id = NPC_Spiny_01,
    .settings = &N(NpcSettings_SpawnedSpiny),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_4 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = SPINY_DROPS,
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
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Spiny_02) = {
    .id = NPC_Spiny_02,
    .settings = &N(NpcSettings_SpawnedSpiny),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_4 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = SPINY_DROPS,
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
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Spiny_03) = {
    .id = NPC_Spiny_03,
    .settings = &N(NpcSettings_SpawnedSpiny),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_4 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = SPINY_DROPS,
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
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Spiny_04) = {
    .id = NPC_Spiny_04,
    .settings = &N(NpcSettings_SpawnedSpiny),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_4 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = SPINY_DROPS,
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
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Lakitu_01), 0x1A09, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Lakitu_02), 0x1A0A, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_01), 0x1A0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_02), 0x1A0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_03), 0x1A0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_04), 0x1A0C, BTL_FLO_STAGE_02),
    {}
};
