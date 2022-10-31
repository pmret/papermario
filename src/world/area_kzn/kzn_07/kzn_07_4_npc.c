#include "kzn_07.h"
#include "effects.h"

#include "world/common/enemy/complete/LavaBubble.inc.c"

StaticNpc N(NpcData_LavaBubble_01) = {
    .id = NPC_Bubble_01,
    .settings = &N(NpcSettings_LavaBubble),
    .pos = { -200.0f, 50.0f, 150.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400,
    .drops = LAVA_BUBBLE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -200, 50, 150 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -200, 50, 150 },
            .detectSize = { 300 },
        }
    },
    .animations = LAVA_BUBBLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_LavaBubble_02) = {
    .id = NPC_Bubble_02,
    .settings = &N(NpcSettings_LavaBubble),
    .pos = { -250.0f, 80.0f, 50.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400,
    .drops = LAVA_BUBBLE_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -250, 80, 50 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -250, 80, 50 },
            .detectSize = { 300 },
        }
    },
    .animations = LAVA_BUBBLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_LavaBubble_01), BTL_KZN_FORMATION_05, BTL_KZN_STAGE_01),
    NPC_GROUP(N(NpcData_LavaBubble_02), BTL_KZN_FORMATION_06, BTL_KZN_STAGE_01),
    {}
};
