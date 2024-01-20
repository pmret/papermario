#include "pra_35.h"

#define INCLUDE_FROST_CLUBBA_PATROL
#include "world/common/enemy/FrostClubba_Multi.inc.c"
#include "world/common/enemy/Duplighost_Patrol.inc.c"

#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

EvtScript N(EVS_NpcInit_EnableReflection) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Return
    End
};

NpcData N(NpcData_Clubba)[] = {
    {
        .id = NPC_Clubba,
        .pos = { 200.0f, 0.0f, 75.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 200, 0, 75 },
                    { 300, 0, 75 },
                },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 250, 0, 75 },
                .detectSize = { 200, 100 },
            }
        },
        .init = &N(EVS_NpcInit_EnableReflection),
        .settings = &N(NpcSettings_FrostClubba_Patrol),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = FROST_CLUBBA_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_CLUBBA_MACE_HITBOX(NPC_Clubba_Hitbox),
};

NpcData N(NpcData_Duplighost) = {
    .id = NPC_Duplighost,
    .pos = { 200.0f, 0.0f, -75.0f },
    .yaw = 90,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 200, 0, -75 },
                { 300, 0, -75 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 250, 0, 75 },
            .detectSize = { 200, 100 },
        }
    },
    .init = &N(EVS_NpcInit_EnableReflection),
    .settings = &N(NpcSettings_Duplighost_Patrol),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = DUPLIGHOST_DROPS,
    .animations = DUPLIGHOST_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Clubba), BTL_PRA_FORMATION_08, BTL_PRA_STAGE_01),
    NPC_GROUP(N(NpcData_Duplighost), BTL_PRA3_FORMATION_04, BTL_PRA3_STAGE_00),
    {}
};
