#include "pra_39.h"

#include "world/common/enemy/complete/Swooper.inc.c"
#include "world/common/enemy/complete/Duplighost_Wander.inc.c"

EvtScript N(EVS_NpcInit_Duplighost) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Duplighost) = {
    .id = NPC_Duplighost,
    .settings = &N(NpcSettings_Duplighost_Wander),
    .pos = { 250.0f, 0.0f, 75.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_200000,
    .init = &N(EVS_NpcInit_Duplighost),
    .drops = DUPLIGHOST_DROPS,
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
    .animations = DUPLIGHOST_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Duplighost), BTL_PRA3_FORMATION_08, BTL_PRA3_STAGE_00),
    {}
};
