#include "jan_23.h"
#include "sprite/player.h"

#include "world/common/npc/RaphaelRaven.inc.c"
#include "world/common/npc/Raven.inc.c"

EvtScript N(EVS_Ravens_Converse) = {
    EVT_LOOP(4)
        EVT_CALL(SetNpcAnimation, NPC_RaphaelRaven, ANIM_RaphaelRaven_TalkNoFeet)
        EVT_CALL(InterpNpcYaw, NPC_Raven_01, 90, 1)
        EVT_CALL(InterpNpcYaw, NPC_Raven_02, 270, 1)
        EVT_CALL(InterpNpcYaw, NPC_Raven_03, 0, 4)
        EVT_CALL(InterpNpcYaw, NPC_Raven_04, 90, 1)
        EVT_CALL(InterpNpcYaw, NPC_Raven_05, 270, 1)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_RaphaelRaven, ANIM_RaphaelRaven_IdleNoFeet)
        EVT_CALL(InterpNpcYaw, NPC_Raven_01, 270, 2)
        EVT_CALL(InterpNpcYaw, NPC_Raven_02, 90, 1)
        EVT_CALL(InterpNpcYaw, NPC_Raven_03, 0, 1)
        EVT_CALL(InterpNpcYaw, NPC_Raven_04, 270, 4)
        EVT_CALL(InterpNpcYaw, NPC_Raven_05, 90, 1)
        EVT_WAIT(20)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Raven_01, 0, 1)
    EVT_CALL(InterpNpcYaw, NPC_Raven_02, 0, 1)
    EVT_CALL(InterpNpcYaw, NPC_Raven_03, 0, 1)
    EVT_CALL(InterpNpcYaw, NPC_Raven_04, 0, 1)
    EVT_CALL(InterpNpcYaw, NPC_Raven_05, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven1_Descend) = {
    EVT_CALL(SetNpcRotationPivot, NPC_Raven_01, 50)
    EVT_LOOP(2)
        EVT_SET(LVar3, -30)
        EVT_LOOP(20)
            EVT_CALL(SetNpcRotation, NPC_Raven_01, 0, 0, LVar3)
            EVT_ADD(LVar3, 3)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(20)
            EVT_CALL(SetNpcRotation, NPC_Raven_01, 0, 0, LVar3)
            EVT_ADD(LVar3, -3)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_LOOP(10)
        EVT_CALL(SetNpcRotation, NPC_Raven_01, 0, 0, LVar3)
        EVT_ADD(LVar3, 3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcRotationPivot, NPC_Raven_01, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven2_Descend) = {
    EVT_CALL(SetNpcRotationPivot, NPC_Raven_02, 60)
    EVT_LOOP(2)
        EVT_SET(LVar3, -30)
        EVT_LOOP(20)
            EVT_CALL(SetNpcRotation, NPC_Raven_02, 0, 0, LVar3)
            EVT_ADD(LVar3, 3)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(20)
            EVT_CALL(SetNpcRotation, NPC_Raven_02, 0, 0, LVar3)
            EVT_ADD(LVar3, -3)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_LOOP(10)
        EVT_CALL(SetNpcRotation, NPC_Raven_02, 0, 0, LVar3)
        EVT_ADD(LVar3, 3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcRotationPivot, NPC_Raven_02, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven3_Descend) = {
    EVT_CALL(SetNpcRotationPivot, NPC_Raven_03, 50)
    EVT_LOOP(2)
        EVT_SET(LVar3, -30)
        EVT_LOOP(20)
            EVT_CALL(SetNpcRotation, NPC_Raven_03, 0, 0, LVar3)
            EVT_ADD(LVar3, 3)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(20)
            EVT_CALL(SetNpcRotation, NPC_Raven_03, 0, 0, LVar3)
            EVT_ADD(LVar3, -3)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_LOOP(10)
        EVT_CALL(SetNpcRotation, NPC_Raven_03, 0, 0, LVar3)
        EVT_ADD(LVar3, 3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcRotationPivot, NPC_Raven_03, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven4_Descend) = {
    EVT_CALL(SetNpcRotationPivot, NPC_Raven_04, 60)
    EVT_LOOP(2)
        EVT_SET(LVar3, -30)
        EVT_LOOP(20)
            EVT_CALL(SetNpcRotation, NPC_Raven_04, 0, 0, LVar3)
            EVT_ADD(LVar3, 3)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(20)
            EVT_CALL(SetNpcRotation, NPC_Raven_04, 0, 0, LVar3)
            EVT_ADD(LVar3, -3)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_LOOP(10)
        EVT_CALL(SetNpcRotation, NPC_Raven_04, 0, 0, LVar3)
        EVT_ADD(LVar3, 3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcRotationPivot, NPC_Raven_04, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven5_Descend) = {
    EVT_CALL(SetNpcRotationPivot, NPC_Raven_05, 50)
    EVT_LOOP(2)
        EVT_SET(LVar3, -30)
        EVT_LOOP(20)
            EVT_CALL(SetNpcRotation, NPC_Raven_05, 0, 0, LVar3)
            EVT_ADD(LVar3, 3)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(20)
            EVT_CALL(SetNpcRotation, NPC_Raven_05, 0, 0, LVar3)
            EVT_ADD(LVar3, -3)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_LOOP(10)
        EVT_CALL(SetNpcRotation, NPC_Raven_05, 0, 0, LVar3)
        EVT_ADD(LVar3, 3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcRotationPivot, NPC_Raven_05, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven1_MoveToMeetingPos) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Raven_01, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_Raven_01, 540, 85, 0)
    EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Raven_01, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven2_MoveToMeetingPos) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Raven_02, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_Raven_02, 560, 132, 0)
    EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Raven_02, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven3_MoveToMeetingPos) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Raven_03, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_Raven_03, 590, 105, 0)
    EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Raven_03, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven4_MoveToMeetingPos) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Raven_04, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_Raven_04, 615, 122, 0)
    EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Raven_04, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven5_Sweat) = {
    EVT_LABEL(0)
        EVT_CALL(ShowSweat, NPC_Raven_05, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        EVT_WAIT(8)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Raven5_MoveToMeetingPos) = {
    EVT_WAIT(10)
    EVT_EXEC_GET_TID(N(EVS_Raven5_Sweat), LVar9)
    EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Raven_05, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_Raven_05, 645, 78, 0)
    EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Raven_05, 0, 1)
    EVT_WAIT(15)
    EVT_KILL_THREAD(LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_RaphaelRaven_Before) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 460)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 0, MSG_CH5_00DA)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(35 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 5, MSG_CH5_00DB)
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_SET(MF_Unk_00, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeetAngry, ANIM_RaphaelRaven_TalkNoFeetAngry, 5, MSG_CH5_00DC)
        EVT_SET(MF_Unk_00, TRUE)
    EVT_END_THREAD
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeetAngry)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(12.0))
    EVT_LOOP(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BIG_DRUM_A, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 310)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BIG_DRUM_B, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 460)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_LOOP
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 0, 10)
    EVT_LABEL(2)
        EVT_IF_EQ(MF_Unk_00, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_IdleNoFeet)
    EVT_WAIT(15 * DT)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_ADD(LVar1, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 580)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
    EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Flail)
    EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Flail)
    EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Flail)
    EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Flail)
    EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Flail)
    EVT_CALL(SetNpcPos, NPC_Raven_01, 800, 450, -20)
    EVT_CALL(SetNpcPos, NPC_Raven_02, 820, 452, 0)
    EVT_CALL(SetNpcPos, NPC_Raven_03, 840, 452, 27)
    EVT_CALL(SetNpcPos, NPC_Raven_04, 830, 452, 56)
    EVT_CALL(SetNpcPos, NPC_Raven_05, 795, 455, 20)
    EVT_CALL(EnableNpcShadow, NPC_Raven_01, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Raven_02, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Raven_03, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Raven_04, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Raven_05, FALSE)
    EVT_THREAD
        EVT_EXEC(N(EVS_Raven1_Descend))
        EVT_CALL(SetNpcJumpscale, NPC_Raven_01, 0)
        EVT_CALL(GetNpcPos, NPC_Raven_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -120)
        EVT_ADD(LVar1, -250)
        EVT_ADD(LVar2, 63)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_01, SOUND_RAVEN_FALL_A, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Raven_01, LVar0, LVar1, LVar2, 100)
        EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
        EVT_CALL(EnableNpcShadow, NPC_Raven_01, TRUE)
        EVT_EXEC_WAIT(N(EVS_Raven1_MoveToMeetingPos))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_EXEC(N(EVS_Raven2_Descend))
        EVT_CALL(SetNpcJumpscale, NPC_Raven_02, 0)
        EVT_CALL(GetNpcPos, NPC_Raven_02, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -120)
        EVT_ADD(LVar1, -250)
        EVT_ADD(LVar2, 63)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_02, SOUND_RAVEN_FALL_B, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Raven_02, LVar0, LVar1, LVar2, 100)
        EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
        EVT_CALL(EnableNpcShadow, NPC_Raven_02, TRUE)
        EVT_EXEC_WAIT(N(EVS_Raven2_MoveToMeetingPos))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(InterpPlayerYaw, 90, 1)
        EVT_WAIT(20)
        EVT_SET(LVar3, 625)
        EVT_SET(LVar5, 220)
        EVT_CALL(PlayerMoveTo, LVar3, LVar5, 30)
        EVT_CALL(InterpPlayerYaw, 10, 4)
    EVT_END_THREAD
    EVT_THREAD
        EVT_EXEC(N(EVS_Raven3_Descend))
        EVT_CALL(SetNpcJumpscale, NPC_Raven_03, 0)
        EVT_CALL(GetNpcPos, NPC_Raven_03, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -100)
        EVT_ADD(LVar1, -250)
        EVT_ADD(LVar2, 50)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_03, SOUND_RAVEN_FALL_C, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Raven_03, LVar0, LVar1, LVar2, 90)
        EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
        EVT_CALL(EnableNpcShadow, NPC_Raven_03, TRUE)
        EVT_EXEC_WAIT(N(EVS_Raven3_MoveToMeetingPos))
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_THREAD
        EVT_EXEC(N(EVS_Raven4_Descend))
        EVT_CALL(SetNpcJumpscale, NPC_Raven_04, 0)
        EVT_CALL(GetNpcPos, NPC_Raven_04, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -100)
        EVT_ADD(LVar1, -250)
        EVT_ADD(LVar2, 60)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_04, SOUND_RAVEN_FALL_A, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_Raven_04, LVar0, LVar1, LVar2, 100)
        EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
        EVT_CALL(EnableNpcShadow, NPC_Raven_04, TRUE)
        EVT_EXEC_WAIT(N(EVS_Raven4_MoveToMeetingPos))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_EXEC(N(EVS_Raven5_Descend))
    EVT_CALL(SetNpcJumpscale, NPC_Raven_05, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_FALL_B, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_Raven_05, 737, 200, 65, 100)
    EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
    EVT_CALL(EnableNpcShadow, NPC_Raven_05, TRUE)
    EVT_EXEC_WAIT(N(EVS_Raven5_MoveToMeetingPos))
    EVT_WAIT(20)
    EVT_CALL(InterpPlayerYaw, 350, 4)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 5, MSG_CH5_00DD)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 5, MSG_CH5_00DE)
    EVT_EXEC_WAIT(N(EVS_Ravens_Converse))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 5, MSG_CH5_00DF)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 535, 200, 215)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_RAVEN_FALL_A, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Walk)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -70)
        EVT_ADD(LVar1, -7)
        EVT_ADD(LVar2, 175)
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Idle)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.5))
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Walk)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -100)
        EVT_ADD(LVar1, -300)
        EVT_ADD(LVar2, 175)
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Idle)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_END_THREAD
    EVT_WAIT(40 * DT)
    EVT_THREAD
        EVT_WAIT(35 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_01, SOUND_RAVEN_FALL_B, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Raven_01, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Walk)
        EVT_CALL(GetNpcPos, NPC_Raven_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -40)
        EVT_ADD(LVar2, 154)
        EVT_CALL(NpcMoveTo, NPC_Raven_01, LVar0, LVar2, 20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
        EVT_CALL(SetNpcJumpscale, NPC_Raven_01, EVT_FLOAT(1.5))
        EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Walk)
        EVT_CALL(GetNpcPos, NPC_Raven_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -20)
        EVT_ADD(LVar1, -300)
        EVT_ADD(LVar2, 154)
        EVT_CALL(NpcJump0, NPC_Raven_01, LVar0, LVar1, LVar2, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
        EVT_CALL(SetNpcPos, NPC_Raven_01, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_Raven_01, NPC_FLAG_GRAVITY, FALSE)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_WAIT(35 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_02, SOUND_RAVEN_FALL_C, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Raven_02, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
        EVT_CALL(GetNpcPos, NPC_Raven_02, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -55)
        EVT_ADD(LVar2, 110)
        EVT_CALL(NpcMoveTo, NPC_Raven_02, LVar0, LVar2, 20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
        EVT_CALL(SetNpcJumpscale, NPC_Raven_02, EVT_FLOAT(1.5))
        EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
        EVT_CALL(GetNpcPos, NPC_Raven_02, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -40)
        EVT_ADD(LVar1, -300)
        EVT_ADD(LVar2, 110)
        EVT_CALL(NpcJump0, NPC_Raven_02, LVar0, LVar1, LVar2, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
        EVT_CALL(SetNpcPos, NPC_Raven_02, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_Raven_02, NPC_FLAG_GRAVITY, FALSE)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_WAIT(35 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_03, SOUND_RAVEN_FALL_A, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Raven_03, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
        EVT_CALL(GetNpcPos, NPC_Raven_03, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -75)
        EVT_ADD(LVar2, 134)
        EVT_CALL(NpcMoveTo, NPC_Raven_03, LVar0, LVar2, 20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
        EVT_CALL(SetNpcJumpscale, NPC_Raven_03, EVT_FLOAT(1.5))
        EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
        EVT_CALL(GetNpcPos, NPC_Raven_03, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -70)
        EVT_ADD(LVar1, -300)
        EVT_ADD(LVar2, 134)
        EVT_CALL(NpcJump0, NPC_Raven_03, LVar0, LVar1, LVar2, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
        EVT_CALL(SetNpcPos, NPC_Raven_03, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_Raven_03, NPC_FLAG_GRAVITY, FALSE)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_WAIT(35 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_04, SOUND_RAVEN_FALL_B, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Raven_04, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
        EVT_CALL(GetNpcPos, NPC_Raven_04, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -110)
        EVT_ADD(LVar2, 115)
        EVT_CALL(NpcMoveTo, NPC_Raven_04, LVar0, LVar2, 20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
        EVT_CALL(SetNpcJumpscale, NPC_Raven_04, EVT_FLOAT(1.5))
        EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
        EVT_CALL(GetNpcPos, NPC_Raven_04, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -110)
        EVT_ADD(LVar1, -300)
        EVT_ADD(LVar2, 115)
        EVT_CALL(NpcJump0, NPC_Raven_04, LVar0, LVar1, LVar2, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
        EVT_CALL(SetNpcPos, NPC_Raven_04, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_Raven_04, NPC_FLAG_GRAVITY, FALSE)
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_WAIT(45 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_FALL_C, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_Raven_05, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
    EVT_CALL(GetNpcPos, NPC_Raven_05, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -100)
    EVT_ADD(LVar2, 161)
    EVT_CALL(NpcMoveTo, NPC_Raven_05, LVar0, LVar2, 30 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
        EVT_CALL(SetNpcJumpscale, NPC_Raven_05, EVT_FLOAT(1.5))
        EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
        EVT_CALL(GetNpcPos, NPC_Raven_05, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -70)
        EVT_ADD(LVar1, -500)
        EVT_ADD(LVar2, 161)
        EVT_CALL(NpcJump0, NPC_Raven_05, LVar0, LVar1, LVar2, 35 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
        EVT_CALL(SetNpcPos, NPC_Raven_05, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcFlagBits, NPC_Raven_05, NPC_FLAG_GRAVITY, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 550, -150, 400)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 580)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-4.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.8 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(15 * DT)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0 * DT))
    EVT_SET(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_RaphaelRaven_After) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 0, MSG_CH5_00E0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_RaphaelRaven) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_IdleNoFeet)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_RAPHAEL_LEFT_NEST)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RaphaelRaven_Before)))
        EVT_CASE_GE(STORY_CH5_ZIP_LINE_READY)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RaphaelRaven_After)))
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Raven_01) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Raven_02) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Raven_03) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Raven_04) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Raven_05) = {
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Ravens)[] = {
    {
        .id = NPC_RaphaelRaven,
        .pos = { 590.0f, 210.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RaphaelRaven),
        .settings = &N(NpcSettings_RaphaelRaven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY,
        .drops = NO_DROPS,
        .animations = RAPHAEL_RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RaphaelRaven,
    },
    {
        .id = NPC_Raven_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven_01),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenA,
    },
    {
        .id = NPC_Raven_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven_02),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
    },
    {
        .id = NPC_Raven_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven_03),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenC,
    },
    {
        .id = NPC_Raven_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven_04),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenD,
    },
    {
        .id = NPC_Raven_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven_05),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenE,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Ravens)),
    {}
};
