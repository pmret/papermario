#include "trd_06.h"
#include "sprite.h"
#include "sprite/player.h"

extern EvtScript N(EVS_PushSong);
extern EvtScript N(EVS_PopSong);
API_CALLABLE(N(LoadPartyImage));

#include "world/common/util/ChangeNpcToPartner.inc.c"

NpcSettings N(NpcSettings_Bobomb) = {
    .height = 23,
    .radius = 20,
    .level = ACTOR_LEVEL_BOB_OMB,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_KoopaTroopa) = {
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_Bombette_DemonstrateAbility) = {
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 96, 0, 129)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6 / DT))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Walk)
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_PARTNER, 124, 129, 0)
        EVT_CALL(GetAngleToPlayer, NPC_PARTNER, LVar0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVar0, 5)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, 96, 129, 0)
    EVT_CALL(GetAngleToNPC, NPC_PARTNER, LVar0)
    EVT_CALL(InterpPlayerYaw, LVar0, 5)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00E1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bombette) = {
    EVT_THREAD
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT), 0, EVT_FLOAT(300.0), EVT_FLOAT(18.0), EVT_FLOAT(-7.0))
    EVT_END_THREAD
    EVT_CALL(GetAngleToPlayer, NPC_SELF, LVar0)
    EVT_IF_LT(LVar0, 180)
        EVT_SET(LVar1, 27)
    EVT_ELSE
        EVT_SET(LVar1, -27)
    EVT_END_IF
    EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
    EVT_SUB(LVarA, LVar2)
    EVT_IF_LT(LVarA, 0)
        EVT_MUL(LVarA, -1)
    EVT_END_IF
    EVT_IF_LT(LVarA, 20)
        EVT_ADD(LVar2, LVar1)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PlayerMoveTo, LVar2, LVar4, 0)
        EVT_CALL(PlayerFaceNpc, NPC_Bombette, 3)
    EVT_END_IF
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_IF_EQ(GF_TRD06_Met_Bombette, FALSE)
        EVT_SET(GF_TRD06_Met_Bombette, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DA)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
        EVT_CALL(EndSpeech, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DB)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DC)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DD)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.8))
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15 * DT)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DE)
        EVT_CALL(N(ChangeNpcToPartner), NPC_Bombette, PARTNER_BOMBETTE)
        EVT_SET(GB_StoryProgress, STORY_CH1_BOMBETTE_JOINED_PARTY)
        EVT_CALL(N(LoadPartyImage))
        EVT_EXEC(N(EVS_PushSong))
        EVT_WAIT(15 * DT)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_018B, 160, 40)
        EVT_EXEC(N(EVS_PopSong))
        EVT_WAIT(10 * DT)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DF)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
        EVT_WAIT(15 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_WAIT(25 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, -45, 30, EMOTER_NPC, 0, 0, 0, 0)
        EVT_WAIT(40 * DT)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00E0)
        EVT_EXEC_WAIT(N(EVS_Bombette_DemonstrateAbility))
    EVT_END_IF
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bombette) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_BOMBETTE_JOINED_PARTY)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_ELSE
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bombette)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_KoopaTroopa) = {
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_METAL_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 90, 15, EASING_COS_IN_OUT)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o93, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o94, LVar0, 0, 1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_Jailer_KoopaTroopa, -350, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Jailer_Bobomb_01, -370, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Jailer_Bobomb_02, -390, 0, 0)
    EVT_CALL(SetNpcSpeed, NPC_Jailer_KoopaTroopa, EVT_FLOAT(4.0 / DT))
    EVT_CALL(SetNpcSpeed, NPC_Jailer_Bobomb_01, EVT_FLOAT(4.0 / DT))
    EVT_CALL(SetNpcSpeed, NPC_Jailer_Bobomb_02, EVT_FLOAT(4.0 / DT))
    EVT_CALL(SetNpcAnimation, NPC_Jailer_KoopaTroopa, ANIM_KoopaTroopa_Run)
    EVT_CALL(SetNpcAnimation, NPC_Jailer_Bobomb_01, ANIM_Bobomb_Run)
    EVT_CALL(SetNpcAnimation, NPC_Jailer_Bobomb_02, ANIM_Bobomb_Run)
    EVT_CALL(SetNpcFlagBits, NPC_Jailer_KoopaTroopa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Jailer_Bobomb_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Jailer_Bobomb_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Jailer_KoopaTroopa, -237, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(NpcMoveTo, NPC_Jailer_Bobomb_01, -274, 25, 0)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(NpcMoveTo, NPC_Jailer_Bobomb_02, -266, -15, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -260, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -260, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Jailer_Bobomb_01, ANIM_Bobomb_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Jailer_Bobomb_02, ANIM_Bobomb_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Jailer_KoopaTroopa, ANIM_KoopaTroopa_Run, ANIM_KoopaTroopa_Idle, 0, MSG_CH1_00F0)
    EVT_CALL(SetNpcAnimation, NPC_Jailer_Bobomb_01, ANIM_Bobomb_Run)
    EVT_CALL(SetNpcAnimation, NPC_Jailer_Bobomb_02, ANIM_Bobomb_Run)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(MakeLerp, 90, 0, 15, EASING_COS_IN_OUT)
        EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o93, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o94, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_METAL_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Jailer_KoopaTroopa, -233, 147, 0)
        EVT_CALL(NpcMoveTo, NPC_Jailer_KoopaTroopa, -167, 218, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Jailer_Bobomb_01, -254, 144, 0)
        EVT_CALL(NpcMoveTo, NPC_Jailer_Bobomb_01, -203, 222, 0)
    EVT_END_THREAD
    EVT_WAIT(15 * DT)
    EVT_CALL(NpcMoveTo, NPC_Jailer_Bobomb_02, -265, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_Jailer_Bobomb_02, -186, 175, 0)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcJumpscale, NPC_Jailer_KoopaTroopa, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_Jailer_KoopaTroopa, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Jailer_KoopaTroopa, LVar0, LVar1, LVar2, 10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Jailer_Bobomb_01, ANIM_Bobomb_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Jailer_Bobomb_02, ANIM_Bobomb_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Jailer_KoopaTroopa, ANIM_KoopaTroopa_Run, ANIM_KoopaTroopa_Idle, 0, MSG_CH1_00F1)
    EVT_CALL(SetNpcAnimation, NPC_Jailer_Bobomb_01, ANIM_Bobomb_Run)
    EVT_CALL(SetNpcAnimation, NPC_Jailer_Bobomb_02, ANIM_Bobomb_Run)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_KoopaTroopa) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GB_StoryProgress, STORY_CH1_DEFEATED_DUNGEON_GUARDS)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaTroopa)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_KoopaTroopa)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_DUNGEON_GUARDS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_Jailer) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_DUNGEON_GUARDS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_01) = {
    EVT_IF_EQ(GF_TRD06_BombedWall, FALSE)
        EVT_IF_EQ(AF_TRD_MetPrisoner1, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_00E4)
            EVT_SET(AF_TRD_MetPrisoner1, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_00E5)
            EVT_SET(AF_TRD_MetPrisoner1, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_00E6)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_02) = {
    EVT_IF_EQ(GF_TRD06_BombedWall, FALSE)
        EVT_IF_EQ(AF_TRD_MetPrisoner2, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_00E7)
            EVT_SET(AF_TRD_MetPrisoner2, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_00E8)
            EVT_SET(AF_TRD_MetPrisoner2, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_00E9)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_03) = {
    EVT_IF_EQ(GF_TRD06_BombedWall, FALSE)
        EVT_IF_EQ(AF_TRD_MetPrisoner3, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00EA)
            EVT_SET(AF_TRD_MetPrisoner3, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00EB)
            EVT_SET(AF_TRD_MetPrisoner3, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00EC)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_04) = {
    EVT_IF_EQ(GF_TRD06_BombedWall, FALSE)
        EVT_IF_EQ(AF_TRD_MetPrisoner4, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00ED)
            EVT_SET(AF_TRD_MetPrisoner4, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00EE)
            EVT_SET(AF_TRD_MetPrisoner4, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00EF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_04)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Bombette) = {
    .id = NPC_Bombette,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Bombette),
    .settings = &N(NpcSettings_Bobomb),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_WorldBombette_Idle,
        .walk   = ANIM_WorldBombette_Walk,
        .run    = ANIM_WorldBombette_Walk,
        .chase  = ANIM_WorldBombette_Walk,
        .anim_4 = ANIM_WorldBombette_Walk,
        .anim_5 = ANIM_WorldBombette_Walk,
        .death  = ANIM_WorldBombette_Still,
        .hit    = ANIM_WorldBombette_Still,
        .anim_8 = ANIM_WorldBombette_Still,
        .anim_9 = ANIM_WorldBombette_Still,
        .anim_A = ANIM_WorldBombette_Still,
        .anim_B = ANIM_WorldBombette_Still,
        .anim_C = ANIM_WorldBombette_Still,
        .anim_D = ANIM_WorldBombette_Still,
        .anim_E = ANIM_WorldBombette_Still,
        .anim_F = ANIM_WorldBombette_Still,
    },
    .tattle = MSG_NpcTattle_TRD_Bombette,
};

NpcData N(NpcData_Jailers)[] = {
    {
        .id = NPC_Jailer_KoopaTroopa,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_MUSHROOM, 5, 0 },
                { ITEM_HONEY_SYRUP, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
        },
        .animations = {
            .idle   = ANIM_KoopaTroopa_Idle,
            .walk   = ANIM_KoopaTroopa_Walk,
            .run    = ANIM_KoopaTroopa_Run,
            .chase  = ANIM_KoopaTroopa_Run,
            .anim_4 = ANIM_KoopaTroopa_Idle,
            .anim_5 = ANIM_KoopaTroopa_Idle,
            .death  = ANIM_KoopaTroopa_Hurt,
            .hit    = ANIM_KoopaTroopa_Hurt,
            .anim_8 = ANIM_KoopaTroopa_ShellEnter,
            .anim_9 = ANIM_KoopaTroopa_ShellSpin,
            .anim_A = ANIM_KoopaTroopa_ShellExit,
            .anim_B = ANIM_KoopaTroopa_Run,
            .anim_C = ANIM_KoopaTroopa_Run,
            .anim_D = ANIM_KoopaTroopa_Run,
            .anim_E = ANIM_KoopaTroopa_Run,
            .anim_F = ANIM_KoopaTroopa_Run,
        },
    },
    {
        .id = NPC_Jailer_Bobomb_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bobomb_Jailer),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Bobomb_Idle,
            .walk   = ANIM_Bobomb_Walk,
            .run    = ANIM_Bobomb_Run,
            .chase  = ANIM_Bobomb_Run,
            .anim_4 = ANIM_Bobomb_Idle,
            .anim_5 = ANIM_Bobomb_Idle,
            .death  = ANIM_Bobomb_Hurt,
            .hit    = ANIM_Bobomb_Hurt,
            .anim_8 = ANIM_Bobomb_Run,
            .anim_9 = ANIM_Bobomb_Run,
            .anim_A = ANIM_Bobomb_Run,
            .anim_B = ANIM_Bobomb_Run,
            .anim_C = ANIM_Bobomb_Run,
            .anim_D = ANIM_Bobomb_Run,
            .anim_E = ANIM_Bobomb_Run,
            .anim_F = ANIM_Bobomb_Run,
        },
    },
    {
        .id = NPC_Jailer_Bobomb_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bobomb_Jailer),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Bobomb_Idle,
            .walk   = ANIM_Bobomb_Walk,
            .run    = ANIM_Bobomb_Run,
            .chase  = ANIM_Bobomb_Run,
            .anim_4 = ANIM_Bobomb_Idle,
            .anim_5 = ANIM_Bobomb_Idle,
            .death  = ANIM_Bobomb_Hurt,
            .hit    = ANIM_Bobomb_Hurt,
            .anim_8 = ANIM_Bobomb_Run,
            .anim_9 = ANIM_Bobomb_Run,
            .anim_A = ANIM_Bobomb_Run,
            .anim_B = ANIM_Bobomb_Run,
            .anim_C = ANIM_Bobomb_Run,
            .anim_D = ANIM_Bobomb_Run,
            .anim_E = ANIM_Bobomb_Run,
            .anim_F = ANIM_Bobomb_Run,
        },
    },
};

NpcData N(NpcData_Inmates)[] = {
    {
        .id = NPC_Bobomb_01,
        .pos = { 25.0f, 0.0f, 127.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Bobomb_01),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 5, 0 },
                { ITEM_FIRE_FLOWER, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Red_Idle,
            .walk   = ANIM_WorldBobomb_Red_Walk,
            .run    = ANIM_WorldBobomb_Red_Run,
            .chase  = ANIM_WorldBobomb_Red_Run,
            .anim_4 = ANIM_WorldBobomb_Red_Idle,
            .anim_5 = ANIM_WorldBobomb_Red_Idle,
            .death  = ANIM_WorldBobomb_Red_Still,
            .hit    = ANIM_WorldBobomb_Red_Still,
            .anim_8 = ANIM_WorldBobomb_Red_Still,
            .anim_9 = ANIM_WorldBobomb_Red_Still,
            .anim_A = ANIM_WorldBobomb_Red_Still,
            .anim_B = ANIM_WorldBobomb_Red_Still,
            .anim_C = ANIM_WorldBobomb_Red_Still,
            .anim_D = ANIM_WorldBobomb_Red_Still,
            .anim_E = ANIM_WorldBobomb_Red_Still,
            .anim_F = ANIM_WorldBobomb_Red_Still,
        },
        .tattle = MSG_NpcTattle_TRD_BobombA,
    },
    {
        .id = NPC_Bobomb_02,
        .pos = { -30.0f, 0.0f, 130.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bobomb_02),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 5, 0 },
                { ITEM_FIRE_FLOWER, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Blue_Idle,
            .walk   = ANIM_WorldBobomb_Blue_Walk,
            .run    = ANIM_WorldBobomb_Blue_Run,
            .chase  = ANIM_WorldBobomb_Blue_Run,
            .anim_4 = ANIM_WorldBobomb_Blue_Idle,
            .anim_5 = ANIM_WorldBobomb_Blue_Idle,
            .death  = ANIM_WorldBobomb_Blue_Still,
            .hit    = ANIM_WorldBobomb_Blue_Still,
            .anim_8 = ANIM_WorldBobomb_Blue_Still,
            .anim_9 = ANIM_WorldBobomb_Blue_Still,
            .anim_A = ANIM_WorldBobomb_Blue_Still,
            .anim_B = ANIM_WorldBobomb_Blue_Still,
            .anim_C = ANIM_WorldBobomb_Blue_Still,
            .anim_D = ANIM_WorldBobomb_Blue_Still,
            .anim_E = ANIM_WorldBobomb_Blue_Still,
            .anim_F = ANIM_WorldBobomb_Blue_Still,
        },
        .tattle = MSG_NpcTattle_TRD_BobombB,
    },
    {
        .id = NPC_Bobomb_03,
        .pos = { -140.0f, 0.0f, -90.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Bobomb_03),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 5, 0 },
                { ITEM_FIRE_FLOWER, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Green_Idle,
            .walk   = ANIM_WorldBobomb_Green_Walk,
            .run    = ANIM_WorldBobomb_Green_Run,
            .chase  = ANIM_WorldBobomb_Green_Run,
            .anim_4 = ANIM_WorldBobomb_Green_Idle,
            .anim_5 = ANIM_WorldBobomb_Green_Idle,
            .death  = ANIM_WorldBobomb_Green_Still,
            .hit    = ANIM_WorldBobomb_Green_Still,
            .anim_8 = ANIM_WorldBobomb_Green_Still,
            .anim_9 = ANIM_WorldBobomb_Green_Still,
            .anim_A = ANIM_WorldBobomb_Green_Still,
            .anim_B = ANIM_WorldBobomb_Green_Still,
            .anim_C = ANIM_WorldBobomb_Green_Still,
            .anim_D = ANIM_WorldBobomb_Green_Still,
            .anim_E = ANIM_WorldBobomb_Green_Still,
            .anim_F = ANIM_WorldBobomb_Green_Still,
        },
        .tattle = MSG_NpcTattle_TRD_BobombC,
    },
    {
        .id = NPC_Bobomb_04,
        .pos = { -75.0f, 0.0f, -80.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bobomb_04),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 5, 0 },
                { ITEM_FIRE_FLOWER, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Green_Idle,
            .walk   = ANIM_WorldBobomb_Green_Walk,
            .run    = ANIM_WorldBobomb_Green_Run,
            .chase  = ANIM_WorldBobomb_Green_Run,
            .anim_4 = ANIM_WorldBobomb_Green_Idle,
            .anim_5 = ANIM_WorldBobomb_Green_Idle,
            .death  = ANIM_WorldBobomb_Green_Still,
            .hit    = ANIM_WorldBobomb_Green_Still,
            .anim_8 = ANIM_WorldBobomb_Green_Still,
            .anim_9 = ANIM_WorldBobomb_Green_Still,
            .anim_A = ANIM_WorldBobomb_Green_Still,
            .anim_B = ANIM_WorldBobomb_Green_Still,
            .anim_C = ANIM_WorldBobomb_Green_Still,
            .anim_D = ANIM_WorldBobomb_Green_Still,
            .anim_E = ANIM_WorldBobomb_Green_Still,
            .anim_F = ANIM_WorldBobomb_Green_Still,
        },
        .tattle = MSG_NpcTattle_TRD_BobombD,
    },
};

NpcGroupList N(NpcGroup_Prisoners) = {
    NPC_GROUP(N(NpcData_Bombette)),
    NPC_GROUP(N(NpcData_Inmates)),
    NPC_GROUP(N(NpcData_Jailers), BTL_TRD_1_FORMATION_04, BTL_TRD_1_STAGE_0B),
    {}
};
