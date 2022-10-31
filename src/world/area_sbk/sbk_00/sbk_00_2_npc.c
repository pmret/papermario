#include "sbk_00.h"

#include "world/common/enemy/complete/Pokey.inc.c"

StaticNpc N(NpcData_Pokey_01) = {
    .id = NPC_Pokey_01,
    .settings = &N(NpcSettings_Pokey),
    .pos = { -40.0f, 0.0f, 160.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_800,
    .drops = POKEY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -40, 0, 160 },
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
    .pos = { 245.0f, 0.0f, 75.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_800,
    .drops = POKEY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 245, 0, 75 },
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
    NPC_GROUP(N(NpcData_Pokey_01), BTL_SBK_FORMATION_00, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Pokey_02), BTL_SBK_FORMATION_01, BTL_SBK_STAGE_00),
    {}
};
