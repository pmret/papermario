#include "iwa_03.h"

#include "world/common/enemy/complete/MontyMole_GroundAmbush.inc.c"
#include "world/common/enemy/complete/Cleft.inc.c"

StaticNpc N(NpcData_Cleft_01) = {
    .id = NPC_Cleft_01,
    .settings = &N(NpcSettings_Cleft),
    .pos = { -525.0f, -75.0f, 60.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -525, -75, 60 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -525, -75, 60 },
            .detectSize = { 250 },
        }
    },
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Cleft_02) = {
    .id = NPC_Cleft_02,
    .settings = &N(NpcSettings_Cleft),
    .pos = { -1686.0f, -60.0f, 180.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -1686, -60, 180 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -1686, -60, 180 },
            .detectSize = { 250 },
        }
    },
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Cleft_03) = {
    .id = NPC_Cleft_03,
    .settings = &N(NpcSettings_Cleft),
    .pos = { -1300.0f, 408.0f, -125.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -1300, 408, -125 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -1290, 408, -125 },
            .detectSize = { 140 },
        }
    },
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_MontyMole)[] = {
    {
        .id = NPC_MontyMole,
        .settings = &N(NpcSettings_MontyMole_GroundAmbush),
        .pos = { -1000.0f, 23.0f, 60.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_400,
        .drops = MONTY_MOLE_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -1000, 23, 60 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -1000, 23, 60 },
                .detectSize = { 250 },
            }
        },
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_Hole,
        .settings = &N(NpcSettings_MontyMole_GroundAmbush_Hole),
        .pos = { -1000.0f, 23.0f, 60.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_20 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Cleft_01), BTL_IWA_FORMATION_03, BTL_IWA_STAGE_00),
    NPC_GROUP(N(NpcData_Cleft_02), BTL_IWA_FORMATION_00, BTL_IWA_STAGE_00),
    NPC_GROUP(N(NpcData_Cleft_03), BTL_IWA_FORMATION_01, BTL_IWA_STAGE_00),
    NPC_GROUP(N(NpcData_MontyMole), BTL_IWA_FORMATION_09, BTL_IWA_STAGE_00),
    {}
};
