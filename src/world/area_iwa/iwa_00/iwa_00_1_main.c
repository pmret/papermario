#include "iwa_00.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_BindSlideTriggers);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [iwa_00_ENTRY_0]    {   55.0,   -5.0,  -25.0,   90.0 },
    [iwa_00_ENTRY_1]    { 1313.0,   90.0,  -40.0,  270.0 },
    [iwa_00_ENTRY_2]    {  625.0,  -30.0,  259.0,   45.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_iwa_00 },
};

EvtScript N(EVS_ExitWalk_iwa_10_1) = EVT_EXIT_WALK(60, iwa_00_ENTRY_0, "iwa_10", iwa_10_ENTRY_1);
EvtScript N(EVS_ExitWalk_iwa_01_0) = EVT_EXIT_WALK(60, iwa_00_ENTRY_1, "iwa_01", iwa_01_ENTRY_0);

EvtScript N(EVS_TexPan_Water) = {
    EVT_CALL(EnableTexPanning, MODEL_o949, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_water, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 3000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_10_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_RUGGED)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_EXEC(N(EVS_BindSlideTriggers))
    EVT_CALL(SetMusicTrack, 0, SONG_MT_RUGGED, 0, 8)
    EVT_CALL(PlaySoundAtF, SOUND_8000000B, 1, 35, -80, -120)
    EVT_CALL(PlaySoundAtF, SOUND_8000000C, 1, 500, 85, -120)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
