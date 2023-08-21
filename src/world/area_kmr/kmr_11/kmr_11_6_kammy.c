#include "kmr_11.h"

Vec3f N(FlightPath_Away)[] = {
    {    0.0,     0.0,    0.0 },
    {  100.0,    50.0,    0.0 },
    {  200.0,   150.0,    0.0 },
    {  250.0,   400.0,    0.0 },
};

EvtScript N(EVS_Scene_KammyWatching) = {
    EVT_CALL(SetMusicTrack, 0, SONG_KAMMY_KOOPA_THEME, 0, 8)
    EVT_CALL(SetNpcVar, NPC_Kammy, 0, 1)
    EVT_CALL(SetNpcPos, NPC_Kammy, 100, 182, -353)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 100, 0, -220)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 100, 0, -220)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1176)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 59, -159)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, -24, -256)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 8, -5)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(60 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 100, 0, -220)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 100, 190, -353)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 100, 0, -220)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 100, 190, -353)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1000)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.65 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Kammy, LVar7, LVar8, LVar9)
        EVT_CALL(LoadPath, 80 * DT, EVT_PTR(N(FlightPath_Away)), ARRAY_COUNT(N(FlightPath_Away)), EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADD(LVar1, LVar7)
        EVT_ADD(LVar2, LVar8)
        EVT_ADD(LVar3, LVar9)
        EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(24 * DT)
            EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_FLIGHT, SOUND_SPACE_DEFAULT)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(110 * DT)
    EVT_EXEC_WAIT(N(EVS_BadExit_kmr_24_0))
    EVT_RETURN
    EVT_END
};
