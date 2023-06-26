#include "kkj_14.h"
#include "sprite/player.h"

Vec3f N(TwinkEmergePath)[] = {
    {  110.0,     0.0, -190.0 },
    {  160.0,    70.0, -150.0 },
    {  100.0,    40.0,  -60.0 },
    {   20.0,    70.0, -100.0 },
    {  -60.0,    40.0,  -20.0 },
    {    0.0,    20.0,   30.0 },
};

EvtScript N(EVS_OpenAndCloseDoor_Ch2) = {
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

EvtScript N(EVS_OpenDoor_Ch2) = {
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

EvtScript N(EVS_CloseDoor_Ch2) = {
    EVT_CALL(MakeLerp, 120, 0, 8, EASING_COS_FAST_OVERSHOOT)
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

EvtScript N(EVS_FocusCam_Door_Ch2) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -330, 0, -30)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -330, 0, -30)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(325.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-310.0), EVT_FLOAT(32.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Chapter2) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 110, 0, -190)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 270)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Door_Ch2))
    EVT_EXEC(N(EVS_OpenAndCloseDoor_Ch2))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_Bowser, -470, 0, -30)
    EVT_CALL(SetNpcVar, NPC_Bowser, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Bowser, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Bowser, -30, 30, 0)
        EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
        EVT_CALL(SetNpcVar, NPC_Bowser, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 30)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcVar, NPC_Bowser, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_TalkEyesClosed, 0, MSG_Peach_005C)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_WAIT(1)
    EVT_CALL(EndSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ArmsCrossedIdle)
    EVT_CALL(InterpPlayerYaw, 90, 3)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_005D)
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_TalkEyesClosed, 5, MSG_Peach_005E)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(EndSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_Bowser, 270, 0)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Door_Ch2))
    EVT_WAIT(5 * DT)
    EVT_EXEC(N(EVS_OpenDoor_Ch2))
    EVT_CALL(SetMusicTrack, 0, SONG_KAMMY_KOOPA_THEME, 0, 8)
    EVT_CALL(SetNpcPos, NPC_Kammy, -470, 0, -30)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim03)
    EVT_CALL(SetNpcSpeed, NPC_Kammy, EVT_FLOAT(5.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Kammy, -340, -30, 0)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_WAIT(10)
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_005F)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -30, 0, -30)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -287, 32)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim03)
    EVT_CALL(SetNpcSpeed, NPC_Kammy, EVT_FLOAT(5.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Kammy, -110, 30, 0)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0060)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0061)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    EVT_CALL(NpcMoveTo, NPC_Kammy, -90, 40, 10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0062)
    EVT_CALL(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Shock)
    EVT_CALL(NpcJump0, NPC_Bowser, LVar0, LVar1, LVar2, 10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0063)
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0064)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_ArmsCrossed)
    EVT_WAIT(50 * DT)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0065)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Bowser, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Bowser, -470, -30, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_Kammy, 0, 1)
    EVT_THREAD
        EVT_WAIT(40 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
        EVT_CALL(SetNpcSpeed, NPC_Kammy, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Kammy, -470, -30, 0)
        EVT_CALL(SetNpcVar, NPC_Kammy, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 350, 400, 100 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcVar, NPC_Kammy, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_CloseDoor_Ch2))
    EVT_WAIT(30 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_PRISONER_PEACH_THEME, 0, 8)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 20, 0, 30)
    EVT_WAIT(3 * DT)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar0, -58)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_END_THREAD
    EVT_CALL(LoadPath, 80 * DT, EVT_PTR(N(TwinkEmergePath)), ARRAY_COUNT(N(TwinkEmergePath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0066)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0067)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0068)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0069)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_006A)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
