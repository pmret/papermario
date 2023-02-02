#include "sam_10.h"

#include "world/common/enemy/complete/FrostClubba_Wander.inc.c"

StaticNpc N(NpcData_Clubba)[] = {
    {
        .id = NPC_FrostClubba,
        .settings = &N(NpcSettings_FrostClubba_Wander),
        .pos = { 575.0f, 480.0f, -50.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .drops = FROST_CLUBBA_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 575, 480, -50 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 575, 480, -50 },
                .detectSize = { 200 },
            }
        },
        .animations = FROST_CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_CLUBBA_MACE_HITBOX(NPC_FrostClubba_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Clubba), BTL_SAM_FORMATION_0C, BTL_SAM_STAGE_02),
    {}
};
