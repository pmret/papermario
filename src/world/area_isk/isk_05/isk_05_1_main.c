#include "isk_05.h"

EvtScript N(D_80241F10_97F9E0) = EVT_EXIT_WALK(40, isk_05_ENTRY_0, "isk_04", isk_04_ENTRY_4);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80241F10_97F9E0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterWalk_80241F98) = {
    EVT_CALL(TranslateGroup, MODEL_g304, 0, 65, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    EVT_CALL(SetSpriteShading, SHADING_ISK_05)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
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
    EVT_CALL(TranslateGroup, MODEL_g304, 0, 65, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_EQ(GF_ISK05_Hammer2Block, FALSE)
        EVT_CALL(SetGroupVisibility, MODEL_wan1, MODEL_GROUP_VISIBLE)
        EVT_CALL(SetGroupVisibility, MODEL_wan2, MODEL_GROUP_HIDDEN)
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_wan1, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_wan2, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
