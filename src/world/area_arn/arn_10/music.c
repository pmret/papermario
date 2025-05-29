#include "arn_10.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_HEART_FLED_FIRST_TUNNEL)
            Call(SetMusic, 0, SONG_TUBBA_ESCAPE, 0, VOL_LEVEL_FULL)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SetMusic, 0, SONG_TUBBA_BLUBBA_THEME, 0, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_GUSTY_GULCH, 0, VOL_LEVEL_FULL)
    EndSwitch
    Return
    End
};
