#include "sbk_24.h"
#include "entity.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [sbk_24_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_24_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_24_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_24_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
    [sbk_24_ENTRY_4]    {  157.0,  200.0, -338.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_24 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_23_1) = EVT_EXIT_WALK(60, sbk_24_ENTRY_0, "sbk_23", sbk_23_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_25_0) = EVT_EXIT_WALK(60, sbk_24_ENTRY_1, "sbk_25", sbk_25_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_14_3) = EVT_EXIT_WALK(60, sbk_24_ENTRY_2, "sbk_14", sbk_14_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_34_2) = EVT_EXIT_WALK(60, sbk_24_ENTRY_3, "sbk_34", sbk_34_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_23_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_25_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_14_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_34_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240600_93B230) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(sbk_24_ENTRY_4)
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
    EVT_EXEC(N(D_80240600_93B230))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_RETURN
    EVT_END
};
