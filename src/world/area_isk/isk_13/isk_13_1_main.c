#include "isk_13.h"

EvtScript N(EVS_ExitWalk_isk_12_3) = EVT_EXIT_WALK(40, isk_13_ENTRY_0, "isk_12", isk_12_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_12_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    EVT_CALL(SetSpriteShading, SHADING_ISK_13)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
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
