#include "flo_11.h"

#include "world/common/enemy/Lakitu_Stationary.inc.c"

Vec3f N(FlightPath_Lakitu_01_Search)[] = {
    {  460.0,   200.0, -240.0 },
    {  360.0,   150.0, -140.0 },
    {  260.0,   100.0, -240.0 },
    {  360.0,   100.0, -440.0 },
    {  460.0,   100.0, -240.0 },
    {  360.0,   100.0, -140.0 },
    {  260.0,   100.0, -240.0 },
    {  360.0,   100.0, -440.0 },
};

Vec3f N(FlightPath_Lakitu_02_Search)[] = {
    { -100.0,   200.0,  -50.0 },
    {    0.0,   150.0, -150.0 },
    {  100.0,   100.0,  -50.0 },
    {    0.0,   100.0,   50.0 },
    { -100.0,   100.0,  -50.0 },
    {    0.0,   100.0, -150.0 },
    {  100.0,   100.0,  -50.0 },
    {    0.0,   100.0,   50.0 },
};

Vec3f N(FlightPath_Lakitu_01_Gather)[] = {
    {  360.0,   100.0, -440.0 },
    {  350.0,   120.0, -220.0 },
    {  300.0,   120.0, -164.0 },
    {  160.0,   110.0, -180.0 },
};

Vec3f N(FlightPath_Lakitu_02_Gather)[] = {
    {    0.0,   100.0,   50.0 },
    {  200.0,   110.0,   29.0 },
    {  231.0,   110.0,  -18.0 },
    {  115.0,   100.0, -150.0 },
};

Vec3f N(FlightPath_Lakitu_01_Attack)[] = {
    {  285.0,   120.0, -108.0 },
    {  370.0,   100.0, -130.0 },
    {  454.0,    60.0,  -20.0 },
};

Vec3f N(FlightPath_Lakitu_02_Attack)[] = {
    {  263.0,   110.0,  -66.0 },
    {  360.0,    90.0,   50.0 },
    {  454.0,    50.0,   20.0 },
};

Vec3f N(FlightPath_Lakitu_01_Flee)[] = {
    {  400.0,    30.0,  -40.0 },
    {  300.0,    80.0,  -40.0 },
    {  150.0,   200.0,  -40.0 },
    {  100.0,   350.0,  -40.0 },
};

Vec3f N(FlightPath_Lakitu_02_Flee)[] = {
    {  400.0,    30.0,   40.0 },
    {  300.0,    80.0,   40.0 },
    {  150.0,   200.0,   40.0 },
    {  100.0,   350.0,   40.0 },
};

EvtScript N(EVS_PlayFlightSounds) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySound, SOUND_FLIGHT)
        EVT_WAIT(LVar0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LakitusFlying_Search) = {
    EVT_SET(LVar0, 5)
    EVT_EXEC_GET_TID(N(EVS_PlayFlightSounds), MV_FlyingSoundsScript)
    EVT_THREAD
        EVT_CALL(LoadPath, 160 * DT, EVT_PTR(N(FlightPath_Lakitu_01_Search)),
            ARRAY_COUNT(N(FlightPath_Lakitu_01_Search)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Lakitu_01, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 160 * DT, EVT_PTR(N(FlightPath_Lakitu_02_Search)),
        ARRAY_COUNT(N(FlightPath_Lakitu_02_Search)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Lakitu_02, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(MV_LakituSearchSync, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LakitusFlying_Gather) = {
    EVT_THREAD
        EVT_CALL(LoadPath, 30 * DT, EVT_PTR(N(FlightPath_Lakitu_01_Gather)),
            ARRAY_COUNT(N(FlightPath_Lakitu_01_Gather)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Lakitu_01, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 45 * DT, EVT_PTR(N(FlightPath_Lakitu_02_Gather)),
        ARRAY_COUNT(N(FlightPath_Lakitu_02_Gather)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Lakitu_02, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(MV_FlyingSoundsScript)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LakitusFlying_Attack) = {
    EVT_SET(LVar0, 4)
    EVT_EXEC_GET_TID(N(EVS_PlayFlightSounds), MV_FlyingSoundsScript)
    EVT_THREAD
        EVT_CALL(LoadPath, 35 * DT, EVT_PTR(N(FlightPath_Lakitu_01_Attack)),
            ARRAY_COUNT(N(FlightPath_Lakitu_01_Attack)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Lakitu_01, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(LoadPath, 35 * DT, EVT_PTR(N(FlightPath_Lakitu_02_Attack)),
        ARRAY_COUNT(N(FlightPath_Lakitu_02_Attack)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Lakitu_02, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LakitusFlying_Flee) = {
    EVT_THREAD
        EVT_CALL(LoadPath, 40 * DT, EVT_PTR(N(FlightPath_Lakitu_01_Flee)),
            ARRAY_COUNT(N(FlightPath_Lakitu_01_Flee)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Lakitu_01, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Lakitu_01, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_CALL(LoadPath, 40 * DT, EVT_PTR(N(FlightPath_Lakitu_02_Flee)),
        ARRAY_COUNT(N(FlightPath_Lakitu_02_Flee)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Lakitu_02, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Lakitu_02, NPC_DISPOSE_LOCATION)
    EVT_WAIT(40 * DT)
    EVT_KILL_THREAD(MV_FlyingSoundsScript)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_LakituAmbush) = {
    EVT_IF_EQ(GF_FLO11_Defeated_Lakitus, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_GOT_MAGICAL_BEAN)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_Lakitu_01, 460, 200, -240)
    EVT_CALL(SetNpcPos, NPC_Lakitu_02, -100, 200, -50)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 440)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(MV_LakituSearchSync, 0)
    EVT_EXEC(N(EVS_LakitusFlying_Search))
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(25.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_SET(LVar0, 270)
    EVT_SET(LVar1, 100)
    EVT_SET(LVar2, -87)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(14.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 87, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -50)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 87, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 150)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-16.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MV_LakituSearchSync, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(NpcFaceNpc, NPC_Lakitu_01, NPC_Lakitu_02, 1)
    EVT_CALL(NpcFaceNpc, NPC_Lakitu_02, NPC_Lakitu_01, 1)
    EVT_EXEC(N(EVS_LakitusFlying_Gather))
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_Lakitu_01, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 0, MSG_CH6_0088)
    EVT_CALL(NpcFaceNpc, NPC_Lakitu_02, NPC_Lakitu_01, 1)
    EVT_CALL(SpeakToPlayer, NPC_Lakitu_02, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 0, MSG_CH6_0089)
    EVT_CALL(InterpNpcYaw, NPC_Lakitu_01, 0, 1)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Lakitu_01, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 0, MSG_CH6_008A)
    EVT_CALL(SpeakToPlayer, NPC_Lakitu_02, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 0, MSG_CH6_008B)
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(14.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 87, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -50)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC(N(EVS_LakitusFlying_Attack))
    EVT_CALL(SetNpcVar, NPC_Lakitu_01, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Lakitu_01) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), 0, 1000, EVT_FLOAT(14.0), EVT_FLOAT(-11.0))
    EVT_END_THREAD
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Lakitu_01) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetNpcPos, NPC_Lakitu_01, 400, 20, -40)
            EVT_CALL(SetNpcPos, NPC_Lakitu_02, 400, 20, 40)
            EVT_CALL(InterpNpcYaw, NPC_Lakitu_01, 270, 0)
            EVT_CALL(InterpNpcYaw, NPC_Lakitu_02, 270, 0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar2, -60)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 900)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(24.0), EVT_FLOAT(-4.0))
            EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-95.0), EVT_FLOAT(0.0))
            EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(-50.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_EXEC_WAIT(N(EVS_LakitusFlying_Flee))
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
            EVT_SET(GF_FLO11_Defeated_Lakitus, TRUE)
            EVT_SET(MV_LakituAmbushState, 1)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Lakitu_02) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_LABEL(0)
            EVT_IF_EQ(MV_LakituAmbushState, 0)
                EVT_WAIT(1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lakitu_01) = {
    EVT_CALL(SetNpcPos, NPC_Lakitu_01, NPC_DISPOSE_LOCATION)
    EVT_IF_EQ(GF_FLO11_Defeated_Lakitus, FALSE)
        EVT_IF_GE(GB_StoryProgress, STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, TRUE)
                EVT_SET(MV_LakituAmbushState, 0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Lakitu_01)))
                EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Lakitu_01)))
                EVT_CALL(SetNpcPos, NPC_Lakitu_01, 350, 120, -220)
                EVT_CALL(InterpNpcYaw, NPC_Lakitu_01, 270, 1)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lakitu_02) = {
    EVT_CALL(SetNpcPos, NPC_Lakitu_02, NPC_DISPOSE_LOCATION)
    EVT_IF_EQ(GF_FLO11_Defeated_Lakitus, FALSE)
        EVT_IF_GE(GB_StoryProgress, STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, TRUE)
                EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Lakitu_02)))
                EVT_CALL(SetNpcPos, NPC_Lakitu_02, 200, 110, 29)
                EVT_CALL(InterpNpcYaw, NPC_Lakitu_02, 0, 1)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Lakitus)[] = {
    {
        .id = NPC_Lakitu_01,
        .pos = { 553.0f, 60.0f, 52.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Lakitu_01),
        .settings = &N(NpcSettings_Lakitu),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = LAKITU_DROPS,
        .animations = LAKITU_ANIMS,
    },
    {
        .id = NPC_Lakitu_02,
        .pos = { 553.0f, 60.0f, 52.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Lakitu_02),
        .settings = &N(NpcSettings_Lakitu),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = LAKITU_DROPS,
        .animations = LAKITU_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Lakitus), BTL_FLO_FORMATION_07, BTL_FLO_STAGE_08),
    {}
};
