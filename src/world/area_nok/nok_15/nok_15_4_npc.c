#include "nok_15.h"

#include "world/common/enemy/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/Paratroopa.inc.c"
#include "world/common/enemy/SpikedGoomba_Wander.inc.c"

NpcData N(NpcData_KoopaTroopa) = {
    .id = NPC_KoopaTroopa,
    .pos = { -450.0f, 0.0f, -45.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -450, 0, -45 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -450, 0, -45 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = KOOPA_TROOPA_NOK_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_ParaTroopa) = {
    .id = NPC_ParaTroopa,
    .pos = { -150.0f, 50.0f, -70.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -150, 50, -70 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -150, 50, -70 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_ParaTroopa),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = PARATROOPA_DROPS,
    .animations = PARATROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_NOK_FORMATION_0D, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_ParaTroopa), BTL_NOK_FORMATION_14, BTL_NOK_STAGE_00),
    {}
};
