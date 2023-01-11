#include "sbk_46.h"

#include "world/common/enemy/complete/Bandit.inc.c"
#include "world/common/enemy/complete/Pokey.inc.c"

StaticNpc N(NpcData_Pokey) = {
    .id = NPC_Pokey,
    .settings = &N(NpcSettings_Pokey),
    .pos = { 310.0f, 0.0f, -100.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_800,
    .drops = POKEY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 310, 0, -100 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .animations = POKEY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Bandit_01) = {
    .id = NPC_Bandit_01,
    .settings = &N(NpcSettings_Bandit),
    .pos = { -190.0f, 0.0f, -318.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_800,
    .drops = BANDIT_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -190, 0, -318 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .animations = BANDIT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Bandit_02) = {
    .id = NPC_Bandit_02,
    .settings = &N(NpcSettings_Bandit),
    .pos = { -200.0f, 0.0f, 115.0f },
    .yaw = 300,
    .flags = ENEMY_FLAG_800,
    .drops = BANDIT_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -200, 0, 115 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .animations = BANDIT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Pokey), BTL_SBK_FORMATION_06, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Bandit_01), BTL_SBK_FORMATION_0D, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Bandit_02), BTL_SBK_FORMATION_0C, BTL_SBK_STAGE_00),
    {}
};
