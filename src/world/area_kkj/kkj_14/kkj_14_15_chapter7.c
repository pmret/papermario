#include "kkj_14.h"
#include "effects.h"
#include "sprite/player.h"

Vec3f N(TwinkHidePath)[] = {
    {  440.0,    65.0,    0.0 },
    {  420.0,   120.0,  -20.0 },
    {  400.0,    80.0,  -35.0 },
    {  375.0,    80.0,  -50.0 },
    {  375.0,   100.0,  -50.0 },
};

Vec3f N(TwinkAttackPath)[] = {
    {  375.0,   100.0,  -50.0 },
    {  375.0,    80.0,  -50.0 },
    {  390.0,    90.0,   10.0 },
};

EvtScript N(EVS_ApproachPeach) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 26)
        EVT_SUB(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Ch7_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Ch7_Koopatrol_01, LVar0, 70, 0)
        EVT_CALL(NpcFacePlayer, NPC_Ch7_Koopatrol_01, 5)
        EVT_CALL(NpcMoveTo, NPC_Ch7_Koopatrol_01, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_Ch7_Koopatrol_02, 0, 1)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 26)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Ch7_Koopatrol_02, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Ch7_Koopatrol_02, LVar0, 70, 0)
        EVT_CALL(NpcFacePlayer, NPC_Ch7_Koopatrol_02, 5)
        EVT_CALL(NpcMoveTo, NPC_Ch7_Koopatrol_02, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(SetNpcVar, NPC_Ch7_Koopatrol_02, 0, 0)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Ch7_Koopatrol_02, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TiePeachUp) = {
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim18)
        EVT_CALL(GetNpcPos, NPC_Ch7_Koopatrol_01, LVar0, LVar1, LVar2)
        EVT_LOOP(5)
            EVT_LOOP(5)
                EVT_ADD(LVar0, 2)
                EVT_CALL(SetNpcPos, NPC_Ch7_Koopatrol_01, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(5)
                EVT_SUB(LVar0, 2)
                EVT_CALL(SetNpcPos, NPC_Ch7_Koopatrol_01, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim18)
        EVT_CALL(GetNpcPos, NPC_Ch7_Koopatrol_02, LVar0, LVar1, LVar2)
        EVT_LOOP(5)
            EVT_LOOP(5)
                EVT_SUB(LVar0, 2)
                EVT_CALL(SetNpcPos, NPC_Ch7_Koopatrol_02, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(5)
                EVT_ADD(LVar0, 2)
                EVT_CALL(SetNpcPos, NPC_Ch7_Koopatrol_02, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 16)
        EVT_LOOP(50)
            EVT_CALL(RandInt, 32, LVar3)
            EVT_CALL(RandInt, 50, LVar4)
            EVT_ADD(LVar3, LVar0)
            EVT_ADD(LVar4, LVar1)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 1, LVar3, LVar4, LVar2, 1, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_GaspStill)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(ShowMessageAtWorldPos, MSG_Peach_016D, LVar0, LVar1, LVar2)
    EVT_END_THREAD
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 45)
    EVT_LOOP(20)
        EVT_CALL(InterpPlayerYaw, LVar0, 0)
        EVT_ADD(LVar0, LVar1)
        EVT_ADD(LVar1, 2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TiedIdle)
    EVT_LOOP(20)
        EVT_CALL(InterpPlayerYaw, LVar0, 0)
        EVT_ADD(LVar0, LVar1)
        EVT_SUB(LVar1, 2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PickUpPeach) = {
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Ch7_Koopatrol_01, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        EVT_ADD(LVar0, 10)
        EVT_CALL(NpcMoveTo, NPC_Ch7_Koopatrol_01, LVar0, LVar2, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Ch7_Koopatrol_02, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim12)
        EVT_SUB(LVar0, 10)
        EVT_CALL(NpcMoveTo, NPC_Ch7_Koopatrol_02, LVar0, LVar2, 10)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_LOOP(4)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Peach3_TiedSideways)
    EVT_LOOP(5)
        EVT_ADD(LVar1, 4)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CarryPeachAway) = {
    EVT_CALL(InterpNpcYaw, NPC_Ch7_Koopatrol_01, 270, 3)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_Ch7_Koopatrol_02, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 22)
            EVT_ADD(LVar1, 30)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Ch7_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Ch7_Koopatrol_01, 364, 68, 0)
        EVT_CALL(NpcMoveTo, NPC_Ch7_Koopatrol_01, 84, 68, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Ch7_Koopatrol_02, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Ch7_Koopatrol_02, 396, 72, 0)
        EVT_CALL(NpcMoveTo, NPC_Ch7_Koopatrol_02, 116, 72, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenAndCloseDoor_Ch7) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 120, 14, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(40)
    EVT_CALL(MakeLerp, 120, 0, 8, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenDoor_Ch7) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 120, 14, EASING_COS_FAST_OVERSHOOT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_Door_Ch7) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -340, 0, -30)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -340, 0, -30)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-13.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-310.0), EVT_FLOAT(32.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_Bed) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 380, 30, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 380, 30, 10)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Chapter7) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 440, 65, 0)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 270)
    EVT_CALL(RotateModel, MODEL_o83, 80, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o85, 80, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o84, 80, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o86, 80, 0, 1, 0)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Door_Ch7))
    EVT_WAIT(30 * DT)
    EVT_EXEC(N(EVS_OpenAndCloseDoor_Ch7))
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Walk)
    EVT_CALL(SetNpcPos, NPC_Ch7_Bowser, -470, 0, -30)
    EVT_CALL(SetNpcSpeed, NPC_Ch7_Bowser, EVT_FLOAT(3.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Ch7_Bowser, -290, -30, 0)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_0161)
    EVT_WAIT(10 * DT)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Bed))
    EVT_CALL(LoadPath, 30 / DT, EVT_PTR(N(TwinkHidePath)), ARRAY_COUNT(N(TwinkHidePath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Sad)
    EVT_CALL(SetNpcPos, NPC_Ch7_Bowser, 100, 0, 20)
    EVT_CALL(SetNpcFlagBits, NPC_Ch7_Bowser, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Walk)
    EVT_CALL(NpcMoveTo, NPC_Ch7_Bowser, 300, 20, 0)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(325.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_0162)
    EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ArmsCrossedIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_0163)
    EVT_CALL(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_0164)
    EVT_CALL(InterpPlayerYaw, 270, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_0165)
    EVT_CALL(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_TalkEyesClosed, 5, MSG_Peach_0166)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(EndSpeech, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_0167)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Door_Ch7))
    EVT_EXEC(N(EVS_OpenDoor_Ch7))
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim03)
    EVT_CALL(SetNpcPos, NPC_Ch7_Kammy, -470, 0, -30)
    EVT_CALL(SetNpcSpeed, NPC_Ch7_Bowser, EVT_FLOAT(5.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Ch7_Kammy, -340, -30, 0)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim01)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Ch7_Bowser, MSG_Peach_0168)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(SetNpcYaw, NPC_Ch7_Bowser, 270)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 270)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 250, 30, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 250, 30, 10)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(325.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_Ch7_Kammy, 50, 0, -10)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim03)
    EVT_CALL(NpcMoveTo, NPC_Ch7_Kammy, 180, -10, 0)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim01)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Ch7_Kammy, MSG_Peach_0169)
    EVT_CALL(SpeakToNpc, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Ch7_Bowser, MSG_Peach_016A)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Shock)
    EVT_CALL(GetNpcPos, NPC_Ch7_Bowser, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Ch7_Bowser, LVar0, LVar1, LVar2, 10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(SpeakToNpc, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Ch7_Kammy, MSG_Peach_016B)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(InterpNpcYaw, NPC_Ch7_Bowser, 270, 10)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_016C)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_Ch7_Koopatrol_01, 48, 0, 70)
    EVT_CALL(SetNpcPos, NPC_Ch7_Koopatrol_02, 100, 0, 70)
    EVT_CALL(SetNpcFlagBits, NPC_Ch7_Koopatrol_01, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Ch7_Koopatrol_02, NPC_FLAG_GRAVITY, TRUE)
    EVT_WAIT(10 * DT)
    EVT_EXEC_WAIT(N(EVS_ApproachPeach))
    EVT_EXEC_WAIT(N(EVS_TiePeachUp))
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Angry)
    EVT_CALL(LoadPath, 15, EVT_PTR(N(TwinkAttackPath)), ARRAY_COUNT(N(TwinkAttackPath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_TalkAngry, ANIM_Twink_Sad, 5, MSG_Peach_016E)
    EVT_CALL(SetNpcVar, NPC_Ch7_Bowser, 0, 0)
    EVT_THREAD
        EVT_CALL(NpcFlyTo, NPC_PARTNER, 410, 80, 10, 7, 0, EASING_LINEAR)
        EVT_LOOP(2)
            EVT_CALL(NpcFlyTo, NPC_PARTNER, 400, 70, 10, 5, 0, EASING_LINEAR)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 0, 400, 70, 10, 0)
            EVT_CALL(NpcFlyTo, NPC_PARTNER, 410, 80, 10, 5, 0, EASING_LINEAR)
        EVT_END_LOOP
        EVT_CALL(NpcFlyTo, NPC_PARTNER, 360, 80, 10, 7, 0, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(NpcFlyTo, NPC_PARTNER, 360, 70, 10, 5, 0, EASING_LINEAR)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 0, 360, 70, 10, 0)
            EVT_CALL(NpcFlyTo, NPC_PARTNER, 350, 80, 10, 5, 0, EASING_LINEAR)
            EVT_CALL(GetNpcVar, NPC_Ch7_Bowser, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcVar, NPC_Ch7_Bowser, 0, 2)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_016F)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 5, MSG_Peach_0170)
    EVT_CALL(SetNpcVar, NPC_Ch7_Bowser, 0, 1)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Ch7_Bowser, 0, LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Walk)
    EVT_CALL(NpcMoveTo, NPC_Ch7_Bowser, 310, 20, 5)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Swipe)
    EVT_WAIT(3)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(PlaySoundAt, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT, 350, 80, 10)
    EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, 350, 80, 10, 1, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(7.5 / DT))
    EVT_CALL(NpcFlyTo, NPC_PARTNER, 500, 130, 10, 0, 0, EASING_LINEAR)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_TiedIdle, ANIM_Peach2_TiedIdle, 5, MSG_Peach_0171)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_0172)
    EVT_WAIT(10 * DT)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(NpcFacePlayer, NPC_Ch7_Bowser, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_EXEC_WAIT(N(EVS_PickUpPeach))
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_TiedSideways, ANIM_Peach3_TiedSideways, 5, MSG_Peach_0173)
    EVT_EXEC_WAIT(N(EVS_CarryPeachAway))
    EVT_WAIT(30 * DT)
    EVT_EXEC_WAIT(N(EVS_EndPeachChapter7))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
