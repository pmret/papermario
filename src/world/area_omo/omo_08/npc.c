#include "omo_08.h"

#include "world/common/npc/TrainToad.inc.c"
#include "world/common/enemy/ShyGuy_Wander.inc.c"

EvtScript N(EVS_NpcInteract_Conductor) = {
    Call(DisablePlayerInput, TRUE)
    ExecWait(N(EVS_80247100))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Conductor) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Conductor)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_TrainToad) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_SOLVED_COLOR_PUZZLE)
            Call(FindKeyItem, ITEM_MYSTERY_NOTE, LVar0)
            IfEq(LVar0, -1)
                IfEq(GF_OMO09_SpawnedPeachChoice3, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002B)
                Else
                    IfEq(GF_OMO09_Chest_Dictionary, FALSE)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002C)
                    Else
                        Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002F)
                    EndIf
                EndIf
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002D)
            EndIf
        CaseLt(STORY_CH4_WATT_JOINED_PARTY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002E)
        CaseLt(STORY_CH4_DEFEATED_GENERAL_GUY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002F)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_0030)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_TrainToad) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_TrainToad)))
    Return
    End
};

EvtScript N(EVS_NpcAI_BoxedShyGuy) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        Switch(LVar0)
            CaseEq(0)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                IfEq(LVar1, 0)
                    Call(SetSelfVar, 0, 1)
                    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy_Wander)))
                EndIf
            CaseEq(2)
                Call(DisablePlayerInput, TRUE)
                Wait(25)
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
                Call(SetSelfVar, 0, 0)
                Call(DisablePlayerInput, FALSE)
        EndSwitch
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcDefeat_BoxedShyGuy) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetSelfVar, 0, 2)
            Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_BoxedShyGuy)))
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_BoxedShyGuy) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_BoxedShyGuy)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_BoxedShyGuy)))
    Return
    End
};

NpcData N(NpcData_Toads)[] = {
    {
        .id = NPC_Conductor,
        .pos = { -145.0f, 50.0f, -110.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Conductor),
        .settings = &N(NpcSettings_TrainToad),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TRAIN_CONDUCTOR_ANIMS,
        .tattle = MSG_NpcTattle_OMO_TrainConductor,
    },
    {
        .id = NPC_TrainToad,
        .pos = { -250.0f, 0.0f, 50.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TrainToad),
        .settings = &N(NpcSettings_TrainToad),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TRAIN_TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_OMO_TrainConductor,
    },
};

NpcData N(NpcData_ShyGuy_01) = {
    .id = NPC_ShyGuy_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -15, 0, 365 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -15, 0, 365 },
            .detectSize = { 120 },
        }
    },
    .init = &N(EVS_NpcInit_BoxedShyGuy),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_02) = {
    .id = NPC_ShyGuy_02,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 64, 0, 275 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 64, 0, 275 },
            .detectSize = { 120 },
        }
    },
    .init = &N(EVS_NpcInit_BoxedShyGuy),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_03) = {
    .id = NPC_ShyGuy_03,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 145, 0, 365 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 145, 0, 365 },
            .detectSize = { 120 },
        }
    },
    .init = &N(EVS_NpcInit_BoxedShyGuy),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_04) = {
    .id = NPC_ShyGuy_04,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 224, 0, 275 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 224, 0, 275 },
            .detectSize = { 120 },
        }
    },
    .init = &N(EVS_NpcInit_BoxedShyGuy),
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toads)),
    NPC_GROUP(N(NpcData_ShyGuy_01), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_06),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_06),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_06),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_06),
    {}
};
