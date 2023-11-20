#include "kkj_14.h"
#include "sprite/player.h"

API_CALLABLE(N(SetPeachDepressed)) {
    gGameStatusPtr->peachFlags |= PEACH_FLAG_DEPRESSED;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ClearPeachDepressed)) {
    gGameStatusPtr->peachFlags &= ~PEACH_FLAG_DEPRESSED;
    return ApiStatus_DONE2;
}

Vec3f N(TwinkEnterPath)[] = {
    {  520.0,    70.0,  -62.0 },
    {  400.0,    57.0,   47.0 },
    {  300.0,    50.0,   40.0 },
    {  300.0,    50.0,  -10.0 },
    {  320.0,    65.0,    0.0 },
};

Vec3f N(TwinkExitPath)[] = {
    {  352.0,    50.0,   -2.0 },
    {  300.0,    85.0,    0.0 },
    {  350.0,   120.0,    0.0 },
    {  400.0,   105.0,   -7.0 },
    {  430.0,    90.0,  -15.0 },
};

EvtScript N(EVS_OpenDoor_Ch0) = {
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

EvtScript N(EVS_CloseDoor_Ch0) = {
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

EvtScript N(EVS_TwinkTappingOnGlassDoor) = {
    EVT_LOOP(0)
        EVT_CALL(NpcFlyTo, NPC_PARTNER, 520, 70, -60, 30 * DT, -10, EASING_LINEAR)
        EVT_CALL(NpcFlyTo, NPC_PARTNER, 520, 70, -61, 10 * DT, -5, EASING_LINEAR)
        EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_KKJ_WINDOW_TAP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcFlyTo, NPC_PARTNER, 520, 70, -62, 10 * DT, -5, EASING_LINEAR)
        EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_KKJ_WINDOW_TAP, SOUND_SPACE_DEFAULT)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Chapter0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(SetPeachDepressed))
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_SadStill)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 520, 60, -35)
    EVT_CALL(SetNpcPos, NPC_Bowser, -450, 0, -20)
    EVT_CALL(SetNpcPos, NPC_Kammy, -510, 0, -20)
    EVT_CALL(SetNpcYaw, NPC_Bowser, 90)
    EVT_CALL(SetNpcYaw, NPC_Kammy, 90)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 20, 250, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_SadTalk, ANIM_Peach2_SadStill, 5, MSG_Peach_0016)
    EVT_WAIT(5 * DT)
    EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_CALL(PlayerMoveTo, 20, 30, 30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_SadTalk, ANIM_Peach2_SadStill, 5, MSG_Peach_0017)
    EVT_WAIT(5 * DT)
    EVT_CALL(InterpPlayerYaw, 270, 5)
    EVT_CALL(PlayerMoveTo, -20, 30, 30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_SadTalk, ANIM_Peach2_SadStill, 5, MSG_Peach_0018)
    EVT_WAIT(5 * DT)
    EVT_CALL(InterpPlayerYaw, 90, 5)
    EVT_CALL(PlayerMoveTo, 20, 30, 30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_SadTalk, ANIM_Peach2_SadStill, 5, MSG_Peach_0019)
    EVT_WAIT(30 * DT)
    EVT_CALL(N(ClearPeachDepressed))
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, -45, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpPlayerYaw, 270, 3)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -330, 0, 0)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -330, 32)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(3 * DT)
    EVT_EXEC(N(EVS_OpenDoor_Ch0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcVar, NPC_Bowser, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Bowser, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Bowser, -300, -20, 0)
        EVT_CALL(NpcMoveTo, NPC_Bowser, -50, 30, 0)
        EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
        EVT_CALL(SetNpcVar, NPC_Bowser, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
        EVT_CALL(SetNpcSpeed, NPC_Kammy, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Kammy, -110, 30, 0)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_THREAD
        EVT_WAIT(40 * DT)
        EVT_CALL(MakeLerp, 250, 300, 80 * DT, EASING_LINEAR)
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
        EVT_ADD(LVar0, 10)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Bowser, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_TalkEyesClosed, 0, MSG_Peach_001A)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_WAIT(1)
    EVT_CALL(EndSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, MSG_Peach_001B)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Brandish)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_BrandishTalk, ANIM_WorldBowser_BrandishIdle, 0, MSG_Peach_001C)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Startle)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(EndSpeech, NPC_Bowser, ANIM_WorldBowser_BrandishTalk, ANIM_WorldBowser_BrandishIdle, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, MSG_Peach_001D)
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_001E)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, MSG_Peach_001F)
    EVT_WAIT(15 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
        EVT_CALL(NpcMoveTo, NPC_Bowser, -450, 30, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_Kammy, 270, 5)
        EVT_WAIT(60 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
        EVT_CALL(NpcMoveTo, NPC_Kammy, -510, 30, 0)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(FadeOutMusic, 0, 2000 * DT)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0020)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 150)
    EVT_CALL(PlaySoundAt, SOUND_KKJ_WINDOW_TAP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAt, SOUND_KKJ_WINDOW_TAP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, -45, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpPlayerYaw, 135, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0021)
    EVT_SET(AF_KKJ_03, FALSE)
    EVT_EXEC_GET_TID(N(EVS_TwinkTappingOnGlassDoor), LVarA)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 413, 0, -66)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, 338, 44)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, 413, -66)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, 179, -4, 0)
    EVT_CALL(PlayerMoveTo, 439, -16, 0)
    EVT_SET(AF_KKJ_03, TRUE)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_OpenDoors)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tte, SOUND_WINDOW_OPEN_A, 0)
    EVT_CALL(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o83, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o85, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o84, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o86, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    EVT_THREAD
        EVT_CALL(LoadPath, 100 * DT, EVT_PTR(N(TwinkEnterPath)), ARRAY_COUNT(N(TwinkEnterPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_SET(AF_KKJ_03, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar0, 310)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 430)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(InterpPlayerYaw, 220, 5)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_THREAD
        EVT_WAIT(40 * DT)
        EVT_CALL(func_802D1270, 420, 0, EVT_FLOAT(2.0 / DT))
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 370, 30, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 370, 30, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(370.0), EVT_FLOAT(32.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_KKJ_03, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 320, 30, 17)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(200.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-16.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0022)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 370, 30, 17)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0023)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0024)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.4 / DT))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 350, 30, 17)
    EVT_CALL(PlayerMoveTo, 380, 0, 30)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0025)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0026)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 17, -14)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 380, 30, 17)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0027)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TalkSad)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 17, -16)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 320, 30, 17)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_TalkSad, ANIM_Twink_TalkSad, 0, MSG_Peach_0028)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 17, -10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 350, 30, 17)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0029)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_TalkSad, ANIM_Twink_TalkSad, 0, MSG_Peach_002A)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_002B)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Startle)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, -45, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_002C)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    EVT_CALL(EndSpeech, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_GiveItem)
    EVT_WAIT(12 * DT)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_SUB(LVar2, 10)
    EVT_ADD(LVar3, 20)
    EVT_ADD(LVar4, 2)
    EVT_CALL(MakeItemEntity, ITEM_LUCKY_STAR, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar9, LVar0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(200.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-12.5))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 365, 30, 17)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(NpcFlyTo, NPC_PARTNER, 350, 50, -2, 30 * DT, -5, EASING_LINEAR)
    EVT_END_THREAD
    EVT_WAIT(40 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Wink)
    EVT_CALL(MakeLerp, 50, 70, 10 * DT, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_ADD(LVar2, -2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar0, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TalkWink)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_TalkWink, ANIM_Twink_TalkWink, 0, MSG_Peach_002D)
    EVT_SET(LVar3, LVar0)
    EVT_LOOP(10)
        EVT_ADD(LVar3, -1)
        EVT_CALL(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Tense)
    EVT_CALL(RemoveItemEntity, LVar9)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 17, -10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 355, 30, 17)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_IF_GT(LVar0, 380)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(InterpPlayerYaw, 90, 5)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
        EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_002E)
        EVT_SET(AF_KKJ_03, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar0, 310)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_END_THREAD
    EVT_CALL(LoadPath, 60 * DT, EVT_PTR(N(TwinkExitPath)), ARRAY_COUNT(N(TwinkExitPath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_KKJ_03, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 17, -13)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 405, 30, 17)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(400.0), EVT_FLOAT(32.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_002F)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    EVT_CALL(NpcFlyTo, NPC_PARTNER, 420, 60, 0, 20 * DT, 0, EASING_LINEAR)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0030)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0031)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(FadeOutMusic, 0, 2000 * DT)
    EVT_CALL(NpcFlyTo, NPC_PARTNER, 600, 100, -80, 40, 0, EASING_LINEAR)
    EVT_WAIT(30 * DT)
    EVT_CALL(GotoMap, EVT_PTR("kkj_26"), kkj_26_ENTRY_2)
    EVT_WAIT(100 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
