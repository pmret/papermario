#include "mim_06.h"

#include "world/common/enemy/complete/PiranhaPlant.inc.c"
#include "world/common/enemy/complete/ForestFuzzy.inc.c"

StaticNpc N(NpcData_PiranhaPlant_01)[] = {
    {
        .id = NPC_PiranhaPlant_01,
        .settings = &N(NpcSettings_PiranhaPlant),
        .pos = { -240.0f, 0.0f, -240.0f },
        .yaw = 0,
        .flags = 0,
        .drops = PIRANHA_PLANT_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 400 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 400 },
            }
        },
        .animations = PIRANHA_PLANT_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    PIRANHA_PLANT_HITBOX(NPC_PiranhaPlant_01_Hitbox)
};

StaticNpc N(NpcData_PiranhaPlant_02)[] = {
    {
        .id = NPC_PiranhaPlant_02,
        .settings = &N(NpcSettings_PiranhaPlant),
        .pos = { 240.0f, 0.0f, -240.0f },
        .yaw = 0,
        .flags = 0,
        .drops = PIRANHA_PLANT_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 400 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 400 },
            }
        },
        .animations = PIRANHA_PLANT_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    PIRANHA_PLANT_HITBOX(NPC_PiranhaPlant_02_Hitbox)
};

StaticNpc N(NpcData_Fuzzy) = {
    .id = NPC_Fuzzy,
    .settings = &N(NpcSettings_ForestFuzzy),
    .pos = { -140.0f, 0.0f, 300.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_400,
    .drops = FOREST_FUZZY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 400 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 400 },
        }
    },
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PiranhaPlant_01), BTL_MIM_FORMATION_0D, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_PiranhaPlant_02), BTL_MIM_FORMATION_0E, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_Fuzzy), BTL_MIM_FORMATION_07, BTL_MIM_STAGE_00),
    {}
};
