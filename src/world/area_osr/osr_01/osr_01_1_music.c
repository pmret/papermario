
#include "osr_01.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 6)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 6)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlaySong_Starship) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, osr_01_ENTRY_3)
        EVT_CALL(SetMusicTrack, 0, SONG_STARSHIP_THEME, 0, 8)
    EVT_ELSE
        EVT_EXEC(N(EVS_SetupMusic))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
