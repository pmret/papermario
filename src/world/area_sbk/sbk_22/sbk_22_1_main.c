#include "sbk_22.h"

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [sbk_22_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_22_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_22_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_22_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_22 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_21_1) = EVT_EXIT_WALK(60, sbk_22_ENTRY_0, "sbk_21", sbk_21_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_23_0) = EVT_EXIT_WALK(60, sbk_22_ENTRY_1, "sbk_23", sbk_23_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_12_3) = EVT_EXIT_WALK(60, sbk_22_ENTRY_2, "sbk_12", sbk_12_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_32_2) = EVT_EXIT_WALK(60, sbk_22_ENTRY_3, "sbk_32", sbk_32_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_21_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_23_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_12_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_32_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
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
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(N(SpawnSunEffect))
    EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};
