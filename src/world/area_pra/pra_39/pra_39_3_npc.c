#include "pra_39.h"

#include "world/common/enemy/Swooper.inc.c"
#include "world/common/enemy/Duplighost_Wander.inc.c"

EvtScript N(EVS_NpcInit_Duplighost) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Duplighost) = {
    .id = NPC_Duplighost,
    .pos = { 250.0f, 0.0f, 75.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 250, 0, 75 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 250, 0, 75 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_Duplighost),
    .settings = &N(NpcSettings_Duplighost_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = DUPLIGHOST_DROPS,
    .animations = DUPLIGHOST_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Duplighost), BTL_PRA3_FORMATION_08, BTL_PRA3_STAGE_00),
    {}
};
