#include "nok_13.h"

#include "world/common/enemy/Fuzzy_Wander.inc.c"

NpcData N(NpcData_Fuzzy) = {
    .id = NPC_UnusedFuzzy,
    .pos = { 175.0f, 0.0f, -270.0f },
    .yaw = 180,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 175, 0, -270 },
            .wanderSize = { 70 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 175, 0, -270 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Fuzzy_Wander),
    .drops = FUZZY_DROPS,
    .animations = FUZZY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    {}
};
