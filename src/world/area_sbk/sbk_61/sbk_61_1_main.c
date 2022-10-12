#include "sbk_61.h"
#include "entity.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [sbk_61_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_61_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_61_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_61_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_61 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_60_1) = EVT_EXIT_WALK(60, sbk_61_ENTRY_0, "sbk_60", sbk_60_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_62_0) = EVT_EXIT_WALK(60, sbk_61_ENTRY_1, "sbk_62", sbk_62_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_51_3) = EVT_EXIT_WALK(60, sbk_61_ENTRY_2, "sbk_51", sbk_51_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_60_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_62_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_51_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
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
    EVT_RETURN
    EVT_END
};
