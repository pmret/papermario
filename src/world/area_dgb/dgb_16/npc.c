#include "dgb_16.h"

#define INCLUDE_CLUBBA_NAPPING
#include "world/common/enemy/Clubba_Multi.inc.c"

NpcData N(NpcData_Clubba_01)[] = {
    {
        .id = NPC_Clubba_01,
        .pos = { -70.0f, 0.0f, -100.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -70, 0, -100 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 150, 0, -175 },
                .detectSize = { 430, 92 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Napping),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = CLUBBA_DROPS,
        .animations = CLUBBA_ANIMS,
        .extraAnimations = N(ExtraAnims_Clubba),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_01_Hitbox),
};

NpcData N(NpcData_Clubba_02)[] = {
    {
        .id = NPC_Clubba_02,
        .pos = { 0.0f, 0.0f, -235.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, -235 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 150, 0, -175 },
                .detectSize = { 430, 92 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Napping),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = CLUBBA_DROPS,
        .animations = CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_02_Hitbox),
};

NpcData N(NpcData_Clubba_03)[] = {
    {
        .id = NPC_Clubba_03,
        .pos = { 70.0f, 0.0f, -100.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 70, 0, -100 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 150, 0, -175 },
                .detectSize = { 430, 92 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Napping),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = CLUBBA_DROPS,
        .animations = CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_03_Hitbox),
};

NpcData N(NpcData_Clubba_04)[] = {
    {
        .id = NPC_Clubba_04,
        .pos = { 140.0f, 0.0f, -235.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 140, 0, -235 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 150, 0, -175 },
                .detectSize = { 430, 92 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Napping),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = CLUBBA_DROPS,
        .animations = CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_04_Hitbox),
};

NpcData N(NpcData_Clubba_05)[] = {
    {
        .id = NPC_Clubba_05,
        .pos = { 210.0f, 0.0f, -100.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 210, 0, -100 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 150, 0, -175 },
                .detectSize = { 430, 92 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Napping),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = CLUBBA_DROPS,
        .animations = CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_05_Hitbox),
};

NpcData N(NpcData_Clubba_06)[] = {
    {
        .id = NPC_Clubba_06,
        .pos = { 280.0f, 0.0f, -235.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 280, 0, -235 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 150, 0, -175 },
                .detectSize = { 430, 92 },
            }
        },
        .settings = &N(NpcSettings_Clubba_Napping),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = CLUBBA_DROPS,
        .animations = CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_06_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Clubba_01), BTL_DGB_FORMATION_03, BTL_DGB_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_02), BTL_DGB_FORMATION_00, BTL_DGB_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_03), BTL_DGB_FORMATION_00, BTL_DGB_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_04), BTL_DGB_FORMATION_00, BTL_DGB_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_05), BTL_DGB_FORMATION_01, BTL_DGB_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_06), BTL_DGB_FORMATION_01, BTL_DGB_STAGE_02),
    {}
};
