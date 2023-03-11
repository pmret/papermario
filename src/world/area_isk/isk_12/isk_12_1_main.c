#include "isk_12.h"

EvtScript N(EVS_ExitWalk_isk_11_1) = EVT_EXIT_WALK(40, isk_12_ENTRY_0, "isk_11", isk_11_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_11_2) = EVT_EXIT_WALK(40, isk_12_ENTRY_1, "isk_11", isk_11_ENTRY_2);
EvtScript N(EVS_ExitWalk_isk_18_1) = EVT_EXIT_WALK(40, isk_12_ENTRY_2, "isk_18", isk_18_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_13_0) = EVT_EXIT_WALK(40, isk_12_ENTRY_3, "isk_13", isk_13_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_11_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_11_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_18_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_13_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    EVT_CALL(SetSpriteShading, SHADING_ISK_12)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
        EVT_CALL(SetZoneEnabled, ZONE_deiliw, FALSE)
    EVT_ELSE
        EVT_CALL(SetZoneEnabled, ZONE_deiliw, FALSE)
        EVT_CALL(SetZoneEnabled, ZONE_on, FALSE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupSand))
    EVT_EXEC(N(EVS_SetupSwitches))
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
