#include "trd_02.h"

#include "world/common/enemy/complete/Bobomb_Wander.inc.c"
#include "world/common/enemy/complete/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/complete/KoopaTroopa_Patrol.inc.c"

StaticNpc N(NpcData_Bobomb_01) = {
    .id = NPC_Bobomb_01,
    .settings = &N(NpcSettings_Bobomb_Wander),
    .pos = { -70.0f, 0.0f, 80.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = BOBOMB_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -70, 0, 80 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 0, 0, 35 },
            .detectSize = { 250, 175 },
        }
    },
    .animations = BOBOMB_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Bobomb_02) = {
    .id = NPC_Bobomb_02,
    .settings = &N(NpcSettings_Bobomb_Wander),
    .pos = { 140.0f, 0.0f, 80.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = BOBOMB_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 140, 0, 80 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 0, 0, 35 },
            .detectSize = { 250, 175 },
        }
    },
    .animations = BOBOMB_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_KoopaTroopa) = {
    .id = NPC_KoopaTroopa,
    .settings = &N(NpcSettings_KoopaTroopa_Patrol),
    .pos = { 50.0f, 187.0f, 183.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 70, 187, 183 },
                { -20, 187, 183 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 20, 187, 207 },
            .detectSize = { 150, 80 },
        }
    },
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bobomb_01), BTL_TRD_PART_1_FORMATION_10, BTL_TRD_PART_1_STAGE_09),
    NPC_GROUP(N(NpcData_Bobomb_02), BTL_TRD_PART_1_FORMATION_10, BTL_TRD_PART_1_STAGE_09),
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_TRD_PART_1_FORMATION_07, BTL_TRD_PART_1_STAGE_0C),
    {}
};
