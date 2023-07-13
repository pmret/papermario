#include "kmr_11.h"

#define NAME_SUFFIX _Scripted
#include "common/foliage.inc.c"
#define NAME_SUFFIX

API_CALLABLE(N(SetupFog)) {
    set_world_fog_dist(980, 1000);
    set_world_fog_color(15, 5, 55, 255);
    enable_world_fog();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UseSlowerFadeOnMapChange)) {
    set_map_change_fade_rate(10); // 20 is default
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PlayFortressAnimation) = {
    EVT_CALL(LoadAnimatedModel, MDL_ANIMATOR_1, EVT_PTR(N(AnimSkeleton_Fortress)))
    EVT_CALL(PlayModelAnimation, MDL_ANIMATOR_1, EVT_PTR(N(AnimScript_Fortress)))
    EVT_CALL(SetAnimatedModelRootPosition, MDL_ANIMATOR_1, 0, 0, 0)
    EVT_CALL(SetAnimatedModelRenderMode, MDL_ANIMATOR_1, RENDER_MODE_SURFACE_OPA)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayBridgeAnimation) = {
    EVT_CALL(LoadAnimatedModel, MDL_ANIMATOR_0, EVT_PTR(N(AnimSkeleton_Bridge)))
    EVT_CALL(PlayModelAnimation, MDL_ANIMATOR_0, EVT_PTR(N(AnimScript_Bridge)))
    EVT_CALL(SetAnimatedModelRootPosition, MDL_ANIMATOR_0, 0, 0, 0)
    EVT_CALL(SetAnimatedModelRenderMode, MDL_ANIMATOR_0, RENDER_MODE_SURFACE_OPA)
    EVT_RETURN
    EVT_END
};

//@bug exit to 'Save and Continue?' map is not properly terminated!
EvtScript N(EVS_BadExit_kmr_24_0) = {
    EVT_CALL(FadeOutMusic, 0, 1500)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_24"), kmr_24_ENTRY_0, TRANSITION_MARIO_BLACK)
    EVT_WAIT(100)
};

EvtScript N(EVS_ExitWalk_kmr_12_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kmr_11_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("kmr_12"), kmr_12_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kmr_10_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kmr_11_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        EVT_CALL(GotoMap, EVT_PTR("kmr_10"), kmr_10_ENTRY_0)
        EVT_WAIT(100)
        EVT_RETURN
    EVT_ELSE
        EVT_WAIT(10)
        EVT_EXEC_WAIT(N(EVS_Scene_KammyWatching))
    EVT_END_IF
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1,exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_10_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_RETURN
    EVT_END
};

FoliageModelList N(SwitchBush_Models) = FOLIAGE_MODEL_LIST(MODEL_kusa4);

FoliageVectorList N(SwitchBush_Effects) = {
    .count = 1,
    .vectors = {
        { -381.0f, 12.0f, 82.0f },
    }
};

SearchBushConfig N(SearchBush_SwitchBush) = {
    .bush = &N(SwitchBush_Models),
    .vectors = &N(SwitchBush_Effects),
    .callback = &N(EVS_Interact_SwitchBush),
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_GOOMBA_ROAD)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(N(UseSlowerFadeOnMapChange))
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(ClearDefeatedEnemies)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        EVT_CALL(N(SetupFog))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetupFoliage))
    EVT_CALL(InitAnimatedModels)
    EVT_CALL(EnableModel, MODEL_eye_mask, FALSE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_HIT_GATEHOUSE_SWITCH)
        EVT_CALL(EnableModel, MODEL_bb, FALSE)
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_ue, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_sotokabe, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_tobira, MODEL_GROUP_HIDDEN)
        EVT_CALL(EnableModel, MODEL_b1, FALSE)
        EVT_CALL(EnableModel, MODEL_b2, FALSE)
        EVT_CALL(EnableModel, MODEL_b3, FALSE)
        EVT_CALL(EnableModel, MODEL_b4, FALSE)
        EVT_CALL(EnableModel, MODEL_b5, FALSE)
        EVT_CALL(EnableModel, MODEL_b6, FALSE)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_DEFEATED_GOOMBA_KING)
        EVT_IF_EQ(GF_KMR11_GoombaBrosFledToCastle, FALSE)
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_CALL(SetMusicTrack, 0, SONG_GOOMBA_BROS_RETREAT, 1, 8)
            EVT_EXEC_WAIT(N(EVS_Scene_MeetGoombaKing))
            EVT_SET(GF_KMR11_GoombaBrosFledToCastle, TRUE)
        EVT_ELSE
            EVT_EXEC(N(EVS_SetupMusic))
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_END_IF
    EVT_ELSE
        EVT_EXEC(N(EVS_SetupMusic))
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_SwitchBush)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Scripted)), TRIGGER_WALL_PRESS_A, COLLIDER_kusa4, 1, 0)
    EVT_CALL(SetGroupVisibility, MODEL_event_cam, MODEL_GROUP_HIDDEN)
    EVT_CALL(TranslateGroup, MODEL_g172, NPC_DISPOSE_LOCATION)
    EVT_CALL(TranslateGroup, MODEL_g173, NPC_DISPOSE_LOCATION)
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_HIT_GATEHOUSE_SWITCH)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
