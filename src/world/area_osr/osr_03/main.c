#include "osr_03.h"

EvtScript N(EVS_HideGroundModels) = {
    Call(EnableGroup, MODEL_hiru, false)
    Call(EnableGroup, MODEL_niwa, false)
    Call(EnableGroup, MODEL_jimidori, false)
    Call(EnableGroup, MODEL_kumo, false)
    Call(EnableGroup, MODEL_ki1, false)
    Call(EnableGroup, MODEL_jimen, false)
    Call(EnableGroup, MODEL_kemuri, false)
    Call(EnableGroup, MODEL_obj, false)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(osr_03_ENTRY_1)
            Exec(N(MV_Scene_CastleAscending))
        CaseEq(osr_03_ENTRY_2)
            Exec(N(MV_Scene_PlayerTossedOut))
        CaseEq(osr_03_ENTRY_3)
            Exec(N(EVS_HideGroundModels))
            Exec(N(EVS_Scene_Starship))
        CaseEq(osr_03_ENTRY_4)
            Wait(15)
            Exec(N(EVS_Scene_BeginInterlude))
        CaseEq(osr_03_ENTRY_5)
            Exec(N(EVS_HideGroundModels))
            Exec(N(EVS_Scene_CastleDestruction))
        CaseEq(osr_03_ENTRY_6)
            Exec(N(EVS_Scene_UnusedTossOut))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_NONE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(osr_03_ENTRY_4)
            Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
        CaseDefault
    EndSwitch
    Switch(GB_StoryProgress)
        CaseOrEq(STORY_CH0_MET_STAR_SPIRITS)
        CaseOrEq(STORY_CH1_STAR_SPIRIT_RESCUED)
        CaseOrEq(STORY_CH3_STAR_SPIRIT_RESCUED)
            Call(ClearAmbientSounds, 250)
            Call(SetMusic, 0, SONG_PRISONER_PEACH_THEME, 0, VOL_LEVEL_FULL)
        EndCaseGroup
        CaseEq(STORY_CH2_STAR_SPIRIT_RESCUED)
            Call(ClearAmbientSounds, 250)
            Call(SetMusic, 0, SONG_BOWSER_THEME, 0, VOL_LEVEL_FULL)
        CaseOrEq(STORY_CH4_STAR_SPIRIT_RESCUED)
        CaseOrEq(STORY_CH5_OPENED_ESCAPE_ROUTE)
        CaseOrEq(STORY_CH6_STAR_SPIRIT_RESCUED)
            Call(ClearAmbientSounds, 250)
            Call(SetMusic, 0, SONG_PEACH_MISSION, 0, VOL_LEVEL_FULL)
        EndCaseGroup
        CaseEq(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(ClearAmbientSounds, 250)
            Call(FadeOutMusic, 0, 500)
        CaseDefault
            IfEq(GF_KKJ25_Defeated_Bowser, false)
            Else
                Call(SetMusic, 0, SONG_BOWSERS_CASTLE_FALLS, 0, VOL_LEVEL_FULL)
            EndIf
    EndSwitch
    Exec(N(EVS_EnterMap))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, osr_03_ENTRY_4)
        Wait(15)
    Else
        Wait(1)
    EndIf
    Return
    End
};
