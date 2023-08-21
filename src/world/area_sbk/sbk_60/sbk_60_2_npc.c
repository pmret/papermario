#include "sbk_60.h"

#include "world/common/enemy/Pokey.inc.c"

NpcData N(NpcData_Pokey) = {
    .id = NPC_Pokey,
    .pos = { 160.0f, 0.0f, -120.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 160, 0, -120 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .settings = &N(NpcSettings_Pokey),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = POKEY_DROPS,
    .animations = POKEY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Pokey), BTL_SBK_FORMATION_03, BTL_SBK_STAGE_00),
    {}
};
