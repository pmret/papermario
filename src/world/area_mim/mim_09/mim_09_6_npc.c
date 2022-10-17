#include "mim_09.h"

#include "world/common/npc/Oaklie.inc.c"
#include "world/common/enemy/complete/ForestFuzzy.inc.c"

StaticNpc N(NpcData_Fuzzy) = {
    .id = NPC_Fuzzy,
    .settings = &N(NpcSettings_ForestFuzzy),
    .pos = { 270.0f, 0.0f, 200.0f },
    .yaw = 0,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = FOREST_FUZZY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 270, 0, 200 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 400 },
        }
    },
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Fuzzy), BTL_MIM_FORMATION_05, BTL_MIM_STAGE_00),
    {}
};
