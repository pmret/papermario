#include "mim_11.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_ARRIVED_AT_BOOS_MANSION)
            Call(SetMusic, 0, SONG_BOOS_MANSION, BGM_VARIATION_1, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_FOREVER_FOREST, 0, VOL_LEVEL_FULL)
    EndSwitch
    Call(PlayAmbientSounds, AMBIENT_SPOOKY)
    Return
    End
};
