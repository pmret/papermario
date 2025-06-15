#include "flo_25.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SetMusic, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_FLOWER_FIELDS_SUNNY, 0, VOL_LEVEL_FULL)
    EndSwitch
    Return
    End
};
