#include "flo_11.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EndSwitch
    Return
    End
};
