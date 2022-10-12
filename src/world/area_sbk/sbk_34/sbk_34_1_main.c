#include "sbk_34.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupFoliage);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [sbk_34_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_34_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_34_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_34_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_34 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_33_1) = EVT_EXIT_WALK(60, sbk_34_ENTRY_0, "sbk_33", sbk_33_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_35_0) = EVT_EXIT_WALK(60, sbk_34_ENTRY_1, "sbk_35", sbk_35_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_24_3) = EVT_EXIT_WALK(60, sbk_34_ENTRY_2, "sbk_24", sbk_24_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_44_2) = EVT_EXIT_WALK(60, sbk_34_ENTRY_3, "sbk_44", sbk_44_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_33_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_35_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_24_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_44_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
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
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_RETURN
    EVT_END
};
