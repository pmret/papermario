#include "pra_37.h"

#include "world/common/enemy/complete/FrostClubba_Wander.inc.c"

EvtScript N(EVS_NpcInit_FrostClubba) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_FrostClubba)[] = {
    {
        .id = NPC_FrostClubba,
        .settings = &N(NpcSettings_FrostClubba_Wander),
        .pos = { 175.0f, 0.0f, 75.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_FrostClubba),
        .drops = FROST_CLUBBA_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 175, 0, 75 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 175, 0, 75 },
                .detectSize = { 200 },
            }
        },
        .animations = FROST_CLUBBA_ANIMS,
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_CLUBBA_MACE_HITBOX(NPC_FrostClubba_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_FrostClubba), BTL_PRA_FORMATION_0D, BTL_PRA_STAGE_00),
    {}
};
