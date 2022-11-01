#include "sbk_12.h"

#include "world/common/enemy/complete/Pokey.inc.c"

StaticNpc N(NpcData_Pokey_01) = {
    .id = NPC_Pokey_01,
    .settings = &N(NpcSettings_Pokey),
    .pos = { -190.0f, 0.0f, -130.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .drops = POKEY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -190, 0, -130 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .animations = POKEY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Pokey_02) = {
    .id = NPC_Pokey_02,
    .settings = &N(NpcSettings_Pokey),
    .pos = { -40.0f, 0.0f, -200.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .drops = POKEY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -40, 0, -200 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .animations = POKEY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Pokey_03) = {
    .id = NPC_Pokey_03,
    .settings = &N(NpcSettings_Pokey),
    .pos = { 195.0f, 0.0f, -255.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .drops = POKEY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 195, 0, -255 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .animations = POKEY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Pokey_01), BTL_SBK_FORMATION_02, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Pokey_02), BTL_SBK_FORMATION_00, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Pokey_03), BTL_SBK_FORMATION_01, BTL_SBK_STAGE_00),
    {}
};
