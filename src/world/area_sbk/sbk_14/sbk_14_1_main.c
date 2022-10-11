#include "sbk_14.h"
#include "entity.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [sbk_14_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_14_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_14_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_14_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
    [sbk_14_ENTRY_4]    {  157.0,  200.0, -338.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_14 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_13_1) = EVT_EXIT_WALK(60, sbk_14_ENTRY_0, "sbk_13", sbk_13_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_15_0) = EVT_EXIT_WALK(60, sbk_14_ENTRY_1, "sbk_15", sbk_15_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_04_3) = EVT_EXIT_WALK(60, sbk_14_ENTRY_2, "sbk_04", sbk_04_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_24_2) = EVT_EXIT_WALK(60, sbk_14_ENTRY_3, "sbk_24", sbk_24_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_15_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_04_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_24_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802402C0_9369A0) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(sbk_14_ENTRY_4)
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
    EVT_EXEC(N(D_802402C0_9369A0))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
