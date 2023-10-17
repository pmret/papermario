#include "omo_04.h"
#include "effects.h"

s32 N(HoverOffsets)[] = {
     1,  2,  3,  2,  1,
    -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcIdle_Kammy) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar6, LVar3, LVar4)
    EVT_LOOP(0)
        EVT_USE_BUF(EVT_PTR(N(HoverOffsets)))
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            EVT_CALL(GetSelfVar, 0, LVar5)
            EVT_IF_EQ(LVar5, 0)
                EVT_SWITCH(LVar6)
                    EVT_CASE_LT(LVar2)
                        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
                    EVT_CASE_GT(LVar2)
                        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
                EVT_END_SWITCH
                EVT_SET(LVar6, LVar2)
                EVT_WAIT(1)
            EVT_ELSE
                EVT_BUF_READ1(LVar1)
                EVT_ADD(LVar3, LVar1)
                EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
                EVT_WAIT(3)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#define KAMMY_NPC NPC_Kammy
#include "world/common/util/GetKammyBroomEmitterPos.inc.c"

EvtScript N(EVS_NpcAux_Kammy) = {
    EVT_SET(MF_KammyFlying, FALSE)
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar6, LVar7, LVar8)
    EVT_LOOP(0)
        EVT_CALL(N(GetKammyBroomEmitterPos), MF_KammyFlying)
        EVT_CALL(GetNpcPos, NPC_Kammy, LVar9, LVarA, LVarB)
        EVT_SET(LVar3, LVar9)
        EVT_SET(LVar4, LVarA)
        EVT_SET(LVar5, LVarB)
        EVT_SUBF(LVar3, LVar6)
        EVT_SUBF(LVar4, LVar7)
        EVT_SUBF(LVar5, LVar8)
        EVT_SETF(LVar6, LVar9)
        EVT_SETF(LVar7, LVarA)
        EVT_SETF(LVar8, LVarB)
        EVT_IF_NE(LVar3, 0)
            EVT_IF_NE(LVar5, 0)
                EVT_PLAY_EFFECT(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0))
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

Vec3f N(FlightPath_Kammy1)[] = {
    {  800.0,   140.0,  -20.0 },
    { 1050.0,   120.0,  -70.0 },
    { 1150.0,    95.0, -100.0 },
    { 1200.0,    77.0,  -30.0 },
    { 1150.0,    62.0,   85.0 },
    { 1050.0,    50.0,  130.0 },
    {  800.0,    40.0,   50.0 },
    { 1000.0,    20.0,    0.0 },
};

Vec3f N(FlightPath_Kammy2)[] = {
    { 1000.0,    20.0,    0.0 },
    { 1010.0,    17.0,    0.0 },
    { 1020.0,    15.0,    0.0 },
};

Vec3f N(FlightPath_Kammy3)[] = {
    { 1020.0,    15.0,    0.0 },
    { 1080.0,    30.0,   30.0 },
    { 1160.0,    80.0,  -40.0 },
    {  600.0,   150.0,   90.0 },
};

EvtScript N(EVS_PlayKammyFlightSounds) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_FLIGHT, SOUND_SPACE_DEFAULT)
        EVT_WAIT(4)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_KammySetAmbush) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GF_OMO04_SpawnedPeachChoice1, TRUE)
    EVT_SET(AB_OMO_CurrentPeachChoice, GB_OMO_PeachChoice1)
    EVT_SWITCH(AB_OMO_CurrentPeachChoice)
        EVT_CASE_EQ(0)
            EVT_SET(MV_AmbushID, NPC_Goomba)
        EVT_CASE_EQ(1)
            EVT_SET(MV_AmbushID, NPC_Clubba)
        EVT_CASE_EQ(2)
            EVT_SET(MV_AmbushID, ITEM_MUSHROOM)
    EVT_END_SWITCH
    EVT_CALL(SetNpcPos, NPC_Kammy, 800, 140, -20)
    EVT_CALL(SetNpcYaw, NPC_Kammy, 270)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim15)
    EVT_IF_NE(AB_OMO_CurrentPeachChoice, 2)
        EVT_CALL(SetNpcPos, MV_AmbushID, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 1100, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 1100, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(60 * DT)
    EVT_EXEC_GET_TID(N(EVS_PlayKammyFlightSounds), MV_FlightSoundsScriptID)
    EVT_SET(MF_KammyFlying, TRUE)
    EVT_THREAD
        EVT_WAIT(100 * DT)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
#if VERSION_PAL
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2 / DT))
#else
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 2)
#endif
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(LoadPath, 150 * DT, EVT_PTR(N(FlightPath_Kammy1)), ARRAY_COUNT(N(FlightPath_Kammy1)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_NE(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(MF_KammyFlying, FALSE)
    EVT_KILL_THREAD(MV_FlightSoundsScriptID)
    EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_SKID, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -5)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        EVT_WAIT(3)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(LoadPath, 10 * DT, EVT_PTR(N(FlightPath_Kammy2)), ARRAY_COUNT(N(FlightPath_Kammy2)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_NE(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(15 * DT)
    EVT_CALL(SetNpcVar, NPC_Kammy, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    EVT_WAIT(45 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 25)
    EVT_ADD(LVar1, 38)
    EVT_CALL(PlaySoundAt, SOUND_KAMMY_SUMMON_MAGIC, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 100)
    EVT_WAIT(100 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
    EVT_ADD(LVar0, 55)
    EVT_CALL(PlaySoundAt, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, 0, 0, 1, 15, 3, 8)
    EVT_WAIT(5 * DT)
    EVT_IF_NE(AB_OMO_CurrentPeachChoice, 2)
        EVT_CALL(SetNpcPos, MV_AmbushID, LVar0, 0, 0)
    EVT_ELSE
        EVT_CALL(MakeItemEntity, MV_AmbushID, LVar0, 0, 0, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_END_IF
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    EVT_WAIT(45 * DT)
    EVT_SWITCH(AB_OMO_CurrentPeachChoice)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0036)
            EVT_WAIT(30 * DT)
            EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0037)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0038)
            EVT_WAIT(10 * DT)
            EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0039)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0034)
            EVT_WAIT(30 * DT)
            EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 517, MSG_CH4_0035)
    EVT_END_SWITCH
    EVT_CALL(SetNpcVar, NPC_Kammy, 0, 0)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_EXEC_GET_TID(N(EVS_PlayKammyFlightSounds), MV_FlightSoundsScriptID)
    EVT_SET(MF_KammyFlying, TRUE)
    EVT_THREAD
        EVT_CALL(LoadPath, 130 * DT, EVT_PTR(N(FlightPath_Kammy3)), ARRAY_COUNT(N(FlightPath_Kammy3)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_NE(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(90 * DT)
    EVT_IF_NE(AB_OMO_CurrentPeachChoice, 2)
        EVT_CALL(PlaySoundAtNpc, MV_AmbushID, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, MV_AmbushID, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
        EVT_WAIT(5 * DT)
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("omo_04"), omo_04_ENTRY_0)
    EVT_WAIT(100 * DT)
    EVT_RETURN
    EVT_END
};
