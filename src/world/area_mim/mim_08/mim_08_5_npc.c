#include "mim_08.h"

#include "world/common/enemy/Bzzap.inc.c"

#include "world/common/enemy/PiranhaPlant.inc.c"

EvtScript N(EVS_NpcIdle_Bzzap) = {
    Label(100)
    Wait(1)
    IfEq(MV_Unk_00, 0)
        Goto(100)
    EndIf
    Call(SetNpcPos, NPC_SELF, -280, 108, 0)
    Call(SetNpcJumpscale, NPC_SELF, Float(0.0))
    Call(NpcJump1, NPC_SELF, -280, 50, 10, 5)
    Wait(50)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Bzzap)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bzzap) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Bzzap)))
    Return
    End
};

NpcData N(NpcData_Bzzap) = {
    .id = NPC_Bzzap,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -300, 60, 0 },
            .wanderSize = { 60 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -300, 60, 0 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_Bzzap),
    .settings = &N(NpcSettings_Bzzap),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = BZZAP_ANIMS,
};

NpcData N(NpcData_PiranhaPlant_01)[] = {
    {
        .id = NPC_PiranhaPlant_01,
        .pos = { -240.0f, 0.0f, -240.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 400 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 400 },
            }
        },
        .settings = &N(NpcSettings_PiranhaPlant),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = PIRANHA_PLANT_DROPS,
        .animations = PIRANHA_PLANT_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    PIRANHA_PLANT_HITBOX(NPC_PiranhaPlant_01_Hitbox)
};

NpcData N(NpcData_PiranhaPlant_02)[] = {
    {
        .id = NPC_PiranhaPlant_02,
        .pos = { 240.0f, 0.0f, 240.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 400 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 400 },
            }
        },
        .settings = &N(NpcSettings_PiranhaPlant),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = PIRANHA_PLANT_DROPS,
        .animations = PIRANHA_PLANT_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    PIRANHA_PLANT_HITBOX(NPC_PiranhaPlant_02_Hitbox)
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bzzap), BTL_MIM_FORMATION_10, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_PiranhaPlant_01), BTL_MIM_FORMATION_0F, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_PiranhaPlant_02), BTL_MIM_FORMATION_09, BTL_MIM_STAGE_00),
    {}
};
