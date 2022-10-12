#include "sbk_36.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFoliage);

EntryList N(Entrances) = {
    [sbk_36_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_36_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_36_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_36_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_36 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_35_1) = EVT_EXIT_WALK(60, sbk_36_ENTRY_0, "sbk_35", sbk_35_ENTRY_1);
EvtScript N(EVS_ExitWalk_dro_01_0) = EVT_EXIT_WALK(60, sbk_36_ENTRY_1, "dro_01", dro_01_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_26_3) = EVT_EXIT_WALK(60, sbk_36_ENTRY_2, "sbk_26", sbk_26_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_46_2) = EVT_EXIT_WALK(60, sbk_36_ENTRY_3, "sbk_46", sbk_46_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_35_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_dro_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_26_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_46_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_DESERT)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
        EVT_CALL(DisablePulseStone, FALSE)
    EVT_END_IF
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(N(SpawnSunEffect))
    EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_RETURN
    EVT_END
};
