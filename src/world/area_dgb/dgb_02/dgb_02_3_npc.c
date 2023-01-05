#include "dgb_02.h"

#define INCLUDE_CLUBBA_WANDER
#define INCLUDE_CLUBBA_NAPPING
#include "world/common/enemy/complete/Clubba_Multi.inc.c"

StaticNpc N(NpcData_Clubba_01)[] = {
    {
        .id = NPC_Clubba_01,
        .settings = &N(NpcSettings_Clubba_Wander),
        .pos = { -200.0f, 0.0f, 180.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .drops = CLUBBA_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -200, 0, 180 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { -200, 0, 175 },
                .detectSize = { 250, 90 },
            }
        },
        .animations = CLUBBA_ANIMS,
        .extraAnimations = N(ExtraAnims_Clubba),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_01_Hitbox),
};

StaticNpc N(NpcData_Clubba_02)[] = {
    {
        .id = NPC_Clubba_02,
        .settings = &N(NpcSettings_Clubba_Napping),
        .pos = { 375.0f, 0.0f, 100.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .drops = CLUBBA_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 375, 0, 100 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 320, 0, 175 },
                .detectSize = { 250, 90 },
            }
        },
        .animations = CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_02_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Clubba_01), BTL_DGB_FORMATION_02, BTL_DGB_STAGE_00),
    NPC_GROUP(N(NpcData_Clubba_02), BTL_DGB_FORMATION_01, BTL_DGB_STAGE_00),
    {}
};
