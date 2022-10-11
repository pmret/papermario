#include "sbk_04.h"

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [sbk_04_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_04_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_04_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_04_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_04 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_03_1) = EVT_EXIT_WALK(60, sbk_04_ENTRY_0, "sbk_03", sbk_03_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_05_0) = EVT_EXIT_WALK(60, sbk_04_ENTRY_1, "sbk_05", sbk_05_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_14_2) = EVT_EXIT_WALK(60, sbk_04_ENTRY_3, "sbk_14", sbk_14_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_14_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
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
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(N(SpawnSunEffect))
    EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};
