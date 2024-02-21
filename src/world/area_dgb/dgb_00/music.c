#include "dgb_00.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_WOKE_UP)
            Call(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
    EndSwitch
    Call(ClearAmbientSounds, 250)
    Return
    End
};
