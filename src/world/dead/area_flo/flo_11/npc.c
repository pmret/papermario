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
    Loop(0)
        Call(PlaySound, SOUND_FLIGHT)
        Wait(LVar0)
    EndLoop
    Return
    End
};

EvtScript N(EVS_LakitusFlying_Search) = {
    Set(LVar0, 5)
    ExecGetTID(N(EVS_PlayFlightSounds), MV_FlyingSoundsScript)
    Thread
        Call(LoadPath, 160, Ref(N(FlightPath_Lakitu_01_Search)),
            ARRAY_COUNT(N(FlightPath_Lakitu_01_Search)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Lakitu_01, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(LoadPath, 160, Ref(N(FlightPath_Lakitu_02_Search)),
        ARRAY_COUNT(N(FlightPath_Lakitu_02_Search)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Lakitu_02, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Set(MV_LakituSearchSync, 1)
    Return
    End
};

EvtScript N(EVS_LakitusFlying_Gather) = {
    Thread
        Call(LoadPath, 30, Ref(N(FlightPath_Lakitu_01_Gather)),
            ARRAY_COUNT(N(FlightPath_Lakitu_01_Gather)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Lakitu_01, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(LoadPath, 45, Ref(N(FlightPath_Lakitu_02_Gather)),
        ARRAY_COUNT(N(FlightPath_Lakitu_02_Gather)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Lakitu_02, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    KillThread(MV_FlyingSoundsScript)
    Return
    End
};

EvtScript N(EVS_LakitusFlying_Attack) = {
    Set(LVar0, 4)
    ExecGetTID(N(EVS_PlayFlightSounds), MV_FlyingSoundsScript)
    Thread
        Call(LoadPath, 35, Ref(N(FlightPath_Lakitu_01_Attack)),
            ARRAY_COUNT(N(FlightPath_Lakitu_01_Attack)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Lakitu_01, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(LoadPath, 35, Ref(N(FlightPath_Lakitu_02_Attack)),
        ARRAY_COUNT(N(FlightPath_Lakitu_02_Attack)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Lakitu_02, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_LakitusFlying_Flee) = {
    Thread
        Call(LoadPath, 40, Ref(N(FlightPath_Lakitu_01_Flee)),
            ARRAY_COUNT(N(FlightPath_Lakitu_01_Flee)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Lakitu_01, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcPos, NPC_Lakitu_01, NPC_DISPOSE_LOCATION)
    EndThread
    Call(LoadPath, 40, Ref(N(FlightPath_Lakitu_02_Flee)),
        ARRAY_COUNT(N(FlightPath_Lakitu_02_Flee)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Lakitu_02, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcPos, NPC_Lakitu_02, NPC_DISPOSE_LOCATION)
    Wait(40)
    KillThread(MV_FlyingSoundsScript)
    Return
    End
};

EvtScript N(EVS_Scene_LakituAmbush) = {
    IfEq(GF_FLO11_Defeated_Lakitus, true)
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH6_GOT_MAGICAL_BEAN)
        Return
    EndIf
    IfEq(GF_FLO10_LilyRequestedWaterStone, false)
        Return
    EndIf
    Call(SetNpcPos, NPC_Lakitu_01, 460, 200, -240)
    Call(SetNpcPos, NPC_Lakitu_02, -100, 200, -50)
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 440)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, true)
    Set(MV_LakituSearchSync, 0)
    Exec(N(EVS_LakitusFlying_Search))
    Call(SetCamType, CAM_DEFAULT, 1, false)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(25.0), Float(-7.0))
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20)
    Set(LVar0, 270)
    Set(LVar1, 100)
    Set(LVar2, -87)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(14.0), Float(-11.0))
    Call(SetCamPosA, CAM_DEFAULT, 87, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, -50)
    Call(SetCamPosC, CAM_DEFAULT, 87, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30)
    Call(SetCamDistance, CAM_DEFAULT, 150)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-16.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Loop(0)
        Wait(1)
        IfEq(MV_LakituSearchSync, 1)
            BreakLoop
        EndIf
    EndLoop
    Call(NpcFaceNpc, NPC_Lakitu_01, NPC_Lakitu_02, 1)
    Call(NpcFaceNpc, NPC_Lakitu_02, NPC_Lakitu_01, 1)
    Exec(N(EVS_LakitusFlying_Gather))
    Wait(30)
    Call(SpeakToPlayer, NPC_Lakitu_01, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 0, MSG_CH6_0088)
    Call(NpcFaceNpc, NPC_Lakitu_02, NPC_Lakitu_01, 1)
    Call(SpeakToPlayer, NPC_Lakitu_02, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 0, MSG_CH6_0089)
    Call(InterpNpcYaw, NPC_Lakitu_01, 0, 1)
    Wait(20)
    Call(SpeakToPlayer, NPC_Lakitu_01, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 0, MSG_CH6_008A)
    Call(SpeakToPlayer, NPC_Lakitu_02, ANIM_Lakitu_Anim16, ANIM_Lakitu_Anim01, 0, MSG_CH6_008B)
    Call(SetCamType, CAM_DEFAULT, 1, false)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(14.0), Float(-11.0))
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(SetCamPosA, CAM_DEFAULT, 87, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, -50)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Exec(N(EVS_LakitusFlying_Attack))
    Call(SetNpcVar, NPC_Lakitu_01, 0, 1)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Lakitu_01) = {
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Thread
        Call(AdjustCam, CAM_DEFAULT, Float(4.0), 0, 1000, Float(14.0), Float(-11.0))
    EndThread
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Lakitu_01) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetNpcPos, NPC_Lakitu_01, 400, 20, -40)
            Call(SetNpcPos, NPC_Lakitu_02, 400, 20, 40)
            Call(InterpNpcYaw, NPC_Lakitu_01, 270, 0)
            Call(InterpNpcYaw, NPC_Lakitu_02, 270, 0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar2, -60)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, 900)
            Call(SetCamPitch, CAM_DEFAULT, Float(24.0), Float(-4.0))
            Call(SetCamPosA, CAM_DEFAULT, Float(-95.0), Float(0.0))
            Call(SetCamPosB, CAM_DEFAULT, Float(0.0), Float(-50.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            ExecWait(N(EVS_LakitusFlying_Flee))
            Call(ResetCam, CAM_DEFAULT, Float(4.0))
            Set(GF_FLO11_Defeated_Lakitus, true)
            Set(MV_LakituAmbushState, 1)
            Call(DisablePlayerInput, false)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Lakitu_02) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Label(0)
            IfEq(MV_LakituAmbushState, 0)
                Wait(1)
                Goto(0)
            EndIf
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakitu_01) = {
    Call(SetNpcPos, NPC_Lakitu_01, NPC_DISPOSE_LOCATION)
    IfEq(GF_FLO11_Defeated_Lakitus, false)
        IfGe(GB_StoryProgress, STORY_CH6_GOT_MAGICAL_BEAN)
            IfEq(GF_FLO10_LilyRequestedWaterStone, true)
                Set(MV_LakituAmbushState, 0)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Lakitu_01)))
                Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Lakitu_01)))
                Call(SetNpcPos, NPC_Lakitu_01, 350, 120, -220)
                Call(InterpNpcYaw, NPC_Lakitu_01, 270, 1)
            EndIf
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakitu_02) = {
    Call(SetNpcPos, NPC_Lakitu_02, NPC_DISPOSE_LOCATION)
    IfEq(GF_FLO11_Defeated_Lakitus, false)
        IfGe(GB_StoryProgress, STORY_CH6_GOT_MAGICAL_BEAN)
            IfEq(GF_FLO10_LilyRequestedWaterStone, true)
                Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Lakitu_02)))
                Call(SetNpcPos, NPC_Lakitu_02, 200, 110, 29)
                Call(InterpNpcYaw, NPC_Lakitu_02, 0, 1)
            EndIf
        EndIf
    EndIf
    Return
    End
};

NpcData N(NpcData_Lakitus)[] = {
    {
        .id = NPC_Lakitu_01,
        .pos = { 553.0f, 60.0f, 52.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Lakitu_01),
        .settings = &N(NpcSettings_Lakitu),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
        .drops = LAKITU_DROPS,
        .animations = LAKITU_ANIMS,
    },
    {
        .id = NPC_Lakitu_02,
        .pos = { 553.0f, 60.0f, 52.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Lakitu_02),
        .settings = &N(NpcSettings_Lakitu),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
        .drops = LAKITU_DROPS,
        .animations = LAKITU_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Lakitus), 0x1A07, BTL_FLO_STAGE_08),
    {}
};
