#include "pra_35.h"

#define INCLUDE_FROST_CLUBBA_PATROL
#include "world/common/enemy/complete/FrostClubba_Multi.inc.c"
#include "world/common/enemy/complete/Duplighost_Patrol.inc.c"

#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

EvtScript N(EVS_NpcInit_EnableReflection) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Clubba)[] = {
    {
        .id = NPC_Clubba,
        .settings = &N(NpcSettings_FrostClubba_Patrol),
        .pos = { 200.0f, 0.0f, 75.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_EnableReflection),
        .drops = FROST_CLUBBA_DROPS,
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
        .animations = FROST_CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_CLUBBA_MACE_HITBOX(NPC_Clubba_Hitbox),
};

StaticNpc N(NpcData_Duplighost) = {
    .id = NPC_Duplighost,
    .settings = &N(NpcSettings_Duplighost_Patrol),
    .pos = { 200.0f, 0.0f, -75.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_200000,
    .init = &N(EVS_NpcInit_EnableReflection),
    .drops = DUPLIGHOST_DROPS,
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
    .animations = DUPLIGHOST_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Clubba), BTL_PRA_FORMATION_08, BTL_PRA_STAGE_01),
    NPC_GROUP(N(NpcData_Duplighost), BTL_PRA3_FORMATION_04, BTL_PRA3_STAGE_00),
    {}
};
