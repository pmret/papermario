#include "flo_00.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(flo_00_ENTRY_8)
            EVT_IF_NE(AF_FLO_RidingBeanstalk, FALSE)
                EVT_CALL(SetMusicTrack, 0, SONG_MAGIC_BEANSTALK, 1, 8)
            EVT_ELSE
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
            EVT_END_IF
        EVT_CASE_EQ(flo_00_ENTRY_9)
            EVT_CALL(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
        EVT_CASE_EQ(flo_00_ENTRY_A)
            EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_WAIT(1)
                    EVT_IF_GE(GB_StoryProgress, STORY_CH6_STAR_SPRIT_DEPARTED)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
            EVT_END_THREAD
        EVT_CASE_EQ(flo_00_ENTRY_B)
            EVT_CALL(FadeInMusic, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 3000, 0, 127)
        EVT_CASE_DEFAULT
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                    EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
