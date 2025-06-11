#include "arn_07.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_WOKE_UP)
            Call(SetMusic, 0, SONG_GUSTY_GULCH, 0, VOL_LEVEL_FULL)
            Call(PlayAmbientSounds, AMBIENT_WIND)
        CaseLt(STORY_CH3_HEART_ESCAPED_WINDY_MILL)
            Call(SetMusic, 0, SONG_TUBBA_ESCAPE, 0, VOL_LEVEL_FULL)
            Call(PlayAmbientSounds, AMBIENT_WIND)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SetMusic, 0, SONG_TUBBA_BLUBBA_THEME, 0, VOL_LEVEL_FULL)
            Call(PlayAmbientSounds, AMBIENT_WIND)
        CaseEq(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(SetMusic, 0, SONG_STAR_SPIRIT_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_GUSTY_GULCH, 0, VOL_LEVEL_FULL)
            Call(PlayAmbientSounds, AMBIENT_WIND)
    EndSwitch
    Return
    End
};
