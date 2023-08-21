#include "iwa_01.h"

#include "world/common/enemy/MontyMole_StoneThrower.inc.c"
#include "world/common/enemy/MontyMole_GroundAmbush.inc.c"
#include "world/common/enemy/MontyMole_WallAmbush.inc.c"
#include "world/common/enemy/Cleft.inc.c"

NpcData N(NpcData_MontyMole_WallAmbush)[] = {
    {
        .id = NPC_MontyMole_01,
        .pos = { 340.0f, 70.0f, 101.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 345, 70, 245 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 425, 70, 245 },
                .detectSize = { 145, 300 },
            }
        },
        .settings = &N(NpcSettings_MontyMole_WallAmbush),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = MONTY_MOLE_DROPS,
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_01_Hole,
        .pos = { 340.0f, 70.0f, 101.0f },
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
        .settings = &N(NpcSettings_MontyMole_WallAmbush_Hole),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DISABLE_AI | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
};

NpcData N(NpcData_MontyMole_StoneThrower_01)[] = {
    {
        .id = NPC_MontyMole_02,
        .pos = { -250.0f, 10.0f, 260.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -250, 10, 260 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -250, 10, 260 },
                .detectSize = { 180 },
            }
        },
        .settings = &N(NpcSettings_MontyMole_StoneThrower),
        .flags = ENEMY_FLAG_FLYING,
        .drops = MONTY_MOLE_DROPS,
        .animations = MONTY_MOLE_THROWER_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    MONTY_MOLE_STONE_HITBOX(NPC_MontyMole_02_Stone)
};

NpcData N(NpcData_MontyMole_StoneThrower_02)[] = {
    {
        .id = NPC_MontyMole_03,
        .pos = { -175.0f, 10.0f, 240.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -175, 10, 240 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -175, 10, 240 },
                .detectSize = { 180 },
            }
        },
        .settings = &N(NpcSettings_MontyMole_StoneThrower),
        .flags = ENEMY_FLAG_FLYING,
        .drops = MONTY_MOLE_DROPS,
        .animations = MONTY_MOLE_THROWER_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    MONTY_MOLE_STONE_HITBOX(NPC_MontyMole_03_Stone)
};

NpcData N(NpcData_MontyMole_StoneThrower_03)[] = {
    {
        .id = NPC_MontyMole_04,
        .pos = { -55.0f, 10.0f, 180.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -55, 10, 180 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -55, 10, 180 },
                .detectSize = { 180 },
            }
        },
        .settings = &N(NpcSettings_MontyMole_StoneThrower),
        .flags = ENEMY_FLAG_FLYING,
        .drops = MONTY_MOLE_DROPS,
        .animations = MONTY_MOLE_THROWER_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    MONTY_MOLE_STONE_HITBOX(NPC_MontyMole_04_Stone)
};

NpcData N(NpcData_Cleft) = {
    .id = NPC_Cleft,
    .pos = { -657.0f, 163.0f, 155.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -639, 163, 100 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -655, 0, 125 },
            .detectSize = { 125, 125 },
        }
    },
    .settings = &N(NpcSettings_Cleft),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = CLEFT_DROPS,
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_MontyMole_WallAmbush), BTL_IWA_FORMATION_06, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_StoneThrower_01), BTL_IWA_FORMATION_07, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_StoneThrower_02), BTL_IWA_FORMATION_06, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_StoneThrower_03), BTL_IWA_FORMATION_07, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Cleft), BTL_IWA_FORMATION_04, BTL_IWA_STAGE_01),
    {}
};
