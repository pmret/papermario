#include "nok_13.h"

#include "world/common/enemy/Fuzzy_Wander.inc.c"

StaticNpc N(NpcData_Fuzzy) = {
    .id = NPC_UnusedFuzzy,
    .settings = &N(NpcSettings_Fuzzy_Wander),
    .pos = { 175.0f, 0.0f, -270.0f },
    .yaw = 180,
    .drops = FUZZY_DROPS,
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
    .animations = FUZZY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    {}
};
