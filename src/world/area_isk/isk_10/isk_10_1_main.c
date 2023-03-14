#include "isk_10.h"

EvtScript N(EVS_ExitWalk_isk_08_1) = EVT_EXIT_WALK(40, isk_10_ENTRY_0, "isk_08", isk_08_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_14_0) = EVT_EXIT_WALK(40, isk_10_ENTRY_1, "isk_14", isk_14_ENTRY_0);
EvtScript N(EVS_ExitWalk_isk_18_0) = EVT_EXIT_WALK(40, isk_10_ENTRY_2, "isk_18", isk_18_ENTRY_0);
MAP_RODATA_PAD(1,unk);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_08_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_18_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    EVT_CALL(SetSpriteShading, SHADING_ISK_10)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.8))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupBombableWall))
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
