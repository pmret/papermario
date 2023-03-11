#include "isk_18.h"

EvtScript N(EVS_ExitWalk_isk_10_2) = EVT_EXIT_WALK(40, isk_18_ENTRY_0, "isk_10", isk_10_ENTRY_2);
EvtScript N(EVS_ExitWalk_isk_12_2) = EVT_EXIT_WALK(40, isk_18_ENTRY_1, "isk_12", isk_12_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_10_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_12_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    EVT_CALL(SetSpriteShading, SHADING_ISK_18)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_SetupFlames))
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
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
        EVT_CALL(EnableModel, MODEL_o1956, FALSE)
        EVT_CALL(EnableModel, MODEL_o1957, FALSE)
        EVT_CALL(EnableModel, MODEL_o1958, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};
