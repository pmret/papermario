#include "isk_16.h"

EvtScript N(EVS_NpcIdle_Tutankoopa_01) = {
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(StartBossBattle, SONG_TUTANKOOPA_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Tutankoopa_01) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_1, TRUE)
            EVT_CALL(InterpPlayerYaw, 90, 0)
            EVT_EXEC_WAIT(N(EVS_Scene_TutankoopaDefeated))
            EVT_EXEC(N(EVS_SpawnStarCard))
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tutankoopa_01) = {
    EVT_CALL(InterpNpcYaw, NPC_Tutankoopa_01, 150, 1)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_DEFEATED_TUTANKOOPA)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Tutankoopa_01)))
            EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Tutankoopa_01)))
        EVT_CASE_GE(STORY_CH2_DEFEATED_TUTANKOOPA)
            EVT_CALL(SetNpcPos, NPC_Tutankoopa_01, 0, -1500, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ChainChomp) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Tutankoopa_01) = {
    .defaultAnim = ANIM_Tutankoopa_Idle,
    .height = 40,
    .radius = 36,
};

NpcSettings N(NpcSettings_ChainChomp) = {
    .defaultAnim = ANIM_ChainChomp_QuickBite,
    .height = 32,
    .radius = 32,
};

NpcSettings N(NpcSettings_Tutankoopa_02) = {
    .defaultAnim = ANIM_Tutankoopa_Still,
    .height = 40,
    .radius = 36,
};

NpcData N(NpcData_Tutankoopa)[] = {
    {
        .id = NPC_Tutankoopa_01,
        .pos = { 457.0f, -1300.0f, 316.0f },
        .yaw = 230,
        .init = &N(EVS_NpcInit_Tutankoopa_01),
        .initVarCount = 1,
        .initVar = { .value = 0 },
        .settings = &N(NpcSettings_Tutankoopa_01),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Tutankoopa_Idle,
            .walk   = ANIM_Tutankoopa_Idle,
            .run    = ANIM_Tutankoopa_Idle,
            .chase  = ANIM_Tutankoopa_Idle,
            .anim_4 = ANIM_Tutankoopa_Idle,
            .anim_5 = ANIM_Tutankoopa_Idle,
            .death  = ANIM_Tutankoopa_Hurt,
            .hit    = ANIM_Tutankoopa_Hurt,
            .anim_8 = ANIM_Tutankoopa_Idle,
            .anim_9 = ANIM_Tutankoopa_Idle,
            .anim_A = ANIM_Tutankoopa_Idle,
            .anim_B = ANIM_Tutankoopa_Idle,
            .anim_C = ANIM_Tutankoopa_Idle,
            .anim_D = ANIM_Tutankoopa_Idle,
            .anim_E = ANIM_Tutankoopa_Idle,
            .anim_F = ANIM_Tutankoopa_Idle,
        },
    },
    {
        .id = NPC_Tutankoopa_02,
        .pos = { 500.0f, -1300.0f, 316.0f },
        .yaw = 230,
        .settings = &N(NpcSettings_Tutankoopa_02),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Tutankoopa_Idle,
            .walk   = ANIM_Tutankoopa_Idle,
            .run    = ANIM_Tutankoopa_Idle,
            .chase  = ANIM_Tutankoopa_Idle,
            .anim_4 = ANIM_Tutankoopa_Idle,
            .anim_5 = ANIM_Tutankoopa_Idle,
            .death  = ANIM_Tutankoopa_Hurt,
            .hit    = ANIM_Tutankoopa_Hurt,
            .anim_8 = ANIM_Tutankoopa_Idle,
            .anim_9 = ANIM_Tutankoopa_Idle,
            .anim_A = ANIM_Tutankoopa_Idle,
            .anim_B = ANIM_Tutankoopa_Idle,
            .anim_C = ANIM_Tutankoopa_Idle,
            .anim_D = ANIM_Tutankoopa_Idle,
            .anim_E = ANIM_Tutankoopa_Idle,
            .anim_F = ANIM_Tutankoopa_Idle,
        },
    },
};

NpcData N(NpcData_ChainChomp) = {
    .id = NPC_ChainChomp,
    .pos = { 457.0f, -1300.0f, 316.0f },
    .yaw = 230,
    .init = &N(EVS_NpcInit_ChainChomp),
    .settings = &N(NpcSettings_ChainChomp),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_ChainChomp_Still,
        .walk   = ANIM_ChainChomp_Still,
        .run    = ANIM_ChainChomp_Still,
        .chase  = ANIM_ChainChomp_Still,
        .anim_4 = ANIM_ChainChomp_Still,
        .anim_5 = ANIM_ChainChomp_Still,
        .death  = ANIM_ChainChomp_Still,
        .hit    = ANIM_ChainChomp_Still,
        .anim_8 = ANIM_ChainChomp_Still,
        .anim_9 = ANIM_ChainChomp_Still,
        .anim_A = ANIM_ChainChomp_Still,
        .anim_B = ANIM_ChainChomp_Still,
        .anim_C = ANIM_ChainChomp_Still,
        .anim_D = ANIM_ChainChomp_Still,
        .anim_E = ANIM_ChainChomp_Still,
        .anim_F = ANIM_ChainChomp_Still,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Tutankoopa), BTL_ISK_2_FORMATION_00, BTL_ISK_2_STAGE_01),
    NPC_GROUP(N(NpcData_ChainChomp)),
    {}
};
