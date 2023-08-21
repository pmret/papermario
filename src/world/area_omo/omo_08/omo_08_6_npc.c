#include "omo_08.h"

#include "world/common/npc/TrainToad.inc.c"
#include "world/common/enemy/ShyGuy_Wander.inc.c"

EvtScript N(EVS_NpcInteract_Conductor) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_80247100))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Conductor) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Conductor)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_TrainToad) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_SOLVED_COLOR_PUZZLE)
            EVT_CALL(FindKeyItem, ITEM_MYSTERY_NOTE, LVar0)
            EVT_IF_EQ(LVar0, -1)
                EVT_IF_EQ(GF_OMO09_SpawnedPeachChoice3, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002B)
                EVT_ELSE
                    EVT_IF_EQ(GF_OMO09_Chest_Dictionary, FALSE)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002C)
                    EVT_ELSE
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002F)
                    EVT_END_IF
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002D)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002E)
        EVT_CASE_LT(STORY_CH4_DEFEATED_GENERAL_GUY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_002F)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_TrainToad_Green_Talk, ANIM_TrainToad_Green_Idle, 0, MSG_CH4_0030)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrainToad) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TrainToad)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_BoxedShyGuy) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetSelfVar, 0, 1)
                    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy_Wander)))
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_WAIT(25)
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
                EVT_CALL(SetSelfVar, 0, 0)
                EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_BoxedShyGuy) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetSelfVar, 0, 2)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_BoxedShyGuy)))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BoxedShyGuy) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_BoxedShyGuy)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_BoxedShyGuy)))
    EVT_RETURN
    EVT_END
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
