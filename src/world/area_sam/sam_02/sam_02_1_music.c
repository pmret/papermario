#include "sam_02.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Call(SetMusicTrack, 0, SONG_SHIVER_CITY, 0, 8)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetMusicTrack, 0, SONG_PENGUIN_MYSTERY, 0, 8)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetMusicTrack, 0, SONG_SHIVER_CITY, 0, 8)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    Return
    End
};
