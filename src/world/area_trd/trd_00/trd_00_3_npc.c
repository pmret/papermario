#include "trd_00.h"
#include "effects.h"
#include "sprite/player.h"

extern EvtScript N(EVS_SetupMusic);

API_CALLABLE(N(UpgradeStarPowerCh1)) {
    set_max_star_power(1);
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    sync_status_bar();
    return ApiStatus_DONE2;
}

#include "world/common/todo/SyncStatusBar.inc.c"

NpcSettings N(NpcSettings_KoopaBros) = {
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_NpcIdle_KoopaBros) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(AwaitPlayerApproach, -580, 276, 50)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_tt2, SOUND_METAL_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 0, 100, 10, EASING_COS_IN_OUT)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o62, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_doa, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -570, 0, 173)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Run)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.5 / DT))
    EVT_CALL(NpcMoveTo, NPC_SELF, -556, 180, 0)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ANIM, IMGFX_ANIM_STARTLE, 2, 1, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Shock)
    EVT_WAIT(12 * DT)
    EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KoopaBros_Black_Talk, ANIM_KoopaBros_Black_Idle, 0, MSG_CH1_00D2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Walk)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 45, 2)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_RUN_AWAY_BUILDUP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_KoopaBros_Black_Run)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.8))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 8 * DT)
    EVT_WAIT(8 * DT)
    EVT_WAIT(12 * DT)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(8.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_SELF, -496, 101, 0)
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 100, 0, 10, EASING_COS_IN_OUT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o62, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_doa, LVar0, 0, 1, 0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tt2, SOUND_METAL_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_WAIT(10 * DT)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.5 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(GB_StoryProgress, STORY_CH1_SPOTTED_BY_KOOPA_BROS)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaBros) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaBros)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_SPOTTED_BY_KOOPA_BROS)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Eldstar) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Eldstar) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241DA4_99BA14) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(SetNpcPos, NPC_Eldstar, -567, 26, 236)
    EVT_CALL(PlayerFaceNpc, NPC_Eldstar, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Eldstar, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -527, 0, 216)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -527, 0, 216)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(475.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_010D)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Eldstar, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, NPC_Eldstar, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Leap)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_UsePower)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_ADD(LVar0, 5)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 30)
    EVT_LOOP(6)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        EVT_WAIT(6 * DT)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        EVT_WAIT(6 * DT)
    EVT_END_LOOP
    EVT_WAIT(20 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    EVT_WAIT(40 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Idle)
    EVT_CALL(EnableNpcAI, NPC_Eldstar, TRUE)
    EVT_CALL(N(UpgradeStarPowerCh1))
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0191, 160, 40)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_010E)
    EVT_CALL(ShowChoice, MSG_Choice_0013)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_010F)
        EVT_CALL(ShowChoice, MSG_Choice_0013)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(ContinueSpeech, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_0110)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_0111)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(StartBattle)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(FullyRestoreSP)
    EVT_CALL(N(SyncStatusBar))
    EVT_LABEL(10)
    EVT_WAIT(30 * DT)
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_0112)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -527, 0, 216)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 512, MSG_CH1_0113)
    EVT_CALL(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            EVT_WAIT(4 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0x00000708)
        EVT_CALL(MakeLerp, LVar2, LVar3, 100 * DT, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Eldstar, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Eldstar, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, 180)
        EVT_CALL(MakeLerp, LVar3, LVar5, 100 * DT, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_Eldstar, LVar2, LVar0, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Eldstar, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Eldstar, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(90 * DT)
    EVT_CALL(ResetCam, CAM_DEFAULT, 3)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_SET(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, trd_00_ENTRY_5)
        EVT_CALL(GetLoadType, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_ELSE
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Eldstar)))
            EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Eldstar)))
            EVT_EXEC(N(D_80241DA4_99BA14))
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_KoopaBros) = {
    .id = NPC_KoopaBros,
    .pos = { -469.0f, 0.0f, 101.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_KoopaBros),
    .settings = &N(NpcSettings_KoopaBros),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_KoopaBros_Green_Idle,
        .walk   = ANIM_KoopaBros_Green_Walk,
        .run    = ANIM_KoopaBros_Green_Run,
        .chase  = ANIM_KoopaBros_Green_Run,
        .anim_4 = ANIM_KoopaBros_Green_Idle,
        .anim_5 = ANIM_KoopaBros_Green_Idle,
        .death  = ANIM_KoopaBros_Green_HurtStill,
        .hit    = ANIM_KoopaBros_Green_HurtStill,
        .anim_8 = ANIM_KoopaBros_Green_Run,
        .anim_9 = ANIM_KoopaBros_Green_Run,
        .anim_A = ANIM_KoopaBros_Green_Run,
        .anim_B = ANIM_KoopaBros_Green_Run,
        .anim_C = ANIM_KoopaBros_Green_Run,
        .anim_D = ANIM_KoopaBros_Green_Run,
        .anim_E = ANIM_KoopaBros_Green_Run,
        .anim_F = ANIM_KoopaBros_Green_Run,
    },
};

NpcData N(NpcData_Eldstar) = {
    .id = NPC_Eldstar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { NPC_DISPOSE_LOCATION },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { NPC_DISPOSE_LOCATION },
            .detectSize = { 500 },
        }
    },
    .init = &N(EVS_NpcInit_Eldstar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = ELDSTAR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaBros)),
    NPC_GROUP(N(NpcData_Eldstar), BTL_TRD_3_FORMATION_00),
    {}
};
