#include "kkj_16.h"
#include "sprite/player.h"

Vec3f N(TwinkHide1)[] = {
    { -752.0,    60.0,  -55.0 },
    { -755.0,   120.0,  -60.0 },
    { -770.0,   140.0, -130.0 },
};

Vec3f N(TwinkFollowPath1)[] = {
    { -770.0,   140.0, -130.0 },
    { -755.0,   135.0,  -90.0 },
    { -670.0,   110.0,  -80.0 },
};

Vec3f N(TwinkFollowPath2)[] = {
    { -670.0,   110.0,  -80.0 },
    { -630.0,   100.0,  -80.0 },
    { -470.0,    90.0,  -80.0 },
};

EvtScript N(EVS_ApproachPeach) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcVar, NPC_HammerBros, 0, 1)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 26)
        EVT_SUB(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim07)
        EVT_CALL(SetNpcSpeed, NPC_HammerBros, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim02)
        EVT_CALL(NpcFacePlayer, NPC_HammerBros, 5)
        EVT_CALL(SetNpcVar, NPC_HammerBros, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 26)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_01, 5)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_HammerBros, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PickUpPeach) = {
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_HammerBros, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim13)
        EVT_ADD(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        EVT_SUB(LVar0, 5)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
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
    EVT_ADD(LVar0, 10)
    EVT_LOOP(5)
        EVT_ADD(LVar1, 4)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CarryPeachAway) = {
    EVT_CALL(InterpNpcYaw, NPC_Koopatrol_01, 90, 3)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_HammerBros, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 32)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetPlayerPos, LVar0, 30, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_HammerBros, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim08)
        EVT_CALL(SetNpcSpeed, NPC_HammerBros, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_HammerBros, -606, -57, 0)
        EVT_CALL(SetNpcPos, NPC_HammerBros, 354, 0, 0)
        EVT_CALL(SetNpcVar, NPC_HammerBros, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, -574, -53, 0)
        EVT_CALL(SetNpcPos, NPC_Koopatrol_01, 386, 0, 0)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_HammerBros, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageSneakingScenes) = {
    EVT_IF_EQ(AF_KKJ_07, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(DisablePartnerAI, 1)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_006C)
        EVT_SET(AF_KKJ_07, TRUE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LE(LVar0, -770)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_THREAD
        EVT_CALL(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 8)
        EVT_WAIT(3)
        EVT_CALL(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 7)
        EVT_WAIT(3)
        EVT_CALL(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 6)
        EVT_WAIT(3)
        EVT_CALL(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 5)
        EVT_WAIT(3)
        EVT_CALL(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 4)
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Startle)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_THREAD
        EVT_CALL(NpcFlyTo, NPC_PARTNER, -776, 50, -65, 10 * DT, 0, EASING_LINEAR)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlayerMoveTo, -778, -55, 10 * DT)
        EVT_CALL(InterpPlayerYaw, 185, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_006E)
    EVT_CALL(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_006F)
    EVT_CALL(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_0070)
    EVT_CALL(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_0071)
    EVT_CALL(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_0072)
    EVT_CALL(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_0073)
    EVT_CALL(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_0074)
    EVT_CALL(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_0075)
    EVT_CALL(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_0076)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-10.5))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -775, -50)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_BattleBow_Talk, ANIM_Peach1_Idle, 5, MSG_Peach_0077)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_0078)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_0079)
    EVT_CALL(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_007A)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim07)
        EVT_CALL(NpcMoveTo, NPC_HammerBros, -820, 50, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim02)
        EVT_CALL(NpcFacePlayer, NPC_HammerBros, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_01, -840, 10, 30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(NpcFacePlayer, NPC_Koopatrol_01, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
        EVT_CALL(LoadPath, 20 * DT, EVT_PTR(N(TwinkHide1)), ARRAY_COUNT(N(TwinkHide1)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 10 * DT)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_007B)
    EVT_CALL(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_007C)
    EVT_EXEC_WAIT(N(EVS_ApproachPeach))
    EVT_EXEC_WAIT(N(EVS_PickUpPeach))
    EVT_EXEC_WAIT(N(EVS_CarryPeachAway))
    EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_007D)
    EVT_WAIT(10 * DT)
    EVT_CALL(LoadPath, 40 * DT, EVT_PTR(N(TwinkFollowPath1)), ARRAY_COUNT(N(TwinkFollowPath1)), EASING_LINEAR)
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
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    EVT_THREAD
        EVT_CALL(LoadPath, 30 * DT, EVT_PTR(N(TwinkFollowPath2)), ARRAY_COUNT(N(TwinkFollowPath2)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(15 * DT)
    EVT_CALL(FadeOutMusic, 0, 1000 * DT)
    EVT_EXEC_WAIT(N(EVS_EndPeachChapter2))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
