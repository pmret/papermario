#include "iwa_01.h"

#include "world/common/enemy/complete/MontyMole_StoneThrower.inc.c"
#include "world/common/enemy/complete/MontyMole_GroundAmbush.inc.c"
#include "world/common/enemy/complete/MontyMole_WallAmbush.inc.c"
#include "world/common/enemy/complete/Cleft.inc.c"

StaticNpc N(NpcData_MontyMole_WallAmbush)[] = {
    {
        .id = NPC_MontyMole_01,
        .settings = &N(NpcSettings_MontyMole_WallAmbush),
        .pos = { 340.0f, 70.0f, 101.0f },
        .yaw = 0,
        .flags = NPC_FLAG_LOCK_ANIMS,
        .drops = MONTY_MOLE_DROPS,
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
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_01_Hole,
        .settings = &N(NpcSettings_MontyMole_WallAmbush_Hole),
        .pos = { 340.0f, 70.0f, 101.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_AI | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
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

StaticNpc N(NpcData_MontyMole_StoneThrower_01)[] = {
    {
        .id = NPC_MontyMole_02,
        .settings = &N(NpcSettings_MontyMole_StoneThrower),
        .pos = { -250.0f, 10.0f, 260.0f },
        .yaw = 90,
        .flags = NPC_FLAG_JUMPING,
        .drops = MONTY_MOLE_DROPS,
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
        .animations = MONTY_MOLE_THROWER_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    MONTY_MOLE_STONE_HITBOX(NPC_MontyMole_02_Stone)
};

StaticNpc N(NpcData_MontyMole_StoneThrower_02)[] = {
    {
        .id = NPC_MontyMole_03,
        .settings = &N(NpcSettings_MontyMole_StoneThrower),
        .pos = { -175.0f, 10.0f, 240.0f },
        .yaw = 270,
        .flags = NPC_FLAG_JUMPING,
        .drops = MONTY_MOLE_DROPS,
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
        .animations = MONTY_MOLE_THROWER_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    MONTY_MOLE_STONE_HITBOX(NPC_MontyMole_03_Stone)
};

StaticNpc N(NpcData_MontyMole_StoneThrower_03)[] = {
    {
        .id = NPC_MontyMole_04,
        .settings = &N(NpcSettings_MontyMole_StoneThrower),
        .pos = { -55.0f, 10.0f, 180.0f },
        .yaw = 270,
        .flags = NPC_FLAG_JUMPING,
        .drops = MONTY_MOLE_DROPS,
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
        .animations = MONTY_MOLE_THROWER_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    MONTY_MOLE_STONE_HITBOX(NPC_MontyMole_04_Stone)
};

StaticNpc N(NpcData_Cleft) = {
    .id = NPC_Cleft,
    .settings = &N(NpcSettings_Cleft),
    .pos = { -657.0f, 163.0f, 155.0f },
    .yaw = 0,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = CLEFT_DROPS,
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
