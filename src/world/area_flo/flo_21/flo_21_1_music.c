#include "flo_21.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        EVT_CALL(FadeOutMusic, 0, 500)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_CLOUDY_CLIMB, 0, 8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
