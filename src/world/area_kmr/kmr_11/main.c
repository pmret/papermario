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
    Call(LoadAnimatedModel, MDL_ANIMATOR_1, Ref(N(AnimSkeleton_Fortress)))
    Call(PlayModelAnimation, MDL_ANIMATOR_1, Ref(N(AnimScript_Fortress)))
    Call(SetAnimatedModelRootPosition, MDL_ANIMATOR_1, 0, 0, 0)
    Call(SetAnimatedModelRenderMode, MDL_ANIMATOR_1, RENDER_MODE_SURFACE_OPA)
    Return
    End
};

EvtScript N(EVS_PlayBridgeAnimation) = {
    Call(LoadAnimatedModel, MDL_ANIMATOR_0, Ref(N(AnimSkeleton_Bridge)))
    Call(PlayModelAnimation, MDL_ANIMATOR_0, Ref(N(AnimScript_Bridge)))
    Call(SetAnimatedModelRootPosition, MDL_ANIMATOR_0, 0, 0, 0)
    Call(SetAnimatedModelRenderMode, MDL_ANIMATOR_0, RENDER_MODE_SURFACE_OPA)
    Return
    End
};

//@bug exit to 'Save and Continue?' map is not properly terminated!
EvtScript N(EVS_BadExit_kmr_24_0) = {
    Call(FadeOutMusic, 0, 1500)
    Call(GotoMapSpecial, Ref("kmr_24"), kmr_24_ENTRY_0, TRANSITION_MARIO_BLACK)
    Wait(100)
};

EvtScript N(EVS_ExitWalk_kmr_12_1) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(UseExitHeading, 60, kmr_11_ENTRY_0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("kmr_12"), kmr_12_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_kmr_10_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(UseExitHeading, 60, kmr_11_ENTRY_1)
    Exec(ExitWalk)
    IfGe(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        Call(GotoMap, Ref("kmr_10"), kmr_10_ENTRY_0)
        Wait(100)
        Return
    Else
        Wait(10)
        ExecWait(N(EVS_Scene_KammyWatching))
    EndIf
    Unbind
    Return
    End
};

MAP_RODATA_PAD(1,exits);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_10_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    Return
    End
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
    Set(GB_WorldLocation, LOCATION_GOOMBA_ROAD)
    Call(SetSpriteShading, SHADING_NONE)
    Call(N(UseSlowerFadeOnMapChange))
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Call(ClearDefeatedEnemies)
    ExecWait(N(EVS_MakeEntities))
    IfLt(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        Call(N(SetupFog))
    EndIf
    ExecWait(N(EVS_SetupFoliage))
    Call(InitAnimatedModels)
    Call(EnableModel, MODEL_eye_mask, FALSE)
    IfLt(GB_StoryProgress, STORY_CH0_HIT_GATEHOUSE_SWITCH)
        Call(EnableModel, MODEL_bb, FALSE)
    Else
        Call(SetGroupVisibility, MODEL_ue, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_sotokabe, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_tobira, MODEL_GROUP_HIDDEN)
        Call(EnableModel, MODEL_b1, FALSE)
        Call(EnableModel, MODEL_b2, FALSE)
        Call(EnableModel, MODEL_b3, FALSE)
        Call(EnableModel, MODEL_b4, FALSE)
        Call(EnableModel, MODEL_b5, FALSE)
        Call(EnableModel, MODEL_b6, FALSE)
    EndIf
    IfLt(GB_StoryProgress, STORY_CH0_DEFEATED_GOOMBA_KING)
        IfEq(GF_KMR11_GoombaBrosFledToCastle, FALSE)
            Exec(N(EVS_BindExitTriggers))
            Call(SetMusicTrack, 0, SONG_GOOMBA_BROS_RETREAT, BGM_VARIATION_1, VOL_LEVEL_FULL)
            ExecWait(N(EVS_Scene_MeetGoombaKing))
            Set(GF_KMR11_GoombaBrosFledToCastle, TRUE)
        Else
            Exec(N(EVS_SetupMusic))
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        EndIf
    Else
        Exec(N(EVS_SetupMusic))
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
        Wait(1)
    EndIf
    Set(LVar0, Ref(N(SearchBush_SwitchBush)))
    BindTrigger(Ref(N(EVS_SearchBush_Scripted)), TRIGGER_WALL_PRESS_A, COLLIDER_kusa4, 1, 0)
    Call(SetGroupVisibility, MODEL_event_cam, MODEL_GROUP_HIDDEN)
    Call(TranslateGroup, MODEL_g172, NPC_DISPOSE_LOCATION)
    Call(TranslateGroup, MODEL_g173, NPC_DISPOSE_LOCATION)
    IfGe(GB_StoryProgress, STORY_CH0_HIT_GATEHOUSE_SWITCH)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
