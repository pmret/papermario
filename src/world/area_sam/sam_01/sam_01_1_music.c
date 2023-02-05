#include "sam_01.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_CALL(SetMusicTrack, 0, SONG_SHIVER_CITY, 0, 8)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetMusicTrack, 0, SONG_PENGUIN_MYSTERY, 0, 8)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetMusicTrack, 0, SONG_SHIVER_CITY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
