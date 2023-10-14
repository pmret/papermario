#include "jan_15.h"

EvtScript N(EVS_ExitWalk_jan_16) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, jan_15_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_REACHED_RAPHAELS_TREE)
        EVT_CALL(GotoMap, EVT_PTR("jan_16"), jan_16_ENTRY_3)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("jan_16"), jan_16_ENTRY_0)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_jan_14_1) = EVT_EXIT_WALK(60, jan_15_ENTRY_0, "jan_14", jan_14_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_14_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_16)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupTrees))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilits, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_CALL(SetMusicTrack, 0, SONG_DEEP_JUNGLE, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_JUNGLE)
    EVT_RETURN
    EVT_END
};
