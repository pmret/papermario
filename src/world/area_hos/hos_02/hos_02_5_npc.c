#include "hos_02.h"

#include "world/common/enemy/Ember.inc.c"

StaticNpc N(NpcData_Ember) = {
    .id = NPC_Ember_01,
    .settings = &N(NpcSettings_Ember),
    .pos = { -410.0f, -15.0f, 260.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = EMBER_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -410, -15, 260 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -410, -15, 260 },
            .detectSize = { 1000 },
        }
    },
    .animations = EMBER_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Ember_02) = {
    .id = NPC_Ember_02,
    .settings = &N(NpcSettings_Ember),
    .pos = { 220.0f, 200.0f, -205.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = EMBER_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 220, 200, -205 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 220, 200, -205 },
            .detectSize = { 1000 },
        }
    },
    .animations = EMBER_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Ember_03) = {
    .id = NPC_Ember_03,
    .settings = &N(NpcSettings_Ember),
    .pos = { -135.0f, 370.0f, 270.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = EMBER_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -135, 370, 270 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -135, 370, 270 },
            .detectSize = { 1000 },
        }
    },
    .animations = EMBER_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Ember), BTL_HOS_FORMATION_01, BTL_HOS_STAGE_01),
    NPC_GROUP(N(NpcData_Ember_02), BTL_HOS_FORMATION_01, BTL_HOS_STAGE_01),
    NPC_GROUP(N(NpcData_Ember_03), BTL_HOS_FORMATION_01, BTL_HOS_STAGE_01),
    {}
};
