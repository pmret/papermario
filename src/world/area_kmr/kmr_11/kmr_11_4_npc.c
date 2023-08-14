#include "kmr_11.h"

#include "world/common/enemy/GoombaBros_Guard.inc.c"

EvtScript N(EVS_NpcIdle_GoombaBros_01) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_GoombaBros_02) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_GoombaKing) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_IF_EQ(GF_KMR11_GoombaBrosFledToCastle, TRUE)
                EVT_CALL(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
                EVT_CALL(AwaitPlayerApproach, LVar0, LVar2, 300)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
                EVT_CALL(PlayerMoveTo, -564, -64, 0)
            EVT_ELSE
                EVT_LABEL(0)
                EVT_CALL(GetSelfVar, 0, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_WAIT(1)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_GE(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetNpcJumpscale, NPC_RedGoombaBro, EVT_FLOAT(0.8))
    EVT_CALL(SetNpcJumpscale, NPC_BlueGoombaBro, EVT_FLOAT(0.8))
    EVT_CALL(SetNpcJumpscale, NPC_GoombaKing, EVT_FLOAT(0.8))
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_RedGoombaBro, LVar0, LVar1, LVar2)
        EVT_CALL(GetAngleToPlayer, NPC_RedGoombaBro, LVar3)
        EVT_CALL(AddVectorPolar, LVar0, LVar2, EVT_FLOAT(100.0), LVar3)
        EVT_CALL(PlaySoundAtNpc, NPC_RedGoombaBro, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_RedGoombaBro, LVar0, 0, LVar2, 30 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_BlueGoombaBro, LVar0, LVar1, LVar2)
        EVT_CALL(GetAngleToPlayer, NPC_BlueGoombaBro, LVar3)
        EVT_CALL(AddVectorPolar, LVar0, LVar2, EVT_FLOAT(100.0), LVar3)
        EVT_CALL(PlaySoundAtNpc, NPC_BlueGoombaBro, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_BlueGoombaBro, LVar0, 0, LVar2, 30 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
        EVT_CALL(GetAngleToPlayer, NPC_GoombaKing, LVar3)
        EVT_CALL(AddVectorPolar, LVar0, LVar2, EVT_FLOAT(100.0), LVar3)
        EVT_CALL(PlaySoundAtNpc, NPC_GoombaKing, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_GoombaKing, LVar0, 0, LVar2, 30 * DT)
    EVT_END_THREAD
    EVT_WAIT(15 * DT)
    EVT_CALL(StartBossBattle, SONG_GOOMBA_KING_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BossDefeated) = {
    EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
    EVT_CALL(N(SetupFog))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(N(SetCameraVFov), 25)
    EVT_CALL(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Walk, ANIM_GoombaKing_Idle, 0, MSG_CH0_00D1)
    EVT_CALL(SetNpcSpeed, NPC_BlueGoombaBro, EVT_FLOAT(6.0 / DT))
    EVT_CALL(SetNpcSpeed, NPC_RedGoombaBro, EVT_FLOAT(6.0 / DT))
    EVT_CALL(SetNpcSpeed, NPC_GoombaKing, EVT_FLOAT(6.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_Run)
    EVT_CALL(SetNpcAnimation, NPC_RedGoombaBro, ANIM_GoombaBros_Red_Run)
    EVT_CALL(SetNpcAnimation, NPC_GoombaKing, ANIM_GoombaKing_Run)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_GoombaKing, -358, -107, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(NpcMoveTo, NPC_BlueGoombaBro, -396, -121, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(NpcMoveTo, NPC_RedGoombaBro, -396, -89, 0)
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tt, SOUND_METAL_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 90, 20, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o416, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o415, LVar0, 0, 1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(5 * DT)
    EVT_CALL(MakeLerp, 90, 0, 20, EASING_COS_IN_OUT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o416, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o415, LVar0, 0, 1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tt, SOUND_METAL_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(2.0))
    EVT_SET(GB_StoryProgress, STORY_CH0_DEFEATED_GOOMBA_KING)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT), 0, EVT_FLOAT(250.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
    EVT_WAIT(10 * DT)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_00D2)
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(10 * DT)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_WAIT(40)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_BlueGoombaBro, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_RedGoombaBro, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_GoombaKing) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_EXEC_WAIT(N(EVS_Scene_BossDefeated))
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetPlayerSpeed, EVT_FLOAT(6.0))
            EVT_CALL(PlayerMoveTo, -954, -50, 0)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_GoombaBros_01) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_GoombaBros_02) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_Kammy) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#define KAMMY_NPC NPC_Kammy
#include "world/common/util/GetKammyBroomEmitterPos.inc.c"

EvtScript N(EVS_NpcAux_Kammy) = {
    EVT_LABEL(1)
        // wait to be activated
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar6, LVar7, LVar8)
    EVT_LABEL(0)
        EVT_CALL(N(GetKammyBroomEmitterPos))
        EVT_CALL(GetNpcPos, NPC_Kammy, LVar9, LVarA, LVarB)
        EVT_VEC3I_VSET(LVar3, LVar9)
        EVT_VEC3I_VSUB(LVar3, LVar6)
        EVT_VEC3I_VSET(LVar6, LVar9)
        EVT_IF_EQ(LVar3, 0)
            EVT_IF_EQ(LVar5, 0)
            EVT_ELSE
                EVT_PLAY_EFFECT(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0))
            EVT_END_IF
        EVT_ELSE
            EVT_PLAY_EFFECT(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0))
        EVT_END_IF
        EVT_WAIT(3)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(KammyFloatingOffsets)[] = {
     1,  2,  3,  2,  1,
    -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcAI_Kammy) = {
    EVT_LABEL(0)
        EVT_USE_BUF(EVT_PTR(N(KammyFloatingOffsets)))
        EVT_LOOP(ARRAY_COUNT(N(KammyFloatingOffsets)))
            EVT_BUF_READ1(LVar1)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            EVT_ADD(LVar3, LVar1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            EVT_WAIT(3)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GoombaBros_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_GoombaBros_01)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_GoombaBros_01)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_IF_EQ(GF_KMR11_GoombaBrosFledToCastle, TRUE)
                EVT_CALL(SetNpcPos, NPC_BlueGoombaBro, -432, 130, -146)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_CALL(SetNpcPos, NPC_BlueGoombaBro, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetNpcFlagBits, NPC_BlueGoombaBro, NPC_FLAG_GRAVITY, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GoombaBros_02) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_GoombaBros_02)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_GoombaBros_02)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_IF_EQ(GF_KMR11_GoombaBrosFledToCastle, TRUE)
                EVT_CALL(SetNpcPos, NPC_RedGoombaBro, -412, 130, -35)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_CALL(SetNpcPos, NPC_RedGoombaBro, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetNpcFlagBits, NPC_RedGoombaBro, NPC_FLAG_GRAVITY, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GoombaKing) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_GoombaKing)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_GoombaKing)))
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 70, 50)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_DEFEATED_GOOMBA_KING)
            EVT_IF_EQ(GF_KMR11_GoombaBrosFledToCastle, TRUE)
                EVT_CALL(SetNpcPos, NPC_GoombaKing, -419, 119, -91)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH0_HIT_GATEHOUSE_SWITCH)
            EVT_CALL(SetNpcPos, NPC_GoombaKing, -358, 0, -107)
        EVT_CASE_GE(STORY_CH0_HIT_GATEHOUSE_SWITCH)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Kammy) = {
    .defaultAnim = ANIM_WorldKammy_Anim0A,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_Kammy),
    .ai = &N(EVS_NpcAI_Kammy),
    .aux = &N(EVS_NpcAux_Kammy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
};

NpcData N(NpcData_Enemies)[] = {
    {
        .id = NPC_BlueGoombaBro,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_GoombaBros_01),
        .settings = &N(NpcSettings_GoombaBros_Guard),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_GoombaBros_Blue_Idle,
            .walk   = ANIM_GoombaBros_Blue_Walk,
            .run    = ANIM_GoombaBros_Blue_Run,
            .chase  = ANIM_GoombaBros_Blue_Run,
            .anim_4 = ANIM_GoombaBros_Blue_Idle,
            .anim_5 = ANIM_GoombaBros_Blue_Idle,
            .death  = ANIM_GoombaBros_Blue_Hurt,
            .hit    = ANIM_GoombaBros_Blue_Hurt,
            .anim_8 = ANIM_GoombaBros_Blue_Run,
            .anim_9 = ANIM_GoombaBros_Blue_Run,
            .anim_A = ANIM_GoombaBros_Blue_Run,
            .anim_B = ANIM_GoombaBros_Blue_Run,
            .anim_C = ANIM_GoombaBros_Blue_Run,
            .anim_D = ANIM_GoombaBros_Blue_Run,
            .anim_E = ANIM_GoombaBros_Blue_Run,
            .anim_F = ANIM_GoombaBros_Blue_Run,
        },
    },
    {
        .id = NPC_RedGoombaBro,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_GoombaBros_02),
        .settings = &N(NpcSettings_GoombaBros_Guard),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_GoombaBros_Red_Idle,
            .walk   = ANIM_GoombaBros_Red_Walk,
            .run    = ANIM_GoombaBros_Red_Run,
            .chase  = ANIM_GoombaBros_Red_Run,
            .anim_4 = ANIM_GoombaBros_Red_Idle,
            .anim_5 = ANIM_GoombaBros_Red_Idle,
            .death  = ANIM_GoombaBros_Red_Hurt,
            .hit    = ANIM_GoombaBros_Red_Hurt,
            .anim_8 = ANIM_GoombaBros_Red_Run,
            .anim_9 = ANIM_GoombaBros_Red_Run,
            .anim_A = ANIM_GoombaBros_Red_Run,
            .anim_B = ANIM_GoombaBros_Red_Run,
            .anim_C = ANIM_GoombaBros_Red_Run,
            .anim_D = ANIM_GoombaBros_Red_Run,
            .anim_E = ANIM_GoombaBros_Red_Run,
            .anim_F = ANIM_GoombaBros_Red_Run,
        },
    },
    {
        .id = NPC_GoombaKing,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_GoombaKing),
        .settings = &N(NpcSettings_GoombaBros_Guard),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_GoombaKing_Idle,
            .walk   = ANIM_GoombaKing_Walk,
            .run    = ANIM_GoombaKing_Run,
            .chase  = ANIM_GoombaKing_Run,
            .anim_4 = ANIM_GoombaKing_Idle,
            .anim_5 = ANIM_GoombaKing_Idle,
            .death  = ANIM_GoombaKing_Dead,
            .hit    = ANIM_GoombaKing_Dead,
            .anim_8 = ANIM_GoombaKing_Run,
            .anim_9 = ANIM_GoombaKing_Run,
            .anim_A = ANIM_GoombaKing_Run,
            .anim_B = ANIM_GoombaKing_Run,
            .anim_C = ANIM_GoombaKing_Run,
            .anim_D = ANIM_GoombaKing_Run,
            .anim_E = ANIM_GoombaKing_Run,
            .anim_F = ANIM_GoombaKing_Run,
        },
    },
};

NpcData N(NpcData_Kammy) = {
    .id = NPC_Kammy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 100,
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_Kammy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .animations = {},
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Enemies), BTL_KMR_2_FORMATION_01),
    NPC_GROUP(N(NpcData_Kammy)),
    {}
};
