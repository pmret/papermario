#include "osr_00.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_INTRO)
            EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
        EVT_CASE_EQ(STORY_EPILOGUE)
            EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, osr_00_ENTRY_3)
        EVT_CALL(ClearAmbientSounds, 250)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
