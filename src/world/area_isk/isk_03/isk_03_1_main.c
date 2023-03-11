#include "isk_03.h"

EvtScript N(EVS_ExitWalk_isk_02_1) = EVT_EXIT_WALK(40, isk_03_ENTRY_0, "isk_02", isk_02_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_02_2) = EVT_EXIT_WALK(40, isk_03_ENTRY_1, "isk_02", isk_02_ENTRY_2);
EvtScript N(EVS_ExitWalk_isk_04_0) = EVT_EXIT_WALK(40, isk_03_ENTRY_2, "isk_04", isk_04_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_02_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    EVT_CALL(SetSpriteShading, SHADING_ISK_03)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_FIRST_SAND_ROOM)
        EVT_CALL(SetZoneEnabled, ZONE_o2023, FALSE)
        EVT_CALL(SetZoneEnabled, ZONE_03, FALSE)
    EVT_ELSE
        EVT_CALL(SetZoneEnabled, ZONE_o2023, FALSE)
        EVT_CALL(SetZoneEnabled, ZONE_o2008, FALSE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupSand))
    EVT_EXEC(N(EVS_SetupSwitch))
#if VERSION_PAL
    EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_RUINS, 0, 8)
#else
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
            EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_RUINS, 0, 8)
        EVT_CASE_LT(STORY_CH2_DEFEATED_TUTANKOOPA)
            EVT_CALL(SetMusicTrack, 0, SONG_RUINS_BASEMENT, 0, 8)
        EVT_CASE_GE(STORY_CH2_DEFEATED_TUTANKOOPA)
            EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_RUINS, 0, 8)
    EVT_END_SWITCH
#endif
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};
