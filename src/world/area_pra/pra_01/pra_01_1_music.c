#include "pra_01.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH7_BEGAN_PEACH_MISSION)
        EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_SHIVER_MOUNTAIN, 0, 8)
    EVT_END_IF
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_RETURN
    EVT_END
};
