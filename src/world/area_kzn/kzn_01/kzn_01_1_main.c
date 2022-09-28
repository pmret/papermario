#include "kzn_01.h"

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [kzn_01_ENTRY_0]    { -445.0,    0.0,    0.0,   90.0 },
    [kzn_01_ENTRY_1]    {  425.0, -255.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_01 },
};

#include "world/common/atomic/kzn_SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_jan_22) = EVT_EXIT_WALK(60,  kzn_01_ENTRY_0, "jan_22",  jan_22_ENTRY_2);
EvtScript N(EVS_ExitWalk_kzn_02) = EVT_EXIT_WALK(60,  kzn_01_ENTRY_1, "kzn_02",  kzn_02_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_jan_22), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_02), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_01)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(GF_MAP_MtLavalava, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_ENTERED_MT_LAVA_LAVA)
        EVT_SET(GB_StoryProgress, STORY_CH5_ENTERED_MT_LAVA_LAVA)
    EVT_END_IF
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeLeft))
    EVT_RETURN
    EVT_END
};
