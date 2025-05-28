#include "jan_03.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING, STORY_CH5_SUSHIE_JOINED_PARTY)
            Call(SetMusicTrack, 0, SONG_YOSHIS_PANIC, 0, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_YOSHIS_VILLAGE, 0, VOL_LEVEL_FULL)
    EndSwitch
    Call(ClearAmbientSounds, 250)
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusicTrack, 0, SONG_TAKING_REST, 0, VOL_LEVEL_FULL)
    Return
    End
};
