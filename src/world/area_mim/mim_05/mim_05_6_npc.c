#include "mim_05.h"

#include "world/common/enemy/complete/PiranhaPlant.inc.c"

StaticNpc N(NpcData_PiranhaPlant_01)[] = {
    {
        .id = NPC_PiranhaPlant_01,
        .settings = &N(NpcSettings_PiranhaPlant),
        .pos = { -240.0f, 0.0f, 240.0f },
        .yaw = 0,
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
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
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
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

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PiranhaPlant_01), BTL_MIM_FORMATION_0B, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_PiranhaPlant_02), BTL_MIM_FORMATION_0A, BTL_MIM_STAGE_00),
    {}
};
