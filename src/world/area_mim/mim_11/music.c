#include "mim_11.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_ARRIVED_AT_BOOS_MANSION)
            Call(SetMusicTrack, 0, SONG_BOOS_MANSION, 1, 8)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_FOREVER_FOREST, 0, 8)
    EndSwitch
    Call(PlayAmbientSounds, AMBIENT_SPOOKY)
    Return
    End
};
