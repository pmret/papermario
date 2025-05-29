#include "omo_15.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_DEFEATED_GENERAL_GUY)
            Call(SetMusic, 0, SONG_GENERAL_GUY_THEME, 0, VOL_LEVEL_FULL)
        CaseEq(STORY_CH4_DEFEATED_GENERAL_GUY)
            Call(FadeOutMusic, 0, 500)
        CaseDefault
            Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
    EndSwitch
    Return
    End
};
