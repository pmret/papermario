#include "omo_17.h"

#include "world/common/enemy/complete/ShyGuy_Wander.inc.c"
#include "world/common/enemy/complete/PyroGuy.inc.c"
#include "world/common/enemy/complete/GrooveGuy.inc.c"
#include "world/common/enemy/complete/SkyGuy.inc.c"
#include "world/common/enemy/complete/SpyGuy.inc.c"

EvtScript N(EVS_NpcAuxAI_Conductor) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Conductor) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Conductor) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Conductor) = {
    .defaultAnim = ANIM_TrainToad_Blue_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_Conductor),
    .onInteract = &N(EVS_NpcInteract_Conductor),
    .ai = &N(EVS_NpcAI_Conductor),
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
};

StaticNpc N(NpcData_Conductor) = {
    .id = NPC_Conductor,
    .settings = &N(NpcSettings_Conductor),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAG_PASSIVE,
    .initVarCount = 1,
    .initVar = { .value = 0 },
};

StaticNpc N(NpcData_SpyGuy)[] = {
    {
        .id = NPC_SpyGuy,
        .settings = &N(NpcSettings_SpyGuy),
        .pos = { -305.0f, 0.0f, 135.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = SPY_GUY_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -305, 0, 135 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -305, 0, 135 },
                .detectSize = { 250 },
            }
        },
        .animations = SPY_GUY_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock1),
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock2),
    SPY_GUY_ROCK_HITBOX(NPC_SpyGuy_Rock3),
};

StaticNpc N(NpcData_PyroGuy) = {
    .id = NPC_PyroGuy,
    .settings = &N(NpcSettings_PyroGuy),
    .pos = { 354.0f, 10.0f, -113.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = PYRO_GUY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 354, 10, -113 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 354, 10, -113 },
            .detectSize = { 250 },
        }
    },
    .animations = PYRO_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_GrooveGuy) = {
    .id = NPC_GrooveGuy,
    .settings = &N(NpcSettings_GrooveGuy),
    .pos = { -150.0f, 10.0f, -125.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = GROOVE_GUY_DROPS_B,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -150, 10, -125 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -150, 10, -125 },
            .detectSize = { 200 },
        }
    },
    .animations = GROOVE_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_SpyGuy), BTL_OMO_FORMATION_17, BTL_OMO_STAGE_06),
    NPC_GROUP(N(NpcData_PyroGuy), BTL_OMO_FORMATION_1D, BTL_OMO_STAGE_06),
    NPC_GROUP(N(NpcData_GrooveGuy), BTL_OMO_FORMATION_2B, BTL_OMO_STAGE_06),
    NPC_GROUP(N(NpcData_Conductor)),
    {}
};
