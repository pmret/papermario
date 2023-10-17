#include "dgb_15.h"

#define INCLUDE_CLUBBA_WANDER
#include "world/common/enemy/Clubba_Multi.inc.c"

#include "world/common/enemy/TubbaBlubba.inc.c"

NpcSettings N(NpcSettings_Yakkey) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_CLUBBA,
};

extern EvtScript N(EVS_NpcAI_Tubba);

EvtScript N(EVS_WaitForCloseCall) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcPos, NPC_Tubba, LVar1, LVar2, LVar3)
        EVT_SUB(LVar1, LVar0)
        EVT_IF_LT(LVar1, 150)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(GF_DGB15_CloseCallWithTubba, TRUE)
    EVT_SET(AF_DGB_01, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Tubba) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GE(LVar0, -1150)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -50, 0, 180)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -50, 0, 180)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_SET(GB_ARN_Tubba_MapID, 15)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, 88)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim09)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(NpcMoveTo, NPC_SELF, -53, 180, 60)
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim06)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim06, 0, MSG_CH3_00F3)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Tubba)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayFootstepFX) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar6, LVar7, LVar8)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        EVT_IF_NE(LVar3, LVar6)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HEAVY_NPC_STEP_C, SOUND_PARAM_MUTE | SOUND_SPACE_FULL)
            EVT_CALL(GetDist2D, LVarA, LVar0, LVar2, LVar3, LVar5)
            EVT_SWITCH(LVarA)
                EVT_CASE_LT(200)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.6))
                        EVT_WAIT(5)
                        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(0.8))
                    EVT_END_THREAD
                EVT_CASE_LT(300)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.6))
                        EVT_WAIT(5)
                        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(0.3))
                    EVT_END_THREAD
                EVT_CASE_GE(300)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.1))
                        EVT_WAIT(5)
                        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 2, EVT_FLOAT(0.05))
                    EVT_END_THREAD
            EVT_END_SWITCH
            EVT_WAIT(12)
        EVT_ELSE
        EVT_END_IF
        EVT_CALL(GetNpcPos, NPC_SELF, LVar6, LVar7, LVar8)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_Tubba) = {
    .moveSpeed = 3.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .alertOffsetDist = 80.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 180,
    .chaseUpdateInterval = 2,
    .chaseRadius = 160.0f,
    .chaseOffsetDist = 80.0f,
    .unk_AI_2C = 1,
};

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

EvtScript N(EVS_NpcAI_Tubba) = {
    EVT_EXEC(N(EVS_WaitForCloseCall))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim0C)
    EVT_EXEC(N(EVS_PlayFootstepFX))
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(AISettings_Tubba)))
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnkFunc1.inc.c"

EvtScript N(EVS_NpcDefeat_Tubba) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR("dgb_14"), dgb_14_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tubba) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH3_ARRIVED_AT_TUBBAS_MANOR)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_IF_NE(GB_ARN_Tubba_MapID, 15)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Tubba)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, -310, 0, 180)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Tubba)))
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Tubba)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Tubba) = {
    .id = NPC_Tubba,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 7,
            .points  = {
                { -500, 0, 200 },
                { -700, 0, 200 },
                { -900, 0, 200 },
                { -1000, 0, 200 },
                { -800, 0, 200 },
                { -600, 0, 200 },
                { -400, 0, 200 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -500, 0, 200 },
            .detectSize = { 1000, 250 },
        }
    },
    .init = &N(EVS_NpcInit_Tubba),
    .settings = &N(NpcSettings_TubbaBlubba),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
    .drops = CLUBBA_DROPS,
    .animations = TUBBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Tubba), BTL_DGB_FORMATION_04, BTL_DGB_STAGE_00),
    {}
};
