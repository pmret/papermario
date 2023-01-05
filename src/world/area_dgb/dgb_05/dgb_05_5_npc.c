#include "dgb_05.h"

#define INCLUDE_CLUBBA_NAPPING
#include "world/common/enemy/complete/Clubba_Multi.inc.c"

StaticNpc N(NpcData_Clubba_01)[] = {
    {
        .id = NPC_Clubba_01,
        .settings = &N(NpcSettings_Clubba_Napping),
        .pos = { 132.0f, -110.0f, 238.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_400,
        .drops = CLUBBA_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 132, -110, 238 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 325, 0, 185 },
                .detectSize = { 200 },
            }
        },
        .animations = CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_01_Hitbox),
};

StaticNpc N(NpcData_Clubba_02)[] = {
    {
        .id = NPC_Clubba_02,
        .settings = &N(NpcSettings_Clubba_Napping),
        .pos = { 503.0f, -210.0f, 225.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_400,
        .drops = CLUBBA_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 503, -210, 225 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 503, -210, 290 },
                .detectSize = { 200, 150 },
            }
        },
        .animations = CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_02_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Clubba_01), BTL_DGB_FORMATION_01, BTL_DGB_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_02), BTL_DGB_FORMATION_02, BTL_DGB_STAGE_02),
    {}
};
