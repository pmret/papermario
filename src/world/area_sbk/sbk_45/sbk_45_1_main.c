#include "sbk_45.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [sbk_45_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_45_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_45_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_45_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
    [sbk_45_ENTRY_4]    {  157.0,  200.0, -338.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_45 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_44_1) = EVT_EXIT_WALK(60, sbk_45_ENTRY_0, "sbk_44", sbk_44_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_46_0) = EVT_EXIT_WALK(60, sbk_45_ENTRY_1, "sbk_46", sbk_46_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_35_3) = EVT_EXIT_WALK(60, sbk_45_ENTRY_2, "sbk_35", sbk_35_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_55_2) = EVT_EXIT_WALK(60, sbk_45_ENTRY_3, "sbk_55", sbk_55_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_44_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_46_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_35_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_55_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(sbk_45_ENTRY_4)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
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
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
