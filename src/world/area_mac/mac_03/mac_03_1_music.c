#include "mac_03.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
