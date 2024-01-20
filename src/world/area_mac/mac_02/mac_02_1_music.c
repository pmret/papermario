#include "mac_02.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        CaseDefault
            Exec(N(EVS_SetupMusicTriggers))
    EndSwitch
    Return
    End
};
