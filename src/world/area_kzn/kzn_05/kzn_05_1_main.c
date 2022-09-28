#include "kzn_05.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [kzn_05_ENTRY_0]    { -430.0, -259.0,   10.0,   90.0 },
    [kzn_05_ENTRY_1]    {  450.0,    0.0,   10.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_05 },
};

#include "world/common/atomic/kzn_SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_06) = EVT_EXIT_WALK(60,  kzn_05_ENTRY_0, "kzn_06",  kzn_06_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_03) = EVT_EXIT_WALK(60,  kzn_05_ENTRY_1, "kzn_03",  kzn_03_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_06), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_03), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_05)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeLeft))
    EVT_RETURN
    EVT_END
};
