#include "iwa_03.h"

#include "world/common/enemy/MontyMole_GroundAmbush.inc.c"
#include "world/common/enemy/Cleft.inc.c"

NpcData N(NpcData_Cleft_01) = {
    .id = NPC_Cleft_01,
    .pos = { -525.0f, -75.0f, 60.0f },
    .yaw = 0,
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
    .settings = &N(NpcSettings_Cleft),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = CLEFT_DROPS,
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Cleft_02) = {
    .id = NPC_Cleft_02,
    .pos = { -1686.0f, -60.0f, 180.0f },
    .yaw = 0,
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
    .settings = &N(NpcSettings_Cleft),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = CLEFT_DROPS,
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Cleft_03) = {
    .id = NPC_Cleft_03,
    .pos = { -1300.0f, 408.0f, -125.0f },
    .yaw = 0,
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
    .settings = &N(NpcSettings_Cleft),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = CLEFT_DROPS,
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_MontyMole)[] = {
    {
        .id = NPC_MontyMole,
        .pos = { -1000.0f, 23.0f, 60.0f },
        .yaw = 0,
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
        .settings = &N(NpcSettings_MontyMole_GroundAmbush),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = MONTY_MOLE_DROPS,
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_Hole,
        .pos = { -1000.0f, 23.0f, 60.0f },
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
        .settings = &N(NpcSettings_MontyMole_GroundAmbush_Hole),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DISABLE_AI | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
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
