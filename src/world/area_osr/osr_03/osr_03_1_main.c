#include "osr_03.h"

EvtScript N(EVS_HideGroundModels) = {
    EVT_CALL(EnableGroup, MODEL_hiru, FALSE)
    EVT_CALL(EnableGroup, MODEL_niwa, FALSE)
    EVT_CALL(EnableGroup, MODEL_jimidori, FALSE)
    EVT_CALL(EnableGroup, MODEL_kumo, FALSE)
    EVT_CALL(EnableGroup, MODEL_ki1, FALSE)
    EVT_CALL(EnableGroup, MODEL_jimen, FALSE)
    EVT_CALL(EnableGroup, MODEL_kemuri, FALSE)
    EVT_CALL(EnableGroup, MODEL_obj, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(osr_03_ENTRY_1)
            EVT_EXEC(N(MV_Scene_CastleAscending))
        EVT_CASE_EQ(osr_03_ENTRY_2)
            EVT_EXEC(N(MV_Scene_PlayerTossedOut))
        EVT_CASE_EQ(osr_03_ENTRY_3)
            EVT_EXEC(N(EVS_HideGroundModels))
            EVT_EXEC(N(EVS_Scene_Starship))
        EVT_CASE_EQ(osr_03_ENTRY_4)
            EVT_WAIT(15)
            EVT_EXEC(N(EVS_Scene_BeginInterlude))
        EVT_CASE_EQ(osr_03_ENTRY_5)
            EVT_EXEC(N(EVS_HideGroundModels))
            EVT_EXEC(N(EVS_Scene_CastleDestruction))
        EVT_CASE_EQ(osr_03_ENTRY_6)
            EVT_EXEC(N(EVS_Scene_UnusedTossOut))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_NONE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(osr_03_ENTRY_4)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_OR_EQ(STORY_CH0_MET_STAR_SPIRITS)
        EVT_CASE_OR_EQ(STORY_CH1_STAR_SPIRIT_RESCUED)
        EVT_CASE_OR_EQ(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_CALL(ClearAmbientSounds, 250)
            EVT_CALL(SetMusicTrack, 0, SONG_PRISONER_PEACH_THEME, 0, 8)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(STORY_CH2_STAR_SPIRIT_RESCUED)
            EVT_CALL(ClearAmbientSounds, 250)
            EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
        EVT_CASE_OR_EQ(STORY_CH4_STAR_SPIRIT_RESCUED)
        EVT_CASE_OR_EQ(STORY_CH5_OPENED_ESCAPE_ROUTE)
        EVT_CASE_OR_EQ(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(ClearAmbientSounds, 250)
            EVT_CALL(SetMusicTrack, 0, SONG_PEACH_MISSION, 0, 8)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(ClearAmbientSounds, 250)
            EVT_CALL(FadeOutMusic, 0, 500)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_KKJ25_Defeated_Bowser, FALSE)
            EVT_ELSE
                EVT_CALL(SetMusicTrack, 0, SONG_BOWSERS_CASTLE_FALLS, 0, 8)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, osr_03_ENTRY_4)
        EVT_WAIT(15)
    EVT_ELSE
        EVT_WAIT(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
