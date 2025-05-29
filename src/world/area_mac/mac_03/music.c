#include "mac_03.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusic, 0, SONG_SHY_GUY_INVASION, 0, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_TOAD_TOWN, 0, VOL_LEVEL_FULL)
    EndSwitch
    Return
    End
};
