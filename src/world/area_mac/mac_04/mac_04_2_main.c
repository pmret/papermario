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
    BindTrigger(Ref(N(EVS_ExitWalk_mac_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_mac_02_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mac_04_ENTRY_2)
            Exec(N(EVS_BindExitTriggers))
            Exec(N(EVS_ExitToybox))
            Thread
                Wait(20)
                Set(MF_MusicMixTrigger, TRUE)
            EndThread
        CaseEq(mac_04_ENTRY_3)
            Exec(N(EVS_BindExitTriggers))
            Call(SetPlayerPos, -420, 20, -95)
            Call(SetNpcPos, NPC_PARTNER, -420, 20, -65)
            Thread
                Wait(20)
                Set(MF_MusicMixTrigger, TRUE)
            EndThread
        CaseEq(mac_04_ENTRY_4)
            Call(N(SetNightTintMode))
            Call(N(SetNightFogParams), 0, 0, 0, 0, 0, 0, 0, 950, 1000)
            Exec(N(EVS_Scene_WishingToadKid))
        CaseEq(mac_04_ENTRY_5)
            Exec(N(EVS_BindExitTriggers))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_04_ENTRY_4)
        Call(MakeNpcs, FALSE, Ref(N(WishSceneNPCs)))
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH3_STAR_SPRIT_DEPARTED)
                Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
            CaseLt(STORY_CH4_BEGAN_PEACH_MISSION)
                Call(MakeNpcs, FALSE, Ref(N(Chapter4NPCs)))
            CaseEq(STORY_CH4_BEGAN_PEACH_MISSION)
                Call(MakeNpcs, FALSE, Ref(N(PostChapter4NPCs)))
            CaseLt(STORY_CH5_RETURNED_TO_TOAD_TOWN)
                Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
            CaseLt(STORY_CH7_BEGAN_PEACH_MISSION)
                Call(MakeNpcs, FALSE, Ref(N(Chapter7NPCs)))
            CaseDefault
                Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
        EndSwitch
    EndIf
    Set(AF_MAC_31, FALSE)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupRooms))
    Exec(N(EVS_SetupFoliage))
    Exec(N(EVS_SetupShop))
    ExecWait(N(EVS_Toybox_SetupTrainPrompt))
    IfEq(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        Call(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
    Else
        Exec(N(EVS_SetupMusic))
    EndIf
    Exec(N(EVS_EnterMap))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_04_ENTRY_5)
        Wait(65)
    Else
        Wait(1)
    EndIf
    Set(GF_MAC01_RowfBadgesChosen, FALSE)
    Return
    End
};
