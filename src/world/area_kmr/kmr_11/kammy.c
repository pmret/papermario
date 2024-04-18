#include "kmr_11.h"

Vec3f N(FlightPath_Away)[] = {
    {    0.0,     0.0,    0.0 },
    {  100.0,    50.0,    0.0 },
    {  200.0,   150.0,    0.0 },
    {  250.0,   400.0,    0.0 },
};

EvtScript N(EVS_Scene_KammyWatching) = {
    Call(SetMusicTrack, 0, SONG_KAMMY_KOOPA_THEME, 0, 8)
    Call(SetNpcVar, NPC_Kammy, 0, 1)
    Call(SetNpcPos, NPC_Kammy, 100, 182, -353)
    Call(UseSettingsFrom, CAM_DEFAULT, 100, 0, -220)
    Call(SetPanTarget, CAM_DEFAULT, 100, 0, -220)
    Call(SetCamDistance, CAM_DEFAULT, 1176)
    Call(SetCamPosA, CAM_DEFAULT, 59, -159)
    Call(SetCamPosB, CAM_DEFAULT, -24, -256)
    Call(SetCamPitch, CAM_DEFAULT, 8, -5)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(60 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 100, 0, -220)
    Call(SetPanTarget, CAM_DEFAULT, 100, 190, -353)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(30 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 100, 0, -220)
    Call(SetPanTarget, CAM_DEFAULT, 100, 190, -353)
    Call(SetCamDistance, CAM_DEFAULT, 1000)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.65 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(30 * DT)
    Thread
        Call(GetNpcPos, NPC_Kammy, LVar7, LVar8, LVar9)
        Call(LoadPath, 80 * DT, Ref(N(FlightPath_Away)), ARRAY_COUNT(N(FlightPath_Away)), EASING_LINEAR)
        Label(0)
        Call(GetNextPathPos)
        Add(LVar1, LVar7)
        Add(LVar2, LVar8)
        Add(LVar3, LVar9)
        Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    EndThread
    Thread
        Loop(24 * DT)
            Call(PlaySoundAtNpc, NPC_Kammy, SOUND_FLIGHT, SOUND_SPACE_DEFAULT)
            Wait(4)
        EndLoop
    EndThread
    Wait(110 * DT)
    ExecWait(N(EVS_BadExit_kmr_24_0))
    Return
    End
};
