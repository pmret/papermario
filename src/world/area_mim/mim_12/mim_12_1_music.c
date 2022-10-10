#include "mim_12.h"

EvtScript N(EVS_StartForestMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_ARRIVED_AT_BOOS_MANSION)
            EVT_CALL(SetMusicTrack, 0, SONG_BOOS_MANSION, 1, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FOREVER_FOREST, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartGustyMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_WOKE_UP)
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(PlayAmbientSounds, AMBIENT_WIND)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mim_12_ENTRY_0)
        EVT_EXEC_WAIT(N(EVS_StartForestMusic))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_StartGustyMusic))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
