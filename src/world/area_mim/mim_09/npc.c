#include "mim_09.h"

#include "world/common/npc/Oaklie.inc.c"
#include "world/common/enemy/ForestFuzzy_Wander.inc.c"

NpcData N(NpcData_Fuzzy) = {
    .id = NPC_Fuzzy,
    .pos = { 270.0f, 0.0f, 200.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 270, 0, 200 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 400 },
        }
    },
    .settings = &N(NpcSettings_ForestFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = FOREST_FUZZY_DROPS,
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Fuzzy), BTL_MIM_FORMATION_05, BTL_MIM_STAGE_00),
    {}
};
