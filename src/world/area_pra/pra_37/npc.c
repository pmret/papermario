#include "pra_37.h"

#define INCLUDE_FROST_CLUBBA_WANDER
#include "world/common/enemy/FrostClubba_Multi.inc.c"

EvtScript N(EVS_NpcInit_FrostClubba) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, true)
    Return
    End
};

NpcData N(NpcData_FrostClubba)[] = {
    {
        .id = NPC_FrostClubba,
        .pos = { 175.0f, 0.0f, 75.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = true,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 175, 0, 75 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 175, 0, 75 },
                .detectSize = { 200 },
            }
        },
        .init = &N(EVS_NpcInit_FrostClubba),
        .settings = &N(NpcSettings_FrostClubba_Wander),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = FROST_CLUBBA_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_CLUBBA_MACE_HITBOX(NPC_FrostClubba_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_FrostClubba), BTL_PRA_FORMATION_0D, BTL_PRA_STAGE_00),
    {}
};
