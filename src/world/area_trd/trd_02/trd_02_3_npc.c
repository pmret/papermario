#include "trd_02.h"

#include "world/common/enemy/Bobomb_Wander.inc.c"
#include "world/common/enemy/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/KoopaTroopa_Patrol.inc.c"

NpcData N(NpcData_Bobomb_01) = {
    .id = NPC_Bobomb_01,
    .pos = { -70.0f, 0.0f, 80.0f },
    .yaw = 90,
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
    .settings = &N(NpcSettings_Bobomb_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = BOBOMB_DROPS,
    .animations = BOBOMB_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Bobomb_02) = {
    .id = NPC_Bobomb_02,
    .pos = { 140.0f, 0.0f, 80.0f },
    .yaw = 270,
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
    .settings = &N(NpcSettings_Bobomb_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = BOBOMB_DROPS,
    .animations = BOBOMB_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_KoopaTroopa) = {
    .id = NPC_KoopaTroopa,
    .pos = { 50.0f, 187.0f, 183.0f },
    .yaw = 0,
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
    .settings = &N(NpcSettings_KoopaTroopa_Patrol),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bobomb_01), BTL_TRD_1_FORMATION_10, BTL_TRD_1_STAGE_09),
    NPC_GROUP(N(NpcData_Bobomb_02), BTL_TRD_1_FORMATION_10, BTL_TRD_1_STAGE_09),
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_TRD_1_FORMATION_07, BTL_TRD_1_STAGE_0C),
    {}
};
