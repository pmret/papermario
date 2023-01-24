#include "omo_15.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_DEFEATED_GENERAL_GUY)
            EVT_CALL(SetMusicTrack, 0, SONG_GENERAL_GUY_THEME, 0, 8)
        EVT_CASE_EQ(STORY_CH4_DEFEATED_GENERAL_GUY)
            EVT_CALL(FadeOutMusic, 0, 500)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
