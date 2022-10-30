#include "flo_24.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        EVT_CALL(PlaySound, SOUND_80000022)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
