#include "kpa_81.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,choice);
#include "world/common/complete/NormalItemChoice.inc.c"

EvtScript N(EVS_EnsurePartnerNeutral) = {
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_IF_EQ(LVar0, PARTNER_BOMBETTE)
            EVT_LOOP(0)
                EVT_CALL(GetPartnerInUse, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar0, PARTNER_NONE)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_ELSE
            EVT_CALL(InterruptUsePartner)
            EVT_WAIT(20)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Door) = {
    EVT_IF_EQ(GB_KPA81_BowserDoorState, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GB_KPA81_BowserDoorState, 1)
        EVT_SET(GB_KPA81_BowserDoorState, 2)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(35)
        EVT_CALL(SetCamType, CAM_DEFAULT, 6, FALSE)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 109, 0, 202)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-10.0))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
        EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(133.0), EVT_FLOAT(100.0))
        EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(216.0), EVT_FLOAT(230.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_THREAD
            EVT_CALL(SetMusicTrack, 0, SONG_FINAL_BOWSER_BATTLE, 1, 8)
            EVT_WAIT(150 * DT)
            EVT_CALL(FadeOutMusic, 0, 250)
            EVT_WAIT(15 * DT)
            EVT_EXEC(N(EVS_SetupMusic))
        EVT_END_THREAD
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0008)
        EVT_EXEC(N(EVS_SetupMusic))
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PlayerMoveTo, -115, LVar2, 0)
    EVT_CALL(SetCamType, CAM_DEFAULT, 6, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 109, 0, 202)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(133.0), EVT_FLOAT(100.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(216.0), EVT_FLOAT(230.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(SetMusicTrack, 0, SONG_FINAL_BOWSER_BATTLE, 1, 8)
        EVT_WAIT(150 * DT)
        EVT_CALL(FadeOutMusic, 0, 250)
        EVT_WAIT(15 * DT)
        EVT_EXEC(N(EVS_SetupMusic))
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0000)
    EVT_CALL(ShowChoice, MSG_Choice_0013)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0003)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_LABEL(100)
        EVT_WAIT(1)
        EVT_CALL(IsPlayerWithin, 120, 150, 30, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_ADD(LVar1, 1)
        EVT_IF_LE(LVar1, 300 * DT)
            EVT_GOTO(100)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_EXEC_WAIT(N(EVS_EnsurePartnerNeutral))
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0004)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(AwaitPlayerApproach, 120, 150, 30)
        EVT_GOTO(2)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0002)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(AwaitPlayerApproach, 120, 150, 30)
    EVT_END_IF
    EVT_LABEL(2)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_EnsurePartnerNeutral))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0001)
    EVT_CALL(ShowChoice, MSG_Choice_0013)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(4)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0002)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(AwaitPlayerLeave, 120, 150, 30)
        EVT_CALL(AwaitPlayerApproach, 120, 150, 30)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_LABEL(3)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_EnsurePartnerNeutral))
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 10)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0005)
    EVT_GOTO(5)
    EVT_LABEL(4)
    EVT_EXEC_WAIT(N(EVS_EnsurePartnerNeutral))
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 10)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0006)
    EVT_LABEL(5)
    EVT_CALL(SetCamType, CAM_DEFAULT, 6, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 163, -71, 108)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-16.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(133.0), EVT_FLOAT(100.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(216.0), EVT_FLOAT(230.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(EnableModel, MODEL_o166, TRUE)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(EnableModel, MODEL_o165, FALSE)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitts, SOUND_OPEN_TRAPDOOR, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 90, 30, EASING_COS_SLOW_OVERSHOOT)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o165, LVar0, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o167, LVar0, 0, 0, 1)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Flail)
    EVT_WAIT(30 * DT)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_PanicStill)
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_PLAYER_LONG_FALL, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_LOOP(65)
            EVT_SUB(LVar1, 16)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_LOOP(65)
            EVT_SUB(LVar1, 16)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(65)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(GB_KPA81_BowserDoorState, 1)
    EVT_CALL(GotoMap, EVT_PTR(N(KPA_17)), kpa_17_ENTRY_0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Door) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Door)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, 184, 20, 150)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Door) = {
    .id = NPC_Door,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Door),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Door), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    {}
};
