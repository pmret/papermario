#include "nok_15.h"

#include "world/common/enemy/complete/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/complete/Paratroopa.inc.c"
#include "world/common/enemy/complete/SpikedGoomba_Wander.inc.c"

StaticNpc N(NpcData_KoopaTroopa) = {
    .id = NPC_KoopaTroopa,
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .pos = { -450.0f, 0.0f, -45.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = KOOPA_TROOPA_NOK_DROPS,
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
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_ParaTroopa) = {
    .id = NPC_ParaTroopa,
    .settings = &N(NpcSettings_ParaTroopa),
    .pos = { -150.0f, 50.0f, -70.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = PARATROOPA_DROPS,
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
    .animations = PARATROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_NOK_FORMATION_0D, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_ParaTroopa), BTL_NOK_FORMATION_14, BTL_NOK_STAGE_00),
    {}
};
