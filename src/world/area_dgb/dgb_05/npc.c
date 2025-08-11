#include "dgb_05.h"

#define INCLUDE_CLUBBA_NAPPING
#include "world/common/enemy/Clubba_Multi.inc.c"

NpcData N(NpcData_Clubba_01)[] = {
    {
        .id = NPC_Clubba_01,
        .pos = { 132.0f, -110.0f, 238.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 132, -110, 238 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 325, 0, 185 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Napping),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = CLUBBA_DROPS,
        .animations = CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_01_Hitbox),
};

NpcData N(NpcData_Clubba_02)[] = {
    {
        .id = NPC_Clubba_02,
        .pos = { 503.0f, -210.0f, 225.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 503, -210, 225 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 503, -210, 290 },
                .detectSize = { 200, 150 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Napping),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = CLUBBA_DROPS,
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
