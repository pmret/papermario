#include "kpa_70.h"

#include "world/common/enemy/Koopatrol_Wander.inc.c"

NpcData N(NpcData_Koopatrol_01) = {
    .id = NPC_Koopatrol_01,
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .pos = { 435.0f, 10.0f, 125.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400,
    .drops = KOOPATROL_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 435, 10, 125 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 435, 10, 125 },
            .detectSize = { 200 },
        }
    },
    .animations = KOOPATROL_ANIMS,
};

NpcData N(NpcData_Koopatrol_02) = {
    .id = NPC_Koopatrol_02,
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .pos = { 815.0f, 10.0f, 125.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400,
    .drops = KOOPATROL_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 815, 10, 125 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 815, 10, 125 },
            .detectSize = { 200 },
        }
    },
    .animations = KOOPATROL_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Koopatrol_01), BTL_KPA_FORMATION_18, BTL_KPA_STAGE_02),
    NPC_GROUP(N(NpcData_Koopatrol_02), BTL_KPA_FORMATION_19, BTL_KPA_STAGE_02),
    {}
};
