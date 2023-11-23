#include "mac_04.h"
#include "model.h"

API_CALLABLE(N(SetNightFogParams)) {
    Bytecode* args = script->ptrReadPos;
    s32 primR = evt_get_variable(script, *args++);
    s32 primG = evt_get_variable(script, *args++);
    s32 primB = evt_get_variable(script, *args++);
    s32 primA = evt_get_variable(script, *args++);
    s32 fogR = evt_get_variable(script, *args++);
    s32 fogG = evt_get_variable(script, *args++);
    s32 fogB = evt_get_variable(script, *args++);
    s32 fogStart = evt_get_variable(script, *args++);
    s32 fogEnd = evt_get_variable(script, *args++);

    mdl_set_depth_tint_params(primR, primG, primB, primA, fogR, fogG, fogB, fogStart, fogEnd);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetNightTintMode)) {
    mdl_set_all_tint_type(ENV_TINT_REMAP);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_mac_05_0) = EVT_EXIT_WALK(60, mac_04_ENTRY_1, "mac_05", mac_05_ENTRY_0);
EvtScript N(EVS_ExitWalk_mac_02_0) = EVT_EXIT_WALK(60, mac_04_ENTRY_0, "mac_02", mac_02_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_02_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(mac_04_ENTRY_2)
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_EXEC(N(EVS_ExitToybox))
            EVT_THREAD
                EVT_WAIT(20)
                EVT_SET(MF_MusicMixTrigger, TRUE)
            EVT_END_THREAD
        EVT_CASE_EQ(mac_04_ENTRY_3)
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_CALL(SetPlayerPos, -420, 20, -95)
            EVT_CALL(SetNpcPos, NPC_PARTNER, -420, 20, -65)
            EVT_THREAD
                EVT_WAIT(20)
                EVT_SET(MF_MusicMixTrigger, TRUE)
            EVT_END_THREAD
        EVT_CASE_EQ(mac_04_ENTRY_4)
            EVT_CALL(N(SetNightTintMode))
            EVT_CALL(N(SetNightFogParams), 0, 0, 0, 0, 0, 0, 0, 950, 1000)
            EVT_EXEC(N(EVS_Scene_WishingToadKid))
        EVT_CASE_EQ(mac_04_ENTRY_5)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mac_04_ENTRY_4)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(WishSceneNPCs)))
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH3_STAR_SPRIT_DEPARTED)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
            EVT_CASE_LT(STORY_CH4_BEGAN_PEACH_MISSION)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(Chapter4NPCs)))
            EVT_CASE_EQ(STORY_CH4_BEGAN_PEACH_MISSION)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(PostChapter4NPCs)))
            EVT_CASE_LT(STORY_CH5_RETURNED_TO_TOAD_TOWN)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
            EVT_CASE_LT(STORY_CH7_BEGAN_PEACH_MISSION)
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(Chapter7NPCs)))
            EVT_CASE_DEFAULT
                EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SET(AF_MAC_31, FALSE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupRooms))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_SetupShop))
    EVT_EXEC_WAIT(N(EVS_Toybox_SetupTrainPrompt))
    EVT_IF_EQ(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
    EVT_ELSE
        EVT_EXEC(N(EVS_SetupMusic))
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mac_04_ENTRY_5)
        EVT_WAIT(65)
    EVT_ELSE
        EVT_WAIT(1)
    EVT_END_IF
    EVT_SET(GF_MAC01_RowfBadgesChosen, FALSE)
    EVT_RETURN
    EVT_END
};
