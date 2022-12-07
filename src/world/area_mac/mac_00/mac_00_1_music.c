#include "mac_00.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_INTRO)
            EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
        EVT_CASE_EQ(STORY_EPILOGUE)
            EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 0, 8)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        EVT_CASE_DEFAULT
            EVT_EXEC(N(EVS_SetupMusicTriggers))
    EVT_END_SWITCH
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(mac_00_ENTRY_4)
        EVT_CASE_OR_EQ(mac_00_ENTRY_5)
        EVT_CASE_OR_EQ(mac_00_ENTRY_6)
        EVT_CASE_OR_EQ(mac_00_ENTRY_7)
            EVT_CALL(ClearAmbientSounds, 250)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
