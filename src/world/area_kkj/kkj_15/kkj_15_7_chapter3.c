#include "kkj_15.h"
#include "sprite/player.h"

API_CALLABLE(N(SetPeachDepressed)) {
    gGameStatusPtr->peachFlags |= PEACH_FLAG_DEPRESSED;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ClearPeachDepressed)) {
    gGameStatusPtr->peachFlags &= ~PEACH_FLAG_DEPRESSED;
    return ApiStatus_DONE2;
}

Vec3f N(TwinkHideCh3Path)[] = {
    {  100.0,    50.0, -160.0 },
    {   30.0,   120.0, -120.0 },
    {   50.0,   200.0,  -80.0 },
};

Vec3f N(TwinkFollowCh3Path1)[] = {
    {   50.0,   200.0,  -70.0 },
    {   80.0,   110.0,  -70.0 },
    {  110.0,   120.0,  -70.0 },
    {  140.0,   110.0,  -70.0 },
    {  170.0,   120.0,  -70.0 },
    {  200.0,   110.0,  -70.0 },
    {  230.0,   120.0,  -70.0 },
};

Vec3f N(TwinkFollowCh3Path2)[] = {
    {  230.0,   120.0,  -70.0 },
    {  220.0,    60.0,  -70.0 },
    {  250.0,    40.0,  -70.0 },
};

EvtScript N(EVS_ApproachPeach_Ch3) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcVar, NPC_Koopatrol_03, 0, 1)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 26)
        EVT_SUB(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_03, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_03, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_03, 5)
        EVT_CALL(SetNpcVar, NPC_Koopatrol_03, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 26)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_04, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_04, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_04, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_04, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_04, 5)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Koopatrol_03, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PickUpPeach_Ch3) = {
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopatrol_03, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_03, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim12)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_03, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopatrol_04, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_04, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_04, ANIM_WorldKoopatrol_Anim12)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_04, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_WAIT(1)
    EVT_LOOP(4)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Carried)
    EVT_SUB(LVar0, 10)
    EVT_LOOP(5)
        EVT_ADD(LVar1, 4)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CarryPeachAway_Ch3) = {
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_04, 90, 3)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_Koopatrol_03, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 10)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetPlayerPos, LVar0, 30, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_Koopatrol_03, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_03, EVT_FLOAT(7.5))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_03, 249, -72, 0)
        EVT_CALL(SetNpcVar, NPC_Koopatrol_03, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_04, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_04, EVT_FLOAT(7.5))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_04, 281, -68, 0)
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        EVT_CALL(GetNpcVar, NPC_Koopatrol_03, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Chapter3) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(SetPlayerPos, 50, 10, -250)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 10, 50, -250)
    EVT_CALL(SetNpcPos, NPC_Bowser, -50, 0, -20)
    EVT_CALL(SetNpcPos, NPC_Kammy, -130, 0, -20)
    EVT_CALL(SetNpcYaw, NPC_Bowser, 270)
    EVT_CALL(SetNpcYaw, NPC_Kammy, 90)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -50, 0, -20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -50, 0, -20)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0082)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -50, 0, -20)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0083)
    EVT_THREAD
        EVT_EXEC_WAIT(N(EVS_AnimateRotatingWall_AlmostCaught))
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
        EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LookAround)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(360 * DT)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 100, 50, -160)
        EVT_CALL(LoadPath, 30 * DT, EVT_PTR(N(TwinkHideCh3Path)), ARRAY_COUNT(N(TwinkHideCh3Path)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
    EVT_END_THREAD
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0084)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Tantrum)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_ArmsCrossed)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0085)
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0086)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0087)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_ArmsCrossed)
    EVT_WAIT(30 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Bowser, 90, 7 * DT)
    EVT_WAIT(30 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Bowser, 270, 7 * DT)
    EVT_WAIT(30 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Bowser, 90, 7 * DT)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Bowser, MSG_Peach_0088)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Delighted)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, NPC_Bowser, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Bowser, EMOTE_EXCLAMATION, -45, 30, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Kammy, EMOTE_EXCLAMATION, -45, 30, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcVar, NPC_Bowser, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Shock)
        EVT_CALL(NpcJump0, NPC_Bowser, -50, 0, -20, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim05)
        EVT_CALL(NpcJump0, NPC_Kammy, -130, 0, -20, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LookAround)
        EVT_WAIT(60 * DT)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(N(SetPeachDepressed))
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_SadStill)
        EVT_CALL(func_802D1270, 30, -10, EVT_FLOAT(2.0 / DT))
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(N(ClearPeachDepressed))
        EVT_CALL(SetNpcVar, NPC_Bowser, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Shock, ANIM_WorldBowser_Shock, 0, MSG_Peach_0089)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_CALL(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 0, MSG_Peach_008A)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Bowser, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_ArmsCrossed)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_008B)
    EVT_CALL(ShowChoice, MSG_Choice_0026)
    EVT_SET(GB_OMO_PeachChoice1, LVar0)
    EVT_IF_NE(LVar0, 2)
        EVT_SET(AF_KKJ_08, TRUE)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_008C)
    EVT_CALL(ShowChoice, MSG_Choice_0027)
    EVT_SET(GB_OMO_PeachChoice2, LVar0)
    EVT_IF_NE(LVar0, 2)
        EVT_SET(AF_KKJ_08, TRUE)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_008D)
    EVT_CALL(ShowChoice, MSG_Choice_0028)
    EVT_SET(GB_OMO_PeachChoice3, LVar0)
    EVT_IF_NE(LVar0, 2)
        EVT_SET(AF_KKJ_08, TRUE)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_Idle, 0, MSG_Peach_008E)
    EVT_CALL(InterpNpcYaw, NPC_Bowser, 270, 7)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_008F)
    EVT_IF_EQ(AF_KKJ_08, FALSE)
        EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0090)
    EVT_ELSE
        EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0091)
    EVT_END_IF
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0092)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Bowser, 90, 7 * DT)
    EVT_WAIT(10 * DT)
    EVT_CALL(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_0093)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Bowser, 90, 7 * DT)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_0094)
    EVT_CALL(RotateModel, MODEL_o2, 120, 0, 1, 0)
    EVT_CALL(SetNpcPos, NPC_Koopatrol_03, 249, 0, -70)
    EVT_CALL(SetNpcPos, NPC_Koopatrol_04, 281, 0, -70)
    EVT_CALL(SpeakToNpc, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_Bowser, MSG_Peach_0095)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_EXEC_WAIT(N(EVS_ApproachPeach_Ch3))
    EVT_EXEC_WAIT(N(EVS_PickUpPeach_Ch3))
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_0096)
    EVT_EXEC_WAIT(N(EVS_CarryPeachAway_Ch3))
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
    EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
    EVT_CALL(LoadPath, 80 * DT, EVT_PTR(N(TwinkFollowCh3Path1)), ARRAY_COUNT(N(TwinkFollowCh3Path1)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TalkSad)
    EVT_LOOP(2)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 7 * DT)
        EVT_WAIT(5 * DT)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 7 * DT)
        EVT_WAIT(5 * DT)
    EVT_END_LOOP
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 7)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 7 * DT)
    EVT_CALL(LoadPath, 15 * DT, EVT_PTR(N(TwinkFollowCh3Path2)), ARRAY_COUNT(N(TwinkFollowCh3Path2)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30 * DT)
    EVT_CALL(FadeOutMusic, 0, 1000 * DT)
    EVT_EXEC_WAIT(N(EVS_EndPeachChapter3))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
