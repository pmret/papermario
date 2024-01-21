#include "flo_24.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
    Else
        Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        Call(PlaySound, SOUND_LOOP_FLO_WATER_FLOW_2)
    EndIf
    Return
    End
};
