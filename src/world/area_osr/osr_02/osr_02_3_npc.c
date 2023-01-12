#include "osr_02.h"
#include "effects.h"

NpcSettings N(NpcSettings_Peach) = {
    .height = 46,
    .radius = 36,
    .level = 99,
};

#include "world/common/npc/Twink.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_NpcAuxAI_StarRod) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_StarRod) = {
    .height = 24,
    .radius = 24,
    .level = 99,
    .otherAI = &N(EVS_NpcAuxAI_StarRod),
};

Vec3f N(FlightPath_TwinkStepForward)[] = {
    {  -10.0,    40.0,   10.0 },
    {   15.0,    33.0,   20.0 },
    {   50.0,    30.0,   30.0 },
};

Vec3f N(FlightPath_TwinkDepart)[] = {
    {   50.0,    30.0,   30.0 },
    {   70.0,    45.0,   10.0 },
    {   90.0,    60.0,   30.0 },
    {   70.0,    75.0,   50.0 },
    {   50.0,    90.0,   30.0 },
    {   70.0,   105.0,   10.0 },
    {   90.0,   120.0,   30.0 },
    {   70.0,   135.0,   50.0 },
    {   50.0,   150.0,   30.0 },
    {   70.0,   165.0,   10.0 },
    {   90.0,   180.0,   30.0 },
    {   70.0,   195.0,   50.0 },
    {   50.0,   210.0,   30.0 },
};

EvtScript N(EVS_StarSpirit_FlyAway) = {
    EVT_CALL(SetNpcFlagBits, LVar4, NPC_FLAG_40000, TRUE)
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(GetNpcPos, LVar4, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
            EVT_WAIT(6)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(GetNpcPos, LVar4, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 40)
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 1800, 100, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, LVar4, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, LVar4, LVar7, LVar8, LVar9)
    EVT_CALL(MakeLerp, 80, 260, 100, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, LVar4, LVar7, LVar0, LVar9)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, LVar4, LVar7, NPC_DISPOSE_POS_Y, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Twink_FlyAway) = {
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
            EVT_WAIT(6)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 40)
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 2160, 120, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Twink, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_Twink, SOUND_62, 0)
        EVT_CALL(LoadPath, 120, EVT_PTR(N(FlightPath_TwinkDepart)), ARRAY_COUNT(N(FlightPath_TwinkDepart)), EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, NPC_DISPOSE_POS_Y, LVar3)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(0.5), 0, 550, EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_ReturnStarRod) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 2, 8)
    EVT_CALL(SetPlayerPos, 15, 0, 30)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -70, LVar1, 15)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_RUN)
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(700.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_60005)
    EVT_CALL(SetNpcPos, NPC_StarRod, 30, 25, 30)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Leap)
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 80)
    EVT_SET(LVar2, 35)
    EVT_CALL(SetNpcJumpscale, NPC_StarRod, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump1, NPC_StarRod, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(PlaySound, SOUND_139)
    EVT_LOOP(6)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 9, LVar0, LVar1, LVar2, 1, 20)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar1, LVar2, 30)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_LOOP(20)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetNpcPos, NPC_StarRod, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_StarRod, NPC_DISPOSE_LOCATION)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_Outro_0000)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcJumpscale, NPC_Eldstar, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_Eldstar, 120, 80, 0, 40)
        EVT_CALL(InterpNpcYaw, NPC_Eldstar, 270, 0)
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, 120)
    EVT_SET(LVar1, 80)
    EVT_SET(LVar2, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Mamar, ANIM_WorldMamar_TalkHappy, ANIM_WorldMamar_Idle, 0, MSG_Outro_0001)
    EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Skolar, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 0, MSG_Outro_0002)
    EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 0, MSG_Outro_0003)
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Misstar, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 0, MSG_Outro_0004)
    EVT_CALL(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Klevar, ANIM_WorldKlevar_Talk, ANIM_WorldKlevar_Idle, 0, MSG_Outro_0005)
    EVT_CALL(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Kalmar, ANIM_WorldKalmar_Talk, ANIM_WorldKalmar_Idle, 0, MSG_Outro_0006)
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_Outro_0007)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-2.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Outro_0008)
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Eldstar, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle, 0, MSG_Outro_0009)
    EVT_WAIT(20)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 70, 400, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_THREAD
        EVT_SET(LVar4, NPC_Eldstar)
        EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_2045, 0)
        EVT_EXEC_WAIT(N(EVS_StarSpirit_FlyAway))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_SET(LVar4, NPC_Misstar)
        EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_2046, 0)
        EVT_EXEC_WAIT(N(EVS_StarSpirit_FlyAway))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(60)
        EVT_SET(LVar4, NPC_Skolar)
        EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_2045, 0)
        EVT_EXEC_WAIT(N(EVS_StarSpirit_FlyAway))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(90)
        EVT_SET(LVar4, NPC_Mamar)
        EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_2046, 0)
        EVT_EXEC_WAIT(N(EVS_StarSpirit_FlyAway))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(120)
        EVT_SET(LVar4, NPC_Kalmar)
        EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_2045, 0)
        EVT_EXEC_WAIT(N(EVS_StarSpirit_FlyAway))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(150)
        EVT_SET(LVar4, NPC_Muskular)
        EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_2046, 0)
        EVT_EXEC_WAIT(N(EVS_StarSpirit_FlyAway))
    EVT_END_THREAD
    EVT_WAIT(180)
    EVT_SET(LVar4, NPC_Klevar)
    EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_2045, 0)
    EVT_EXEC_WAIT(N(EVS_StarSpirit_FlyAway))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(20)
    EVT_CALL(SetMusicTrack, 0, SONG_TWINK_THEME, 1, 8)
    EVT_CALL(LoadPath, 30, EVT_PTR(N(FlightPath_TwinkStepForward)), ARRAY_COUNT(N(FlightPath_TwinkStepForward)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-4.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Outro_000A)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach_C0000)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach_C0026)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach_C0001, ANIM_Peach_C0026, 5, MSG_Outro_000B)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach_C0002)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach_A0001)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Disappointed)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Disappointed, ANIM_Twink_Disappointed, 0, MSG_Outro_000C)
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Idle)
    EVT_CALL(EndSpeech, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0)
    EVT_WAIT(20)
    EVT_EXEC(N(EVS_Twink_FlyAway))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_WAIT(250)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach_A0002)
    EVT_CALL(NpcMoveTo, NPC_Peach, -10, 30, 40)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach_A0001)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT(60)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_WAIT(20)
    EVT_CALL(GotoMap, EVT_PTR("hos_10"), hos_10_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Peach) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -25, 0, 40)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Twink) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -10, 40, 10)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_RETURN
    EVT_END
};

s16 N(SpiritHoverOffsets)[] = {
    1, 3, 5, 7, 7, 5, 3
};

API_CALLABLE(N(AnimateSpiritHover)) {
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = 0.0f;
        script->functionTempPtr[2] = get_npc_safe(script->owner2.npcID);
        script->functionTemp[3] = N(SpiritHoverOffsets)[script->owner2.npcID - 2];
    }

    if (script->functionTemp[3] != 0) {
        script->functionTemp[3]--;
        return ApiStatus_BLOCK;
    }

    npc = script->functionTempPtr[2];
    npc->verticalRenderOffset = sin_deg(script->functionTempF[1]) * 1.5f;
    script->functionTempF[1] = clamp_angle(script->functionTempF[1] + 18.0f);
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcAux_Eldstar) = {
    EVT_CALL(N(AnimateSpiritHover))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Eldstar) = {
    EVT_CALL(SetNpcPos, NPC_Eldstar, 60, 20, 30)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Eldstar)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Mamar) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 66, 80, -27)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Eldstar)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Skolar) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 53, 80, -95)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Eldstar)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Muskular) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 91, 80, -132)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Eldstar)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Misstar) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 151, 80, -132)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Eldstar)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Klevar) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 189, 80, -95)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Eldstar)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kalmar) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 176, 80, -27)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Eldstar)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarRod) = {
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_Peach)[] = {
    ANIM_Peach_A0001,
    ANIM_Peach_A0002,
    ANIM_Peach_C0000,
    ANIM_Peach_C0001,
    ANIM_Peach_C0002,
    ANIM_Peach_C0006,
    ANIM_Peach_C001E,
    ANIM_Peach_C0026,
    -1
};

s32 N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Talk,
    ANIM_Twink_Disappointed,
    -1
};

s32 N(ExtraAnims_Eldstar)[] = {
    ANIM_WorldEldstar_Idle,
    ANIM_WorldEldstar_Wave,
    ANIM_WorldEldstar_Leap,
    -1
};

s32 N(ExtraAnims_Mamar)[] = {
    ANIM_WorldMamar_Idle,
    ANIM_WorldMamar_TalkHappy,
    -1
};

s32 N(ExtraAnims_Skolar)[] = {
    ANIM_WorldSkolar_Idle,
    ANIM_WorldSkolar_TalkAngry,
    -1
};

s32 N(ExtraAnims_Muskular)[] = {
    ANIM_WorldMuskular_Idle,
    ANIM_WorldMuskular_Talk,
    -1
};

s32 N(ExtraAnims_Misstar)[] = {
    ANIM_WorldMisstar_Idle,
    ANIM_WorldMisstar_Talk,
    -1
};

s32 N(ExtraAnims_Klevar)[] = {
    ANIM_WorldKlevar_Idle,
    ANIM_WorldKlevar_Talk,
    -1
};

s32 N(ExtraAnims_Kalmar)[] = {
    ANIM_WorldKalmar_Idle,
    ANIM_WorldKalmar_Talk,
    -1
};

StaticNpc N(NpcData_Spirits)[] = {
    {
        .id = NPC_Peach,
        .settings = &N(NpcSettings_Peach),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_20000,
        .init = &N(EVS_NpcInit_Peach),
        .drops = NPC_NO_DROPS,
        .animations = {
            .idle   = ANIM_Peach_A0000,
            .walk   = ANIM_Peach_A0000,
            .run    = ANIM_Peach_A0000,
            .chase  = ANIM_Peach_A0000,
            .anim_4 = ANIM_Peach_A0000,
            .anim_5 = ANIM_Peach_A0000,
            .death  = ANIM_Peach_A0000,
            .hit    = ANIM_Peach_A0000,
            .anim_8 = ANIM_Peach_A0000,
            .anim_9 = ANIM_Peach_A0000,
            .anim_A = ANIM_Peach_A0000,
            .anim_B = ANIM_Peach_A0000,
            .anim_C = ANIM_Peach_A0000,
            .anim_D = ANIM_Peach_A0000,
            .anim_E = ANIM_Peach_A0000,
            .anim_F = ANIM_Peach_A0000,
        },
        .extraAnimations = N(ExtraAnims_Peach),
    },
    {
        .id = NPC_Twink,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Twink),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_Twink),
    },
    {
        .id = NPC_Eldstar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Eldstar),
        .drops = NPC_NO_DROPS,
        .animations = ELDSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Eldstar),
    },
    {
        .id = NPC_Mamar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Mamar),
        .drops = NPC_NO_DROPS,
        .animations = MAMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Mamar),
    },
    {
        .id = NPC_Skolar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Skolar),
        .drops = NPC_NO_DROPS,
        .animations = SKOLAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Skolar),
    },
    {
        .id = NPC_Muskular,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Muskular),
        .drops = NPC_NO_DROPS,
        .animations = MUSKULAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Muskular),
    },
    {
        .id = NPC_Misstar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Misstar),
        .drops = NPC_NO_DROPS,
        .animations = MISSTAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Misstar),
    },
    {
        .id = NPC_Klevar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Klevar),
        .drops = NPC_NO_DROPS,
        .animations = KLEVAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Klevar),
    },
    {
        .id = NPC_Kalmar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Kalmar),
        .drops = NPC_NO_DROPS,
        .animations = KALMAR_ANIMS,
        .extraAnimations = N(ExtraAnims_Kalmar),
    },
    {
        .id = NPC_StarRod,
        .settings = &N(NpcSettings_StarRod),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarRod),
        .drops = NPC_NO_DROPS,
        .animations = {
            .idle   = ANIM_StarRod_Still,
            .walk   = ANIM_StarRod_Still,
            .run    = ANIM_StarRod_Still,
            .chase  = ANIM_StarRod_Still,
            .anim_4 = ANIM_StarRod_Still,
            .anim_5 = ANIM_StarRod_Still,
            .death  = ANIM_StarRod_Still,
            .hit    = ANIM_StarRod_Still,
            .anim_8 = ANIM_StarRod_Still,
            .anim_9 = ANIM_StarRod_Still,
            .anim_A = ANIM_StarRod_Still,
            .anim_B = ANIM_StarRod_Still,
            .anim_C = ANIM_StarRod_Still,
            .anim_D = ANIM_StarRod_Still,
            .anim_E = ANIM_StarRod_Still,
            .anim_F = ANIM_StarRod_Still,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Spirits)),
    {}
};
