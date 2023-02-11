#include "kkj_18.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        EVT_CALL(SetMusicTrack, 0, SONG_PEACH_MISSION, 0, 8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
